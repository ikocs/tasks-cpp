#include <iostream>
#include <string>

void add_symbol(std::string &str, char ch)
{
   if (str.back() != ch) {
      str.push_back(ch);
   }
}

int main()
{
   std::string input, result;
   std::cin >> input;

   result.push_back(input[0]);

   for (size_t i = 1; i < input.size(); ++i)
   {
      switch (input[i])
      {
         case 'a':
         case 'e':
         case 'h':
         case 'i':
         case 'o':
         case 'u':
         case 'w':
         case 'y':
            continue;
         case 'b':
         case 'f':
         case 'p':
         case 'v':
            add_symbol(result, '1');
            break;
         case 'c':
         case 'g':
         case 'j':
         case 'k':
         case 'q':
         case 's':
         case 'x':
         case 'z':
            add_symbol(result, '2');
            break;
         case 'd':
         case 't':
            add_symbol(result, '3');
            break;
         case 'l':
            add_symbol(result, '4');
            break;
         case 'm':
         case 'n':
            add_symbol(result, '5');
            break;
         case 'r':
            add_symbol(result, '6');
            break;
      }

      if (result.back() == result[result.size()-2])
         result.pop_back();
   }

   // while (result.size() < 4) {
   //    result.push_back('0');
   // }

   result.resize(4, '0');

   std::cout << result << "\n";

   return 0;
}
