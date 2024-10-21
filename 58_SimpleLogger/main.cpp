#include <iostream>

class Logger {
public:
   Logger() {  // конструктор без аргументов
      std::cout << "Logger()\n";
   }

   ~Logger() {  // деструктор
      std::cout << "~Logger()\n";
   }
};

int main()
{
   std::cout << "Hello, World!" << std::endl;
   return 0;
}
