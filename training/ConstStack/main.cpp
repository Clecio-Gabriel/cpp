#include "cl_def.hpp"
#include <array>

int main(){
    std::vector <char> input {'a','b','c','d','e'};

    ConstStack inp (input);
    inp.print_end();
    std::cout << inp.get_size() << '\n';
    inp.shuffle();
    inp.print_end();
    for (int i = 0; i < 2; i++){ 
        std::cout << *inp.get_runner() << '\n';
        inp.run_runner();
    }
    inp.print_run();

    std::array <int, 5> arr {1,2,3,4,5};
    Iters arra(arr.begin(), arr.end());
    std::cout << arra.get_size() << '\n';
    std::cout << '\n';
    

    ConstStack <int> test2 ({1,2,3,4,5,6,7,8,9,10});
    test2.print_end();
    for (int i = 0; i < test2.get_size()*2 ; i++){
        std::cout << test2.get_last() << '\n';
    }

}