#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> move_zeroes(const std::vector<int>& input) {
   auto new_v = input;
   std::stable_partition(new_v.begin(), new_v.end(), [](int n) { return n > 0; } );
   return new_v;
}

int main()
{
   auto v = move_zeroes(std::vector<int>{1, 2, 0, 1, 0, 1, 0, 3, 0, 1});
   std::cout << "Hello, World!" << v.size() << std::endl;
   return 0;
}
