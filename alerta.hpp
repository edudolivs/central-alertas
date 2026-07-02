#ifndef ALERTA_HPP
#define ALERTA_HPP

#include <string>

// -------------------------------------------------------------------
// Interface pura: apenas contrato, sem estado e sem implementação
// (exceto o destrutor virtual).
// -------------------------------------------------------------------
class formatavel {
public:
    virtual std::string formatar() const = 0;
    virtual ~formatavel() = default;
};

// -------------------------------------------------------------------
// Classe abstrata: tem estado (origem_, severidade_) e implementa o
// Template Method exibir() (NÃO-virtual), que despacha para os
// métodos virtuais tipo() e formatar().
// -------------------------------------------------------------------
class alerta : public formatavel {
    std::string origem_;
    int severidade_;

public:
    alerta(std::string origem, int severidade);

    // Template Method: NÃO-virtual. Chama tipo() e formatar() (virtuais).
    void exibir() const;

    // Contrato que cada tipo concreto deve cumprir.
    virtual std::string tipo() const = 0;
    // formatar() continua puro (herdado de formatavel).

    // Getters const.
    std::string origem() const;
    int severidade() const;

    ~alerta() override = default;
};

#endif  // ALERTA_HPP
