#include <random>
#include <iostream>
#include <vector>

class Evento{
    private:
        std::mt19937 rng;
        std::uniform_real_distribution<double> dist;
    public:
        Evento(): rng(std::random_device{}()), dist(0.0, 1.0) {}
        int intentarEvento();
};



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
    std::uniform_int_distribution<int> pick(0, evento.size()-1);
    int index = pick(rng);
    std::cout << "Evento ocurrido!: " << evento[index] << "\n"; 
    return index + 1;
}

