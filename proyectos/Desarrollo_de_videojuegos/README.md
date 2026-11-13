# Proyectos de Desarrollo de Videojuegos

Este repositorio reúne tres proyectos prácticos desarrollados para la asignatura **Desarrollo de Videojuegos**. La colección abarca desde programación estructurada a nivel de consola hasta desarrollo e implementación en un motor gráfico tridimensional/bidimensional moderno.

## Juegos Incluidos

### 1. Buscaminas (Consola)

- **Tecnología:** C puro.
    
- **Descripción:** Implementación clásica del juego Buscaminas diseñada para ejecutarse directamente en la terminal de Windows
    
- **Características:**
    
    - Generación aleatoria de minas en la matriz de juego.
        
    - Revelado progresivo de casillas vacías mediante algoritmos recursivos.
        
    - Entrada de datos y comandos mediante teclado en la terminal.
        

### 2. Clon de Pacman

- **Motor:** Unity.
    
- **Descripción:** Recreación bidimensional del clásico arcade Pacman.
    
- **Características:**
    
    - Control del jugador en una cuadrícula con movimiento continuo.
        
    - Comportamiento de fantasmas con patrones de navegación y persecución.
        
    - Transición de estados de juego (victoria, derrota, reinicio de nivel).
        

### 3. Mario Bros (Niveles 1 y 2)

- **Motor:** Unity.
    
- **Descripción:** Adaptación de los dos primeros niveles del Mario Bros clásico.
    
- **Características:**
    
    - Físicas personalizadas para el salto y colisiones del personaje principal
        
    - Sistema de _Tilemaps_ para la construcción de escenarios y bloques rompibles.
        
    - Enemigos básicos (Goombas) con rutinas de movimiento simple y detección de daño.
        
    - Mecánica de recolección de monedas con interfaz de usuario (HUD).
        

## Requisitos e Instalación

### Buscaminas en C

Para compilar y ejecutar el proyecto en C se requiere un compilador estándar como `gcc`:

```
cd Buscaminas-C
gcc -o buscaminas main.c
./buscaminas
```

### Proyectos en Unity (Pacman y Mario Bros)

1. Instalar **Unity Hub** y una versión compatible del motor Unity (2021.3 LTS o superior recomendada).
    
2. Abrir Unity Hub y seleccionar la opción **Add** (Añadir).
    
3. Navegar hasta la carpeta del proyecto correspondiente (`Pacman-Unity` o `MarioBros-Unity`) y abrirla para ejecutar el entorno de desarrollo.

## Créditos y Derechos de Autor 
Este es un proyecto académico desarrollado sin fines de lucro únicamente con propósitos educativos. 
* **Derechos de Autor Originales:** Los sprites, personajes y elementos gráficos pertenecientes a Super Mario Bros pertenecen a la propiedad intelectual de Nintendo y los sprites, personajes y elementos gráficos pertenecientes Pac-Man son propiedad intelectual de Bandai Namco.
* **Recursos Gráficos:** Los recursos visuales (spritesheets) fueron obtenidos a través de la comunidad de [The Spriters Resource](https://www.spriters-resource.com/). 
* **Rippers / Colaboradores:** Créditos a los usuarios de la comunidad de Spriters Resource por extraer los archivos originales.