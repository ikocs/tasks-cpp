#include <iostream>
#include <vector>
#include <algorithm>

int maxSequence(const std::vector<int>& arr) {
   if (arr.size() == 0)
      return 0;

   std::vector<int> sums = {};
   for (size_t i = 0; i < arr.size(); ++i) {
      if (arr[i] <= 0) continue;

      int sum = 0;
      for (size_t j=i; j < arr.size(); ++j){
         sum += arr[j];
         sums.push_back(sum);
      }
   }

   return *std::max_element(sums.begin(), sums.end());
}

int main()
{
   std::cout << "Hello, World!" << 987 % 100 << " " << 987 % 10 << std::endl;
   return 0;
}
