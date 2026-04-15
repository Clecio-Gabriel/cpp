#include <iostream>
#include <string>

using string = std::string;
using value_type = unsigned long long int;

value_type check_walls(string &in, int P, int M, int G, int wall_size);

int main(){

    int n{0};
    int x{0};
    std::cin >> n >> x;

    string input {};
    std::getline(std::cin >> std::ws, input);

    int p{0};
    int m{0};
    int g{0};
    std::cin >> p >> m >> g;

    value_type res{0};
    res = check_walls(input, p, m, g, x);

    std::cout << res << "\n";

    return 0;
}


value_type check_walls(string &in, int P, int M, int G, int wall_size){
    
    value_type walls{0};
    int w{wall_size};

    while (!in.empty()){
        while (w>0){
            char front = in.front();
            switch(front){
                case 'P':
                w -= P;
                break;

                case 'M':
                w -= M;
                break;

                case 'G':
                w -= G;
                break;
            }
            in.erase(0,1);
        }

        walls++;
        w = w + wall_size;

    }

    return walls;
}