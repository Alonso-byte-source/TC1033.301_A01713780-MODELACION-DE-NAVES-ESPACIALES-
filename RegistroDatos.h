#ifndef REGISTRODATOS_H
#define REGISTRODATOS_H
#include <iostream>
#include <vector>
#include <sstream>

class RegistroDatos {
private:
    std::vector<std::pair<int, std::string>> registros;
public:
    RegistroDatos();
    RegistroDatos(int, const std::string&);
    void addRegistro(int, const std::string&);
    std::string toString() const;
    
};
RegistroDatos::RegistroDatos(int t, const std::string &e) { 
    registros.emplace_back(t, e);
} 

void RegistroDatos::addRegistro(int tiempo, const std::string &evento) {
    registros.emplace_back(tiempo, evento);
}

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
