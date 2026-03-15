#include <iostream>

using u = unsigned;

int blackorwhite(u line, u column);

int main(){
    u l{0};
    u c{0};
    int res{0};

    std::cin >> l
             >> c;
    
    res = blackorwhite(l,c);
    
    std::cout << res
              << "\n";

}

int blackorwhite(u line, u column){
    //It's just an IsEven function in disguise
    u sum = line+column;
    if (sum%2==0){
        return 1;
    }
    return 0;
}