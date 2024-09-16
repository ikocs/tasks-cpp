#include <iostream>
#include <map>
#include <string>
#include <set>

int main()
{
   size_t n;
   std::cin >> n;

   std::map<unsigned, std::set<std::string>> map;
   for (size_t i = 0; i < n; i++) {
      std::string word;
      unsigned page;
      std::cin >> word >> page;
      map[page].insert(word);
   }

   for (const auto& [page, words] : map) {
      std::cout << page;
      for (const auto& word : words) {
         std::cout << " " << word;
      }
      std::cout << "\n";
   }

   return 0;
}
