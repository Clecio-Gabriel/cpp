#include <iostream>

using ushort = unsigned short;
using ulong = unsigned long;

int main(){

    //Variables
    ushort tests{0};
    ushort time{0};
    ulong pa{0};
    ulong pb{0};
    double g1{0.0};
    double g2{0.0};
    
    std::cin >> tests;
    for (int i = 0; i<tests; i++){
        time = 0; //to reinitialize the variable
        std::cin >> pa >> pb >> g1 >> g2;
        g1 = (g1/100) + 1;
        g2 = (g2/100) + 1;

        while (pa<=pb){
            if (time>100){
                break;
            }
            pa *= g1;
            pb *= g2;
            time++;
        }

        if (time>100){
            std::cout << "Mais de 1 seculo.\n";
            continue;
        }

        std::cout << time
                  << " anos.\n";
    }

    
    return 0;
}