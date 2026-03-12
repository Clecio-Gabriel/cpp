#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>

//////
//  MADE BY MY PROFESSOR
//////


int main() {
  const std::array input{1, 5, 15, 7, 2, 6, 9, 3, -3, -5, 4};
  // const std::array input{1, 1, 1, 1, 1, -1, 1, 1, 1, 1, 1};

  // [1] Apresentar o vetor
  std::cout << ">> input:[ ";
  for (const auto &element : input) {
    std::cout << element << " ";
  }
  std::cout << "]\n";

  // Saída antecipada, vetor vazio.
  if (input.empty()) {
    std::cout << ">>> Vetor de entrada está vazio!\n";
    return 0;
  }

#ifdef MODERN_CPP
  // [2] Percorrer para identificar o maior.
  auto max_idx{std::distance(input.begin(),
                             input.begin())}; // Assumir o primeiro como maior.
  int max_value{input[0]};
  for (const auto &candidate : input) {
    if (candidate > max_value) {
      max_value = candidate; // atualizar o novo valor máximo.
      max_idx = std::distance(input.begin(), &candidate);
    }
  }
  std::cout << ">>> max " << max_value << "\n";
  std::cout << ">>> index de max eh " << max_idx << "\n";
#else
  size_t idx_current_max{0};
  for (size_t idx_candidate{0}; idx_candidate < input.size(); ++idx_candidate) {
    // Comparar elemento atual com o max até esse momento (temporário)
    if (input[idx_candidate] > input[idx_current_max]) {
      idx_current_max = idx_candidate;
    }
  }
  std::cout << ">>> O maior valor eh: " << input[idx_current_max] << '\n';
  std::cout << "    Localizado no índice: " << idx_current_max << '\n';
#endif

  // [3] Apresentar o maior e sua posição
  return 0;
}
