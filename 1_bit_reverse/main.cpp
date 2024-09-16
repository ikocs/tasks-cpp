#include <iostream>
#include <bitset>

unsigned int bit_reverse(unsigned int x, const unsigned int log2n) {
   unsigned int n = 0;
   for (int i = 0; i < log2n; i++) {
      n <<= 1;
      n |= (x & 1);
      x >>= 1;
   }
   return n;
}

int main()
{
   unsigned int x = 5;
   std::bitset<8> xi(x);
   std::bitset<8> xa(bit_reverse(x, 5));
   std::cout << "Reverse (" << xi << ") = " << xa << std::endl;
   return 0;
}
