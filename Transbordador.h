#ifndef TRANSBORDADOR_H
#define TRANSBORDADOR_H
#include <iostream>
#include <sstream>
#include "NaveEspacial.h"
#include "EstacionOrbital.h"


class Transbordador: public NaveEspacial{
    private:
        int tripulantes;
        double combustible;
        double combustibleRecarga;
        bool acoplado;
    public:
        Transbordador(std::string, std::string, int, double, double);
        void solicitarRecarga(EstacionOrbital&);
        void despegar();
        std::string toString();
        double getCombustible();
        void consumirCombustible(double);
        bool estado();
};

Transbordador::Transbordador(std::string nom, std::string tipMis, int trip, double comb, double combR)
    : NaveEspacial(nom, tipMis), tripulantes(trip), combustible(comb), combustibleRecarga(combR), acoplado(true) {

}

void Transbordador::solicitarRecarga(EstacionOrbital &est){
    if(acoplado == true){
        std::cout << "El transbordador " << nombre << " solicita recarga de " << combustibleRecarga << "L a la estacion " << est.getNombre() << "...\n";
        est.recargarCombustible(combustibleRecarga, combustible);
    } else{
        std::cout << "Necesitas acoplarte para recargar combustibe\n";
    }
}

void Transbordador::despegar(){
    acoplado = false;
    std::cout << "\n " << nombre << " ha despegado exitosamente.\n";
}

std::string Transbordador::toString(){
    std::stringstream aux;
    aux << NaveEspacial::toString();
    aux << "Capacidad: " << tripulantes << " | Combustible: " << combustible << "\n";
    return aux.str();
}

double Transbordador::getCombustible(){
    return combustible;
}

void Transbordador::consumirCombustible(double c){
    combustible = std::max(0.0, combustible - c);
}

bool Transbordador::estado(){
    return acoplado;
}


#endif