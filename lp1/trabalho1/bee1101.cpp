#include <iostream>

int swap (int *num1, int *num2);
int sum_betw(int a, int b);

int main(){

    int m{0};
    int n{0};
    int sum{0};

    while(std::cin >> m >> n){
        if (n<=0 || m<=0){
            break;
        }
        if (m>n){
           swap(&m, &n);
        }
        sum = sum_betw(m,n);
        std::cout << "Sum="
                  << sum
                  << "\n";
    }

    return 0;
}

int sum_betw(int a, int b){
    int sum{0};
    for (int i = a; i <=b; i++){
        sum+=i;
        std::cout << i << " ";
    }
    
    return sum;
}

int swap (int *num1, int *num2){
    int aux{0};
    aux = *num1;
    *num1 = *num2;
    *num2 = aux;

    return 0;
}