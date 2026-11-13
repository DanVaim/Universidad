export class Tab {
  constructor(tabmng) {
    this.contenedor = document.createElement('div');
    this.contenedor.classList.add('tabs');
    document.body.append(this.contenedor);
    this.nav = document.createElement("div");
    this.nav.classList.add("nav");
    this.contenedor.append(this.nav);
    this.contenido = document.createElement("div");
    this.contenido.classList.add("contenido");
    this.contenedor.append(this.contenido);

    for (let i of tabmng) {
      let items = document.createElement("button");
      items.innerHTML = i.titulo;
      //console.log(i.titulo);
      items.setAttribute("data-id", "tab" + i.iD);
      //console.log(i.iD);
      items.addEventListener("click", this.tab.bind(this));
      this.nav.append(items);
      //console.log(items); log del nav
      const contenidoTab = document.createElement("div");
      contenidoTab.id = "tab" + i.iD;
      contenidoTab.classList.add("contenido-tab");
      contenidoTab.innerHTML = i.contenido;
      this.contenido.append(contenidoTab);
      // console.log(contenidoTab); contenido por ID 
      
    }
  }

  tab(e) {
    const id = e.target.getAttribute('data-id');
    const navActivo = document.querySelectorAll('.nav button.activo');
    navActivo.forEach(item => item.classList.remove('activo'));
    e.target.classList.add('activo');
    console.log(id);
    //console.log(navActivo); Mostrar el ID del tab activo
    const contenidoActivo = document.querySelectorAll('.contenido-tab.activo');
    contenidoActivo.forEach(item => item.classList.remove('activo'));
    document.getElementById(id).classList.add('activo');
    console.log(contenidoActivo);
    //console.log(document.getElementById(id)); Mostrar el contenido del tab activo
  }
}
