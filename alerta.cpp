#include "alerta.hpp"

#include <iostream>
#include <stdexcept>
#include <utility>

alerta::alerta(std::string origem, int severidade)
    : origem_{std::move(origem)}, severidade_{severidade} {
    if (severidade_ < 1 || severidade_ > 3) {
        throw std::invalid_argument("severidade deve estar em [1, 3]");
    }
}

void alerta::exibir() const {
    std::cout << "[" << tipo()        // despacho dinâmico
              << "] " << origem_ << ": "
              << formatar()           // despacho dinâmico
              << "\n";
}

std::string alerta::origem() const { return origem_; }

int alerta::severidade() const { return severidade_; }
