#include <iostream>

class EstacionOrbital{
    private://Atributos
        std::string nombre;
        int tripulantes;
    
    public://Métodos
        EstacionOrbital(std::string, int);
        void recibirNave();
        void enviarComunicado();
        void mostrarInfo();
};

//Constructor
EstacionOrbital::EstacionOrbital(std::string nom, int tri){
    nombre = nom;
    tripulantes = tri;
}

void EstacionOrbital::recibirNave(){
    std::cout << "La estacion orbital: " << nombre << " ha recibido una nave." << std::endl;
}

void EstacionOrbital::enviarComunicado(){
    std::cout << "La estacion orbital " << nombre << " ha enviado un comunicado a la tierra." << std::endl;
}

void EstacionOrbital::mostrarInfo(){
    std::cout << "Estacion Orbital: " << nombre << " | Tripulantes: " << tripulantes << std::endl; 
}