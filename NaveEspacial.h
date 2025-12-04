/**
* Proyecto Simulación Espacial
* Alonso Vega Reséndiz
* A01713780
* 03/12/2025
*/

/**
* Clase NaveEspacial contiene los métodos genérios para el manejo de las naves espaciales
* y tiene 3 clases hijas que son especializaciones de nave espacial:
* EstacionOrbital, Transbordador y SondaEspacial
*
*/

#ifndef NAVEESPACIAL_H
#define NAVEESPACIAL_H 
#include <iostream>
#include <sstream>

// Declaración de clase Nave espacial que es abstracta
class NaveEspacial{
    protected:
        // Declaro variables de instacia
        std::string nombre;
        std::string tipoMision;
        double combustible;
    public:
        // Declaro los métodos que va tener el objeto
        NaveEspacial();
        NaveEspacial(std::string, std::string, double);

        std::string toString();
        std::string getNombre();
        std::string getTipoMision();
        void consumirCombustible(double);
        double getCombustible();
        
};

/**
* Constructor por default
*
* @param
* @return Objeto Nave Espacial
*/
NaveEspacial::NaveEspacial() : nombre(""), tipoMision(""), combustible(0.0) {}

/** 
* Constructor donde recibe valores para llenar las variables de instacia
* 
* @param string nom: el nombre de la nave, string tipMis: el tipo de mision, double comb: el combustible
*/
NaveEspacial::NaveEspacial(std::string nom, std::string tipMis, double comb)
    : nombre(nom), tipoMision(tipMis), combustible(comb) {
}

// Getter de nombre, tipo de misión y combustible

/**
* getter nombre
*
* @param 
* @return string: nombre de la nave
*/
std::string NaveEspacial::getNombre(){
    return nombre;
}

/**
* getter tipo de mision
*
* @param 
* @return string: tipo de misión
*/
std::string NaveEspacial::getTipoMision(){
    return tipoMision;
}

/**
* getter combustible
*
* @param 
* @return double: combustible
*/
double NaveEspacial::getCombustible(){ 
    return combustible; 
}

/**
* Almacena los valores de las variables de instancia en una cadena de texto
*
* @param 
* @return string con los datos de la nave
*/
std::string NaveEspacial::toString(){
    std::stringstream aux;
    aux << "Nave: " << nombre << "| Tipo de mision: " << tipoMision << "\n";
    return aux.str();
}

/**
* Método que reduce el combustible de la nave espacial
*
* @param
* @return
*/
void NaveEspacial::consumirCombustible(double c){
    combustible = std::max(0.0, combustible - c);
}

#endif // NAVEESPACIAL_H