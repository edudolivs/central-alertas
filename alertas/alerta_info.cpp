#include "alerta_info.hpp"

#include <utility>

alerta_info::alerta_info(std::string origem, std::string mensagem)
    : alerta{std::move(origem), 1}, mensagem_{std::move(mensagem)} {}

std::string alerta_info::tipo() const { return "INFO"; }

std::string alerta_info::formatar() const { return mensagem_; }
