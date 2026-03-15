#include <iostream>

using uint = unsigned int;

int blackorwhite(uint line, uint column);

int main(){
    uint l{0};
    uint c{0};
    int res{0};

    std::cin >> l
             >> c;
    
    res = blackorwhite(l,c);
    
    std::cout << res
              << "\n";

}

int blackorwhite(uint line, uint column){
    //It's just an IsEven function in disguise
    uint sum = line+column;
    if (sum%2==0){
        return 1;
    }
    return 0;
}