

## **Perrógato** es una aplicación de inteligencia artificial y visión por computadora orientada a la clasificación de imágenes en tiempo real. Utiliza un modelo de CNN entrenado previamente, lo que permite realizar inferencias directamente en el navegador web del usuario.

## Estructura del Proyecto

```
.
├── Clasificador.py         # Script para entrenamiento del modelo
├── favicon.ico           
├── index.html              # Interfaz web principal para la carga de imágenes y predicción
├── modelo.json              
├── modelo1-perrogato1.bin  # Pesos binarios del modelo (parte 1)
├── modelo1-perrogato2.bin  # Pesos binarios del modelo (parte 2)
├── URU.png                 # Logo / Gráfico corporativo o institucional
├── URU-celular.png        
└── URU-tab.png            
```

## Características Principales

- **Navegador:** Ejecución del modelo de clasificación utilizando `modelo.json` y los archivos de pesos `.bin` mediante TensorFlow.js, sin necesidad de enviar imágenes a un servidor externo.
    
- **Interfaz Web Responsiva:** Diseño adaptable (`index.html`) respaldado con assets visuales específicos para dispositivos móviles (`URU-celular.png`), tabletas (`URU-tab.png`) y escritorio (`URU.png`).
    
- **Script de Apoyo en Python:** Archivo `Clasificador.py` para tareas de procesamiento previo, prueba de scripts locales o re-entrenamiento del modelo.
    

## Tecnologías Utilizadas

- **Python:** Entorno de script y procesamiento de datos.
    
- **TensorFlow.js:** Formato de modelo exportado para ejecución web.
    
- **HTML5 / CSS3:** Estructura e interfaz de usuario.
    

## Modo de Uso

### Ejecución de la Interfaz Web

1. Sirve la carpeta del proyecto a través de un servidor local (por ejemplo, usando la extensión _Live Server_ en VS Code o ejecutando `python -m http.server`).
    
2. Abre `index.html` en tu navegador.
    
3. Carga una imagen de un perro o un gato para obtener la predicción del modelo en tiempo real.