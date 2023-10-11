#include "CarRental.hpp"
#include <cassert>

int main() {
    Cliente cliente("John Doe", "12345678901", "123 Main St", "555-1234", "ABC123");
    assert(cliente.getNome() == "John Doe");
    
    assert(cliente.getEndereco() == "123 Main St");
    assert(cliente.getTelefone() == "555-1234");
    assert(cliente.getHabilitacao() == "ABC123");

    cliente.setNome("Jane Doe");
    
    cliente.setEndereco("456 Elm St");
    cliente.setTelefone("555-5678");
    cliente.setHabilitacao("DEF456");

    assert(cliente.getNome() == "Jane Doe");
    
    assert(cliente.getEndereco() == "456 Elm St");
    assert(cliente.getTelefone() == "555-5678");
    assert(cliente.getHabilitacao() == "DEF456");

    return 0;
}