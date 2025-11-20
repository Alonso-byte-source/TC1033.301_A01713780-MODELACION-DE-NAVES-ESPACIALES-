#include <iostream>

class RegistroDatos{
    private://Atributos
         std::string tiempo;
        std::string descripcion;

    public://Métodos
        RegistroDatos(std::string, std::string);
        void mostrarRegistro();
};

//Constructor
RegistroDatos::RegistroDatos(std::string t, std::string des){
        tiempo = t;
        descripcion = des;
    }

void RegistroDatos::mostrarRegistro(){
    std::cout << "Registro generado:" << std::endl;
    std::cout << "Tiempo: " << tiempo << std::endl;
    std::cout << "Evento: " << descripcion << std::endl;
}