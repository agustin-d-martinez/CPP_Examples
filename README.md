# Debug de C y C++ en Windows y Visual Studio Code.
Esta guía posee los pasos para la correcta ejecución de un proyecto de C/C++ utilizando windows y debbugueando en VSCode.

# Pasos a seguir:
## Instalación previa:

1. Instalar VSCode.
2. Instalar las extensiones de VSCode:
	- C/C++
	- C/C++ Extention Pack
	- CMake (Solo si se crean proyectos)
	- CMake Tools (Solo si se crean proyectos)

3. Instalar ([MSYS2](https://www.msys2.org/)) en windows. 
4. Abrir el programa "MSYS2 UCRT64".
5. 
	1. 	Ejecutar los siguientes comandos:
		pacman -S --needed base-devel mingw-w64-ucrt-x86_64-toolchain
		pacman -S mingw-w64-ucrt64-cmake

	2. 	Verificar que estén instalados. Se escriben los siguientes comandos en MSYS2 UCRT64:
		gcc --version
		g++ --version
		gdb --version

6.  Agregar la ubicación de MSYS2 al PATH.
	1. 	Abrir en windows "Editar variables de entorno del sistema" O "edit the system enviorenment variables".

	2. 	Ir a variables de entorno.

	3.	Seleccionar PATH y Editar.

	4.	Agregar la dirección de MSYS2 como nueva. Suele ser "E:\msys2\ucrt64\bin".

## Configurar VSCode:
1. 	Ir a File->Preferences.
2. 	En CMake. Cmake Path agregar: "E:/msys2/mingw64/bin"  (Sin las comillas).
	Esto agrega el Path del CMake a las configuraciones por default para que se encuentren presets al crear el proyecto.

3. 	En C_pp > Default: Compiler Path abrir el .json y colocar la siguiente linea:
	"C_Cpp.default.compilerPath": "E:/msys2/ucrt64/bin/g++.exe",
	Esto permite que visual por default vaya al ejecutable de MSYS2 que instalamos.

## Crear Archivo:
Para crear un único archivo que se desea ejecutar:
1. Abrimos una carpeta con VSCode.
2. Agregamos el archivo .cpp
3. Ejecutamos dandole al triangulo arriba a la derecha. Se puede en Debug o en Run. 
![alt text](image.png)
4. Seleccionamos el g++ como el archivo para compilar.
![alt text](image-1.png)

## Crear Proyecto:
Para crear un proyecto, con múltiples archivos vamos a utilizar CMake:
1. Abrir la consola de comandos de VSCode con CTRL + SHIFT + P .

2. Seleccionar **CMake: Quick Start**.
	1. Ingresar el **Nombre del Proyecto**.
	2. Ingresar el **Lenguaje del proyecto** (C o C++).
	3. Agrega adicionales (Selecciona **CTest**).
	4. Indica el tipo de salida. En caso del proyecto selecciona **Ejecutable**.

	Esto debería crear un archivo main y un CMakeList.txt ![alt text](image-2.png).

3. Vuelve a ejecutar **CMake: Quick Start**.
	1. Selecciona **Add New Preset** y luego **Create from Compilers**.
	2. Selecciona el compilador (Buscar el GCC instalado previamente).
	3. Guarda el nombre del preset.

4. En los comandos de VSCode (CTRL+SHIFT+P) selecciona **Cmake: Set Build Target** e ingresa el **Nombre del Proyecto**.

5. Configura el proyecto en la pestaña de CMake Tools > Configure como indica la foto.![alt text](image-3.png)

6. Realiza el Build o Run a voluntad abajo a la izquierda.![alt text](image-4.png)

### Agregar archivos al proyecto:
Para agregar archivos al proyecto debemos modificar el archivo **CMakeList.txt**.

Todos los archivos .cpp deben colocarse en add_executable() en el archivo **CMakeList.txt** indicando la ruta relativa de cada archivo.

Si los archivos se encuentran en una subcarpeta, se puede utilizar el comando file de CMake para listarlos y luego agregar la variable a add_executable():
```CMake
file(GLOB_RECURSE <variable> [RELATIVE <path>])
add_executable(NOMBRE main.cpp <variable>)
```

En el siguiente ejemplo, se agregan todos los archivos de la carpeta ./lib al CMake:
```CMake
file(GLOB_RECURSE LIB_SOURCES "${CMAKE_SOURCE_DIR}/lib/*.cpp")
add_executable(PROYECT_NAME main.cpp ${LIB_SOURCES})
```

# C++ Examples
Implementación de clases básicas utilizando programación orientada a objetos (POO). 
Las clases son puramente didácticas y no poseen una utilidad específica. 
Algunas ya se encuentran implementadas en el standard de C++.

# Bibliografía:
La información fue adquirida de las siguientes páginas:

[CMAKE Official Site](https://cmake.org/)

[VSCode CMAKE QuickStart](https://code.visualstudio.com/docs/cpp/cmake-quickstart)

[VSCode C++ Guide](https://code.visualstudio.com/docs/cpp/config-mingw)






