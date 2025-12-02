# TC1033.301_A01713780-MODELACION-DE-NAVES-ESPACIALES-
Este proyecto sienta las bases de un juego de texto de exploración espacial mediante programación orientada a objetos, existen 3 clases que representan un tipo de vehículo espacial: transbordador, sonda espacial y estación orbital, estas clases heredan de una clase "general": nave espacial; así mismo existen otras dos clases que sirven para guardadr un registro de las acciones del jugador: misión espacial y registro de datos, todas las clases mecionadas anteriormente componen la clase juego, en donde de acuerdo a las elecciones del jugador interactúan de una o cierta forma. 

# Objetivo
Practicar:
- Creación de clases en C++
- Constructores
- Atributos privados
- Métodos públicos
- Organización de proyecto en archivos .h y .cpp
- Diseño UML

# Uso
El programa principal (`main.cpp`) crea un objeto de tipo Juego para comezar el juego de texto.

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
