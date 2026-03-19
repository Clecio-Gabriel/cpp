#include <iostream>
#include <array>

using array20int = std::array <int,20>;

int trade(array20int &array);       //WORKING
int swap(int *num1, int *num2);     //WORKING
int printarray(array20int array);   //WORKING

int main(){

    array20int arr {};
    for (int i = 0; i < 20; i++){
        std::cin >> arr[i];
    }

    trade(arr);
    printarray(arr);

    return 0;
}

int trade(array20int &array){

    for (int i = 0; i < 10; i++){
        int j = 19-i;
        swap(&array[i],&array[j]);
    }

    return 0;
}

int swap(int *num1, int *num2){

    int aux{0};

    aux = *num1;
    *num1 = *num2;
    *num2 = aux;

    return 0;
}

int printarray(array20int array){
    for (int i = 0; i < 20; i++){
        std::cout << "N["
                  << i
                  << "] = "
                  << array[i]
                  << "\n";
    }

    return 0;
}