/**
* Proyecto Simulación Espacial
* Alonso Vega Reséndiz
* A01713780
* 03/12/2025
*/

/**
* La clase juego se compone de las clases: transbordador, misión espacial, sonda espacial
* y estación orbital, integrandolas y permitiendo que interactuén entre ellas mediante 
* las desiciones del usuario
*
*/
#ifndef JUEGO_H
#define JUEGO_H
#include <iostream>
#include <limits>
#include "MisionEspacial.h"
#include "Transbordador.h"
#include "EstacionOrbital.h"
#include "SondaEspacial.h"
#include "Evento.h"

// Declaración de clase juego
class Juego{
    private:
        // Crea objetos de las clases que lo componen
        MisionEspacial mision;
        EstacionOrbital estacion;
        Transbordador transbordador;
        SondaEspacial sonda;
        Evento evento;
        int tiempo;
        void limpiarEntrada();
        void mostrarCabecera();
        void narrarInicio();
        void mostrarEstado();
        void opcionLanzarTransbordador();
        void opcionAcoplar();
        void opcionRecargar();
        void opcionLanzarSonda();
        void opcionTransmitir();
        void opcionVerRegistro();
        void eventoAleatorio();
    public:
        /** 
        * Constructor donde manda llamar los constructores de las clases que componene la clase juego
        * asignándoles valores
        *
        * @param  mision, estacion, tranbordador, sonda y tiempo(turno)
        * @return
        */
        Juego()
            : mision("Apolo XXI", "Exploracion lunar", 15, RegistroDatos(0, "Mision iniciada")),
            estacion("ISS", "Investigacion", 6, 3000.0, 3000.0),
            transbordador("Discovery", "Transporte", 7, 500.0, 300.0),
            sonda("Voyager", "Exploracion", "Saturno", 10.0),
            tiempo(0){
        }
        void run();
};

/**
* Muestra el menú de acciones y manada llamar las demás funciones dec acuerdo a la elección  
* del usuario
*
* @param 
* @return 
*/
void Juego::run() {
    mostrarCabecera();
    narrarInicio();

    bool salir = false;
    while (!salir) {
        mostrarEstado();
        std::cout << "Elige una accion:\n";
        std::cout << "1) Intentar acoplar " << transbordador.getNombre() << " con " << estacion.getNombre() << std::endl;
        std::cout << "2) Solicitar recarga al " << estacion.getNombre() << std::endl;
        std::cout << "3) Lanzar sonda " << sonda.getNombre() << std::endl;
        std::cout << "4) Forzar transmision de datos desde la sonda\n";
        std::cout << "5) Ver registro de la mision\n";
        std::cout << "6) Lanzar transbordador\n";
        std::cout << "7) Avanzar tiempo (siguiente turno)\n";
        std::cout << "0) Salir\n";
        std::cout << ">> ";

        int opcion;
        if (!(std::cin >> opcion)) {
            std::cout << "Entrada invalida.\n";
            limpiarEntrada();
            continue;
        }

        switch (opcion) {
            case 1: opcionAcoplar(); break;
            case 2: opcionRecargar(); break;
            case 3: opcionLanzarSonda(); break;
            case 4: opcionTransmitir(); break;
            case 5: opcionVerRegistro(); break;
            case 6: opcionLanzarTransbordador(); break;
            case 7:
                tiempo++;
                std::cout << "Avanzas al siguiente turno (turno " << tiempo << ").\n";
                transbordador.consumirCombustible(50.0);
                sonda.consumirCombustible(0.1);
                estacion.consumirCombustible(200);
                eventoAleatorio();
                break;
            case 0:
                salir = true;
                break;

            default:
                std::cout << "Opcion no valida.\n";
            }

        if (!salir) {
            std::cout << "\nPulsa ENTER para continuar...";
            limpiarEntrada();
            std::cin.get();
        }
    }
    std::cout << "Saliendo del juego. Estado final:\n";
    opcionVerRegistro();
}

/**
* Limpia la entrada 
* 
* @param 
* @return 
*/
void Juego::limpiarEntrada(){
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descarta todo lo que quede en el buffer de entrada hasta encpntrar un salto de línea
}

/**
* Muestra la cabecera del juego 
* 
* @param 
* @return 
*/
void Juego::mostrarCabecera(){
    std::cout << "====================\n";
    std::cout << "   MISION ESPACIAL  \n";
    std::cout << "====================\n";
}

/**
* Narra el inicio del juego 
* 
* @param 
* @return 
*/
void Juego::narrarInicio() {
    std::cout << "Estamos en el dia 0 de la mision \"" << "\".\n";
    std::cout << "Objetivo: " << std::endl;
    std::cout << "La flota consta de una estacion orbital, un transbordador y una sonda.\n";
    std::cout << "Decide tus acciones para garantizar el exito de la mision.\n\n";
}

/**
* Manda llamar los métodos toString de estación, transbordador y sonda 
* para mostrar su estado 
*
* @param 
* @return 
*/
void Juego::mostrarEstado() {
    std::cout << "\n--- Estado actual (turno " << tiempo << ") ---\n";
    std::cout << estacion.toString();
    std::cout << "\n";
    std::cout << transbordador.toString();
    std::cout << "\n";
    std::cout << sonda.toString();
    std::cout << "---------------------------------\n\n";
}

/**
* Simula el lanzamiento del transbordador y aplica las físicas correspondientes
* 
* @param 
* @return 
*/
void Juego::opcionLanzarTransbordador(){
    if(transbordador.getCombustible() >= 150){
        transbordador.consumirCombustible(150);
        transbordador.despegar();
    } else {
        std::cout << "\n No hay suficiente combustible para despegar.\n";
    }
}

/**
* Simula el acoplamiento del transbordador a la estación aplicando las físicas  
* correspondientes  
*
* @param 
* @return 
*/
void Juego::opcionAcoplar() {
    if(!transbordador.estado()){
        std::cout << "Intentas acoplar el " << transbordador.getNombre() << " a la estacion " << estacion.getNombre() << "...\n";
        if (transbordador.getCombustible() < 20.0) {
            std::cout << "Combustible insuficiente para maniobra de acoplamiento. Solicita recarga o espera.\n";
        } else {
            std::cout << "Maniobra exitosa. La estacion recibe la nave.\n";
            estacion.recibirNave(transbordador.getNombre());
            mision.addEvento(tiempo, transbordador.getNombre() + " acoplo a " + estacion.getNombre());
            transbordador.consumirCombustible(20.0);
        }
    } else{
        std::cout << "El transbordador ya esta acoplado";
    }
}

/**
* Simula la solicitud de recarga de combustible del transbordador a la estación
* 
*
* @param 
* @return 
*/
void Juego::opcionRecargar() {
    std::cout << "Solicitando recarga desde el transbordador...\n";
    transbordador.solicitarRecarga(estacion);
    mision.addEvento(tiempo, transbordador.getNombre() + " solicito recarga");
}

/**
* Simula el lanzamiento de la sonda espacial
* 
* @param 
* @return 
*/
void Juego::opcionLanzarSonda() {
    std::cout << "Orden de lanzamiento a la sonda " << sonda.getNombre() << "...\n";
    sonda.iniciarMision();
    if (sonda.estaActiva()) {
        mision.addEvento(tiempo, sonda.getNombre() + " lanzo hacia " + std::string("su destino"));
    }
}

/**
* Simula la transmisión de datos de la sonda al transbordador 
* 
* @param 
* @return 
*/
void Juego::opcionTransmitir() {
    std::cout << "Forzando transmision de datos desde la sonda...\n";
    sonda.transmitirDatos();
    mision.addEvento(tiempo, "Transmision de datos desde " + sonda.getNombre());
}

/**
* Muestra el registro de la misión y un historial de las acciones realizadas por el
* usuario y eventos aleatorios ocurridos
*
* @param 
* @return 
*/
void Juego::opcionVerRegistro() {
    std::cout << "Registro de la mision:\n";
    std::cout << mision.toString();
}

/**
* Manda llamar la función intentar evento, de acuerdo el identificador del evento 
* aplica las consecuencias para este
*
* @param 
* @return 
*/
void Juego::eventoAleatorio(){
    int e = evento.intentarEvento();

    switch(e){
        case 0:
            break;

        case 1:
            std::cout << "Asteroide te golpea. El transbordador " << transbordador.getNombre() << " ha perdido 100 de combustible.\n";
            transbordador.consumirCombustible(100);
            mision.addEvento(tiempo, transbordador.getNombre() + " fue golpeado por un asteroide ");
            break;

        case 2:
            std::cout << "Tormenta solar. Posible danio en los sistemas.\n";
            sonda.perderComunicacion();
            mision.addEvento(tiempo, "Tormenta solar.");
            break;
    }
}
#endif