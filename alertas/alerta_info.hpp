#ifndef ALERTA_INFO_HPP
#define ALERTA_INFO_HPP

#include <string>

#include "alerta.hpp"

// NÃO é final: pode ser especializado (ver alerta_debug no Plano 5).
class alerta_info : public alerta {
    std::string mensagem_;

public:
    alerta_info(std::string origem, std::string mensagem);

    std::string tipo() const override;
    std::string formatar() const override;
};

#endif  // ALERTA_INFO_HPP
