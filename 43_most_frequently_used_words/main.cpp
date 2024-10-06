#include <algorithm>
#include <iostream>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>
#include <utility>


int main()
{
   size_t k;
   std::cin >> cokunt;

   std::unordered_map<std::string, int> words;
   std::string word;
   while (std::cin >> word)
   {
      ++words[word];
   }

   std::vector<std::pair<std::string, int>> words_with_freq(words.begin(), words.end());
   std::partial_sort(
      words_with_freq.begin(),
      words_with_freq.begin() + std::min(words_with_freq.size(), k),
      words_with_freq.end(),
      [](const auto& lhs, const auto& rhs){ return std::tie(rhs.second, lhs.first) < std::tie(lhs.second, rhs.first); });

   for (size_t i = 0; i < k && i < words_with_freq.size(); ++i)
   {
      const auto& [w, f] = words_with_freq[i];
      std::cout << w << "\t" << f << "\n";
   }

   return 0;
}
