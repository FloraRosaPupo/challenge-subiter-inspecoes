# Desafio Técnico Subiter — C++ e Flutter

## Descrição

Resolução de um desafio técnico com modelagem de inspeções, proposta de tela integrada a API, cadastro de equipamentos em C++ e protótipo de cadastro de atividade em Flutter. As questões são entregas independentes, não um produto integrado.

## Stack e bibliotecas

C++17, Python para testes de processo e Flutter/Dart.

Dependências e versões declaradas: [cadastro_atividade/pubspec.yaml](cadastro_atividade/pubspec.yaml).

## Funcionalidades

- Cadastro limitado de equipamentos.
- Validação de entrada.
- Protótipo Flutter do desafio.
- Modelagem de inspeções e proposta de arquitetura para listagem via API, documentadas nas questões 1 e 2.

## Licença

Não há uma licença de distribuição definida para este repositório. Nenhuma licença MIT, Apache ou equivalente é concedida por este README. As atribuições e os direitos dos materiais de terceiros permanecem preservados.

## Validação e limites

Entradas inválidas, espaços, limite e EOF no console, além dos testes do protótipo Flutter. Consulte `tests/test_cadastro.py` para a compilação usada pelo teste.

## Onde encontrar cada questão

- **Questão 1** — Modelagem de classes em C++/Qt → `questao1_modelagem_inspecoes.md`
- **Questão 2** — Arquitetura de tela Flutter consumindo API REST → `questao2_tela_listagem_api_rest.md`
- **Questão 3** — Programa C++ de cadastro de equipamentos → `questao3_cadastro_equipamentos.cpp`
- **Questão 4** — Tela Flutter de cadastro de atividade → `cadastro_atividade/` — toda a implementação está em `lib/main.dart`. Daria para separar em arquivos e camadas distintas, mas dado que a funcionalidade pedida é simples, optei por concentrar tudo na main para facilitar a leitura da entrega.

## Desenvolvimento e validação

O aplicativo está em `cadastro_atividade`. Use Flutter 3.41.1. Na pasta do aplicativo, execute:

```sh
flutter pub get
flutter analyze --no-fatal-infos --no-fatal-warnings
flutter test
flutter run
```

A CI valida análise e testes em pushes e pull requests. Serviços externos precisam de configuração própria.

## Organização e manutenção

Questões do desafio continuam separadas por diretório/arquivo para preservar a avaliação original. Não são features de um produto único. A entrada de console é validada antes do cadastro; os testes verificam o processo real.

Veja [a revisão de desenvolvimento](docs/REVISAO.md) para decisões, testes e limites, e [o guia de contribuição](CONTRIBUTING.md) para o fluxo de manutenção.
