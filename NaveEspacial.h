#ifndef NAVEESPACIAL_H
#define NAVEESPACIAL_H 
#include <iostream>
#include <sstream>

class NaveEspacial{
    protected:
        std::string nombre;
        std::string tipoMision;
    public:
        NaveEspacial();
        NaveEspacial(std::string, std::string);
        std::string toString();
        std::string getNombre();
        std::string getTipoMision();
};

//Constructor

NaveEspacial::NaveEspacial() : nombre(""), tipoMision("") {}

NaveEspacial::NaveEspacial(std::string nom, std::string tipMis)
    : nombre(nom), tipoMision(tipMis) {
}

std::string NaveEspacial::toString(){
    std::stringstream aux;
    aux << "Nave: " << nombre << "| Tipo de mision: " << tipoMision << "\n";
    return aux.str();
}

std::string NaveEspacial::getNombre(){
    return nombre;
}

std::string NaveEspacial::getTipoMision(){
    return tipoMision;
}

#endif