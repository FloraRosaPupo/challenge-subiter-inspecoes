import 'package:flutter/material.dart';
import 'package:flutter_test/flutter_test.dart';
import 'package:cadastro_atividade/main.dart';

void main() {
  testWidgets('Exibe os campos e o botão de cadastro', (WidgetTester tester) async {
    await tester.pumpWidget(const App());

    expect(find.byKey(const Key('campoNome')), findsOneWidget);
    expect(find.byKey(const Key('campoLocal')), findsOneWidget);
    expect(find.byKey(const Key('botaoCadastrar')), findsOneWidget);
  });

  testWidgets('Exibe erros de validação ao tentar cadastrar sem preencher', (WidgetTester tester) async {
    await tester.pumpWidget(const App());

    await tester.tap(find.byKey(const Key('botaoCadastrar')));
    await tester.pump();

    expect(find.text('Informe o nome da empresa'), findsOneWidget);
    expect(find.text('Informe o local'), findsOneWidget);
  });

  testWidgets('Exibe dialog de sucesso ao cadastrar com dados válidos', (WidgetTester tester) async {
    await tester.pumpWidget(const App());

    await tester.enterText(find.byKey(const Key('campoNome')), 'ABC Engenharia');
    await tester.enterText(find.byKey(const Key('campoLocal')), 'São José dos Campos');

    await tester.tap(find.byKey(const Key('botaoCadastrar')));
    await tester.pumpAndSettle();

    expect(find.text('Cadastro realizado com sucesso!'), findsOneWidget);
    expect(find.text('ABC Engenharia'), findsAtLeastNWidgets(1));
    expect(find.text('São José dos Campos'), findsAtLeastNWidgets(1));
  });
}
