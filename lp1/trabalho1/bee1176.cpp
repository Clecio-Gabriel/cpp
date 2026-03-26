#include <iostream>
#include <array>

using value_type = unsigned long long int;
using array2values = std::array <value_type, 2>;


value_type fib(int position);

int main(){
    
    int t {0};
    int pos {0};
    value_type res{0};
    std::cin >> t;
    for (int i = 0; i<t; i++){
        std::cin >> pos;
        res = fib(pos);
        std::cout << "Fib(" << pos << ") = " << res << "\n";
    }

    return 0;
}

value_type fib(int position){
    if (position==1){
        return 1;
    }
    array2values arr {0, 1};
    array2values result {};
    for (int i = 1; i<position; i++){
        result.front() = arr.back();
        result.back() = arr.front() + arr.back();
        arr = result;
    }

    return result.back();
}