# Questão 1 - Modelagem de Inspeções (C++/Qt)

## a)
Para modelar será criado uma classe base abstrata, `Inspecao`, aqui que o Qt será usado herdando `QObject`, essa classe serve pra garantir a integração e uso de recursos entre classe herdada e classe derivada com os campos que toda inspeção tem; ID, inspetor, data e resultado. O método de gerar relatório eu deixo virtual puro nessa classe base, dado que cada tipo de inspeção monta o relatório de um jeito diferente, com base em dados diferentes que ela tem, se a base fosse sozinha teria um loop de validações de if e quebraria o conceito de herança proposto

Então as classes `InspecaoTermografica` e `InspecaoUltrassom` herdam de `Inspecao`, cada uma guarda o dado que é só dela, temperatura máxima em Termografia e espessura medida em Ultrassom, e cada uma implementa o relatório da sua forma. Para guardar a lista de inspeções cadastradas idealize a classe de agregação chamada `GerenciadorInspecoes` com um `QVector<Inspecao*>`, o seu comportamento não precisa saber se será termográfica ou ultrassom, garantindo o polimorfismo, sem precisar de várias condicionais de validação

## b)
`Inspecao` será nossa classe base abstrata com os campos comuns entre os dois tipos citados, as duas classes específicas `InspecaoTermografica` e `InspecaoUltrassom` herdando dela as características, e `GerenciadorInspecoes` guardando várias `Inspecao`

```
Inspecao (classe base abstrata)
|-- InspecaoTermografica (herança)
|-- InspecaoUltrassom (herança)

GerenciadorInspecoes (1) --agrega--> (N) Inspecao
```
