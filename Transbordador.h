#include <iostream>

class Transbordador{
    private:
        std::string nombre;
        double combustible;
        int capacidadPasajeros; 
    public:
        Transbordador(std::string, double, int ); // Constructor
        void mostrarInfo();
        void despegar();
        void reabastecer(double);
        
};

// Constructor
Transbordador::Transbordador(std::string nom, double com, int cap){
    nombre = nom;
    combustible = com;
    capacidadPasajeros = cap;
}

void Transbordador::despegar(){
    std::cout << "El transbordador " << nombre << " ha despegado con " << capacidadPasajeros << " pasajeros a bordo" << std::endl;
}

void Transbordador::reabastecer(double litros){
    combustible += litros;
    std::cout << "El transbordador ha sido reabastecido. Combustible actual: " << combustible << "L" << std::endl;
}

void Transbordador::mostrarInfo(){
    std::cout << "Transbordador: " << nombre << " | Pasajeros: " << capacidadPasajeros << " | Combustible: " << combustible << "L"  << std::endl; 
}