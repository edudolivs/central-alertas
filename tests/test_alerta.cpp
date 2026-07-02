#include <catch2/catch_test_macros.hpp>

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

#include "alerta.hpp"

namespace {
// Subclasse mínima só para os testes: permite instanciar a classe abstrata.
class alerta_stub : public alerta {
public:
    using alerta::alerta;  // herda o construtor alerta(origem, severidade)
    std::string tipo() const override { return "STUB"; }
    std::string formatar() const override { return "msg-stub"; }
};
}  // namespace

TEST_CASE("alerta guarda origem e severidade") {
    alerta_stub a{"sensorX", 2};
    REQUIRE(a.origem() == "sensorX");
    REQUIRE(a.severidade() == 2);
}

TEST_CASE("construtor aceita severidade nos limites 1 e 3") {
    REQUIRE_NOTHROW(alerta_stub{"s", 1});
    REQUIRE_NOTHROW(alerta_stub{"s", 3});
}

TEST_CASE("construtor lanca invalid_argument fora de [1,3]") {
    REQUIRE_THROWS_AS((alerta_stub{"s", 0}), std::invalid_argument);
    REQUIRE_THROWS_AS((alerta_stub{"s", 4}), std::invalid_argument);
}

TEST_CASE("exibir imprime [tipo] origem: formatar via despacho dinamico") {
    alerta_stub a{"sensorX", 2};

    std::ostringstream captura;
    std::streambuf* antigo = std::cout.rdbuf(captura.rdbuf());
    a.exibir();
    std::cout.rdbuf(antigo);

    REQUIRE(captura.str() == "[STUB] sensorX: msg-stub\n");
}
