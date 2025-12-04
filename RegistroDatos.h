/**
* Proyecto Simulación Espacial
* Alonso Vega Reséndiz
* A01713780
* 03/12/2025
*/

/**
* Clase RegistroDatos almacena los eventos creados por la clase MisionEspacial  
* en un vector para llevar un registro de las acciones que pasan en la simulación 
* 
*
*/

#ifndef REGISTRODATOS_H
#define REGISTRODATOS_H
#include <iostream>
#include <vector>
#include <sstream>

// Declaración de la clase registro de datos
class RegistroDatos {
private: // Declaro variables de instacia
    // Vector de pares para alamacenar el turno y evento
    std::vector<std::pair<int, std::string>> registros;
public: // Declaro los métodos que va a tener el objeto
    RegistroDatos();
    RegistroDatos(int, const std::string&);
    void addRegistro(int, const std::string&);
    std::string toString() const;
    
};

/** 
* Constructor donde recibe valores para llenar las variables de instacia
* 
* @param int t: el tiempo o turno en que suceden las acciones, string &e: inicializa la variable que va a recibir el evento a almacenar de la clase MisionEspacial
*/
RegistroDatos::RegistroDatos(int t, const std::string &e) { 
    registros.emplace_back(t, e); // Alamacena en cada lugar del vector el turno y el evento
} 

/**
* Recibe el turno y evento a alamacenar de la clase MisionESpacial
* y los alamcena en el vector de pares
* @param int tiempo, string &evento: el evento que almacena
* @return 
*/
void RegistroDatos::addRegistro(int tiempo, const std::string &evento) {
    registros.emplace_back(tiempo, evento);
}

/**
* Almacena los datos de las mision (turno y evento)
*
* @param 
* @return string con los datos de la misión
*/
std::string RegistroDatos::toString() const{
    std::stringstream aux;
    if (registros.empty()) {
        aux << "Sin registros.\n";
        return aux.str();
    }
    for (const std::pair<int, std::string> &r : registros) {
    aux << "[Tiempo: " << r.first << "] Evento: " << r.second << std::endl;
    }
    return aux.str();
}
#endif
