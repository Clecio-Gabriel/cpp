#include <iostream>
#include <algorithm> //try to understand this library
#include <string>

using string = std::string;

//getFrequence :: string → <int, int>
//LET'S DEFINE getFrequence for now as an int(string)
int getFrequence(string &str);
/*
[1] - define the data structure is the most apropriate for this question;
        POSSIBLE CHOICES:
        - map
        - vector
[2] - after the data structure is defined, from it's properties, 
      we'll see if there's any needed treatment to the DATA.
*/

int main(){

    bool firstTime = true;
    string input {};

    while(std::getline(std::cin >> std::ws, input)){
        getFrequence(input);
    }


    return 0;
}

int getFrequence(string &str){

    int freq{0};
    while(!(str.empty())){
        int len = str.length();
        int i {len-1};
        while (i>=0){
            std::cout << i << " " << str << "\n";
            str.erase(str.begin());
            i--;
        }
        //tentar repensar esse algoritmo
        //teoricamente, precisarei somente de um iterador, 
    }

    return freq;
}