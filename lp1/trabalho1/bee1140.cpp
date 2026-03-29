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
    int input_size = in.length();
    int check = std::toupper(in[0]);

    for (int i = 1; i<input_size; i++){
        int ascii_elem = in[i];
        if (ascii_elem==32){
            int ascii_next_e = std::toupper(in[i+1]);
            if (ascii_next_e!=check){
                taut = false;
                break;
            }
        }
    }

    if (taut==false){
        return 'N';
    }
    return 'Y';
}