#include <iostream>
#include <array>

int main(){

    std::array input {1, 5, 15, 7, 2, 6, 9, 3, -3, -5, 4};
    //[1] Apresentar o vetor
    std::cout << ">> input:[ " << std::endl;
    for (const auto &element : input){ //const => ñ alterar | auto => deduzir tipo | & => pointer
        std::cout << element << " ";
    };
    std::cout << "\n";
    // [2] Percorrer para identificar o maior
    //
    // [3] Apresentar o maior e sua posição
    
    return 0;
}