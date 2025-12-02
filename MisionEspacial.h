#ifndef MISIONESPACIAL_H
#define MISIONESPACIAL_H
#include <iostream>
#include "RegistroDatos.h"
#include <sstream>
 
class MisionEspacial{
private:
    std::string nombre;
    std::string objetivo;
    int duracionDias;
    RegistroDatos registro; // composición

public:
    MisionEspacial(std::string, std::string, int, RegistroDatos);
    void addEvento(int, const std::string&);
    std::string toString();
};

MisionEspacial::MisionEspacial(std::string n, std::string o, int d, RegistroDatos r)
        : nombre(n), objetivo(o), duracionDias(d), registro(r) {        
}

void MisionEspacial::addEvento(int tiempo, const std::string &ev){
    registro.addRegistro(tiempo, ev);
}

std::string MisionEspacial::toString(){
    std::stringstream aux;
    aux << "Mision: " << nombre << "\n";
    aux << "Objetivo: " << objetivo<< "\n";
    aux << "Duracion: " << duracionDias << " dias" << "\n"; 
    aux << "Registro: \n" << registro.toString();
    return aux.str();
}

#endif
