#include <iostream>

using namespace std;

bool check(int n);

int main(){

    int a,b,c,d;
    do{
        cin >> a >> b >> c >> d;
    } while ((check(a))||(check(b))||(check(c))||(check(d)));

    cout << ((a+b)*(c-d)) << "\nTakahashi"<< endl;

}

bool check(int n){
    if (n<-100||n>100){
        return true;
    }
    return false;
}