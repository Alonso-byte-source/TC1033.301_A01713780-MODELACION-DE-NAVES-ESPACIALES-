/**
* Proyecto Simulación Espacial
* Alonso Vega Reséndiz
* A01713780
* 03/12/2025
*/

/**
* Clase SondaEspacial simula el comportamiento de una sonda controlada por el
* usuario, va perdiendo combuestible al pasar los turnos, eventos externos pueden afectar su estado
* y puede transmitir datos.
*
*/
#ifndef SONDAESPACIAL_H
#define SONDAESPACIAL_H
#include <iostream>
#include <sstream>
#include "NaveEspacial.h" //Incluimos el archivo de la clase madre

// Declaración de la clase sonda espacial que hereda atributos y métodos de la clase nave espacial
class SondaEspacial : public NaveEspacial{
    private:
        // Declaro las variables de instancia
        std::string destino;
        double combustible;
        bool activa;
    
    public:
        /// Declaro métodos que ba a tener el objeto
        SondaEspacial(std::string, std::string, std::string, double);
        std::string toString();
        void iniciarMision();
        void transmitirDatos();
        bool estaActiva();
        void perderComunicacion();
};

/** 
* Constructor donde recibe valores para llenar las variables de instacia
* 
* @param string nom: el nombre de la nave, string tipMis: el tipo de mision, string des: el destino de la sonda, double comb: el combustible
*/
SondaEspacial::SondaEspacial(std::string nom, std::string tipMis, std::string des, double comb) 
    : NaveEspacial(nom, tipMis, comb), destino(des), activa(false){
}

/**
* Simula el inicio de la misión de una sonda espacial afectando parámetros como el combustible 
* de la nave
* @param 
* @return 
*/
void SondaEspacial::iniciarMision(){
    if(activa){
        std::cout << nombre << "ya esta en mision.\n";
    } else{
        if (combustible < 5.0) {
            std::cout << "Combustible insuficiente para iniciar la misión.\n";
            return;
        } else{
            activa = true;
            combustible -= 0.1; // costo de iniciar
            std::cout << "La sonda " << nombre << " ha iniciado su mision rumbo a " << destino << ".\n";
        }
    }
}

/**
* Simula la transmisión de datos de la sonda
*
* @param 
* @return 
*/
void SondaEspacial::transmitirDatos(){
    if(activa){
        std::cout << "La sonda " << nombre << " esta transmitiendo datos desde " << destino << "." << std::endl;
    }
    else{
        std::cout << "La sonda " << nombre << " aun no ha iniciado la mision." << std::endl;
    }
}

/**
* Almacena los valores de las variables de instancia en una cadena de texto
*
* @param 
* @return string con los datos de la sonda
*/
std::string SondaEspacial::toString(){
    std::stringstream aux;
    aux << NaveEspacial::toString();
    aux << "Destino: " << destino << " | Estado: " << (activa ? "Activa":"Inactiva") << " | Combustible: " << combustible << "kg\n"; 
    return aux.str();
}

/**
* Simula la perdida de comunicación con la sonda desactivando la misión
*
* @param 
* @return 
*/
void SondaEspacial::perderComunicacion(){
    if(activa){
        std::cout<< "Perdiste comunicacion con la sonda " << nombre << ".\n";
        activa = false;
    }
}

/**
* Regresa un booleano con el estado de la sonda (true(activa), false(inactiva))
*
* @param 
* @return bool con el estado de la sonda 
*/
bool SondaEspacial::estaActiva(){
    return activa;
}

#endif