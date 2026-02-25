#include <iostream>

using namespace std;

bool issorted(int n, int vet[]);

int main(){

    int size;
    bool res;
    cin >> size;

    int vet[size];
    for (int i = 0; i<size; i++){
        cin >> vet[i];
    }
    
    res = issorted(size, vet);

    cout << res << endl;

    return 0;
}

bool issorted(int n, int vet[]){
    


}