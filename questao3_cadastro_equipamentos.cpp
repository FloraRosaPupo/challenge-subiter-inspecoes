#include <iostream>
#include <string>
using namespace std;

struct Equipamento {
    string nome;
    string codigo;
    int id;
    string descricao;
};

void cadastrar(Equipamento &eq, int numero) {
    cout << "\n=== Cadastro do Equipamento " << numero << " ===" << endl;
    cout << "Nome: ";
    cin >> eq.nome;
    cout << "Codigo: ";
    cin >> eq.codigo;
    cout << "ID: ";
    cin >> eq.id;
    cout << "Descricao: ";
    cin >> eq.descricao;
}

void exibir(Equipamento equipamentos[], int quantidade) {
    if (quantidade == 0) {
        cout << "\nNenhum equipamento cadastrado ainda." << endl;
        return;
    }
    cout << "\n===== Equipamentos Cadastrados =====" << endl;
    for (int i = 0; i < quantidade; i++) {
        cout << "\nEquipamento " << i + 1 << ":" << endl;
        cout << "Nome: "      << equipamentos[i].nome      << endl;
        cout << "Codigo: "    << equipamentos[i].codigo    << endl;
        cout << "ID: "        << equipamentos[i].id        << endl;
        cout << "Descricao: " << equipamentos[i].descricao << endl;
    }
}

int main() {
    Equipamento equipamentos[3];
    int quantidade = 0;
    int opcao;

    do {
        cout << "\n===== MENU =====" << endl;
        cout << "1 - Cadastrar equipamento (" << quantidade << "/3)" << endl;
        cout << "2 - Exibir equipamentos" << endl;
        cout << "0 - Sair" << endl;
        cout << "Opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                if (quantidade >= 3) {
                    cout << "Limite de 3 equipamentos atingido!" << endl;
                } else {
                    cadastrar(equipamentos[quantidade], quantidade + 1);
                    quantidade++;
                    cout << "Equipamento cadastrado com sucesso!" << endl;
                }
                break;
            case 2:
                exibir(equipamentos, quantidade);
                break;
            case 0:
                cout << "Encerrando..." << endl;
                break;
            default:
                cout << "Opcao invalida!" << endl;
        }

    } while (opcao != 0);

    return 0;
}
