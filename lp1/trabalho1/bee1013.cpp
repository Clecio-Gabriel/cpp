#include <iostream>

using ulong = unsigned long;

ulong module(ulong num);
ulong big(ulong x, ulong y, ulong z);

int main(){

    //Variables
    ulong a{0};
    ulong b{0};
    ulong c{0};
    ulong bigger{0};

    //Input
    std::cin >> a
             >> b
             >> c;
    
    bigger = big(a,b,c);

    std::cout << bigger
              << " eh o maior\n";

}

ulong module(ulong num){
    if (num>=0) return num;
    else return (num*-1);
}

ulong big(ulong x, ulong y, ulong z){
    ulong op1 = (x + y + module(x-y))/2;
    if (op1>z){
        return op1;
    }
    return z;
}