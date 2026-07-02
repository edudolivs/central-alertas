#include "central.hpp"

#include <utility>

void central::registrar(std::unique_ptr<alerta> a) {
    alertas_.push_back(std::move(a));
}

void central::exibir_todos() const {
    for (const auto& a : alertas_) {
        a->exibir();
    }
}

int central::total() const noexcept {
    return static_cast<int>(alertas_.size());
}
