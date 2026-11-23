# Desafio técnico Subiter (C++ e Flutter)

Resolução de um desafio técnico em **entregas independentes**: modelagem de inspeções, proposta de tela integrada a API, cadastro de equipamentos em C++ e protótipo Flutter. Não é um produto integrado.

## Estrutura
```
docs/                                   modelagem e proposta de tela (questões teóricas)
questao3_cadastro_equipamentos.cpp      C++17, CLI de cadastro (entrada e saída padrão)
tests/test_cadastro.py                  roda o binário C++ como processo e valida a saída
cadastro_atividade/                     protótipo Flutter (lib/main.dart, formulário de atividade)
```

## Comandos
```powershell
# C++
g++ -std=c++17 -Wall -Wextra -Werror questao3_cadastro_equipamentos.cpp -o cadastro
python -m unittest discover -s tests -v
# Flutter
cd cadastro_atividade; flutter pub get; flutter analyze; flutter test
```

## CI e deploy
- `cpp.yml`: g++ com `-Werror` mais os testes Python.
- `ci.yml`: Flutter.
- Não há deploy.

## Regras
- Preserve o enunciado e as respostas como foram entregues. Melhorias ficam separadas e marcadas como posteriores.
- O `main.dart` do Flutter tem cerca de 230 linhas num arquivo só. Pode separar em widgets, mas sem mudar o escopo da entrega.
