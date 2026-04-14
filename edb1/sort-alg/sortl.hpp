#include <iterator>
#include <algorithm>
#include <string>

using string = std::string;

namespace sortl{

template <typename Itr>
void brick_sort(Itr first, Itr last){
    bool is_sorted = false; //sort with flag

    while (not is_sorted){
        bool troca = false;

        //EVEN ITERATIONS
        auto left{first};
        while (std::distance(left, last)>1){
            auto right{left+1};
            if (*left>*right){
                std::iter_swap(left, right);
                troca = true;
            }
            left+=2;
        }

        //ODD ITERATIONS
        left = first+1;
        while (std::distance(left, last)>1){
            auto right{left+1};
            if (*left>*right){
                std::iter_swap(left, right);
                troca = true;
            }
            left+=2;
        }

        if (not troca){
            is_sorted = true;
        }
    }
    
}

template <typename Itr>
void print_msg(const string& msg, const Itr start, const Itr end){
    std::cout << msg;
    
    auto runner{start};
    while (runner!=end){
        std::cout << *runner << " ";
        runner++;
    }
    
    std::cout << "\n";
}

}