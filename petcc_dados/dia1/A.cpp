#include <iostream>
using namespace std;

int friendly(int x);
int sum_dig(int num);

int main(){

    int t;
    cin >> t;

    int n;

    for (int i = 0; i<t; i++){
        cin >> n;
        cout << friendly(n) << endl;
    }

    return 0;
}

int friendly(int x){
    if (x%9!=0) return 0;

    int count = 0;
    int ini = x;
    for (int i = 1; i<=81; i++){
        ini = x + i;
        if (ini == (sum_dig(ini)+x)){
            count++;
        }
    }

    return count;
}

int sum_dig(int num){

    //CASO BASE
    if (num/10==0){
        return num;
    }
    //CASO RECURSIVO
    return (num%10) + sum_dig(num/10);
}