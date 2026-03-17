#include <iostream>

long big(long x, long y, long z);

int main(){

    //Variables
    long a{0};
    long b{0};
    long c{0};
    long bigger{0};

    //Input
    std::cin >> a
             >> b
             >> c;
    
    bigger = big(a,b,c);

    std::cout << bigger
              << " eh o maior\n";

}

long big(long x, long y, long z){
    long op1 = (x + y + std::abs(x-y))/2;
    if (op1>z){
        return op1;
    }
    return z;
}