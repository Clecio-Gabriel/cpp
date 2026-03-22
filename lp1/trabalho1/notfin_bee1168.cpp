#include <iostream>
#include <vector>

using ushort = unsigned short;
using ullint = unsigned long long int;
using ushort_vec = std::vector <ushort>;

int dig(ullint num, ushort_vec& digits);

int main(){

    ushort t{0};
    ullint c{0};
    std::cin >> t;

    for (int i = 0; i < t; i++){
        ushort_vec dig {}; //each iteration of the loop, it will initialize empty
        std::cin >> c;
        
    }

    return 0;
}

int dig(ullint num, ushort_vec& digits){
    while (num!=0){
        
    }
}