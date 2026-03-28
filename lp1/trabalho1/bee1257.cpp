#include <iostream>
#include <string>

using string = std::string;

int count_hash(string in, int idx, int *res);
int get_alphabet_num(char c);

int main(){

    int N{0};
    string input{};

    std::cin >> N;
    for (int i = 0; i < N; i++){
        int l{0};
        std::cin >> l;

        int result{0};
        for (int j = 0; j<l; j++){
            std::getline(std::cin >> std::ws, input);
            count_hash(input, j, &result);
        }
        std::cout << result << "\n";

    }

    return 0;
}

int count_hash(string in, int idx, int *res){
    int stringsize = in.length();
    for (int i = 0; i < stringsize; i++){
        *res += get_alphabet_num(in[i]); //alphabet value
        *res += idx; //string index
        *res += i;   //string element index
    }

    return 0;
}

int get_alphabet_num(char c){
    int ascii_val = c;
    int alphabet_val = c-65;

    return alphabet_val;
}