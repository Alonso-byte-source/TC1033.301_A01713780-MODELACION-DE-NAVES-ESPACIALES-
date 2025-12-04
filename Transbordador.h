/**
* Proyecto Simulación Espacial
* Alonso Vega Reséndiz
* A01713780
* 03/12/2025
*/

/**
* Clase Transbordador simula el comportamiento de un transbordaor controlado por el
* usuario, va perdiendo combustible al pasar los turnos, eventos externos pueden afectar también su 
* nivel de combustible y puede solicitar una recarga de este mismo, además de despegar y acoplarse a 
* la estación orbital.
*/
#ifndef TRANSBORDADOR_H
#define TRANSBORDADOR_H
#include <iostream>
#include <sstream>
#include "NaveEspacial.h"
#include "EstacionOrbital.h"

// Declaración de la clase transbordador que hereda atributos y métodos de la clase nave espacial
class Transbordador: public NaveEspacial{
    private:
        // Declaro variables de instancia
        int tripulantes;
        double combustibleRecarga;
        bool acoplado;
    public:
        // Declaro los métodos que va a tener el objeto
        Transbordador(std::string, std::string, int, double, double);
        void solicitarRecarga(EstacionOrbital&);
        void despegar();
        std::string toString();
        bool estado();
};

/** 
* Constructor donde recibe valores para llenar las variables de instacia
* 
* @param string nom: el nombre de la nave, string tipMis: el tipo de mision, int tri: tripulantes del transbordador, double comb: combustible del transbordador
* double combR: cantidad de combuestible que puede solicitar a la estacion orbital
* @return
*/
Transbordador::Transbordador(std::string nom, std::string tipMis, int trip, double comb, double combR)
    : NaveEspacial(nom, tipMis, comb), tripulantes(trip), combustibleRecarga(combR), acoplado(true) {

}

/**
* Solicita una recarga de combustible a la clase EstacioOrbital si esta acoplado a la estacion 
* 
* @param 
* @return 
*/
void Transbordador::solicitarRecarga(EstacionOrbital &est){
    if(acoplado == true){
        std::cout << "El transbordador " << nombre << " solicita recarga de " << combustibleRecarga << "L a la estacion " << est.getNombre() << "...\n";
        est.recargarCombustible(combustibleRecarga, combustible);
    } else{
        std::cout << "Necesitas acoplarte para recargar combustibe\n";
    }
}

/**
* Simula el despegue de el transbordador desacoplandolo de la estación orbital
* 
* @param 
* @return 
*/
void Transbordador::despegar(){
    acoplado = false;
    std::cout << "\n " << nombre << " ha despegado exitosamente.\n";
}

/**
* Almacena los valores de las variables de instancia en una cadena de texto
*
* @param 
* @return string con los datos de el transbordador
*/
std::string Transbordador::toString(){
    std::stringstream aux;
    aux << NaveEspacial::toString();
    aux << "Capacidad: " << tripulantes << " | Combustible: " << combustible << "\n";
    return aux.str();
}

/**
* Regresa un booleano con el estado de el tranbordaodr (true(acoplado), false(desacoplado))
*
* @param 
* @return bool con el estado de la misión 
*/
bool Transbordador::estado(){
    return acoplado;
}


#endif