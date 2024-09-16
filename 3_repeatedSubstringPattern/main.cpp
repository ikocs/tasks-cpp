#include <iostream>

using namespace std;

bool repeatedSubstringPattern(string s) {
   for (size_t sub_str_size = 1; sub_str_size < s.size()/2; ++sub_str_size) {
      if (s.size() % sub_str_size != 0)
         continue;

      for (size_t i = 0; i < s.size()-sub_str_size; i+=sub_str_size) {
         if (s.substr(0, sub_str_size) != s.substr(i, sub_str_size))
            break;
      }

      return true;
   }

   return false;
}

int main()
{
   std::cout << "Hello, World!" << std::endl;
   std::cout << repeatedSubstringPattern("abac");
   return 0;
}
