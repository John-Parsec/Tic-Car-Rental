#include "CarRental.hpp"

Usuario::Usuario(){
    this->cpf = "";
    this->nome = "";
    this->endereco = "";
    this->telefone = "";
}

Usuario::Usuario(string cpf, string nome, string endereco, string telefone){
    this->cpf = cpf;
    this->nome = nome;
    this->endereco = endereco;
    this->telefone = telefone;
}

string Usuario::getCpf(){
    return this->cpf;
}

string Usuario::getNome(){
    return this->nome;
}

string Usuario::getEndereco(){
    return this->endereco;
}

string Usuario::getTelefone(){
    return this->telefone;
}

void Usuario::setCpf(string){
    this->cpf = cpf;
}

void Usuario::setNome(string){
    this->nome = nome;
}

void Usuario::setEndereco(string){
    this->endereco = endereco;
}

void Usuario::setTelefone(string){
    this->telefone = telefone;
}
