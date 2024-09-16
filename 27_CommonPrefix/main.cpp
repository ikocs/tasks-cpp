#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::string CommonPrefix(const std::vector<std::string>& words)
{
   if (words.empty())
      return "";

   size_t min_len_str{words[0].length()};
   for (const auto& word : words)
      if (word.size() < min_len_str)
         min_len_str = word.size();

   std::string result;
   for (size_t i = 0; i < min_len_str; ++i)
   {
      const char latter = words[0][i];
      for (const auto& word : words)
      {
         if (latter != word[i])
            return result;
      }

      result += latter;
   }

   return result;
}

int main()
{
   std::cout << CommonPrefix({"apple", "apricot", "application"}) << std::endl;
   return 0;
}
