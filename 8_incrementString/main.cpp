#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

std::string incrementString(const std::string &str)
{
   auto iter_num = std::find_if(str.begin(), str.end(), ::isdigit);
   if (iter_num == str.end())
      return str + "1";

   iter_num = str.end()-1;
   while (*iter_num >= '0' && *iter_num <= '9')
      iter_num--;
   iter_num++;

   std::string str_without_num(str.begin(), iter_num);
   unsigned num_from_str = atoi(std::string(iter_num, str.end()).c_str());
   std::string num_str = std::to_string(num_from_str + 1);

   if (str_without_num.size() + num_str.size() >= str.size())
      return str_without_num + num_str;

   std::string result = str;
   for (unsigned i = 0; i < num_str.size(); ++i)
      result[result.size()-num_str.size()+i] = num_str[i];

   return result; // you code here
}

int main()
{
   std::cout << incrementString("fo99obar99") << std::endl;
   return 0;
}
