#include <iostream>
#include <vector>


//try to make with iterators
template <typename typestr, typename type>
void InsertionSort(typestr &structure, int end, char op){

    for (int i = 1; i < end; i++){
        type key = structure[i];
        int j = i - 1;
        
        switch(op){
            case 'a':
                while (j>=0 and structure[j] > key){
                    structure[j+1] = structure[j];
                    j--;
                }
                break;
            case 'd':
                while (j>=0 and structure[j] < key){
                    structure[j+1] = structure[j];
                    j--;
                }
        }

        structure[j+1] = key;
        
    }
    
}

template <typename T>
void printVet(std::vector<T> l){
    for (auto el : l){
        std::cout << el << " ";
    }
    std::cout << "\n";
}

void printPair(std::vector<std::pair<int,int>> l){
    for (auto el : l){
        std::cout << el.first << "-" << el.second << " ";
    }
    std::cout << "\n";
}

int main(){

    std::vector inp {8,7,9,0,3,2,55,43,23,33};

        std::cout << "COM INTEIROS:\n\nLISTA ORIGINAL:\n"; 
        printVet<int>(inp);

        std::cout <<"Ordenamento Normal: \n";
        InsertionSort<std::vector<int>, int>(inp, 10, 'a');
        printVet<int>(inp);

        std::cout << "Reverse: \n";
        InsertionSort<std::vector<int>, int>(inp, 10, 'd');
        printVet<int>(inp);

    std::vector <double> inp2 = {1.2, 4.5, 6.7, 8.9, 90.0, 20.0, 30.0, 34.5, 85.3, 23.55, 123.2, 48.0};
    std::cout << "\nCOM DOUBLE:\n\nLISTA ORIGINAL:\n";
    printVet<double>(inp2);
    
        std::cout << "Ordenamento Normal:\n";
        InsertionSort<std::vector<double>, double>(inp2, inp2.size(), 'a');
        printVet<double>(inp2);

        std::cout << "Reverse:\n";
        InsertionSort<std::vector<double>, double>(inp2, inp2.size(), 'd');
        printVet<double>(inp2);

    std::cout << "\nCOM PARES DE INTEIROS:\n\nLISTA ORIGINAL\n";
    std::vector <std::pair<int,int>> vetpair {{2,5},{2,3},{3,9},{3,8},{4,90},{23,7}, {1,0}};
    printPair(vetpair);

        std::cout << "Ordenamento Normal:\n";
        InsertionSort<std::vector<std::pair<int,int>>, std::pair<int,int>>(vetpair, vetpair.size(), 'a');
        printPair(vetpair);
    
        std::cout << "Reverse:\n";
        InsertionSort<std::vector<std::pair<int,int>>, std::pair<int,int>>(vetpair, vetpair.size(), 'd');
        printPair(vetpair);
    
    return 0;
}