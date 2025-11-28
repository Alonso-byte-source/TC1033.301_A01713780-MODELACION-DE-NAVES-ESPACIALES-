#include "Transbordador.h"
#include "EstacionOrbital.h"
#include "SondaEspacial.h"
#include "MisionEspacial.h"
#include "RegistroDatos.h"

int main() {

    RegistroDatos r(10, "Inicio de la mision");

    MisionEspacial m("Apolo XXI", "Exploracion lunar", 15, r);
    m.mostrarInfo();

    EstacionOrbital e("ISS", "Investigacion", 6, 3000);
    e.mostrarInfo();
    
    Transbordador t("Discovery", "Transporte", 7, 500.0, 300.0);
    t.mostrarInfo();
    t.despegar();
    t.solicitarRecarga(e);
    t.mostrarInfo();

    SondaEspacial s("Voyager", "Exploracion", "Saturno", 10);
    s.iniciarMision();
    s.mostrarInfo();
    s.transmitirDatos();

    return 0;
}
