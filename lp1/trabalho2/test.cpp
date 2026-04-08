#include <iostream>
#include <iterator>
#include <utility>
#include <vector>
#include <array>

using intVec = std::vector <int>;

template <class InputIt, class Equal>
InputIt unique(InputIt first, InputIt last, Equal eq) {
  auto slow{first+1};
  auto fast{slow+1};

  while (fast!=last){
    auto runner{first};
    bool isUnique{true};
    
    while (runner!=slow){
      if (eq(*runner, *fast)){
        isUnique = false;
        break;
      }
      runner++;
    }

    if (isUnique){
      std::iter_swap(fast, slow);
      slow++;
    }

    fast++;
  }

  return slow;
}

int main(){

  
  intVec original_array{2,2,2,2,5,3,4,3,4,7,9,9};
  intVec expected_array{2, 5, 3, 4, 7, 9};

  auto predicate = [](const int &a, const int &b) -> bool { return a==b; };
  auto res = unique(original_array.begin(), original_array.end(), predicate);
  int distance = std::distance(original_array.begin(), res);
  for (int i = 0; i < distance; i++){
    std::cout << original_array[i] << " ";
  }
  std::cout << "\n";
  
  
  

}