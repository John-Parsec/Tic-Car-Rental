#include "CarRental.hpp"

void Locadora::cadastrarCliente(){
    string nome, cpf, endereco, telefone, habilitacao;

    cout << "Nome: ";
    getline(cin >> ws, nome);
    cout << "CPF: ";
    cin >> cpf;
    cout << "Endereco: ";
    getline(cin >> ws, endereco);
    cout << "Telefone: ";
    getline(cin >> ws, telefone);
    cout << "Numero de habilitacao: ";
    cin >> habilitacao;
    
    Cliente *novo_cliente = new Cliente(nome, cpf, endereco, telefone, habilitacao);
    Clientes.push_back(novo_cliente);
}

void Locadora::cadastrarCliente(Cliente *cliente){
    Clientes.push_back(cliente);
}

void Locadora::cadastrarFuncionario(){
    string nome, cpf, endereco, telefone, habilitacao;

    cout << "Nome: ";
    getline(cin >> ws, nome);
    cout << "CPF: ";
    cin >> cpf;
    cout << "Endereco: ";
    getline(cin >> ws, endereco);
    cout << "Telefone: ";
    getline(cin >> ws, telefone);
    cout << "Numero de habilitacao: ";
    cin >> habilitacao;
    
    Funcionario *novo_funcionario = new Funcionario(nome, cpf, endereco, telefone, habilitacao);
    Funcionarios.push_back(novo_funcionario);
}

void Locadora::cadastrarFuncionario(Funcionario *funcionario){
    Funcionarios.push_back(funcionario);
}
        
void Locadora::cadastrarVeiculo(){
    string placa, marca, modelo;
    float precoPorDia;
    int anoFabricacao;

    cout << "Placa: ";
    getline(cin >> ws, placa);
    cout << "Marca: ";
    getline(cin >> ws, marca);
    cout << "Modelo: ";
    getline(cin >> ws, modelo);
    cout << "Preco por dia: ";
    cin >> precoPorDia;
    cout << "Ano de fabricacao: ";
    cin >> anoFabricacao;

    Veiculo *novo_veiculo = new Veiculo(placa, marca, modelo, precoPorDia, anoFabricacao);
    Veiculos.push_back(novo_veiculo);
}

void Locadora::cadastrarVeiculo(Veiculo *veiculo){
    Veiculos.push_back(veiculo);
}

void Locadora::listarVeiculos(){
    cout << "Placa\tMarca\tModelo\tPreco por dia \tAno de fabricacao" << endl;
    for(unsigned int i = 0; i < Veiculos.size(); i++)
    {
        Veiculo v = *Veiculos[i];
        cout << v.getPlaca() << "\t" << v.getMarca() << "\t" << v.getModelo() << "\t"
        << v.getPrecoPorDia() << "\t"<< v.getAnoFabricacao() << endl; 
    }
}