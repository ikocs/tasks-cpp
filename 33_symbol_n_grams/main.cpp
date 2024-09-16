#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>

int main()
{
   size_t n_word, n_latter;
   std::cin >> n_word >> n_latter;

   std::map<std::string, int> words_map;
   for (size_t i = 0; i < n_word; ++i)
   {
      std::string word;
      std::cin >> word;
      if (word.size() == n_latter)
      {
         words_map[word]++;
         continue;
      }

      for (size_t it = 0; it < word.size(); ++it)
      {
         if (it + n_latter > word.size()) continue;
         words_map[word.substr(it, n_latter)]++;
      }
   }

   std::vector<std::pair<std::string, int>> words_map_vec(words_map.begin(), words_map.end());
   std::sort(words_map_vec.rbegin(), words_map_vec.rend(),
      [](const auto& lhs, const auto& rhs)
      {
         if (lhs.second != rhs.second)
            return lhs.second < rhs.second;

         return lhs.first > rhs.first;
      });

   for (const auto& [word, count] : words_map_vec)
   {
      std::cout << word << " - " << count << "\n";
   }

   return 0;
}
