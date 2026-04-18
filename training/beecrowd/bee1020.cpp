#include <iostream>
#include <vector>
#include <string>

using value_type = unsigned int;
using string = std::string;
using structure_type = std::vector < std::pair< string, value_type> >;

value_type dec_days(value_type *val, value_type cmp);

int main(){

    value_type input{0};
    structure_type days_conv { 
        {" ano(s)", 365}, 
        {" mes(es)", 30},
        {" dia(s)", 1}
    };

    std::cin >> input;

    for (const auto& [key, value] : days_conv){
        std::cout << dec_days(&input, value) << key << '\n';
    }


    return EXIT_SUCCESS;
}

value_type dec_days(value_type *val, value_type cmp){
    if (*val==0){
        return 0;
    }
    
    auto eq = *val / cmp;
    *val -= eq*cmp;

    return eq;
}