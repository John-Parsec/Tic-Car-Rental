#include "CarRental.hpp"

Cliente::Cliente(){
    this->habilitacao = "00000000000";
}

Cliente::Cliente(string nome, string cpf, string endereco, string telefone, string habilitacao): Usuario(nome, cpf, endereco, telefone){
    this->habilitacao = habilitacao;   
}

string Cliente::getHabilitacao(){
    return this->habilitacao;
}

void Cliente::setHabilitacao(string habilitacao){
    this->habilitacao = habilitacao;
}

vector<Aluguel> Cliente::getAlugueis(){
    return this->alugueis;
}

/*retorna o valor do aluguel no período ou -1 se o veículo estiver alugado.*/
float Cliente::cotar_aluguel(Veiculo veiculo, Date dataInicial, Date dataFinal){
    if(!veiculo.getDisponivel()){
        return -1;
    }
    else{
        return veiculo.getPrecoPorDia() * dataInicial.diasEntre(dataFinal);
    }
}

Aluguel Cliente::solicita_aluguel(Veiculo veiculo, Date dataInicial, Date dataFinal){
    Aluguel aluguel = Aluguel();
    aluguel.setVeiculo(veiculo);
    aluguel.setDataInicio(dataInicial);
    aluguel.setDataTermino(dataFinal);

    this->alugueis.push_back(aluguel);
    
    return aluguel;
}

void Cliente::devolver_veiculo(Aluguel aluguel, Date dataDevolucao){
    aluguel.setDataDevolucao(dataDevolucao);
    aluguel.getVeiculo().setDisponivel(true);
}