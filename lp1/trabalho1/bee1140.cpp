#include <iostream>
#include <string>

using string = std::string;

char isTaut(string in);

int main(){

    string input {};
    string end {"*"};
    while (true){
        std::getline(std::cin >> std::ws, input);   //INPUT WORKING
        if (input.compare(end) == 0){
            break;
        }
    }
    

    return 0;
}

char isTaut(string in){
    bool taut = false;
}