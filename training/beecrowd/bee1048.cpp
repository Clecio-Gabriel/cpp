#include <iostream>
#include <iomanip>

using value_type = double;
using value_tuple = std::pair <value_type, value_type>;

value_tuple bon_calc(value_type *salary);

int main(){

    value_type sal {0.0};

    std::cin >> sal;

    auto bon = bon_calc(&sal);

    std::cout << "Novo salario: " << std::fixed << std::setprecision(2) << sal << '\n'
              << "Reajuste ganho: " << std::setprecision(2) << bon.first << '\n'
              << "Em percentual: " << std::setprecision(0) << bon.second << " %\n"; 


    return EXIT_SUCCESS;
}

value_tuple bon_calc(value_type *salary){
    value_tuple boni {0.0, 0.0}; //[boni_value, boni_percentage]
    
    //[ 1 ] - Check Interval
    if (*salary<=400){
        boni.second = 0.15;
    }
    else if(*salary>400 and *salary<=800){
        boni.second = 0.12;
    }
    else if(*salary>800 and *salary<=1200){
        boni.second = 0.10;
    }
    else if(*salary>1200 and *salary<=2000){
        boni.second = 0.07;
    }
    else{
        boni.second = 0.04;
    }

    //[ 2 ] - Calculate
    boni.first = *salary * boni.second;
    *salary += boni.first;
    boni.second *= 100;

    return boni;
}