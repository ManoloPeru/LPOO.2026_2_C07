# SGPlantaReciclaje — Sistema de Gestión de Planta de Reciclaje

![C++/CLI](https://img.shields.io/badge/C%2B%2B-CLI-blue)
![.NET Framework](https://img.shields.io/badge/.NET-Framework-purple)
![Windows Forms](https://img.shields.io/badge/UI-Windows%20Forms-0078D7)
![Visual Studio](https://img.shields.io/badge/IDE-Visual%20Studio%202026-5C2D91)
![License](https://img.shields.io/badge/license-Academic-lightgrey)

Sistema de escritorio para la **gestión del parque de estaciones clasificadoras** de una planta de reciclaje, desarrollado en **C++/CLI** con **Windows Forms** y **.NET Framework**.

El proyecto implementa una **arquitectura en capas** (Modelo – DAO – Controller – Vista) y operaciones **CRUD** completas sobre las entidades del dominio, con persistencia en archivos de texto plano.

---

## 📋 Tabla de Contenidos

- [Descripción General](#-descripción-general)
- [Características Principales](#-características-principales)
- [Arquitectura del Proyecto](#-arquitectura-del-proyecto)
- [Estructura de Carpetas](#-estructura-de-carpetas)
- [Modelo de Datos](#-modelo-de-datos)
- [Capturas de Pantalla](#-capturas-de-pantalla)
- [Requisitos Previos](#-requisitos-previos)
- [Instalación y Ejecución](#-instalación-y-ejecución)
- [Uso del Sistema](#-uso-del-sistema)
- [Patrones de Diseño](#-patrones-de-diseño)
- [Tecnologías Utilizadas](#-tecnologías-utilizadas)
- [Autor](#-autor)
- [Licencia](#-licencia)

---

## 📖 Descripción General

**SGPlantaReciclaje** es un sistema de información que permite administrar el inventario de **estaciones clasificadoras** dentro de una planta de reciclaje. Cada estación cuenta con:

- **Serial ID** único (identificador visible para el usuario).
- **Alias** o nombre descriptivo.
- **Tipo** de estación (Neumática, Magnética, Óptica, Otros).
- **Estado operativo** (Operativo, En Mantenimiento, Falla Crítica, Apagado).
- **Ubicación** específica dentro de la planta.

El sistema permite realizar las operaciones **CRUD** (Crear, Leer, Actualizar, Eliminar) sobre las estaciones, así como gestionar los **catálogos maestros** de tipos y estados operativos.

---

## ✨ Características Principales

- ✅ **CRUD completo** de estaciones clasificadoras.
- ✅ **Búsqueda combinada** por Serial ID, tipo y estado operativo.
- ✅ **Catálogos maestros** cargados dinámicamente en ComboBox no editables.
- ✅ **Persistencia en archivos de texto plano** (`.txt`) con formato delimitado por `;`.
- ✅ **Ruta centralizada** de los archivos de datos mediante la clase base `BaseDAO`.
- ✅ **Arquitectura en capas** claramente separadas.
- ✅ **Validaciones** en la capa de control y en la capa de presentación.
- ✅ **Interfaz gráfica amigable** con DataGridView y MessageBox de confirmación.

---

## 🏗 Arquitectura del Proyecto

El sistema sigue una arquitectura en capas, donde cada capa reside en su propio proyecto de Visual Studio:

```
┌─────────────────────────────────────────────────────┐
│              CAPA DE PRESENTACIÓN                   │
│           SGPlantaReciclajeView (GUI)               │
│   frmMantEstacion │ frmNuevaEstacion │ frmEditar    │
└──────────────────────┬──────────────────────────────┘
                       │
                       ▼
┌─────────────────────────────────────────────────────┐
│              CAPA DE CONTROL                        │
│          SGPlantaReciclajeController                │
│  EstacionController │ TipoEstacionCtrl │ EstadoCtrl │
└──────────────────────┬──────────────────────────────┘
                       │
                       ▼
┌─────────────────────────────────────────────────────┐
│              CAPA DE PERSISTENCIA                   │
│             SGPlantaReciclajeDAO                    │
│  BaseDAO │ EstacionDAO │ TipoEstacionDAO │ EstadoDAO│
└──────────────────────┬──────────────────────────────┘
                       │
                       ▼
┌─────────────────────────────────────────────────────┐
│              CAPA DE MODELO                         │
│            SGPlantaReciclajeModel                   │
│  EstacionClasificadora │ TipoEstacion │ EstadoOp.   │
└─────────────────────────────────────────────────────┘
```

### Descripción de cada capa

| Capa | Proyecto | Responsabilidad |
|------|----------|-----------------|
| **Modelo** | `SGPlantaReciclajeModel` | Define las entidades del dominio con sus atributos y métodos. |
| **Persistencia** | `SGPlantaReciclajeDAO` | Lee y escribe los datos en archivos `.txt`. Centraliza la ruta mediante `BaseDAO`. |
| **Control** | `SGPlantaReciclajeController` | Implementa la lógica de negocio y valida las operaciones CRUD. |
| **Vista** | `SGPlantaReciclajeView` | Interfaz gráfica Windows Forms con formularios de mantenimiento, alta y edición. |

---

## 📂 Estructura de Carpetas

```
LPOO.2026_2_C07/
│
├── SGPlantaReciclaje.sln                # Solución de Visual Studio
│
├── BD/                                  # Carpeta de datos (auto-creada)
│   └── TXT/
│       ├── Estaciones.txt               # Datos de estaciones clasificadoras
│       ├── EstadoOperativo.txt          # Catálogo de estados operativos
│       └── TipoEstaciones.txt           # Catálogo de tipos de estación
│
├── SGPlantaReciclajeModel/              # Capa de Modelo
│   ├── EstacionClasificadora.h / .cpp
│   ├── TipoEstacion.h / .cpp
│   └── EstadoOperativo.h / .cpp
│
├── SGPlantaReciclajeDAO/                # Capa de Persistencia
│   ├── BaseDAO.h / .cpp                 # Clase base con ruta centralizada
│   ├── EstacionDAO.h / .cpp
│   ├── TipoEstacionDAO.h / .cpp
│   └── EstadoOperativoDAO.h / .cpp
│
├── SGPlantaReciclajeController/         # Capa de Control
│   ├── EstacionController.h / .cpp
│   ├── TipoEstacionController.h / .cpp
│   └── EstadoOperativoController.h / .cpp
│
├── SGPlantaReciclajeView/               # Capa de Presentación (GUI)
│   ├── main.cpp                         # Punto de entrada
│   ├── frmMantEstacion.h / .cpp         # Formulario principal
│   ├── frmNuevaEstacion.h / .cpp        # Formulario de registro
│   └── frmEditarEstacion.h / .cpp       # Formulario de edición
│
├── .gitignore
└── README.md
```

---

## 🗄 Modelo de Datos

### Entidades del dominio

#### `EstacionClasificadora`

| Atributo | Tipo | Descripción |
|----------|------|-------------|
| `serialId` | `String^` | Identificador único visible (PK lógica). |
| `alias` | `String^` | Nombre descriptivo de la estación. |
| `tipo` | `int` | FK → `TipoEstacion.idTipoEstacion`. |
| `estado` | `int` | FK → `EstadoOperativo.idEstadoOperativo`. |
| `ubicacion` | `String^` | Ubicación física dentro de la planta. |

#### `TipoEstacion`

| Atributo | Tipo | Descripción |
|----------|------|-------------|
| `idTipoEstacion` | `int` | Identificador único (PK). |
| `descripcion` | `String^` | Descripción del tipo. |

**Valores del catálogo:**
| ID | Descripción |
|----|-------------|
| 1 | Neumática |
| 2 | Magnética |
| 3 | Óptica |
| 4 | Otros |

#### `EstadoOperativo`

| Atributo | Tipo | Descripción |
|----------|------|-------------|
| `idEstadoOperativo` | `int` | Identificador único (PK). |
| `descripcion` | `String^` | Descripción del estado. |

**Valores del catálogo:**
| ID | Descripción |
|----|-------------|
| 1 | Operativo |
| 2 | En Mantenimiento |
| 3 | Falla Crítica |
| 4 | Apagado |

### Formato de los archivos TXT

**`Estaciones.txt`**
```
serialId;alias;tipo;estado;ubicacion
```

Ejemplo:
```
EST-NEU-001;Clasificadora-Neumatica-01;1;1;Linea de Clasificación de Polímeros
SEP-MAG-002;Separadora-Mag-05;2;1;Zona de Extracción de Metales
EST-OPT-003;Clasificadora-Optica-01;3;1;Linea de Clasificación de Polímeros
```

**`TipoEstaciones.txt`**
```
idTipoEstacion;descripcion
```

**`EstadoOperativo.txt`**
```
idEstadoOperativo;descripcion
```

---

## 📸 Capturas de Pantalla

> _Agrega aquí las capturas de pantalla de los formularios una vez que las tengas disponibles._

- **Formulario principal** (`frmMantEstacion`): Listado con DataGridView y criterios de búsqueda.
- **Formulario de registro** (`frmNuevaEstacion`): Alta de una nueva estación.
- **Formulario de edición** (`frmEditarEstacion`): Modificación de una estación existente.

---

## ⚙ Requisitos Previos

Antes de compilar y ejecutar el proyecto, asegúrate de tener instalado:

- **Visual Studio 2026** (o superior) con la carga de trabajo **Desarrollo para escritorio con C++**.
- **.NET Framework 4.7.2** o superior.
- **Soporte para C++/CLI** (incluido en la carga de trabajo de C++ de Visual Studio).
- **Windows 10 / 11** (para ejecutar la aplicación Windows Forms).

---

## 🚀 Instalación y Ejecución

### 1. Clonar el repositorio

```bash
git clone https://github.com/ManoloPeru/LPOO.2026_2_C07.git
cd LPOO.2026_2_C07
```

### 2. Abrir la solución en Visual Studio

Haz doble clic en el archivo `SGPlantaReciclaje.sln` o ábrelo desde Visual Studio:

```
Archivo → Abrir → Proyecto/Solución → SGPlantaReciclaje.sln
```

### 3. Compilar la solución

```
Compilar → Compilar solución (Ctrl + Shift + B)
```

### 4. Ejecutar la aplicación

Establece `SGPlantaReciclajeView` como **proyecto de inicio** (clic derecho → Establecer como proyecto de inicio) y presiona `F5` o:

```
Depurar → Iniciar depuración
```

### 5. Verificar la carpeta de datos

Al ejecutarse por primera vez, la aplicación creará automáticamente la carpeta `BD\TXT\` en la raíz de la solución con los archivos de datos correspondientes.

---

## 🖥 Uso del Sistema

### Formulario principal — `frmMantEstacion`

Al iniciar la aplicación, se muestra el formulario de **Mantenimiento de Estaciones** con las siguientes funcionalidades:

| Acción | Descripción |
|--------|-------------|
| **Buscar** | Filtra las estaciones por Serial ID, Tipo y/o Estado operativo. |
| **Limpiar** | Restablece los criterios de búsqueda y muestra todas las estaciones. |
| **Nuevo** | Abre el formulario `frmNuevaEstacion` para registrar una nueva estación. |
| **Editar** | Abre el formulario `frmEditarEstacion` con los datos de la estación seleccionada. |
| **Eliminar** | Elimina la estación seleccionada previa confirmación. |

### Formulario de registro — `frmNuevaEstacion`

Permite ingresar los datos de una nueva estación:

- **Serial ID** (obligatorio, único).
- **Alias** (obligatorio).
- **Tipo** (ComboBox no editable, cargado desde `TipoEstaciones.txt`).
- **Estado** (ComboBox no editable, cargado desde `EstadoOperativo.txt`).
- **Ubicación** (obligatorio).

Al presionar **Grabar**, se valida que todos los campos estén completos y que el Serial ID no exista.

### Formulario de edición — `frmEditarEstacion`

Carga los datos de la estación seleccionada y permite modificar:

- **Serial ID** (solo lectura — es el identificador único).
- **Alias**, **Tipo**, **Estado** y **Ubicación**.

Al presionar **Grabar**, se aplican los cambios y se actualiza el archivo de datos.

---

## 🎨 Patrones de Diseño

| Patrón | Descripción | Aplicación |
|--------|-------------|------------|
| **DAO (Data Access Object)** | Separa la lógica de acceso a datos de la lógica de negocio. | `EstacionDAO`, `TipoEstacionDAO`, `EstadoOperativoDAO` |
| **Controller** | Capa intermedia que gestiona las operaciones y validaciones. | `EstacionController`, `TipoEstacionController`, `EstadoOperativoController` |
| **Herencia** | Clase base con funcionalidad común reutilizable. | `BaseDAO` → DAOs concretos |
| **Encapsulamiento** | Atributos privados con getters/setters públicos. | Todas las clases del modelo |
| **MVC simplificado** | Separación Modelo-Vista-Controlador. | Arquitectura general del sistema |

---

## 🛠 Tecnologías Utilizadas

| Tecnología | Versión | Uso |
|------------|---------|-----|
| **C++/CLI** | — | Lenguaje de programación principal. |
| **.NET Framework** | 4.7.2+ | Plataforma de ejecución. |
| **Windows Forms** | — | Framework de interfaz gráfica. |
| **Visual Studio** | 2026 | IDE de desarrollo. |
| **Git / GitHub** | — | Control de versiones. |
| **Archivos TXT** | — | Persistencia de datos. |

---

## 👨‍💻 Autor

**ManoloPeru**

- GitHub: [@ManoloPeru](https://github.com/ManoloPeru)
- Repositorio: [LPOO.2026_2_C07](https://github.com/ManoloPeru/LPOO.2026_2_C07)

---

## 📄 Licencia

Este proyecto es de uso **académico** y fue desarrollado como parte del curso **LPOO.2026_2_C07** (Laboratorio de Programación Orientada a Objetos).

---

## 📝 Notas Adicionales

### Ruta centralizada de los archivos de datos

La clase `BaseDAO` calcula la ruta de la carpeta `BD\TXT\` de forma dinámica, subiendo desde el directorio de ejecución (`AppDomain::CurrentDomain->BaseDirectory`) hasta encontrar la raíz de la solución (donde está el archivo `.sln`). Esto permite que **todos los proyectos** (Consola y GUI) compartan los mismos archivos de datos, sin duplicación.

Si la carpeta `BD\TXT\` no existe al iniciar la aplicación, `BaseDAO` la crea automáticamente.

### Encoding de los archivos

Los archivos `.txt` se guardan con codificación **UTF-8** para soportar caracteres especiales como tildes (á, é, í, ó, ú) y la letra ñ.

### Validaciones

Todas las operaciones CRUD pasan por una doble validación:

1. **Capa de control** (`EstacionController`): valida reglas de negocio (unicidad, existencia).
2. **Capa de presentación** (`frmNuevaEstacion`, `frmEditarEstacion`): valida campos obligatorios y formato.

---

⭐ **Si este proyecto te resultó útil, no olvides darle una estrella en GitHub.** ⭐
