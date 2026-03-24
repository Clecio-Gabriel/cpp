#include <iostream>
#include <array>

using arraydouble12x12 = std::array<std::array<double, 12>, 12>;

double operate(char typ, arraydouble12x12 array);

int main(){

    char op{};
    double res{0.0};
    arraydouble12x12 arr{{}};
    
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

double operate(char typ, arraydouble12x12 array){
    double result{0.0};

    int column_ini{1};
    int column_end{10};
    for(int i = 0; i<5; i++){
        for (int j = column_ini; j<=column_end; j++){
            result += array[i][j];
        }
        column_ini++;
        column_end--;
    }

    if (typ == 'M'){
        result/=30;
    }

    return result;

}