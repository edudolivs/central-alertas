#include <catch2/catch_test_macros.hpp>

#include <iostream>
#include <memory>
#include <sstream>
#include <string>

#include "alertas/alerta_critico.hpp"
#include "alertas/alerta_aviso.hpp"
#include "alertas/alerta_info.hpp"

TEST_CASE("alerta_critico: tipo CRITICO, severidade 3, formatar = mensagem") {
    alerta_critico a{"sensor1", "temperatura 95.3 graus"};
    REQUIRE(a.tipo() == "CRITICO");
    REQUIRE(a.severidade() == 3);
    REQUIRE(a.origem() == "sensor1");
    REQUIRE(a.formatar() == "temperatura 95.3 graus");
}

TEST_CASE("exibir de alerta_critico via ponteiro base (polimorfismo)") {
    std::unique_ptr<alerta> a =
        std::make_unique<alerta_critico>("sensor1", "temperatura 95.3 graus");

    std::ostringstream captura;
    std::streambuf* antigo = std::cout.rdbuf(captura.rdbuf());
    a->exibir();
    std::cout.rdbuf(antigo);

    REQUIRE(captura.str() == "[CRITICO] sensor1: temperatura 95.3 graus\n");
}

TEST_CASE("alerta_aviso: tipo AVISO, severidade 2, formatar = mensagem") {
    alerta_aviso a{"sensor2", "umidade 78.5 pct"};
    REQUIRE(a.tipo() == "AVISO");
    REQUIRE(a.severidade() == 2);
    REQUIRE(a.formatar() == "umidade 78.5 pct");
}

TEST_CASE("alerta_info: tipo INFO, severidade 1, formatar = mensagem") {
    alerta_info a{"sistema", "reinicio agendado"};
    REQUIRE(a.tipo() == "INFO");
    REQUIRE(a.severidade() == 1);
    REQUIRE(a.formatar() == "reinicio agendado");
}
