#ifndef CENTRAL_HPP
#define CENTRAL_HPP

#include <memory>
#include <vector>

#include "alerta.hpp"

class central {
    std::vector<std::unique_ptr<alerta>> alertas_;

public:
    void registrar(std::unique_ptr<alerta> a);  // por valor (move)
    void exibir_todos() const;
    int total() const noexcept;
};

#endif  // CENTRAL_HPP
