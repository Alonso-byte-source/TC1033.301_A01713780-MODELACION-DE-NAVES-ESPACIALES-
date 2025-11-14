#include <iostream>
#include "Transbordador.h"
#include "SondaEspacial.h"
#include "EstacionOrbital.h"

int main(){
    Transbordador Transbordador_1("Challenger", 4500000, 4);
    SondaEspacial SondaEspacial_1("Voyager 1", "Saturno", 4.5);
    SondaEspacial SondaEspacial_2("Voyager 2", "Venus", 3.5);
    EstacionOrbital EstacionOrbital_1("ISS", 5);

    Transbordador_1.despegar();
    Transbordador_1.reabastecer(500000);
    Transbordador_1.mostrarInfo();

    SondaEspacial_1.iniciarMision();
    SondaEspacial_1.transmitirDatos();
    SondaEspacial_1.mostrarInfo();

    SondaEspacial_2.transmitirDatos();
    SondaEspacial_2.mostrarInfo();

    EstacionOrbital_1.enviarComunicado();
    EstacionOrbital_1.recibirNave();
    EstacionOrbital_1.mostrarInfo();


    return 0;
}