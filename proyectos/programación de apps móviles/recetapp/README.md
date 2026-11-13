# RecetAPP

## Descripción General

RecetAPP es un proyecto  diseñado para entusiastas de la cocina que buscan explorar, descubrir y gestionar recetas de manera centralizada. Integrando servicios externos de alimentación mediante API y persistencia de datos local, esta herramienta permite sincronizar inspiración culinaria con preferencias personales en una interfaz minimalista y eficiente.

## Características Principales

- **Consumo Dinámico de API:** Conexión en tiempo real con Spoonacular API para buscar miles de recetas filtradas por ingredientes, restricciones dietéticas, calorías o tiempos de preparación.
    
- **Gestor de Favoritos:** Sistema local para marcar y almacenar recetas predilectas, permitiendo el acceso rápido sin necesidad de realizar consultas repetidas a la red.
    
- **Creación y Edición Personalizada:** Modulo para que los usuarios puedan añadir sus propias recetas caseras, incluyendo listas de ingredientes, pasos de elaboración y tiempos estimados.
    
- **Control de Despensa:** Funcionalidad para introducir los ingredientes disponibles en casa y obtener sugerencias de recetas basadas exclusivamente en esos elementos.
    
- **Interfaz Adaptativa:** Diseño optimizado tanto para dispositivos móviles como para navegadores de escritorio, priorizando la legibilidad durante la preparación de alimentos.
    

## Arquitectura Técnica

- **Frontend:** React / React Native para una experiencia de usuario fluida y multiplataforma.
    
- **Backend:** Node.js con gestión de estado local mediante almacenamiento en MongoDB.
    
- **Cliente HTTP:** Axios para el manejo eficiente de solicitudes asincronas hacia la API externa.
    

## Instalación y Configuración

Sigue los pasos a continuación para clonar y poner en marcha el proyecto en tu entorno de desarrollo local.

### Prerrequisitos

- Node.js (version 18.0 o superior)
    
- Gestor de paquetes npm
    
- Clave de API valida obtenida desde [Spoonacular](https://spoonacular.com/food-api)
    

### Pasos de Instalacion

1. Clona el repositorio:
    
    Bash
    
    ```
    git clone https://github.com/usuario/RecetAPP.git
    cd RecetAPP
    ```
    
2. Instala las dependencias necesarias:
    
    Bash
    
    ```
    npm install
    ```
    
1. Configura las variables de entorno creando un archivo `.env` en la raíz del proyecto y añade tu clave:
    
    Fragmento de código
    
    ```
    RAPI_KEY=tu_clave_de_spoonacular_aqui
    ```
    
2. Ejecuta la aplicacion en modo de desarrollo:
    
    Bash
    
    ```
    npm start
    ```

Deploy en Railway