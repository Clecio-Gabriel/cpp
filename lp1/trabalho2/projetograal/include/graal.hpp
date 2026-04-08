/*!
 * Edite esse arquivo para incluir suas respostas.
 * @author Clécio Gabriel de Oliveira Félix
 * @date April 6th, 2024.
 * @date April 2nd, 2025.
 */

#ifndef GRAAL_HPP
#define GRAAL_HPP

#include <utility>
using std::pair;

namespace graal {

/*!
 * @brief Finds and returns a pair with the smallest and greatest elements in a range.
 *
 * @tparam Itr Iterator to the range.
 * @tparam Compare A regular comparison function. Comparison functor.
 *
 * @param first Pointer to the first element of the range we want to copy
 * (inclusive).
 * @param last Pointer to the last element of the range we want to copy
 * (exclusive).
 * @param cmp The comparison function that return true if the first element is
 * *less* than the second.
 *
 * @return A pair of the smallest and greatest elements.
 *
 */
template <typename Itr, typename Compare>
std::pair<Itr, Itr> minmax(Itr first, Itr last, Compare cmp) {
  auto small{first};
  auto big{first};
  auto check{first};

  while(check!=last){
    
    //IF BIG<CHECK OR BIG==CHECK
    if (cmp(*big, *check) or *big==*check){
      std::swap(big, check);
    }
    
    //IF CHECK<SMALL
    if (cmp(*check, *small)){
      std::swap(small, check);
    }
  
    check++;
  }

  return {small, big};
}


/*!
* @brief Reverse the elements in a range.
*
* @tparam BidirIt Iterator to the range.
*
* @param first Pointer of the first element of the range we want to reverse.
*
* @param last Pointer of the last element of the range we want to reverse
* 
*/
template <class BidirIt> 
void reverse(BidirIt first, BidirIt last) {
  auto left{first};  
  auto right{last-1};

  //MIDDLE DISTANCE BETWEEN THE FIRST AND THE LAST ELEMENT
  auto middle = std::distance(first,last)/2;

  //WHILE DISTANCE BETWEEN FIRST AND LEFT IS NOT EQUAL TO THE MIDDLE DISTANCE
  while (std::distance(first,left)!=middle){
    std::iter_swap(left,right);
    left++;
    right--;
  }
  
}


/*!
* @brief Copies the elements in a range and paste in a second input,
* and returns the end of the second range.
*
* @tparam InputIt Iterators in the input range.
*
* @param first Pointer to the first element in the first input range.
*
* @param last Pointer to the last element in the first input range.
*
* @param d_first Pointer to the first element in the second input range.
* 
* @return A pointer to the last element of the second input range.
* 
*/
template <class InputIt>
InputIt copy(InputIt first, InputIt last, InputIt d_first) {
  auto reader{first};
  auto copy{d_first};
  auto end{copy+1};

  while(reader!=last){
    *copy = *reader;
    reader++;
    copy++;
    end++;
  }

  return end;
}

/*!
*
* @brief Goes through the elements in a range and, if the predicate p applied
* in an element of the range returns true, than it returns the pointer of that
* element. Else, it will returns a pointer to the last element.
*
* @tparam InputIt Iterators in the input range.
* 
* @tparam UnaryPredicate A unary function. Unary functor.
*
* @param first Pointer to the first element in the input range.
*
* @param last Pointer to the last element in the input range.
* 
* @param p A unary function that'll be applied in the elements of the range.
*
* @return A pointer to an element that, after the p function is applied in it, 
* returns true. If there's none, it returns a pointer to the last element in
* the range.
*
*/
template <class InputIt, class UnaryPredicate>
InputIt find_if(InputIt first, InputIt last, UnaryPredicate p) {
  auto check_in{first};

  while(check_in!=last){
    if (p(*check_in)) break;
    check_in++;
  }

  return check_in;
}


/*!
* 
* @brief It goes through the elements of a range and, if the predicate p 
* applied to all of the elements returns true, the function will returns true.
* Else, it returns false.
* 
* @tparam InputIt Iterators in the input range.
*
* @tparam UnaryPredicate A unary function. Unary functor.
*
* @param first Pointer to the first element in the input range.
*
* @param last Pointer to the last element in the input range.
* 
* @param p A unary function that'll be applied in the elements of the range.
* 
* @return True if the predicate p applied to all of the elements in the range
* returns true. Else, it returns false.
* 
*/
template <class InputIt, class UnaryPredicate>
bool all_of(InputIt first, InputIt last, UnaryPredicate p) {
  auto check_in{first};

  while (check_in!=last){
    if (!p(*check_in)) return false;
    check_in++;
  }

  return true;
}

/*!
* 
* @brief It goes through the elements of a range and, if the predicate p 
* applied to any of the elements returns true, the function will returns true.
* Else, it returns false.
* 
* @tparam InputIt Iterators in the input range.
*
* @tparam UnaryPredicate A unary function. Unary functor.
*
* @param first Pointer to the first element in the input range.
*
* @param last Pointer to the last element in the input range.
* 
* @param p A unary function that'll be applied in the elements of the range.
* 
* @return True if the predicate p applied to any of the elements in the range
* returns true. Else, it returns false.
* 
*/
template <class InputIt, class UnaryPredicate>
bool any_of(InputIt first, InputIt last, UnaryPredicate p) {
  auto check_in{first};

  while (check_in!=last){
    if (p(*check_in)) return true;
    check_in++;
  }

  return false;
}


/*!
* 
* @brief It goes through the elements of a range and, if the predicate p 
* applied to any of the elements returns true, the function will returns false.
* Else, it returns true.
* 
* @tparam InputIt Iterators in the input range.
*
* @tparam UnaryPredicate A unary function. Unary functor.
*
* @param first Pointer to the first element in the input range.
*
* @param last Pointer to the last element in the input range.
* 
* @param p A unary function that'll be applied in the elements of the range.
* 
* @return False if the predicate p applied to any of the elements in the range
* returns true. Else, it returns true.
* 
*/
template <class InputIt, class UnaryPredicate>
bool none_of(InputIt first, InputIt last, UnaryPredicate p) {
  auto check_in{first};

  while (check_in!=last){
    if (p(*check_in)) return false;
    check_in++;
  }

  return true; 
}

/*!
* 
* @brief It goes through the elements in the range of the first input and 
* compares them to the range of input2, defined by a starting pointer first2.
* If all elements are equal, it will return true. Else, it will return false.
* 
* @tparam InputIt1 Iterators in the first input range.
*
* @tparam InputIt2 Iterator in the second input range.
*
* @tparam Equal A comparison function. Comparison functor.
*
* @param first1 Pointer to the first element in the first input range.
*
* @param last1 Pointer to the last element in the first input range.
*
* @param first2 Pointer to the first element in the second input range.
*
* @param eq A comparison function that returns true if both elements are equal.
* Else, it returns false.
*
* @return True if all elements in both ranges are equal. False, otherwise.
*
*/
template <class InputIt1, class InputIt2, class Equal>
bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2, Equal eq) {
  auto check_in1 {first1};
  auto check_in2 {first2};

  while (check_in1!=last1){
    if (!eq(*check_in1, *check_in2))  return false;
    check_in1++;
    check_in2++;
  }

  return true;
}

/*!
* 
* @brief It goes through the elements in the range of the first input and 
* compares them to the range of input2, defined by a starting pointer first2
* and an ending pointer last2. If all elements are equal, it will return true. 
* Else, it will return false.
* 
* @tparam InputIt1 Iterators in the first input range.
*
* @tparam InputIt2 Iterator in the second input range.
*
* @tparam Equal A comparison function. Comparison functor.
*
* @param first1 Pointer to the first element in the first input range.
*
* @param last1 Pointer to the last element in the first input range.
*
* @param first2 Pointer to the first element in the second input range.
*
* @param last2 Pointer to the last element in the second input range.
*
* @param eq A comparison function that returns true if both elements are equal.
* Else, it returns false.
*
* @return True if all elements in both ranges are equal. False, otherwise.
*
*/
template <class InputIt1, class InputIt2, class Equal>
bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2,
           Equal eq) {
  auto ran_in1{std::distance(first1,last1)};
  auto ran_in2{std::distance(first2,last2)};
  if (ran_in1!=ran_in2){
    return false;
  }

  auto check_in1{first1};
  auto check_in2{first2};
  while (check_in1!=last1){
    if (!eq(*check_in1,*check_in2)) return false;
    check_in1++;
    check_in2++;
  }

  return true;
}

/*!
* 
* @brief It goes through the elements of an array and realocates duplicates to
* the ending position. It returns a pointer to the last element that is unique.
* 
* @tparam InputIt Iterators in the input range.
* 
* @tparam Equal A comparison function. A comparison functor.
*
* @param first Pointer to the first element in the input range.
*
* @param last Pointer to the last element in the input range.
* 
* @param eq A comparison function that returns true if both elements are equal.
* Else, it returns false.
* 
* @return A pointer to the last element that is unique.
* 
*/
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

template <class ForwardIt, class UnaryPredicate>
ForwardIt partition(ForwardIt first, ForwardIt last, UnaryPredicate p) {
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

} // namespace graal.

#endif
