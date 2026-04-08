#include <iostream>
#include <iterator>
#include <utility>
#include <vector>
#include <array>

using intVec = std::vector <int>;

template <class InputIt, class Equal>
InputIt unique(InputIt first, InputIt last, Equal eq) {
  auto left{first};
  auto end{last};

  while(left!=end){
    auto right{end};
    while (right!=left){
      if (eq(*left, *right)){
        end--;
        std::iter_swap(end, right);
      }
      right--;
    }
    left++;
  }


  return end;
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