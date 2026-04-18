#include <iostream>
#include <string>
#include <array>
#include <unordered_map>

using string = std::string;
using string_arr = std::array <string, 3>;
using string_map = std::unordered_map <string, string>;

string get_animal(const string_arr& input);
int select(const string_map& mp, const string& opt, string& answer);

int main(){

    string_arr inp {};
    for (int i = 0; i < 3; i++){
        std::getline(std::cin >> std::ws, inp[i]);
    }

    std::cout << get_animal(inp) << '\n';

    return EXIT_SUCCESS;
}

string get_animal(const string_arr& input){
    
    string answ {};

    //VERTEBRADO
    if (input[0]=="vertebrado"){
        //AVE
        if (input[1]=="ave"){
            string_map ave {{"carnivoro", "aguia"},{"onivoro","pomba"}};
            select(ave, input[2], answ);
        }

        //MAMÍFERO
        else{
            string_map mamifero {{"onivoro", "homem"},{"herbivoro","vaca"}};
            select(mamifero, input[2], answ);
        }
    }   

    //INVERTEBRADO
    else{
        //INSETO
        if (input[1]=="inseto"){
            string_map inseto {{"hematofago", "pulga"},{"herbivoro","lagarta"}};
            select(inseto, input[2], answ);
        }

        //ANELIDEO
        else{
            string_map anelideo {{"hematofago", "sanguessuga"},{"onivoro","minhoca"}};
            select(anelideo, input[2], answ);
        }
    }

    return answ;
}

int select(const string_map& mp, const string& opt, string& answer){
    for (const auto& [key, value] : mp){
        if (opt==key){
            answer = value;
        }
    }

    return EXIT_SUCCESS;
}