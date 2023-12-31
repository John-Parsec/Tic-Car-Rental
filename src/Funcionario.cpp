#include "CarRental.hpp"

int Funcionario::id = 0;

Funcionario::Funcionario(){
    this->habilitacao = "";
}

Funcionario::Funcionario(string cpf, string nome, string telefone, string endereco, string habilitacao): Usuario(cpf, nome, telefone, endereco){
    this->habilitacao = habilitacao;
}

Aluguel Funcionario::alugar_veiculo(Cliente cliente, Veiculo veiculo, Date dataInicio, Date dataTermino){
    Aluguel a;
    bool aluga = true;
    a.setCodigo(to_string(id++));
    a.setVeiculo(veiculo);
    a.setCliente(cliente);
    a.setDataInicio(dataInicio);
    a.setDataTermino(dataTermino);
    //cout << "i: " << a.getDataInicio().toString() << endl;
    //cout << "f: " << a.getDataTermino().toString() << endl;

    a.setFuncionario(*this);

    for(int i = 0; i < this->getHistoricoAlugueis().size(); i++){
        if(this->getHistoricoAlugueis()[i].getVeiculo().getPlaca() == veiculo.getPlaca()){
            string status;

            status =  this->getHistoricoAlugueis()[i].verificaStatus();
            if(status == "Finalizada"){
                aluga = true;
                cout <<"Carro disponivel para agendamento"<<endl;
            }else if(status== "Agendada" and this->getHistoricoAlugueis()[i].getDataDevolucao() < dataInicio){
                aluga = true;
                cout <<"Carro disponivel para agendamento"<<endl;
                
            }else if(status == "Iniciada" and this->getHistoricoAlugueis()[i].getDataDevolucao() < dataInicio){
                aluga = true;
                cout <<"Carro disponivel para agendamento"<<endl;
            }
            else{
                cout <<"Carro indisponivel para agendamento"<<endl;
                aluga = false;
            }
            
            
            return Aluguel();
        }
    
    }
    if(aluga){
                float valor;
                cout<< "Qual o valor do adicional: ";
                cin >> valor;
                a.setAdicional(valor);
                cout<< "Qual o valor do desconto: ";
                cin >> valor;
                a.setDesconto(valor);
                historicoAlugueis.push_back(a);
                return a;
            }
            //retorna aluguel vazio
    
    return a;
}

void Funcionario::finalizar_aluguel(Aluguel aluguel, Date dataDevolcuacao){
    aluguel.setDataDevolucao(dataDevolcuacao);
    for(int i = 0; i < historicoAlugueis.size(); i++){
        if(historicoAlugueis[i].getCodigo() == aluguel.getCodigo()){
            historicoAlugueis[i] = aluguel;
        }
    }
}

void Funcionario::setHabilitacao(string habilitacao){
    this->habilitacao = habilitacao;
}

string Funcionario::getHabilitacao(){
    return this->habilitacao;
}

vector<Aluguel> Funcionario::getHistoricoAlugueis(){
    return this->historicoAlugueis;
}
