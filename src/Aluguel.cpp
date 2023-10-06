#include "CarRental.hpp"

Aluguel::Aluguel(string codigo, Cliente cliente, Veiculo veiculo, Funcionario funcionario, 
Date dataInicio, Date dataTermino, Date dataDevolucao, float desconto, float adicional){

    this->codigo = codigo;
    this->cliente = cliente;
    this->veiculo = veiculo;
    this->funcionario = funcionario;
    this->dataInicio = dataInicio;
    this->dataTermino = dataTermino;
    this->dataDevolucao = dataDevolucao;
    this->desconto = desconto;
    this->adicional = adicional;
}


string Aluguel::getCodigo(){
    return codigo;
}

Cliente Aluguel::getCliente(){
    return cliente;
}

Veiculo Aluguel::getVeiculo(){
    return veiculo;
}

Funcionario Aluguel::getFuncionario(){
    return funcionario;
}

Date Aluguel::getDataInicio(){
    return dataInicio;
}

Date Aluguel::getDataTermino(){
    return dataTermino;
}

Date Aluguel::getDataDevolucao(){
    return dataDevolucao;
}

float Aluguel::getDesconto(){
    return desconto;
}

float Aluguel::getAdicional(){
    return adicional;
}


void Aluguel::setCodigo(string codigo){
    this->codigo = codigo;
}

void Aluguel::setCliente(Cliente cliente){
    this->cliente = cliente;
}

void Aluguel::setVeiculo(Veiculo veiculo){
    this->veiculo = veiculo;
}

void Aluguel::setFuncionario(Funcionario funcionario){
    this->funcionario = funcionario;
}

void Aluguel::setDataInicio(Date data){
    this->dataInicio = data;
}

void Aluguel::setDataTermino(Date data){
    this->dataTermino = data;
}

void Aluguel::setDataDevolucao(Date data){
    this->dataDevolucao = data;
}

void Aluguel::setDesconto(float desconto){
    this->desconto = desconto;
}

void Aluguel::setAdicional(float adicional){
    this-> adicional = adicional;
}


float Aluguel::calcular_valor_final(){

}

string Aluguel::verifica_status(){
    //agendada, iniciada, atrasada, finalizada
}