#include <iostream>

template <typename T>
void print(T arg){
    if (!arg.has_value()){
        std::cout << "Valor não encontrado\n";
    }
    else{
        std::cout << *arg.value() << "\n";
    }
}