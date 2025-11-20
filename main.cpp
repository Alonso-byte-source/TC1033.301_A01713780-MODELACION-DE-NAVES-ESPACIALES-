#include <iostream>
#include "Transbordador.h"
#include "SondaEspacial.h"
#include "EstacionOrbital.h"
#include "MisionEspacial.h"
#include "RegistroDatos.h"

int main(){
    Transbordador T1("Challenger", 4500000, 4);
    SondaEspacial S1("Voyager 1", "Saturno", 4.5);
    SondaEspacial S2("Voyager 2", "Venus", 3.5);
    EstacionOrbital E1("ISS", 5);
    MisionEspacial M1("Apolo XXI", "Explorar Marte", 180);
    RegistroDatos R1("12:30", "Sistema funcionando correctamente");

    T1.despegar();
    T1.reabastecer(500000);
    T1.mostrarInfo();

    S1.iniciarMision();

    S1.transmitirDatos();
    S1.mostrarInfo();

    S2.transmitirDatos();
    S2.mostrarInfo();

    E1.enviarComunicado();
    E1.recibirNave();
    E1.mostrarInfo();

    M1.mostrarInfo();

    R1.mostrarRegistro();
    return 0;
}