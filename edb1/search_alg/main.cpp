#include <array>
#include <vector>

#include "lib/search_alg.hpp"
#include "lib/print_res.hpp"

int main(){
    std::vector <int> vec  {2, 5, 8, 10, 13, 15, 18, 20, 22, 25, 27, 30, 33, 35, 38, 40, 42, 45, 48, 50};
    std::array <int, 20> arr {42, 7, 100, 19, 3, 88, 12, 1, 55, 24, 9, 67, 15, 31, 5, 20, 11, 4, 14, 2};
    
    int input {0};
    while (std::cout << "Digite um valor: ", 
           std::cin >> input){
        auto res = linearsearch(vec.begin(), vec.end(), input);
        print(res);
    }
    
    return EXIT_SUCCESS;
}