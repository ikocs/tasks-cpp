#include <iostream>
#include <deque>

bool check_parenthesis()
{
   std::deque<char> parents;
   char c;

   while (std::cin >> c)
   {
      if (c == '(' || c == '{' || c == '[')
      {
         parents.push_back(c);
         continue;
      }

      if (parents.empty())
         return false;

      if ((c == ')' && parents.back() == '(')
         || (c == '}' && parents.back() == '{')
         || (c == ']' && parents.back() == '['))
      {
         parents.pop_back();
         continue;
      }

      return false;
   }

   if (parents.empty())
      return true;

   return false;
}

int main()
{
   if (check_parenthesis())
      std::cout << "YES" << std::endl;
   else
      std::cout << "NO" << std::endl;

   return 0;
}
