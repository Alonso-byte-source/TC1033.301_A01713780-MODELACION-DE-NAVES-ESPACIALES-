# TC1033.301_A01713780-MODELACION-DE-NAVES-ESPACIALES-
Este proyecto implementa un juego de texto de exploración espacial, desarrollado en C++ utilizando los principios fundamentales de programación orientada a objetos (POO).
El jugador controla diferentes vehículos espaciales, toma decisiones estratégicas y gestiona una misión espacial a través de un sistema de turnos.

# Objetivo
El propósito de este proyecto es practicar:

- Creación de clases y objetos en C++
- Uso de constructores y encapsulamiento
- Atributos privados con métodos públicos
- Herencia entre clases
- Organización modular en archivos .h y .cpp
- Diseño UML básico
- Manejo de interacción por consola
Este proyecto sienta las bases de un videojuego más grande a través de la experimentación con arquitectura orientada a objetos y lógica de simulación.

# Estructura general del juego
El juego está formado por varias clases que representan vehículos espaciales, sistemas de misión y la lógica del propio juego.

Vehículos espaciales (heredan de NaveEspacial)

- Transbordador
- Sonda espacial
- Estación orbital

Cada una sobrescribe y amplía el comportamiento de la clase base, añadiendo características únicas (transmisión de datos, capacidad de acoplamiento, recarga de combustible, etc.).

Clases auxiliares

- MisionEspacial — crea eventos hechos por el usurio y generados alaeatoriamente
- RegistroDatos — almacena los eventos creados por la clase MisionEspacial para llevar un registro de los eventos que ocurren en la simulación.

Clase principal

Juego — coordina todas las clases anteriores y administra:

- Turnos
- Elección de acciones
- Eventos aleatorios
- Interacción con el usuario
- Registro de actividad
  
El archivo main.cpp simplemente crea un objeto Juego y comienza la simulación.

# Acciones disponibles
El usuario puede realizar las siguientes acciones:
- Intentar acoplar un tranbordador a la estación orbital
- Solicitar una recarga de combustible
- Lanzar una sonda espacial
- Forzar la transmisión de datos desde la sonda
- Lanzar el transbordador
- Ver registro de la mision
- Avanzar de turno
- Salir del juego

# Correcciones 
Entrega 1:

- Correción: Se corrigió el Readme con el fin de mejorar el diseño y explicación para la solución del problema.
- Subcompetencia: Toma de desiciones (SICT0302A)

Entrega 2:

- Corrección: se corrigió el diagrama de clases, antes usaba agregación entre registro y misión espacial, lo cual no tenía sentido, ya que en el programa no tenía sentido que si eliminaba la misión el registro siguiera existiendo.
- Subcompetencia: Toma de desiciones (SICT0302A)

Entrega 3:
- Correción: el uso de referencias en la clase estación orbital, especificamente en la función recragarCombustible era erróneo, ya que estaba mandando como referencia la cantidadSolicitada y el combustibleTransbordador, cuando el único que me interesaba editar sin generar copia era el combustibleTransbordador. Así mismo le dí más sentido al proyecto convirtiendolo es una especie de juego de texto interactivo en lugar de que solo imprima cosas preestablecidas por mi.
- Subcompetencia: Implementa (SICT0303A)
# Uso
El programa principal (`main.cpp`) crea un objeto de tipo Juego para comezar el juego de texto.

Compila como:

g++ main.cpp Juego.h NaveEspacial.h Transbordador.h SondaEspacial.h EstacionOrbital.h MisionEspacial.h RegistroDatos.h Evento.h -o main.exe

Ejecuta como:

./main.exe


