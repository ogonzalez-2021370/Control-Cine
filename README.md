# 🎬 Control de Cine - Proyecto de Programación I

Sistema desarrollado en C++ con Windows Forms (C++/CLI) para la administración y control de un cine. Este proyecto forma parte del curso **Programación I, 2025** de la **Facultad de Ingeniería en Sistemas de Información y Ciencias de la Computación**.

---

## 📌 Descripción

Este sistema permite gestionar las principales operaciones de un cine pequeño, incluyendo:

- Gestión de películas
- Control de salas
- Asignación de películas a salas
- Registro de clientes
- Venta de boletos
- Gestión de usuarios con diferentes niveles de acceso
- Generación de reportes y exportación a HTML

---

## 🎯 Objetivos del proyecto

- Aplicar conceptos de programación orientada a objetos (POO) en C++
- Utilizar estructuras de datos personalizadas (arrays y matrices)
- Implementar relaciones entre clases: asociación, composición y herencia
- Crear una interfaz gráfica amigable usando Windows Forms (C++/CLI)
- Automatizar procesos administrativos del cine

---

## 🛠️ Módulos del sistema

### 🎞️ Películas
- Registro, modificación y eliminación de películas
- Atributos: código, nombre, género, clasificación, idioma, formato, precio, estado

### 🏟️ Salas
- Gestión de salas de cine
- Atributos: código, nombre, capacidad, ubicación, encargado, teléfono

### 🗓️ Asignaciones
- Asignación de películas a salas en horarios específicos
- Atributos: código, película, sala, horario, fecha de estreno

### 👤 Clientes
- Registro y administración de clientes
- Atributos: código, nombre, CUI/pasaporte, fecha de nacimiento, contacto

### 🎫 Boletos
- Venta de boletos con selección de asiento (matriz de sillas)
- Control de estado de sillas (ocupadas / desocupadas)

### 🔐 Usuarios
- Gestión de usuarios del sistema (operadores y administradores)
- Seguridad de acceso mediante login y contraseña
- Tipos de usuario: `Administrador` y `Operador`

---

## 📊 Reportes

- Visualización en pantalla con ordenamientos personalizables
- Exportación en formato `.html`
- Reportes disponibles:
  - Películas por nombre, género, formato
  - Salas por nombre
  - Asignaciones por código
  - Boletos por función
  - Clientes por código

---

## 👥 Roles de usuario

| Rol          | Funciones disponibles |
|--------------|------------------------|
| **Operador** | Gestionar clientes, venta de boletos, generación de reportes |
| **Administrador** | Todas las funciones del operador + gestión de películas, salas, asignaciones y usuarios |

---

## 💾 Carga/Descarga de archivos `.csv`

El sistema permite importar/exportar la información principal para facilitar respaldos:

- `Peliculas.csv`
- `Salas.csv`
- `AsigPeliculasSalas.csv`
- `Clientes.csv`
- `CompraBoleto.csv`
- `Usuarios.csv`

---

## 🚀 Requisitos de ejecución

- 💻 Sistema operativo: Windows
- 🧩 Entorno: Visual Studio (C++/CLI)
- 🛠️ Framework: .NET Framework 4.x
- 📦 No se utilizan bibliotecas externas ni STL, solo arrays personalizados

---

## 📘 Manual de Usuario

El sistema cuenta con un manual de usuario completo que guía paso a paso el uso de cada módulo, incluyendo:

- Inicio de sesión con diferentes tipos de usuario
- Gestión de películas, salas, asignaciones y boletos
- Registro y modificación de clientes
- Control de accesos por roles (Administrador / Operador)
- Carga de archivos `.csv`
- Generación de reportes exportables en formato HTML
- Resolución de problemas comunes
- Preguntas frecuentes

📄 **Manual disponible aquí:**  
[📥 Descargar Manual de Usuario (PDF)](Manuales/Manual%20de%20Usuario.pdf)

---

## 🛠️ Manual Técnico

El manual técnico describe en detalle la arquitectura del sistema, tecnologías empleadas y lógica interna. Incluye el análisis de clases, funciones clave y estructura del código fuente, además de servir como guía para mantenimiento y futuras mejoras.

### Contenido del manual:

- Introducción al sistema y objetivos técnicos
- Detalle de tecnologías utilizadas: C++, C++/CLI, Windows Forms
- Requisitos mínimos del sistema (hardware y software)
- Variables, estructuras y tipos de datos por entidad
- Funciones clave del sistema:
  - CRUD
  - Persistencia con archivos `.csv`
  - Validaciones internas
  - Generación de reportes en HTML
- Eventos principales de la interfaz gráfica
- Diagrama de clases (visual conceptual)
- Glosario de términos técnicos usados en el desarrollo.

📄 **Manual disponible aquí:**  
[📥 Descargar Manual Técnico (PDF)](Manuales/Manual%20T%C3%A9cnico.pdf)












