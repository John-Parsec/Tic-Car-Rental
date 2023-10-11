#include "CarRental.hpp"

int main() {
    Funcionario funcionario("089", "Igor", "rua B", "76891891", "2");
    Cliente cliente("1", "Joao", "rua A", "123", "1");
    Veiculo veiculo("XSA23", "fox", "bc", 12.65, 2016);
    Date dataInicio(1, 1, 2018);
    Date dataTermino(2, 1, 2018);

    funcionario.alugar_veiculo(cliente, veiculo, dataInicio, dataTermino);

    return 0;
}