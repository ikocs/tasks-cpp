#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


std::vector<std::string> Split(const std::string& str, char delimiter)
{
   std::vector<std::string> result;
   for (auto p = str.begin(); p != str.end(); )
   {
      auto p_new = std::find(p, str.end(), delimiter);

      if (p_new == p)
         result.emplace_back("");
      else
         result.emplace_back(p, p_new);

      if (p_new == str.end())
         break;

      if (std::next(p_new) == str.end())
         result.emplace_back("");

      p = p_new + 1;
   }

   return result;
}


int main()
{
   std::string str("-13-24--08-");
   auto vr = Split(str, '-');

   for (const auto& s : vr)
   {
      std::cout << s << std::endl;
   }


   return 0;
}
