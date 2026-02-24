#include <iostream>
#include <iomanip>

using namespace std;

int main(){

    int temp;
    int vel;
    double dis;
    double l;

    cin >> temp >> vel;
    dis = temp * vel;
    l = dis / 12;

    cout << fixed << setprecision(3) << l << endl;

    return 0;
}
