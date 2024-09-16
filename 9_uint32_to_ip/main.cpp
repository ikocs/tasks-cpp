#include <iostream>
#include <cstdint>

std::string uint32_to_ip(uint32_t ip)
{
   uint8_t num1 = ip & 0b11111111;
   uint8_t num2 = (ip & 0b1111111100000000) >> 8;
   uint8_t num3 = (ip & 0b111111110000000000000000) >> 16;
   uint8_t num4 = (ip & 0b11111111000000000000000000000000) >> 24;
   return std::to_string(num4) + "." + std::to_string(num3) + "." + std::to_string(num2) + "."  + std::to_string(num1);
}


int main()
{
   std::cout << uint32_to_ip(2154959208) << std::endl;
   return 0;
}
