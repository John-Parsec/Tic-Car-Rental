#ifndef CAR_RENTAL_HPP
#define CAR_RENTAL_HPP

#include <bits/stdc++.h>

using namespace std;

class Aluguel;

class Date{
    private:
        int dia;
        int mes;
        int ano;
    public:
        Date();
        Date(int, int, int);
        Date(string);
        int diasEntre(Date);
        static int diasEntre(Date, Date);
        bool dataNaoNula();
        static bool dataNaoNula(Date);
        static Date dataAtual();
        string toString();
        bool operator<(const Date&);
};

class Veiculo{
    private:
        string placa;
        string marca;
        string modelo;
        float precoPorDia;
        int anoFabricacao;
        bool disponivel;
    
    public:
        Veiculo();
        Veiculo(string, string, string, float, int);
        string getPlaca();
        string getModelo();
        string getMarca();
        bool getDisponivel();
        float getPrecoPorDia();
        int getAnoFabricacao();
        void setPrecoPorDia(float);
        void setPlaca(string);
        void setDisponivel(bool);
};

class Usuario{
    protected:
        string cpf;
        string nome;
        string endereco;
        string telefone;
    
    public:
        Usuario();
        Usuario(string, string, string, string);
        string getCpf();
        string getNome();
        string getEndereco();
        string getTelefone();
        void setCpf(string);
        void setNome(string);
        void setEndereco(string);
        void setTelefone(string);
};

class Cliente: public Usuario{
    private:
        string habilitacao;
        vector<Aluguel> alugueis;

    public:
        Cliente();
        Cliente(string, string, string, string, string);
        string getHabilitacao();
        void setHabilitacao(string);
        vector<Aluguel> getAlugueis();

        float cotar_aluguel(Veiculo, Date, Date);
        Aluguel solicita_aluguel(Veiculo, Date, Date);
        void devolver_veiculo(Aluguel, Date);      
};

class Funcionario: public Usuario{
    private:
        string habilitacao;
        vector<Aluguel> historicoAlugueis;
        static int id;
    
    public:
        Funcionario();
        Funcionario(string, string, string, string, string);
        string getHabilitacao();
        void setHabilitacao(string);
        
        vector<Aluguel> getHistoricoAlugueis();

        Aluguel alugar_veiculo(Cliente, Veiculo, Date, Date);
        void finalizar_aluguel(Aluguel, Date);
};

class Aluguel{
    private:
        string codigo;
        Cliente cliente;
        Veiculo veiculo;
        Funcionario funcionario;
        Date dataInicio;
        Date dataTermino;
        Date dataDevolucao;
        float desconto;
        float adicional;
    
    public:
        Aluguel();
        Aluguel(string, Cliente, Veiculo, Funcionario, Date, Date, Date, float, float);
        string getCodigo();
        Cliente getCliente();
        Veiculo getVeiculo();
        Funcionario getFuncionario();
        Date getDataInicio();
        Date getDataTermino();
        Date getDataDevolucao();
        float getDesconto();
        float getAdicional();

        void setCodigo(string);
        void setCliente(Cliente);
        void setVeiculo(Veiculo);
        void setFuncionario(Funcionario);
        void setDataInicio(Date);
        void setDataTermino(Date);
        void setDataDevolucao(Date);
        void setDesconto(float);
        void setAdicional(float);

        float calcularValorFinal();
        string verificaStatus();
};


#endif

//#ifndef FUNC_ID
//#define FUNC_ID
//int Funcionario::id = 0;
//#endif
