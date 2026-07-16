# Questão 2 - Tela de Listagem consumindo API REST

Eu usaria arquitetura limpa e separaria o código em três camadas: Service, que busca os dados na API e converte pra objeto Dart, Domain no meio com as regras de negócio, e Presentation que é o BLoC e a tela em si. Assim se mudar algo na API não precisa mexer na tela.

Pro gerenciamento de estado eu usaria BLoC, com a qual eu tenho mais familiaridade. A tela dispara um evento, tipo "carregar inspeções", o BLoC processa o estado vindo da API e devolve um estado (carregando, sucesso, vazio ou erro) e a tela só reage ao estado, sem guardar lógica dentro dela. Uso o BLoC porque esse gerenciamento separa bem o que é evento do que é estado. Porém pra essa questão outro tipo de gerenciamento de estados pode ser feito.

No front usaria `ListView.builder` pra carregar apenas o que ta sendo exibido na tela, com paginação na listagem.

Pra tratar erros, a chamada de API fica dentro de um `try/catch` com timeout, se der problema o BLoC emite o estado de erro com uma mensagem e a tela mostra um botão de tentar de novo, assim não trava nem quebra o app.
