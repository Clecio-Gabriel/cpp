#include <iostream>
#include <string>
#include <vector>
#include <map>

using string = std::string;
using pairInt = std::pair <int,int>;
using freq_map = std::map <pairInt,int>;

int getFrequency(string inp, freq_map &res);
int InvBubbleSort(string &in);
int trade(char *a, char *b);

int main(){

    string input {};
    
    while (std::getline(std::cin >> std::ws, input)){
        InvBubbleSort(input); //To achieve the BIGGER ASCII restriction

        freq_map result {};
        getFrequency(input, result);
        for (auto element : result){
            std::cout << element.second 
                      << " "
                      << element.first.first << "\n";
        }
        std::cout << "\n";
    }

    return 0;
}

int getFrequency(string inp, freq_map &res){

    int inp_Size = inp.length();
    int i{0};
    int k{0};
    while(i<inp_Size){
        int ascii_code = inp[i];
        int j = i+1;
        int freq{0};
        do{
            freq++;
        }while(inp[i++]==inp[j++]);

        res.insert(std::pair<pairInt,int>{pairInt{freq, k++},ascii_code});
    }

    return 0;
}

int InvBubbleSort(string &in){

    int size = in.length();
    for (int i = size-1; i > 0; i--){
        for (int j = size-1; j > 0; j--){
            if (in[j]>in[j-1]){
                trade(&in[j], &in[j-1]);
            }
        }
    }

    return 0;
}

int trade(char *a, char *b){
    
    int aux {0};
    aux = *a;
    *a = *b;
    *b = aux;

    return 0;
}