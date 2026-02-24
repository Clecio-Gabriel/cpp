#include <iostream>

using namespace std;

long int fib(long int n){
    //CASO BASE
    if (n==0 || n==1){
        n = n;
    }
    //CASO RECURSIVO
    return fib(n-1) + fib(n-2);
}

int main(){

    int qnt;
    cin >> qnt;
    
    long int caso;
    long int fibo;

    for (int i  = 0; i<qnt; i++){
        cin >> caso;
        fibo = fib(caso);
        cout << "Fib(" << caso << ") = " << fibo << endl;
    }

    return 0;
}