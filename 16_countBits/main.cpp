#include <iostream>
#include <bitset>
#include <limits>

unsigned int countBits(unsigned long long n){
   std::bitset<std::numeric_limits<unsigned long long>::digits> b_set(n);
   return b_set.count();
}

int main()
{
   countBits(156);
   std::cout << "Hello, World!" << std::endl;
   return 0;
}
