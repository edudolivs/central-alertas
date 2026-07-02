#include "alerta_critico.hpp"

#include <utility>

alerta_critico::alerta_critico(std::string origem, std::string mensagem)
    : alerta{std::move(origem), 3}, mensagem_{std::move(mensagem)} {}

std::string alerta_critico::tipo() const { return "CRITICO"; }

std::string alerta_critico::formatar() const { return mensagem_; }
