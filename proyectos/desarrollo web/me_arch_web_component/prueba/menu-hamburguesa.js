const w = window.innerWidth, h = window.innerHeight

class Menu extends HTMLElement {
    constructor() {
        super()
        this.img = document.createElement('img')
        this.ul = document.createElement('ul')
        this.childObj = []
        for (var i = 0; i < this.children.length; i++) {
            const child = this.children[i]
            this.childObj.push({ text: child.getAttribute('text'), href: child.getAttribute('href') })
        }
        this.hamburgIcon = new HamburgIcon(this.img, this.ul)
        this.animationHandler = new AnimationHandler(this)
        const shadow = this.attachShadow({ mode: 'open' })
        this.initUiPosition()
        shadow.appendChild(this.ul)
        shadow.appendChild(this.img)
    }

    initUiPosition() {
        this.img.style.position = 'fixed'
        const ulSize = Math.min(300, w * 0.75)
        this.img.style.left = '20px'
        this.img.style.top = '20px'
        this.img.style.cursor = 'pointer'
        this.img.style.zIndex = '1000'
        this.img.style.transition = 'transform 0.2s ease'
        
        this.img.onmouseover = () => this.img.style.transform = 'scale(1.05)'
        this.img.onmouseout = () => this.img.style.transform = 'scale(1)'

        this.ul.style.width = `${ulSize}px`
        this.ul.style.height = '100vh'
        this.ul.style.position = 'fixed'
        this.ul.style.left = `-${ulSize}px`
        this.ul.style.top = '0'
        this.ul.style.background = 'rgba(27, 23, 37, 0.95)'
        this.ul.style.backdropFilter = 'blur(10px)'
        this.ul.style.boxShadow = '5px 0 25px rgba(0,0,0,0.3)'
        this.ul.style.padding = '80px 30px 40px 30px'
        this.ul.style.listStyle = 'none'
        this.ul.style.margin = '0'
        this.ul.style.zIndex = '999'
        this.ul.style.display = 'flex'
        this.ul.style.flexDirection = 'column'
        this.ul.style.gap = '15px'

        this.childObj.forEach((child) => {
            const li = document.createElement('li')
            const a = document.createElement('a')
            a.setAttribute('href', child.href)
            a.innerHTML = child.text
            a.style.color = 'rgb(241, 235, 235)'
            a.style.fontSize = '1.2rem'
            a.style.fontFamily = 'system-ui, -apple-system, sans-serif'
            a.style.textDecoration = 'none'
            a.style.display = 'block'
            a.style.padding = '12px 16px'
            a.style.borderRadius = '8px'
            a.style.transition = 'background 0.3s ease, transform 0.2s ease'
            
            a.onmouseover = () => {
                a.style.background = 'rgba(144, 136, 156, 0.2)'
                a.style.transform = 'translateX(5px)'
            }
            a.onmouseout = () => {
                a.style.background = 'transparent'
                a.style.transform = 'translateX(0)'
            }

            li.appendChild(a)
            this.ul.appendChild(li)
        })
    }

    connectedCallback() {
        this.render()
        this.img.onmousedown = (event) => {
            if (this.animationHandler) {
                this.animationHandler.startAnimation()
            }
        }
    }

    render() {
        const canvas = document.createElement('canvas')
        const size = 48
        canvas.width = size
        canvas.height = size
        const context = canvas.getContext('2d')
        context.clearRect(0, 0, size, size)
        
        context.save()
        context.fillStyle = 'rgba(27, 23, 37, 0.9)'
        context.beginPath()
        context.roundRect(0, 0, size, size, 10)
        context.fill()
        context.restore()

        this.hamburgIcon.draw(context, size)
        this.img.src = canvas.toDataURL()
    }

    update() {
        this.hamburgIcon.update()
    }

    startUpdating(dir) {
        this.hamburgIcon.startUpdating(dir)
    }

    stopped() {
        return this.hamburgIcon.stopped()
    }
}

class HamburgIcon {
    constructor(img, ul) {
        this.img = img
        this.ul = ul
        this.dir = 0
        this.progress = 0 
    }

    draw(context, size) {
        context.strokeStyle = 'rgb(241, 235, 235)'
        context.lineWidth = 2.5
        context.lineCap = 'round'
        
        const cx = size / 2
        const cy = size / 2
        const len = 12

        context.save()
        context.translate(cx, cy)

        // Interpolación para transformar las 3 líneas en una X impecable
        const p = this.progress
        const gap = 8 * (1 - p) // Las líneas exterior se contraen al centro
        const angle = p * (Math.PI / 4) // Rotación de 45 grados

        // Línea superior (se desplaza al centro y rota a 45°)
        context.save()
        context.translate(0, -gap)
        context.rotate(angle)
        context.beginPath()
        context.moveTo(-len, 0)
        context.lineTo(len, 0)
        context.stroke()
        context.restore()

        // Línea central (se desvanece suavemente)
        if (p < 1) {
            context.save()
            context.globalAlpha = 1 - p
            context.beginPath()
            context.moveTo(-len, 0)
            context.lineTo(len, 0)
            context.stroke()
            context.restore()
        }

        // Línea inferior (se desplaza al centro y rota a -45°)
        context.save()
        context.translate(0, gap)
        context.rotate(-angle)
        context.beginPath()
        context.moveTo(-len, 0)
        context.lineTo(len, 0)
        context.stroke()
        context.restore()

        context.restore()
    }

    startUpdating(dir) {
        this.dir = dir
    }

    update() {
        const speed = 0.08
        this.progress += this.dir * speed

        if (this.progress > 1) {
            this.progress = 1
            this.dir = 0
        }
        if (this.progress < 0) {
            this.progress = 0
            this.dir = 0
        }

        // Función de aceleración suave (Easing Cubic)
        const ease = p => p < 0.5 ? 4 * p * p * p : 1 - Math.pow(-2 * p + 2, 3) / 2
        const easedProgress = ease(this.progress)

        const ulWidth = parseFloat(this.ul.style.width)
        const currentLeft = -ulWidth + (easedProgress * ulWidth)
        this.ul.style.left = `${currentLeft}px`
        
        // Mantiene el botón de forma elegante dentro del margen superior de la pantalla
        const currentImgLeft = 20 + (easedProgress * (ulWidth - 68))
        this.img.style.left = `${currentImgLeft}px`
    }

    stopped() {
        return this.dir === 0
    }
}

class AnimationHandler {
    constructor(component) {
        this.prevDir = 1
        this.animating = false
        this.component = component
    }

    startAnimation() {
        if (!this.animating) {
            this.animating = true
            this.component.startUpdating(this.prevDir)
            const interval = setInterval(() => {
                this.component.render()
                this.component.update()
                if (this.component.stopped() == true) {
                    this.prevDir *= -1
                    this.animating = false
                    clearInterval(interval)
                    this.component.render()
                }
            }, 16)
        }
    }
}

customElements.define('me-arch', Menu)