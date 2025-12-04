/**
* Proyecto Simulación Espacial
* Alonso Vega Reséndiz
* A01713780
* 03/12/2025
*/

/**
* Clase Evento, se usa para producir un evento aleatorio en cada salto salto de turno,
* los eventos tienen una probabilidd del 45% de ocurrir y se escogen aleatoriamente
*
*/

#ifndef EVENTO_H
#define EVENTO_H
#include <random>
#include <iostream>
#include <vector>

// Declaración de clase evento
class Evento{
    private: // Declaro variables de instancia

        std::mt19937 rng; // Generador de números aleatorio
        std::uniform_real_distribution<double> dist; // Distribución entre 0 y 1

    public: // Declaro los métodos que va a tener el objeto

        /** 
        * Constructor donde recibe valores para llenar las variables de instacia
        * 
        * @param rng(std::random_device{}()): inicializa rng con una semilla obtenida aleatoriamente desde el sistema
        * dist(0.0, 1.0): La distribución va de 0 a 1 con probabilidad uniforme
        * @return
        */
        Evento(): rng(std::random_device{}()), dist(0.0, 1.0) {}
        int intentarEvento();
};


/**
* Los eventos tienen un 45% de probabilidad de ocurrir, si el evento ocurre, entonces aleatoriamente se escoge uno
* del vector de eventos
*
* @param 
* @return regresa el identificador del evento (0 = no paso nada, 1 = Impacto asteroide, 2 = tormenta solar)
*/
int Evento::intentarEvento(){
    double probEvento = 0.45; //probabilidad de evento
    double r = dist(rng); // numero aleatorio entreo 0 y 1

    if(r > probEvento){
        std::cout << "No ocurrio ningun evento. \n";
        return 0;
    } 

    std::vector<std::string> evento = {
        "Impacto de asteroide",
        "Tormenta solar",
    };
    std::uniform_int_distribution<int> pick(0, evento.size()-1); // Elegir un evento aleatorio
    int index = pick(rng);
    std::cout << "Evento ocurrido!: " << evento[index] << "\n"; 
    return index + 1;
}
#endif

