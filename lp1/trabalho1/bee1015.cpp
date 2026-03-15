#include <iostream>
#include <cmath>

int main(){

    double x1{0.0};
    double y1{0.0};
    double x2{0.0};
    double y2{0.0};
    double dist{0.0};

    std::cin >> x1
             >> y1
             >> x2
             >> y2;

    dist = sqrt(
        pow(x2-x1, 2)
        +
        pow(y2-y1, 2)
    );

    printf("%.4f\n", dist);

}
