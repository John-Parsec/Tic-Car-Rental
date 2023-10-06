#include "CarRental.hpp"

Funcionario::Funcionario(){
    this->habilitacao = "";
};

Funcionario::Funcionario(string cpf, string nome, string endereco, string telefone, string habilitacao): Usuario(cpf, nome, telefone, endereco){
    this->habilitacao = habilitacao;
};

Aluguel Funcionario::alugar_veiculo(Cliente cliente, Veiculo veiculo, Date dataInicio, Date dataTermino){
    Aluguel a;
    a.setCodigo(to_string(id++));
    a.setVeiculo(veiculo);
    a.setCliente(cliente);
    a.setDataInicio(dataInicio);
    a.setDataTermino(dataTermino);

    cout <<"Valor do desconto:"<< endl;
    int valor;
    cin >> valor;
    a.setDesconto(valor);
    cout <<"Valor do adional:"<< endl;
    cin >> valor;
    a.setAdicional(valor);
    historicoAlugueis.push_back(a);
    return a;
};
void Funcionario::finalizar_aluguel(Aluguel aluguel, Date dataDevolcuacao){
    aluguel.setDataDevolucao(dataDevolcuacao);
    for(int i = 0; i < historicoAlugueis.size(); i++){
        if(historicoAlugueis[i].getCodigo() == aluguel.getCodigo()){
            historicoAlugueis[i] = aluguel;
        }
    }
};