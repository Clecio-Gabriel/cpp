#include <iostream>
#include <array>

using arraydouble12x12 = std::array<std::array<double, 12>, 12>;

double operate(char typ, arraydouble12x12 &array);

int main(){

    //Variables
    double res{0};
    char op{};
    arraydouble12x12 arr {{}};
    
    std::cin >> op;
    for (int i = 0; i<12; i++){
        for (int j = 0; j<12; j++){
            std::cin >> arr[i][j];
        }
    }

    res = operate(op, arr);

    printf("%.1f\n", res);

    return 0;
}

double operate(char typ, arraydouble12x12 &array){
    double result{0};

    int column{11};
    for (int i = 1; i<12; i++){
        for (int j = column; j<12; j++){
            result += array[i][j];
        }
        column--;
    }

    if (typ == 'M'){
        result/=66;
    }

    return result;
}