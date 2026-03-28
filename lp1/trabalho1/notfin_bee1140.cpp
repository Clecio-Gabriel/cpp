#include <iostream>
#include <string>
#include <cctype>

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
        std::cout << isTaut(input) << "\n";
        
    }
    

    return 0;
}

char isTaut(string in){
    bool taut = true;
    char check = in[0];

    for (int i = 1; i<=in.size(); i++){
        
    }

    return 'Y';
}
