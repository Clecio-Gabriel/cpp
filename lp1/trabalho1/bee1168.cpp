#include <iostream>
#include <string>

using string = std::string;

int calc_leds(string &input, int *result);
char extract_digit(string &num);

int main(){

    int N{0};
    string test {};
    int res{0};

    std::cin >> N;

    for (int i = 0; i < N; i++){
        std::getline(std::cin >> std::ws, test);
        calc_leds(test,&res);
        std::cout << res << " leds" << "\n";
        res = 0;
    }

    return 0;
}

int calc_leds(string &input, int *result){
    if (input.empty()){
        return 0;
    }
    char digit = extract_digit(input);

    switch(digit){
        case '1':
            *result += 2;
            break;

        case '7':
            *result += 3;
            break;
    
        case '4':
            *result += 4;
            break;
        
        case '2':
        case '3':
        case '5':
            *result += 5;
            break;
        
        case '6':
        case '9':
        case '0':
            *result += 6;
            break;
        
        case '8':
            *result += 7;
            break;
    }

    return calc_leds(input, result);
}

char extract_digit(string &num){
    char digit = num.back();
    num.pop_back();

    return digit;
}