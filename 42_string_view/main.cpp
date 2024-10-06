#include <iostream>
#include <string_view>


bool NextToken(std::string_view& input, const char delimiter, std::string_view& seg)
{

   if (input.empty()) return false;

   auto pos = input.find_first_of(delimiter);

   if (pos == std::string_view::npos)
   {
      seg = input;
      input = std::string_view();
      return true;
   }

   seg = input.substr(0, pos);
   input.remove_prefix(pos + 1);

   return true;
}

int main() {
   std::string_view sv = "Hello world and good bye";

   const char delimiter = ' ';
   std::string_view token;

   // Делим строку на токены по разделителю и перебираем эти токены:
   while (NextToken(sv, delimiter, token)) {
      // обрабатываем очередной token
      // например, печатаем его на экране:
      std::cout << token << "\n";
   }
}