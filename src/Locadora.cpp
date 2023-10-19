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

void Locadora::listarClientes(){
    cout << "Nome\tCPF\tEndereco\tTelefone \tNum Habilitacao" << endl;
    for(unsigned int i = 0; i < Clientes.size(); i++)
    {
        Cliente c = *Clientes[i];
        cout << c.getNome() << "\t" << c.getCpf() << "\t" << c.getEndereco() << "\t"
        << c.getTelefone() << "\t"<< c.getHabilitacao() << endl; 
    }
}

void Locadora::listarFuncionarios(){
    cout << "Nome\tCPF\tEndereco\tTelefone \tNum Habilitacao" << endl;
    for(unsigned int i = 0; i < Funcionarios.size(); i++)
    {
        Funcionario f = *Funcionarios[i];
        cout << f.getNome() << "\t" << f.getCpf() << "\t" << f.getEndereco() << "\t"
        << f.getTelefone() << "\t"<< f.getHabilitacao() << endl; 
    }
}

void Locadora::listarVeiculos(){
    cout << "Placa\tMarca\tModelo\tPreco por dia \tAno de fabricacao" << endl;
    for(unsigned int i = 0; i < Veiculos.size(); i++)
    {
        Veiculo v = *Veiculos[i];
        cout << v.getPlaca() << "\t" << v.getMarca() << "\t" << v.getModelo() << "\t"
        << "R$" << v.getPrecoPorDia() << "\t"<< v.getAnoFabricacao() << endl; 
    }
}

/*
string codigo;
Cliente cliente;
Veiculo veiculo;
Funcionario funcionario;
Date dataInicio;
Date dataTermino;
Date dataDevolucao;
float desconto;
float adicional;
*/

void Locadora::listarAlugueis(){
    for(unsigned int i = 0; i < Funcionarios.size(); i++)
    {
        Funcionario f = *Funcionarios[i];
        vector<Aluguel> listaAl = f.getHistoricoAlugueis();
        for(unsigned int j = 0; j < listaAl.size(); j++)
        {
            cout << "Codigo: " << listaAl[i].getCodigo() << endl;
            cout << "Cliente: " << listaAl[i].getCliente().getNome() << " - " << listaAl[i].getCliente().getCpf() << endl;
            cout << "Funcionario: " << listaAl[i].getFuncionario().getNome() << " - " << listaAl[i].getFuncionario().getCpf() << endl;
            cout << "Veiculo: " << listaAl[i].getVeiculo().getPlaca() << " - " << listaAl[i].getVeiculo().getMarca() << " - Diaria de R$" << listaAl[i].getVeiculo().getPrecoPorDia() << endl;
            cout << "Data de inicio: " << listaAl[i].getDataInicio().toString() << endl;
            cout << "Data de fim: " << listaAl[i].getDataTermino().toString() << endl;
            cout << "Data de devolucao: " << listaAl[i].getDataDevolucao().toString() << endl;
            cout << "Desconto: R$" << listaAl[i].getDesconto() << endl;
            cout << "Valor Adicional: R$" << listaAl[i].getAdicional() << endl;
            cout << "--------------------------------------------------------------" << endl << endl;
        }
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