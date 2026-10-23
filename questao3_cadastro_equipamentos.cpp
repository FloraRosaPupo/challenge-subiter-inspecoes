#include <array>
#include <iostream>
#include <sstream>
#include <string>

struct Equipamento {
    std::string nome;
    std::string codigo;
    int id = 0;
    std::string descricao;
};

bool lerInteiro(std::istream& entrada, std::ostream& saida, const std::string& rotulo, int& valor) {
    std::string linha;
    while (saida << rotulo, std::getline(entrada, linha)) {
        std::istringstream parser(linha);
        if (parser >> valor) {
            parser >> std::ws;
            if (parser.eof()) return true;
        }
        saida << "Digite um numero inteiro valido.\n";
    }
    return false;
}

bool lerTexto(std::istream& entrada, std::ostream& saida, const std::string& rotulo, std::string& valor) {
    while (saida << rotulo, std::getline(entrada, valor)) {
        const auto inicio=valor.find_first_not_of(" \t\r");
        if (inicio!=std::string::npos) {
            valor=valor.substr(inicio,valor.find_last_not_of(" \t\r")-inicio+1);
            return true;
        }
        saida << "O campo nao pode ficar vazio.\n";
    }
    return false;
}

bool cadastrar(Equipamento& eq, std::istream& entrada=std::cin, std::ostream& saida=std::cout) {
    return lerTexto(entrada,saida,"Nome: ",eq.nome) &&
           lerTexto(entrada,saida,"Codigo: ",eq.codigo) &&
           lerInteiro(entrada,saida,"ID: ",eq.id) &&
           lerTexto(entrada,saida,"Descricao: ",eq.descricao);
}

int main() {
    std::array<Equipamento,3> equipamentos{};
    std::size_t quantidade=0;
    int opcao=0;
    while (lerInteiro(std::cin,std::cout,"\n1 - Cadastrar\n2 - Exibir\n0 - Sair\nOpcao: ",opcao)) {
        if (opcao==0) break;
        if (opcao==1) {
            if (quantidade==equipamentos.size()) {
                std::cout << "Limite de 3 equipamentos atingido!\n";
                continue;
            }
            Equipamento novo;
            if (!cadastrar(novo)) break;
            equipamentos[quantidade++]=novo;
            std::cout << "Equipamento cadastrado com sucesso!\n";
        } else if (opcao==2) {
            if (quantidade==0) std::cout << "Nenhum equipamento cadastrado ainda.\n";
            for (std::size_t i=0;i<quantidade;++i) {
                const auto& eq=equipamentos[i];
                std::cout << "Nome: " << eq.nome << "\nCodigo: " << eq.codigo
                          << "\nID: " << eq.id << "\nDescricao: " << eq.descricao << '\n';
            }
        } else std::cout << "Opcao invalida!\n";
    }
    return 0;
}
