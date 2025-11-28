#ifndef TRANSBORDADOR_H
#define TRANSBORDADOR_H
#include <iostream>
#include "NaveEspacial.h"
#include "EstacionOrbital.h"


class Transbordador: public NaveEspacial{
    private:
        int capacidad;
        double combustible;
        double combustibleRecarga;
    public:
        Transbordador(std::string, std::string, int, double, double);
        void solicitarRecarga(EstacionOrbital &est);
        void despegar();
        void mostrarInfo();
};

Transbordador::Transbordador(std::string nom, std::string tipMis, int cap, double comb, double combR)
    : NaveEspacial(nom, tipMis), capacidad(cap), combustible(comb), combustibleRecarga(combR) {}

void Transbordador::solicitarRecarga(EstacionOrbital &est){
    std::cout << nombre << " solicita recarga de combustible...\n";
    est.recargarCombustible(combustibleRecarga, combustible);
}

void Transbordador::despegar(){
    NaveEspacial::despegar();
}

void Transbordador::mostrarInfo(){
    NaveEspacial::mostrarInfo();
    std::cout << "Capacidad: " << capacidad << " | Combustible: " << combustible << std::endl;
}
#endif