#include <iostream>
#include <array>
#include <string>
#include <sstream>

using value_type = int;
using struct_type = std::array < value_type , 3>;
using string = std::string;

string time_con(value_type *num, value_type time);

int main(){

    value_type N{0};
    std::cin >> N;

    struct_type time {3600, 60};

    for (int i  = 0; i<3; i++){
        if (i==2){
            std::cout << N;
            break;
        }
        std::cout << time_con(&N, time[i]);
    }
    std::cout << "\n";

    return EXIT_SUCCESS;
}

string time_con(value_type *num, value_type time){
    if (*num==0){
        return "0:";
    }
    auto hours = *num / time;
    *num -= time*hours;

    std::ostringstream oss;
    oss << hours << ":";

    return oss.str();
}