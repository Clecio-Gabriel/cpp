#include <iostream>
#include <array>

using array3int = std::array <int,3>;

int copy(array3int a, array3int b);

int main(){

    array3int input {};
    array3int ordened {};

    for (int i = 0; i < 3; i++){
        std::cin >> input[i];
    }

    copy(input, ordened);

    return 0;
}

int copy(array3int a, array3int b){

    

    return 0;
}