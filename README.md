# Desafio Técnico — Subiter

Repositório com as respostas da prova técnica para a vaga de Desenvolvedor(a) Pleno C++ e Flutter. Cada questão está organizada em seu próprio arquivo ou pasta para facilitar a navegação.

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


## Stack e bibliotecas

C++17, Python para testes de processo e Flutter/Dart.


## Licença

Não há licença de distribuição definida neste repositório. Os direitos de terceiros e as atribuições existentes devem ser respeitados; esta revisão não concede permissão de redistribuição.


## Organização e manutenção

Questões do desafio continuam separadas por diretório/arquivo para preservar a avaliação original. Não são features de um produto único. A entrada de console é validada antes do cadastro; os testes verificam o processo real.

Veja [a revisão de desenvolvimento](docs/REVISAO.md) para decisões, testes e limites, e [o guia de contribuição](CONTRIBUTING.md) para o fluxo de manutenção.
