#include <iostream>

using ushort = unsigned short;

ushort slug_level(ushort speed);

int main(){
    ushort n_slugs{0}; 

    while (std::cin >> n_slugs){
        ushort highest {0}; 

        for (ushort idx_slug{0}; idx_slug < n_slugs; ++idx_slug){
            ushort slug_speed{0};
            std::cin >> slug_speed; 
            if (slug_level(slug_speed)>highest){
                highest = slug_level(slug_speed);
            }
        }

        std::cout << highest << "\n";

    }
}

ushort slug_level(ushort speed){
    constexpr ushort level1 {10};
    constexpr ushort level2 {20};
    if (speed<level1){
        return 1;
    }
    if (speed<level2){
        return 2;
    }
    return 3;
}