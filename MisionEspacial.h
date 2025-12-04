/**
* Proyecto Simulación Espacial
* Alonso Vega Reséndiz
* A01713780
* 03/12/2025
*/

/**
* Clase MisionEspacial simula una misón espacial almacenando eventos y acciones 
* hechas por el usuario
* 
*
*/

#ifndef MISIONESPACIAL_H
#define MISIONESPACIAL_H
#include <iostream>
#include "RegistroDatos.h"
#include <sstream>
 
class MisionEspacial{
private:
    // Declaro variables de instancia
    std::string nombre;
    std::string objetivo;
    int duracionDias;
    RegistroDatos registro; // composición
    //Declaro los métodos que va tener el objeto
public:
    MisionEspacial(std::string, std::string, int, RegistroDatos);
    void addEvento(int, const std::string&);
    std::string toString();
};

/** 
* Constructor donde recibe valores para llenar las variables de instacia
* 
* @param string n: el nombre de la nave, string o: el objetivo de la mision, int d: la duración, RegistroDatos r: crea un registro de datos para almacenar los datos de la misión
*/
MisionEspacial::MisionEspacial(std::string n, std::string o, int d, RegistroDatos r)
        : nombre(n), objetivo(o), duracionDias(d), registro(r) {        
}

/**
* Envía el turno y evento a la clase RegistroDatos para crear un registro
*
* @param int tiempo, string ev: el evento que almacena
* @return 
*/
void MisionEspacial::addEvento(int tiempo, const std::string &ev){
    registro.addRegistro(tiempo, ev);
}

/**
* Almacena los valores de las variables de instancia en una cadena de texto
*
* @param 
* @return string con los datos de la misión
*/
std::string MisionEspacial::toString(){
    std::stringstream aux;
    aux << "Mision: " << nombre << "\n";
    aux << "Objetivo: " << objetivo<< "\n";
    aux << "Duracion: " << duracionDias << " dias" << "\n"; 
    aux << "Registro: \n" << registro.toString();
    return aux.str();
}

#endif
