#include <catch2/catch_test_macros.hpp>

#include <iostream>
#include <memory>
#include <sstream>

#include "central.hpp"
#include "alertas/alerta_critico.hpp"
#include "alertas/alerta_aviso.hpp"
#include "alertas/alerta_info.hpp"

TEST_CASE("central comeca vazia") {
    central c;
    REQUIRE(c.total() == 0);
}

TEST_CASE("registrar incrementa o total") {
    central c;
    c.registrar(std::make_unique<alerta_critico>("s", "m"));
    REQUIRE(c.total() == 1);
    c.registrar(std::make_unique<alerta_aviso>("s", "m"));
    REQUIRE(c.total() == 2);
}

TEST_CASE("exibir_todos imprime cada alerta na ordem de registro") {
    central c;
    c.registrar(std::make_unique<alerta_critico>("sensor1", "temperatura 95.3 graus"));
    c.registrar(std::make_unique<alerta_aviso>("sensor2", "umidade 78.5 pct"));
    c.registrar(std::make_unique<alerta_info>("sistema", "reinicio agendado"));

    std::ostringstream captura;
    std::streambuf* antigo = std::cout.rdbuf(captura.rdbuf());
    c.exibir_todos();
    std::cout.rdbuf(antigo);

    REQUIRE(captura.str() ==
            "[CRITICO] sensor1: temperatura 95.3 graus\n"
            "[AVISO] sensor2: umidade 78.5 pct\n"
            "[INFO] sistema: reinicio agendado\n");
}
