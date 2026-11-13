````
# Me-Arch Web Component 

Un componente web personalizado (`<me-arch>`) desarrollado en JavaScript vanilla que implementa un menú lateral deslizante (hamburger menu) con animaciones fluidas dibujadas por Canvas y transiciones de ícono integradas.

## Características

- **Web Component Nativo:** Encapsulado mediante *Shadow DOM* sin dependencias externas de librerías o frameworks.
- **Icono Dinámico en Canvas:** El botón del menú se renderiza dinámicamente mediante un contexto 2D de HTML5 Canvas.
- **Movimiento Eased:** Desplazamiento lateral optimizado con cubic easing para evitar movimientos bruscos.
- **Estilos Modernos:** Fondo translúcido con efecto de desenfoque y diseño responsivo adaptado.

## Instalación y Uso

1. Copia el archivo del script de JavaScript en tu proyecto.
2. Registra el componente web en tu HTML e inserta los elementos dentro de la etiqueta `<me-arch>` utilizando los atributos de texto y enlace:

```html
<script src="path/to/menu-component.js"></script>

<!-- Uso del componente en tu HTML -->
<me-arch>
  <div text="Inicio" href="#home"></div>
  <div text="Servicios" href="#services"></div>
  <div text="Portafolio" href="#portfolio"></div>
  <div text="Contacto" href="#contact"></div>
</me-arch>
````

## Tecnologías utilizadas:

- **JavaScript (ES6+ Classes)**
    
- **Custom Elements & Shadow DOM API**
    
- **HTML5 Canvas**
    
- **CSS Styles & Inline DOM manipulation**
    