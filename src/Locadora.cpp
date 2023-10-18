#include "CarRental.hpp"

void Locadora::cadastrarCliente(){
    string nome, cpf, endereco, telefone, habilitacao;
    cout << "Cadastrando cliente" << endl;
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
    cout << "Cadastrando funcionario" << endl;
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
    
    Funcionario *novo_funcionario = new Funcionario(cpf, nome, endereco, telefone, habilitacao);
    Funcionarios.push_back(novo_funcionario);
}

void Locadora::cadastrarFuncionario(Funcionario *funcionario){
    Funcionarios.push_back(funcionario);
}
        
void Locadora::cadastrarVeiculo(){
    string placa, marca, modelo;
    float precoPorDia;
    int anoFabricacao;

    cout << "Cadastrando veiculo" << endl;
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


int Locadora::buscaCliente(string cpf){
    for (int i = 0; i< Clientes.size(); i++){
        if(Clientes[i]->getCpf() == cpf){
            return i;
        }
    }
    return -1;
}

int Locadora::buscaVeiuclo(string placa){
    for (int i = 0; i< Veiculos.size(); i++){
        if(Veiculos[i]->getPlaca() == placa){
            return i;
        }
    }
    return -1;
}

int Locadora::buscaFuncionario(string cpf){
    for (int i = 0; i< Funcionarios.size(); i++){
        if(Funcionarios[i]->getCpf() == cpf){
            return i;
        }
    }
    return -1;
}

void Locadora::AlugarVeiculo(){
    string cpf, placa, data;
    int indexFuncionario, indexCliente, indexVeiculo;

    cout << "Alugando veiculo" << endl;
    cout << "Digite CPF do funcionario: ";
    cin >> cpf;
    indexFuncionario = buscaFuncionario(cpf);
    if(indexFuncionario == -1){
        cout << "Funcionario não encontrado!!" << endl;
        return;
    }
    cout << "CPF do cliente: ";
    cin >> cpf;
    indexCliente = buscaCliente(cpf);
    if(indexCliente == -1){
        cout << "Cliente não encontrado!!" << endl;
        return;
    }
    cout << "Placa do veiculo: ";
    cin >> placa;
    indexVeiculo = buscaVeiuclo(placa);
    if(indexVeiculo == -1){
        cout << "Veiculo não encontrado!!" << endl;
        return;
    }
    cout << "Data de inicio: ";
    cin >> data;
    Date dataInicio(data);
    cout << "Data de termino: ";
    cin >> data;
    Date dataTermino(data);

    Funcionarios[indexFuncionario]->alugar_veiculo(*Clientes[indexCliente], *Veiculos[indexVeiculo], dataInicio, dataTermino);

}