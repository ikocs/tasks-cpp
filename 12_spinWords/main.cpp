#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

std::string spinWords(const std::string &str)
{
   if (str.size() < 5)
      return str;

   std::stringstream ss(str);
   std::vector<std::string> words;
   std::string word;
   while (std::getline(ss, word, ' '))
      words.push_back(word);

   std::string result;
   for (auto w : words)
   {
      if (w.size() >= 5)
      {
         std::reverse(w.begin(), w.end());
      }

      result += w + " ";
   }

   result.pop_back();
   return result;
}// spinWords

std::string spinWords2(const std::string &str)
{
   std::stringstream ss(str);
   std::string result;
   std::string buff;
   while (ss >> buff) {
      if (buff.size() >= 5) {
         std::reverse(buff.begin(), buff.end());
      }
      result += buff + ' ';
   }
   result.pop_back();
   return result;
}

int main()
{
   std::cout << spinWords("Hey fellow warriors") << std::endl;
   return 0;
}
