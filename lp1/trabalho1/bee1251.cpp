#include <iostream>
#include <string>
#include <vector>

using string = std::string;
using intPair = std::pair<int,int>;
using intPairVector = std::vector <intPair>;

int getFrequency(string &inp, intPairVector &res);  //WORKING
template <typename typestr, typename type>  //WORKING
void InsertionSort(typestr &structure, int end){

    for (int i = 1; i < end; i++){
        type key = structure[i];
        int j = i - 1;
        
        while (j>=0 and structure[j] > key){
            structure[j+1] = structure[j];
            j--;
        }
        
        structure[j+1] = key;
        
    }
    
}   
int diffSort(intPairVector &input);
int reverse(intPairVector &vec, int start_idx, int end_idx);

int main(){

    string input {};
    
    while (std::getline(std::cin >> std::ws, input)){
        
        intPairVector result {};
        getFrequency(input, result);
        InsertionSort<intPairVector, intPair>(result, result.size());
        diffSort(result);

        std::cout << "\n";
        for (auto element : result){
            std::cout << element.second
                      << " "
                      << element.first
                      << "\n";
        }
    }

    return 0;
}

int getFrequency(string &inp, intPairVector &res){

    int freq{0};

    while (true){
        if (inp.empty()) break;
        int inp_Size = inp.length();
        int i{0};
        int key = inp[i];
        int ascii_code = key;
        int j{inp_Size-1};
        freq = 1;
        while(j>i){
            if (key==inp[j]) {
                freq++;
                inp.erase(inp.begin()+j);
            };
            j--;
        };
        inp.erase(inp.begin()+i);
        i++;
        
        res.push_back(intPair {freq, ascii_code});
    }

    return 0;
}

int diffSort(intPairVector &input){
    int size = input.size();
    
    int start{0};
    int end{0};
    if (size==1) return 0;
    while (!(start>=size)){
        for (int j = start; j < size; j++){
            if (input[start].first==input[j].first){
                end = j;
            }
        }
        if(start!=end) reverse(input, start, end);
        start = end+1;
    }

    return 0;
}

int reverse(intPairVector &vec, int start_idx, int end_idx){
    intPairVector temp {};
    
    int i = end_idx;
    while (i>=start_idx){
        temp.push_back(vec[i]);
        i--;
    }

    int k{0};
    for (int j = start_idx; j<=end_idx; j++){
        vec[j] = temp[k];
        k++;
    }

    return 0;
}