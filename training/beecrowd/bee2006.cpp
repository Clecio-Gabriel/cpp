#include <iostream>
#include <array>

using arr5int = std::array <int, 5>;

int count_answ(const arr5int& part, const int& answ);

int main(){

    int cf {0};
    std::cin >> cf;

    arr5int answers {};
    for (int i = 0; i < 5; i++){
        std::cin >> answers[i];
    }

    std::cout << count_answ(answers, cf) << '\n';

    return EXIT_SUCCESS;
}

int count_answ(const arr5int& part, const int& answ){
    int count{0};

    for (auto el : part){
        if (el == answ){
            count++;
        }
    }

    return count;
}