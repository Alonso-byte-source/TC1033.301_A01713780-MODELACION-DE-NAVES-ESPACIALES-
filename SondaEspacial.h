#ifndef SONDAESPACIAL_H
#define SONDAESPACIAL_H
#include <iostream>
#include "NaveEspacial.h"

class SondaEspacial : public NaveEspacial{
    private://Atributos
        std::string destino;
        double combustible;
        bool activa;
    
    public://Métodos
        SondaEspacial(std::string, std::string, std::string, double);
        void mostrarInfo();
        void iniciarMision();
        void transmitirDatos();
};

//Constructor
SondaEspacial::SondaEspacial(std::string nom, std::string tipMis, std::string des, double com) 
    : NaveEspacial(nom, tipMis), destino(des), combustible(com){
    activa = false;
}

void SondaEspacial::iniciarMision(){
    activa = true;
    std::cout << "La sonda espacial " << nombre << " ha iniciado su mision rumbo a " << destino << "." << std::endl;
}

void SondaEspacial::transmitirDatos(){
    if(activa == true){
        std::cout << "La sonda " << nombre << " esta transmitiendo datos desde " << destino << "." << std::endl;
    }
    else{
        std::cout << "La sonda " << nombre << " aun no ha iniciado la mision." << std::endl;
    }
}

void SondaEspacial::mostrarInfo(){
    NaveEspacial::mostrarInfo();
    std::cout << "Destino: " << destino << " | Estado: " << (activa ? "Activa":"Inactiva") << " | Combustible: " << combustible << "kg" <<std::endl; 
}

#endif