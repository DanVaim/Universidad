# Danotes

## Descripción General

Danote es una aplicación web inspirada en Samsung Notes que permite a los usuarios crear, editar, organizar y gestionar sus notas y recordatorios a través de una interfaz limpia e intuitiva. Esta diseñada con componentes modulares en React para brindar una experiencia interactiva

## Características Principales

- **Editor de Notas Avanzado:** Creación y edición de notas con soporte para modales interactivos y visualización estructurada.
    
- **Gestión de Contexto:** Control de estado global mediante React Context para la sincronización de datos entre el editor y la vista principal.
    
- **Autenticación e Inicio de Sesión:** Componentes dedicados para la gestión de sesiones de usuario donde guardan cada uno sus propias notas personales.
    
- **Interfaz Modular:** Estructura basada en componentes reutilizables para garantizar la escalabilidad y facilidad de mantenimiento.
    

## Tecnologías Utilizadas

- **Frontend:** React.js 
    
- **Estilos y Recursos:** CSS / Assets estáticos integrados
   
- BD: Firebase
    

## Estructura del Proyecto
```
```danotes/
└── src/
    ├── assets/
    ├── components/
    │   ├── Content.jsx        # Visualizacion del contenido de las notas
    │   ├── ContentModal.jsx   # Modal para inspeccionar notas detalladas
    │   ├── EditorContext.jsx # Proveedor de estado global para el editor
    │   ├── EditorModal.jsx   # Modal de edicion y creacion de contenido
    │   ├── Home.jsx          # Vista principal de la aplicacion
    │   ├── Login.jsx         # Vista de inicio de sesion y autenticacion
    │   └── Note.jsx          # Componente tarjeta/elemento de nota 
    ├── scss/
    │   └── style.scss        # Hojas de estilo globales compiladas con 
    ├── App.jsx               # Componente principal de la aplicacion
    ├── credenciales.js       # integracion de autenticacion
    └── main.jsx              # Punto de entrada principal de React

```

## Instalacion y Configuracion

### Prerrequisitos

- Node.js (version 18.0 o superior)
    
- npm
    

### Pasos de Instalacion

1. Clona el repositorio:
    
    ```
    git clone https://github.com/usuario/danotes.git
    cd danotes
    ```
    
2. Instala las dependencias:
    
    ```
    npm install
    ```
    
3. Inicia la aplicacion en entorno de desarrollo:
    
    ```
    npm start
    ```