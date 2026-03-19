#include <iostream>
#include <array>

using uint = unsigned int;
using ushort = unsigned short;

ushort notes(uint *total, ushort value);

int main(){

    std::array <ushort, 7> types {100, 50, 20, 10, 5, 2, 1};
    uint money;
    std::cin >> money;
    std::cout << money
              << "\n";
    for (ushort money_type : types){
        std::cout << notes(&money, money_type)
                  << " nota(s) de R$ "
                  << money_type
                  << ",00\n";
    }
    

    return 0;
}

ushort notes(uint *total, ushort value){
    ushort bills = *total/value;
    if (bills==0){
        return 0;
    }
    *total -= bills*value;
    return bills;
}