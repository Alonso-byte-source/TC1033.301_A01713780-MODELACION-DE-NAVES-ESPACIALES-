#ifndef MISIONESPACIAL_H
#define MISIONESPACIAL_H
#include <iostream>
#include "RegistroDatos.h"
 
class MisionEspacial{
private:
    std::string nombre;
    std::string objetivo;
    int duracionDias;
    RegistroDatos registro; // composición

public:
    MisionEspacial(std::string n, std::string o, int d, RegistroDatos r)
        : nombre(n), objetivo(o), duracionDias(d), registro(r) {}

    void mostrarInfo() const {
        std::cout << "Mision: " << nombre
                  << "\nObjetivo: " << objetivo
                  << "\nDuracion: " << duracionDias << " dias" << std::endl;
        registro.mostrarRegistro();
    }
};

#endif
