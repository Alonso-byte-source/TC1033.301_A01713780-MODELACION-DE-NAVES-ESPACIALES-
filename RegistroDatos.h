#ifndef REGISTRODATOS_H
#define REGISTRODATOS_H
#include <iostream>

class RegistroDatos{
private:
    int tiempo;
    std::string evento;

public:
    RegistroDatos(int t, const std::string &e) : tiempo(t), evento(e) {}

    void mostrarRegistro() const {
        std::cout << "[Tiempo: " << tiempo << "] Evento: " << evento << std::endl;
    }
};

#endif
