# Control de un Coche de Dos Ruedas con Arduino Nano

Este repositorio contiene el código para controlar un coche de dos ruedas utilizando un Arduino Nano y un puente H. El control del coche se realiza mediante PWM (Modulación por Ancho de Pulso) para ajustar la velocidad de los motores.

## Características

- **Configuración de Pines**: Define y configura los pines de salida para los motores y el control PWM.
- **Funciones de Movimiento**:
  - **Adelante y Atrás**: Controla el movimiento hacia adelante y hacia atrás del coche.
  - **Giros**: Permite realizar giros a la izquierda y a la derecha.
  - **Formas Geométricas**: Implementa movimientos en forma de cuadrado y triángulo.
  - **Movimiento Circular**: Permite que el coche se mueva en un círculo ajustando los PWMs de los motores.
- **Funciones Auxiliares**:
  - **Parar**: Detiene los motores del coche.
  - **Calcular Circunferencia y Radio**: Funciones matemáticas para el cálculo del movimiento circular.

## Archivos Principales

- `setup()`: Configura la comunicación serial y define los pines como salidas.
- `loop()`: Ejecuta en bucle las funciones de movimiento, alternando entre diferentes formas geométricas y movimientos circulares.
- `Adelante()`, `Atras()`, `Parar()`, `GiroDerecha()`, `GiroIzquierda()`: Funciones básicas para controlar el movimiento del coche.
- `Cuadrado()`, `realCuadrado()`, `realTriangulo()`, `Circulo()`, `CirculoPWM()`: Funciones avanzadas para movimientos específicos y formas geométricas.
- Funciones auxiliares para el cálculo de PWM y movimientos circulares (`obtenerPWM()`, `calcularCircunferencia()`, `calcularRadio()`).

## Ejecución

El programa se ejecuta en un bucle infinito, alternando entre diferentes movimientos y formas geométricas, con pausas intermedias para detener el coche.

## Instalación y Uso

1. Clona este repositorio: `git clone https://github.com/DanHxH/C--Control-de-un-Coche-de-Dos-Ruedas-con-Arduino-Nano.git`
2. Abre el archivo `.ino` en el IDE de Arduino.
3. Conecta tu Arduino Nano y sube el programa.
4. Conecta el puente H y los motores según la configuración de pines indicada.

## Requisitos

- Arduino Nano
- Puente H (L298N o similar)
- Motores de corriente continua
- Cables y resistencias para conexiones
- Fuente de alimentación adecuada para los motores

## Contribuciones

Las contribuciones son bienvenidas. Por favor, abre un issue para discutir cualquier cambio o mejora.
