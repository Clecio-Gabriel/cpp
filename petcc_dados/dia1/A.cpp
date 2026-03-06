#include <iostream>

using namespace std;

int sum_dig(int num);

int main(){

    int t;
    cin >> t;

    int n;

    for (int i = 0; i<t; i++){
        cin >> n;
        cout << sum_dig(n) << endl;
    }

    return 0;
}

int sum_dig(int num){

    //CASO BASE
    if (num/10==0){
        return num;
    }
    //CASO RECURSIVO
    return (num%10) + sum_dig(num/10);
}