#include <iostream>

class SondaEspacial{
    private://Atributos
        std::string nombre, destino;
        double combustible;
        bool activa;
    
    public://Métodos
        SondaEspacial(std::string, std::string, double);
        void mostrarInfo();
        void iniciarMision();
        void transmitirDatos();
};

//Constructor
SondaEspacial::SondaEspacial(std::string nom, std::string des, double com){
    nombre = nom;
    destino = des;
    combustible = com;
    activa = false;
}

void SondaEspacial::iniciarMision(){
    activa = true;
    std::cout << "La sonda espacial " << nombre << " ha iniciado su mision rumbo a " << destino << "." << std::endl;
}

void SondaEspacial::transmitirDatos(){
    if(activa == true){
        std::cout << "La sonda " << nombre << " esta transmitiendo datos desde " << destino << "." << std::endl;
    }
    else{
        std::cout << "La sonda " << nombre << " aun no ha iniciado la mision." << std::endl;
    }
}

void SondaEspacial::mostrarInfo(){
    std::cout << "Sonda Espacial: " << nombre << " | Destino: " << destino << " | Estado: " << (activa ? "Activa":"Inactiva") << " | Combustible: " << combustible << "kg" <<std::endl; 
}