#ifndef ALERTA_CRITICO_HPP
#define ALERTA_CRITICO_HPP

#include <string>

#include "alerta.hpp"

// Severidade máxima. Marcado como final: não pode ser estendido.
class alerta_critico final : public alerta {
    std::string mensagem_;

public:
    alerta_critico(std::string origem, std::string mensagem);

    std::string tipo() const override;
    std::string formatar() const override;
};

#endif  // ALERTA_CRITICO_HPP
