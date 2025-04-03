# LUAR: Localización GPS con ESP32 y Módulo GPS NEO 6M

**Sistema de localización para perros con Arduino para ESP32, Firebase para recibir las coordenadas en tiempo real, HTML, CSS, JavaScript para visualizar el mapa.**

![WhatsApp Image 2025-04-03 at 16 08 51](https://github.com/user-attachments/assets/10fec954-a210-425f-b534-b93fbbe87ab7)

## Descripción

**LUAR** es un sistema de localización en tiempo real para perros, utilizando una placa **ESP32** y un **Módulo GPS NEO 6M**. El sistema almacena y actualiza las coordenadas del perro en tiempo real mediante **Firebase** y las visualiza en un mapa en una página web utilizando **HTML**, **CSS**, y **JavaScript**.

### Tecnologías Utilizadas:
- **ESP32**: Placa microcontroladora para la recolección de datos.
- **Módulo GPS NEO 6M**: Módulo para obtener las coordenadas GPS en tiempo real.
- **Firebase**: Plataforma en tiempo real para almacenar las coordenadas.
- **HTML/CSS/JavaScript**: Tecnologías utilizadas para crear el sitio web que muestra el mapa.
- **Arduino IDE**: Entorno de desarrollo para programar el ESP32.

## Imágenes del Proyecto

### **Código en Arduino IDE**
Este es el código utilizado en el **Arduino IDE** para programar la **placa ESP32** con el **módulo GPS NEO 6M** y la integración con Firebase.

![Captura de Pantalla 2025-04-03 a la(s) 15 59 20](https://github.com/user-attachments/assets/417a0b82-addb-481c-ba9f-de563a5e594f)

### **Base de Datos en Tiempo Real en Firebase**
La base de datos en **Firebase** almacena las coordenadas GPS en tiempo real. Los datos son accesibles y actualizados de manera instantánea para ser visualizados en el mapa.

![Base de datos en Firebase](https://github.com/user-attachments/assets/ce41b85c-7bbb-4be4-9684-af32c9cf0b5a)

### **Sitio Web del Mapa**
El sitio web permite visualizar la ubicación del perro en tiempo real en un mapa. La interfaz está diseñada para ser intuitiva y fácil de usar.

![Captura de Pantalla 2025-04-03 a la(s) 16 04 30](https://github.com/user-attachments/assets/e23dfa7e-6081-4025-97f6-a74f390060a4)

## Componentes Requeridos

- **Placa ESP32**
- **Módulo GPS NEO 6M**
- **Baterías** (para alimentar el ESP32 y el módulo GPS)
- **Jumpers Hembra-Hembra** (para las conexiones entre el ESP32 y el módulo GPS)
  
## Software y Herramientas

- **Arduino IDE**: Utilizado para programar la placa **ESP32**.
- **Visual Studio Code (VSC)**: Usado para desarrollar la página web del sistema.
- **Firebase**: Plataforma en la nube para almacenar las coordenadas en tiempo real.

## Pasos de Configuración

### 1. Programar la Placa ESP32
   - **Conectar la placa ESP32** a tu PC.
   - **Vaciar el código** en el Arduino IDE para programar la placa ESP32.
   - Asegúrate de tener instaladas las bibliotecas necesarias para el módulo **GPS NEO 6M** y la **conexión a Firebase** en el **Arduino IDE**.

### 2. Configuración de Firebase
   - Crea una cuenta en **Firebase** si aún no tienes una.
   - Crea un **proyecto nuevo** en Firebase y configura la **base de datos en tiempo real**.
   - Copia las credenciales de tu proyecto en Firebase y pégalos en el código de Arduino para autenticar tu ESP32 y permitir la escritura de datos en la base de datos en tiempo real.

### 3. Crear la Página Web
   - Crea una **página web** utilizando **HTML**, **CSS** y **JavaScript**.
   - Integra el **Google Maps API** en la página web para visualizar el mapa.
   - Utiliza **Firebase JavaScript SDK** para conectar tu página web con la base de datos de Firebase y mostrar las coordenadas en tiempo real.

### 4. Configuración de Firebase en Arduino y JavaScript
   - En el código de **Arduino**, configura la conexión a **Firebase** usando las credenciales obtenidas en el paso 2.
   - En el código de **JavaScript** de la página web, también configura **Firebase** para recibir las coordenadas GPS y actualizarlas en tiempo real en el mapa.

## Uso del Proyecto

1. **Encender el ESP32** y conectar el módulo GPS NEO 6M.
2. El **ESP32** enviará las coordenadas GPS a **Firebase**.
3. La página web, con la integración de **Firebase**, mostrará las coordenadas en **tiempo real** en un mapa.
4. Puedes visualizar la ubicación del perro de manera continua, gracias a la actualización en tiempo real de la base de datos.




