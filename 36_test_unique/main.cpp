#include <algorithm>
#include <iostream>
#include <ostream>
#include <vector>


int main() {
   std::vector<int> v = {5, 5, 3, 2, 2, 5, 9, 1};
   auto iter = std::unique(v.begin(), v.end());
   // В векторе окажется 5, 3, 2, 5, 9, 1, 9, 1
   //                                      ^ iter будет указывать сюда
   // v.erase(iter, v.end());  // удаляем хвост из ненужных элементов
   for (const auto& i : v)
   {
      std::cout << i << " ";
   }
}