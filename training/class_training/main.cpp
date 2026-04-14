#include <iostream>
#include "rect.hpp"

int main(){
    Rectangle rect;
    rect.set_values(40,20);

    std::cout << ">>> Rect: " << rect.to_string() << "\n";

    return EXIT_SUCCESS;
}

