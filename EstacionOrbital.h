/**
* Proyecto Simulación Espacial
* Alonso Vega Reséndiz
* A01713780
* 03/12/2025
*/

/**
* Clase estacion orbital simula el comportamiento de una estacion orbital,  
* pierde combustible al pasar los turnos, puede recibir una nave y acoplarla, así como tiene 
* combustible para reabastecer un transbordador si este esta acoplado
*
*/
#ifndef ESTACIONORBITAL_H
#define ESTACIONORBITAL_H
#include <iostream>
#include <sstream>
#include "NaveEspacial.h"

// Declaración de la clase estacion orbitalque hereda atributos y métodos de la clase nave espacial
class EstacionOrbital : public NaveEspacial{
    private:
        // Declaro variables de instancia
        double combustibleDisponible;
        int tripulantes;
    
    public:
        // Declaro los métodos que va a tener el objeto
        EstacionOrbital(std::string, std::string, int, double, double);
        void recibirNave(const std::string&);
        std::string toString();
        void recargarCombustible(double, double&);
        double getCombustibleDisponible();
};

/** 
* Constructor donde recibe valores para llenar las variables de instacia
* 
* @param string nom: el nombre de la nave, string tipMis: el tipo de mision, int tri: tripulantes del transbordador, double comb: combustible de la estación
* double combD: cantidad de combuestible disponible para reabastecer el transbordador
* @return
*/
EstacionOrbital::EstacionOrbital(std::string nom, std::string tipMis, int tri, double combD, double comb)
    : NaveEspacial(nom, tipMis, comb), tripulantes(tri), combustibleDisponible(combD) {
}

/**
* Recibe y acopla un transbordador 
* 
* @param string &nombreNave: nombre del transbordador
* @return 
*/
void EstacionOrbital::recibirNave(const std::string &nombreNave){
    std::cout << "La estacion orbital " << nombre << " ha recibido a " << nombreNave << ".\n";
}


std::string EstacionOrbital::toString(){
    std::stringstream aux;
    aux << NaveEspacial::toString();
    aux << "Tripulantes: " << tripulantes << " | Combustible para recarga: " << combustibleDisponible << " L  | Combustible: " << combustible << "L.\n" ; 
    return aux.str();
}

/**
* Recibe la solicitud de recarga de combustible y si tiene combustible disponible la ejecuta 
* 
* @param double cantidadSolicitada: la cantidad de combustible a dar, double &combustibleTransbordador: combustible del transbordador
* @return 
*/
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

/**
* Regresa un double con el combustible disponible para recargar al transbordador
*
* @param 
* @return double con la cantidad de combustible 
*/
double EstacionOrbital::getCombustibleDisponible() { 
    return combustibleDisponible; 
}

#endif