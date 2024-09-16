#include <iostream>
#include <vector>
#include <map>

int findOdd(const std::vector<int>& numbers){
   std::map<int, unsigned> counter;
   for (const auto& num : numbers) {
      counter[num] += 1;
   }

   for (const auto& c : counter) {
      if (c.second % 2 != 0) {
         return c.first;
      }
   }

   return 0;
}

int main()
{
   std::cout << findOdd({20,1,-1,2,-2,3,3,5,5,1,2,4,20,4,-1,-2,5}) << std::endl;
   return 0;
}
