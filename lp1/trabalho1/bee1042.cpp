#include <iostream>
#include <array>

using array3int = std::array <int,3>;

int ord(array3int &arr); //WORKING 
int trade(int *num1, int *num2); //WORKING
int printarr(array3int arr); //WORKING 

int main(){

    array3int input {};
    array3int ordened {};

    for (int i = 0; i < 3; i++){
        std::cin >> input[i];
        ordened[i] = input[i];
    }

    ord(ordened);
    printarr(ordened);
    std::cout << "\n";
    printarr(input);


    return 0;
}

int ord(array3int &arr){ 
    //BUBBLE SORT
    for (int i = 0; i < 2 ;i++){
        for (int j = 0; j < (2 - i) ; j++){
            int idx = j+1;
            if (arr[j]>arr[idx]){
                trade(&arr[j], &arr[idx]);
            }
        }
    }

    return 0;
}

int trade(int *num1, int *num2){
    int help {0};
    
    help = *num1;
    *num1 = *num2;
    *num2 = help;

    return 0;
}

int printarr(array3int arr){
    for (int i = 0; i < 3; i++){
        std::cout << arr[i]
                  << "\n";
    }

    return 0;
}