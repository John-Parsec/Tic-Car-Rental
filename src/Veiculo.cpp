#include "CarRental.hpp"

Veiculo::Veiculo(){
    placa = "";
    marca = "";
    modelo = "";
    precoPorDia = 0;
    anoFabricacao = 0;
}

Veiculo::Veiculo(string placa, string marca, string modelo, float precoPorDia, int anoFabricacao){
    this->placa = placa;
    this->marca = marca;
    this->modelo = modelo;
    this->precoPorDia = precoPorDia;
    this->anoFabricacao = anoFabricacao;
}

string Veiculo::getPlaca(){
    return placa;
}

string Veiculo::getModelo(){
    return modelo;
}

string Veiculo::getMarca(){
    return marca;
}

float Veiculo::getPrecoPorDia(){
    return precoPorDia;
}

int Veiculo::getAnoFabricacao(){
    return anoFabricacao;
}

bool Veiculo::getDisponivel(){
    return disponivel;
}

void Veiculo::setPrecoPorDia(float preco){
    this -> precoPorDia = preco;
}

void Veiculo::setPlaca(string placa){
    this->placa = placa;
}

void Veiculo::setDisponivel(bool disponivel){
    this->disponivel = disponivel;
}