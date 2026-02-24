

#include <iostream>


using namespace std;


int d(int y){
    if(y == 0) return 0;
    return y % 10 + d(y/10);
}


int main()
{
    int qnt;

    cin >> qnt; 

    int arr[qnt];
    int arrResp[qnt];
    
    for(int i = 0; i < qnt; i++){
        cin >> arr[i];
        arrResp[i] = 0;
    }
    
    for(int i = 0; i < qnt; i++){
    
    if(arr[i] % 9 != 0){
        arrResp[i] = 0;
    }
    
    for(int j = arr[i]; j < arr[i] + 180; j++){
        if(j - d(j) == arr[i]){
            arrResp[i] += 1;
        }
    }
    }
    
    for(int i = 0; i < qnt; i++){
        cout << arrResp[i] << endl;
    }
 
    return 0;
}