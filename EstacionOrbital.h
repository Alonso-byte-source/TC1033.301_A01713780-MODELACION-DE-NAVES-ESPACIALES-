#ifndef ESTACIONORBITAL_H
#define ESTACIONORBITAL_H
#include <iostream>
#include "NaveEspacial.h"

class EstacionOrbital : public NaveEspacial{
    private://Atributos
        double combustibleDisponible;
        int tripulantes;
    
    public://Métodos
        EstacionOrbital(std::string, std::string, int, double);
        void recibirNave();
        void enviarComunicado();
        void mostrarInfo();
        void recargarCombustible(double &pedido, double &cant);
};

//Constructor
EstacionOrbital::EstacionOrbital(std::string nom, std::string tipMis, int tri, double comb)
    : NaveEspacial(nom, tipMis), tripulantes(tri), combustibleDisponible(comb) {}

void EstacionOrbital::recibirNave(){
    std::cout << "La estacion orbital: " << nombre << " ha recibido una nave." << std::endl;
}

void EstacionOrbital::enviarComunicado(){
    std::cout << "La estacion orbital " << nombre << " ha enviado un comunicado a la tierra." << std::endl;
}

void EstacionOrbital::mostrarInfo(){
    NaveEspacial::mostrarInfo();
    std::cout << "Tripulantes: " << tripulantes << std::endl; 
}

void EstacionOrbital::recargarCombustible(double &pedido, double &cant){
    std::cout << "El transbordador: " << nombre << " esta reabasteciendo combustible..." << std::endl;
    combustibleDisponible -= pedido;
    cant += pedido;
    std::cout << "La estacion ahora tiene " << combustibleDisponible << "L" << "\n";
}

#endif