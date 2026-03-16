#include <iostream>

int odd_sum(int a, int b); //kinda the second main func of this program
int trade(int *num1, int *num2);

int main(){

    //Variables
    int x{0};
    int y{0};
    int sum_res{0};

    std::cin >> x
             >> y;

    sum_res = odd_sum(x,y);

    std::cout << sum_res << "\n";

    return 0;
}

int odd_sum(int a, int b){
    int sum{0};
    
    if (b<a){
        trade(&a,&b);
    }
    
    for (int i = a+1; i<b; i++) {
        if (i%2!=0){
            sum += i;
        }
    }

    return sum;
}

int trade(int *num1, int *num2){

    int aux{0};
    
    aux = *num1;
    *num1 = *num2;
    *num2 = aux;

    return 0;
}