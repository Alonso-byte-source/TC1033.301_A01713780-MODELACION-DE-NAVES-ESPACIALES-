#ifndef SONDAESPACIAL_H
#define SONDAESPACIAL_H
#include <iostream>
#include <sstream>
#include "NaveEspacial.h"

class SondaEspacial : public NaveEspacial{
    private://Atributos
        std::string destino;
        double combustible;
        bool activa;
    
    public://Métodos
        SondaEspacial(std::string, std::string, std::string, double);
        std::string toString();
        void iniciarMision();
        void transmitirDatos();
        bool estaActiva();
};

//Constructor
SondaEspacial::SondaEspacial(std::string nom, std::string tipMis, std::string des, double com) 
    : NaveEspacial(nom, tipMis), destino(des), combustible(com), activa(false){
}

void SondaEspacial::iniciarMision(){
    if(activa){
        std::cout << nombre << "ya esta en mision.\n";
    }
    if (combustible < 10.0) {
            std::cout << "Combustible insuficiente para iniciar la misión.\n";
            return;
        }
        activa = true;
        combustible -= 10.0; // costo de iniciar
        std::cout << "La sonda " << nombre << " ha iniciado su misión rumbo a " << destino << ".\n";
}

void SondaEspacial::transmitirDatos(){
    if(activa){
        std::cout << "La sonda " << nombre << " esta transmitiendo datos desde " << destino << "." << std::endl;
    }
    else{
        std::cout << "La sonda " << nombre << " aun no ha iniciado la mision." << std::endl;
    }
}

std::string SondaEspacial::toString(){
    std::stringstream aux;
    aux << NaveEspacial::toString();
    aux << "Destino: " << destino << " | Estado: " << (activa ? "Activa":"Inactiva") << " | Combustible: " << combustible << "kg\n"; 
    return aux.str();
}

bool SondaEspacial::estaActiva(){
    return activa;
}

#endif