cmake_minimum_required(VERSION 3.14)
project(central_alertas LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Flags comuns aos alvos DO PROJETO (não são aplicadas ao Catch2).
add_library(projeto_flags INTERFACE)
target_compile_options(projeto_flags INTERFACE -Wall -Wextra -fsanitize=address,undefined)
target_link_options(projeto_flags INTERFACE -fsanitize=address,undefined)

# Biblioteca com as classes do domínio.
add_library(alertas_lib
    alerta.cpp
    alertas/alerta_critico.cpp
    alertas/alerta_aviso.cpp
    alertas/alerta_info.cpp
)
target_include_directories(alertas_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(alertas_lib PUBLIC projeto_flags)

# ---- Testes com Catch2 (baixado via FetchContent) ----
include(FetchContent)
FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG        v3.5.2
)
FetchContent_MakeAvailable(Catch2)

enable_testing()
add_executable(tests
    tests/test_alerta.cpp
    tests/test_alertas_concretos.cpp
)
target_link_libraries(tests PRIVATE alertas_lib Catch2::Catch2WithMain)

list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
include(Catch)
catch_discover_tests(tests)
