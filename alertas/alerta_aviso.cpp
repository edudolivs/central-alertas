#include "alerta_aviso.hpp"

#include <utility>

alerta_aviso::alerta_aviso(std::string origem, std::string mensagem)
    : alerta{std::move(origem), 2}, mensagem_{std::move(mensagem)} {}

std::string alerta_aviso::tipo() const { return "AVISO"; }

std::string alerta_aviso::formatar() const { return mensagem_; }
