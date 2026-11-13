## Descripción General

web_chat es una aplicación web de mensajeria en tiempo real desarrollada para demostrar la comunicación bidireccional cliente-servidor. La plataforma permite a multiples usuarios conectarse a salas de chat, enviar mensajes instantáneos.

## Características Principales

- **Mensajería en Tiempo Real:** Comunicación instantánea impulsada por WebSockets para el envío y recepción de mensajes con baja latencia.
    
- **Gestión de Salas y Usuarios:** Capacidad para unirse a salas temáticas y monitorear los usuarios conectados en tiempo real (en progreso)
    
- **Interfaz Dinámica:** Renderizado de vistas mediante motor de plantillas en el lado del servidor, ofreciendo una experiencia fluida e interactiva.
    

## Arquitectura y Tecnologías

- **Servidor Web:** Express.js sobre Node.js para la gestión de rutas y middleware.
    
- **Comunicación Bidireccional:** Socket.IO nativos para el manejo de eventos en tiempo real.
    
- **Motor de Plantillas:** EJS (Embedded JavaScript) para la generación dinámica de HTML.
    

## Instalación y Configuración

Sigue los siguientes pasos para ejecutar el proyecto de manera local.

### Prerrequisitos

- Node.js (version 18.0 o superior)
    
- npm
    

### Pasos de Instalacion

1. Clona el repositorio:
    
    ```
    git clone https://github.com/usuario/web_chat.git
    cd web_chat
    ```
    
2. Instala las dependencias del proyecto:
    
    ```
    npm install
    ```
    
3. Inicia el servidor de desarrollo:
    
    ```
    npm start
    ```
    
4. Abre tu navegador e ingresa a `http://localhost:3000`.
    

## Estructura del Proyecto

```
Socket/
├── public/
├──── script.js      # Archivos estaticos (CSS, JS del cliente)
├── views/           # Plantillas EJS (chat, vistas de inicio)
├──── index.ejs
├──── password.ejs
├──── room.ejs       # Punto de entrada de la aplicacion y eventos de Socket
├──── package.json   # Configuracion del proyecto y dependencias
├──── server.js      # Inicialización del servidor
└──── package-lock.json
```
