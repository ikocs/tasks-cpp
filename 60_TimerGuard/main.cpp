#include <iostream>
#include <chrono>
#include <thread>

#include "some_long_stuff.h"

void FirstLongFunction() { std::this_thread::sleep_for(std::chrono::seconds(1)); }
void SecondLongFunction() { std::this_thread::sleep_for(std::chrono::seconds(2)); }
void ThirdLongFunction() { std::this_thread::sleep_for(std::chrono::seconds(3)); }

void SomeFunc() {
   {
      TimerGuard timer("FirstLongFunction elapsed:", std::cout);
      FirstLongFunction();
   }
   {
      TimerGuard timer("SecondLongFunction elapsed:", std::cout);
      SecondLongFunction();
   }
   {
      TimerGuard timer("ThirdLongFunction elapsed:", std::cout);
      ThirdLongFunction();
   }
}

int main() {
   SomeFunc();
   return 0;
}