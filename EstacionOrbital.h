#ifndef ESTACIONORBITAL_H
#define ESTACIONORBITAL_H
#include <iostream>
#include <sstream>
#include "NaveEspacial.h"

class EstacionOrbital : public NaveEspacial{
    private://Atributos
        double combustibleDisponible;
        int tripulantes;
    
    public://Métodos
        EstacionOrbital(std::string, std::string, int, double);
        void recibirNave(const std::string&);
        std::string toString();
        void recargarCombustible(double, double&);
        double getCombustibleDisponible();
};

//Constructor
EstacionOrbital::EstacionOrbital(std::string nom, std::string tipMis, int tri, double comb)
    : NaveEspacial(nom, tipMis), tripulantes(tri), combustibleDisponible(comb) {}

void EstacionOrbital::recibirNave(const std::string &nombreNave){
    std::cout << "La estacion orbital " << nombre << " ha recibido a " << nombreNave << ".\n";
}


std::string EstacionOrbital::toString(){
    std::stringstream aux;
    aux << NaveEspacial::toString();
    aux << "Tripulantes: " << tripulantes << " | Combustible disponible: " << combustibleDisponible << " L\n"; 
    return aux.str();
}

void EstacionOrbital::recargarCombustible(double cantidadSolicitada, double &combustibleTransbordador){
    if(combustibleDisponible >= cantidadSolicitada){
        combustibleDisponible -= cantidadSolicitada;
        combustibleTransbordador += cantidadSolicitada;
        std::cout << "\n Recarga exitosa: +" << cantidadSolicitada << "L\n";
    } else{
        std::cout << "\n La estación no tiene suficiente combustible. \n";
    }
    std::cout << "La estacion " << nombre << " ahora tiene: " << combustibleDisponible << "L\n";
    std::cout << "El transbordador ahora tiene: " << combustibleTransbordador << "L\n";
}

double EstacionOrbital::getCombustibleDisponible() { 
    return combustibleDisponible; 
}

#endif