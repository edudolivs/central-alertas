#ifndef ALERTA_DEBUG_HPP
#define ALERTA_DEBUG_HPP

#include <string>

#include "alerta_info.hpp"

// Demonstra que alerta_info NÃO é final: alerta_debug o especializa.
// Mantém tipo() == "INFO" (herdado) e apende um contexto técnico ao formatar().
class alerta_debug : public alerta_info {
    std::string contexto_;

public:
    alerta_debug(std::string origem, std::string mensagem, std::string contexto);

    std::string formatar() const override;
    // tipo() NÃO é sobrescrito → continua "INFO".
};

#endif  // ALERTA_DEBUG_HPP
