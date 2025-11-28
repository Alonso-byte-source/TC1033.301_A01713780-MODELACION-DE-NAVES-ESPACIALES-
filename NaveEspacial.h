#ifndef NAVEESPACIAL_H
#define NAVEESPACIAL_H 
#include <iostream>

class NaveEspacial{
    protected:
        std::string nombre;
        std::string tipoMision;
    public:
        NaveEspacial();
        NaveEspacial(std::string, std::string);
        void despegar();
        void mostrarInfo();
        std::string getNombre();
        std::string getTipoMision();
};

//Constructor

NaveEspacial::NaveEspacial() : nombre(""), tipoMision("") {}

NaveEspacial::NaveEspacial(std::string nom, std::string tipMis)
    : nombre(nom), tipoMision(tipMis) {
}

void NaveEspacial::despegar() {
    std::cout << "La nave " << nombre << " esta despegando...\n";
}

void NaveEspacial::mostrarInfo(){
    std::cout << "Nave: " << nombre << "| Tipo de mision: " << tipoMision << "\n";
}

std::string NaveEspacial::getNombre(){
    return nombre;
}

std::string NaveEspacial::getTipoMision(){
    return tipoMision;
}

#endif