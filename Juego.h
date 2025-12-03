#include <iostream>
#include <limits>
#include "MisionEspacial.h"
#include "Transbordador.h"
#include "EstacionOrbital.h"
#include "SondaEspacial.h"
#include "Evento.h"

class Juego{
    private:
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
        Juego()
            : mision("Apolo XXI", "Exploracion lunar", 15, RegistroDatos(0, "Mision iniciada")),
            estacion("ISS", "Investigacion", 6, 3000.0),
            transbordador("Discovery", "Transporte", 7, 500.0, 300.0),
            sonda("Voyager", "Exploracion", "Saturno", 10.0),
            tiempo(0){
        }
        void run();
};

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

void Juego::limpiarEntrada(){
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Juego::mostrarCabecera(){
    std::cout << "====================\n";
    std::cout << "   MISION ESPACIAL  \n";
    std::cout << "====================\n";
}

void Juego::narrarInicio() {
    std::cout << "Estamos en el dia 0 de la mision \"" << "\".\n";
    std::cout << "Objetivo: " << std::endl;
    std::cout << "La flota consta de una estacion orbital, un transbordador y una sonda.\n";
    std::cout << "Decide tus acciones para garantizar el exito de la mision.\n\n";
}

void Juego::mostrarEstado() {
    std::cout << "\n--- Estado actual (turno " << tiempo << ") ---\n";
    std::cout << estacion.toString();
    std::cout << "\n";
    std::cout << transbordador.toString();
    std::cout << "\n";
    std::cout << sonda.toString();
    std::cout << "---------------------------------\n\n";
}

void Juego::opcionLanzarTransbordador(){
    if(transbordador.getCombustible() >= 150){
        transbordador.consumirCombustible(150);
        transbordador.despegar();
    } else {
        std::cout << "\n No hay suficiente combustible para despegar.\n";
    }
}

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

void Juego::opcionRecargar() {
    std::cout << "Solicitando recarga desde el transbordador...\n";
    transbordador.solicitarRecarga(estacion);
    mision.addEvento(tiempo, transbordador.getNombre() + " solicito recarga");
}

void Juego::opcionLanzarSonda() {
    std::cout << "Orden de lanzamiento a la sonda " << sonda.getNombre() << "...\n";
    sonda.iniciarMision();
    if (sonda.estaActiva()) {
        mision.addEvento(tiempo, sonda.getNombre() + " lanzo hacia " + std::string("su destino"));
    }
}

void Juego::opcionTransmitir() {
    std::cout << "Forzando transmision de datos desde la sonda...\n";
    sonda.transmitirDatos();
    mision.addEvento(tiempo, "Transmision de datos desde " + sonda.getNombre());
}

void Juego::opcionVerRegistro() {
    std::cout << "Registro de la mision:\n";
    std::cout << mision.toString();
}

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