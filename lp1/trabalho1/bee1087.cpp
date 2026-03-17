#include <iostream>
#include <cmath>

using ushort = unsigned short;

int main(){ 

    ushort x1{0};
    ushort y1{0};
    ushort x2{0};
    ushort y2{0};

    while(std::cin >> x1 >> y1 >> x2 >> y2){
        
        if (x1==0){
            break;
        }

        auto delta_x{std::abs(x1-x2)};
        auto delta_y{std::abs(y1-y2)};

        //1 - same position
        if (x1==x2 && y1==y2){
            std::cout << 0 << "\n";
        }

        //2 - same line as the queen(horizontal, vertical or diagonal)
        /*
        possibilities:
        delta_x == 0 → same line, vertically
        delta_y == 0 → same line,  horizontally
        delta_x == delta_y → same line, diagonally
        */
        else if (delta_x==0 || delta_y==0 || delta_x==delta_y){
            std::cout << 1 << "\n";
        }

        else{
            std::cout << 2 << "\n";
        }

    }

    return 0;
}