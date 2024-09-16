#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

std::size_t duplicateCount(const std::string& in)
{
   std::unordered_map<unsigned char, unsigned> counter;
   for (const auto& s : in) {
      counter[std::tolower(s)] += 1;
   }

   return std::count_if(counter.begin(), counter.end(),
                        [](std::pair<char, unsigned> p) { return p.second > 1; });
}

int main()
{
   std::cout << duplicateCount("Indivisibilities") << std::endl;
   return 0;
}
