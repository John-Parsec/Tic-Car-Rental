#include "CarRental.hpp"
using namespace std;
class Usuario{
    protected:
        string cpf;
        string nome;
        string endereco;
        string telefone;
    
    public:
        Usuario();
        Usuario(string cpf, string nome, string endereço, string telefone){
            this->cpf = cpf;
            this->nome = nome;
            this->endereco = endereco;
            this->telefone = telefone;
        };
        string getCpf(){
            return this->cpf;
        };
        string getNome(){
            return this->nome;
        };
        string getEndereco(){
            return this->endereco;
        };
        string getTelefone(){
            return this->telefone;
        };
        void setCpf(string){
            this->cpf = cpf;
        };
        void setNome(string){
            this->nome = nome;
        };
        void setEndereco(string){
            this->endereco = endereco;
        };
        void setTelefone(string){
            this->telefone = telefone;
        };
        
};