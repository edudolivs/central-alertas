#ifndef ALERTA_AVISO_HPP
#define ALERTA_AVISO_HPP

#include <string>

#include "alerta.hpp"

class alerta_aviso : public alerta {
    std::string mensagem_;

public:
    alerta_aviso(std::string origem, std::string mensagem);

    std::string tipo() const override;
    std::string formatar() const override;
};

#endif  // ALERTA_AVISO_HPP
