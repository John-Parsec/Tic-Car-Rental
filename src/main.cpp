#include "CarRental.hpp"

int main() {
    Locadora locadora;
    locadora.cadastrarFuncionario();
    locadora.cadastrarCliente();
    locadora.cadastrarVeiculo();

    int acao = 1;

    while(acao != 0)
    {
        cout << 
        "1 - Cadastrar Cliente" << endl <<
        "2 - Cadastrar Funcionario" << endl <<
        "3 - Cadastrar Veiculo" << endl <<
        "4 - Listar Veiculos" << endl <<
        "5 - Alugar Veiculo" << endl <<
        "0 - Sair" << endl <<
        "Digite uma opcao: ";
        cin >> acao;

        if(acao == 1)
        {
            locadora.cadastrarCliente();
        }

        else if(acao == 2)
        {
            locadora.cadastrarFuncionario();
        }

        else if(acao == 3)
        {
            locadora.cadastrarVeiculo();
        }

        else if(acao == 4)
        {
            locadora.listarVeiculos();
        }

        else if(acao == 5)
        {
            
        }

        else {acao = 0;}
    }    
    /*
    Funcionario funcionario("089", "Igor", "rua B", "76891891", "2");
    Cliente cliente("1", "Joao", "rua A", "123", "1");
    Veiculo veiculo("XSA23", "fox", "bc", 12.65, 2016);
    Date dataInicio(1, 1, 2018);
    Date dataTermino(2, 1, 2018);
    funcionario.alugar_veiculo(cliente, veiculo, dataInicio, dataTermino);
    */
    return 0;
}