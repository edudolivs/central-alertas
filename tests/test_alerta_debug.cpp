#include <catch2/catch_test_macros.hpp>

#include <iostream>
#include <memory>
#include <sstream>
#include <string>

#include "central.hpp"
#include "alertas/alerta_debug.hpp"

TEST_CASE("alerta_debug mantem tipo INFO e severidade 1 (herdados)") {
    alerta_debug d{"sistema", "reinicio agendado", "pid=42"};
    REQUIRE(d.tipo() == "INFO");
    REQUIRE(d.severidade() == 1);
}

TEST_CASE("alerta_debug apende contexto tecnico ao formatar") {
    alerta_debug d{"sistema", "reinicio agendado", "pid=42"};
    REQUIRE(d.formatar() == "reinicio agendado | debug: pid=42");
}

TEST_CASE("central exibe alerta_debug como [INFO] com contexto") {
    central c;
    c.registrar(std::make_unique<alerta_debug>(
        "sistema", "reinicio agendado", "pid=42"));

    std::ostringstream captura;
    std::streambuf* antigo = std::cout.rdbuf(captura.rdbuf());
    c.exibir_todos();
    std::cout.rdbuf(antigo);

    REQUIRE(captura.str() == "[INFO] sistema: reinicio agendado | debug: pid=42\n");
}
