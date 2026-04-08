#include <iostream>
#include <iterator>
#include <algorithm>
#include <list>

using intList = std::list <int>;

template <class ForwardIt, class UnaryPredicate>
ForwardIt part(ForwardIt first, ForwardIt last, UnaryPredicate p) {
  auto fast{first};
  auto slow{first};

  while (fast!=last){
    if (p(*fast)){
      std::iter_swap(fast,slow);
      slow++;
    }
    fast++;
  }

  return slow;
}

int main(){

    intList l = {2,22,222,2222,22222,3};
    auto predicate = [](int x){return x>200;};
    auto new_end = part(l.begin(), l.end(), predicate);
    int dist = std::distance(l.begin(), new_end);
    for (auto it = l.cbegin(); std::distance(l.cbegin(),it)<dist; it++){
        std::cout << *it << " ";
    }
    std::cout << "\n";

    return 0;
}