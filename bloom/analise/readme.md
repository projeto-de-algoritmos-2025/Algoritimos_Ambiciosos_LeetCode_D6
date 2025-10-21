# Análise de Critérios Ambiciosos

Esta pasta contém um código de experimento e casos de teste para o problema 2136. Earliest Possible Day of Full Bloom.

O arquivo `compara_criterios.cpp` foi criado para comparar os resultados de diferentes estratégias (critérios de ordenação) para a solução ambiciosa.

O objetivo é validar empiricamente que a ordenação por growTime (tempo de crescimento) decrescente é, de fato, a solução ótima.

## Como Usar

### 1. Compilação

Para compilar o programa, utilize um compilador C++ versão 11 ou superior

```bash
g++ -std=c++11 compara_criterios.cpp
```

### 2. Execução

Para rodar os testes, execute o programa compilado e redirecione o conteúdo do arquivo com os casos de teste

```bash
./a.out < input.txt
```

