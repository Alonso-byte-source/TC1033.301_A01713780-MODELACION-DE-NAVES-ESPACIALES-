#include <iostream>

class MisionEspacial{
    private://Atributos
        std::string nombre;
        std::string objetivo;
        int duracionDias;

    public://Métodos
        MisionEspacial(std::string, std::string, int);
        void mostrarInfo();
};

//Constructor
MisionEspacial::MisionEspacial(std::string nom, std::string obj, int dur){
    nombre = nom;
    objetivo = obj;
    duracionDias = dur;
}

void MisionEspacial::mostrarInfo(){
    std::cout << "Mision Espacial: " << nombre << " | Objetivo: " << objetivo << " | Duracion: " << duracionDias << " dias" << std::endl;
}

