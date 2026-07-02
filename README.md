Nome: Eduardo de Oliveira Silva

Matrícula: 20250018691


# Central de Alertas

Sistema de monitoramento em **C++17** que gera, registra e exibe alertas de diferentes
tipos (**crítico**, **aviso**, **info**).

## Estrutura final

```
central-alertas/
├── CMakeLists.txt
├── alerta.hpp / .cpp        formatavel + alerta (abstrata)
├── alertas/
│   ├── alerta_critico.hpp / .cpp   (final, severidade 3)
│   ├── alerta_aviso.hpp   / .cpp   (severidade 2)
│   ├── alerta_info.hpp    / .cpp   (severidade 1, não-final)
│   └── alerta_debug.hpp   / .cpp   (desafio: especializa alerta_info)
├── central.hpp / .cpp      registrar / exibir_todos / total
├── main.cpp
└── tests/                  testes Catch2 (um arquivo por camada)
```

## Build e testes

A partir da raiz do projeto:

```bash
cmake -S . -B build      # 1ª vez baixa o Catch2 (precisa de git + internet)
cmake --build build
ctest --test-dir build --output-on-failure
./build/central_alertas  # disponível a partir da Fase 4
```

Toolchain exigida: `-Wall -Wextra -std=c++17` (sem warnings) e
`-fsanitize=address,undefined` (sem erros). Saída esperada do programa:

```
Total: 3 alertas

[CRITICO] sensor1: temperatura 95.3 graus
[AVISO] sensor2: umidade 78.5 pct
[INFO] sistema: reinicio agendado
```

## Fases de implementação

**Fase 1 — Fundação**

```text
Crie um projeto C++17 com CMake para um sistema de alertas (compile com -Wall -Wextra e
-fsanitize=address,undefined). Comece pela base:
- uma interface pura `formatavel` com `std::string formatar() const = 0` e destrutor virtual;
- uma classe abstrata `alerta` que herda dela, com `origem_` (string) e `severidade_` (int).
  O construtor lança `std::invalid_argument` se a severidade não estiver entre 1 e 3. Adicione
  getters `origem()`/`severidade()`, os virtuais puros `tipo()` e `formatar()`, e um método
  NÃO-virtual `exibir()` (Template Method) que imprime `[tipo()] origem: formatar()`.
Escreva testes para o construtor, a validação e o exibir().
```

**Fase 2 — Alertas concretos**

```text
No mesmo projeto, crie três tipos que herdam de `alerta`, cada um com uma mensagem própria e
override de `tipo()` e `formatar()`:
- `alerta_critico`: final, severidade 3, tipo "CRITICO";
- `alerta_aviso`: severidade 2, tipo "AVISO";
- `alerta_info`: severidade 1, tipo "INFO", e que NÃO pode ser final.
Escreva testes conferindo tipo, severidade e mensagem de cada um.
```

**Fase 3 — Central**

```text
Crie a classe `central` que guarda os alertas em `std::vector<std::unique_ptr<alerta>>`:
- `registrar` recebe um `unique_ptr<alerta>` por valor e o move para dentro do vetor;
- `exibir_todos()` const chama `exibir()` de cada alerta;
- `total()` é noexcept e devolve a quantidade de alertas.
Escreva testes para registrar/total e para a ordem de exibição.
```

**Fase 4 — main + saída**

```text
Escreva o `main` que cria uma `central`, registra (com make_unique, sem new/delete) um
alerta_critico, um alerta_aviso e um alerta_info, imprime "Total: N alertas" e chama
exibir_todos. A saída deve ser exatamente:

Total: 3 alertas

[CRITICO] sensor1: temperatura 95.3 graus
[AVISO] sensor2: umidade 78.5 pct
[INFO] sistema: reinicio agendado

Garanta que compila sem warnings e sem erros de sanitizer.
```

**Fase 5 — Desafio alerta_debug (opcional)**

```text
Como desafio, crie `alerta_debug` que herda de `alerta_info` (mostrando que ele não é final).
Ele recebe uma mensagem de contexto técnico a mais, mantém o tipo "INFO" e acrescenta esse
contexto ao `formatar()`. Registre um na central e confirme que o exibir imprime
"[INFO] ... | debug: ...".
