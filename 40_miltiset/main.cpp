// #include <deque>
// #include <iostream>
// #include <set>
// #include <queue>
//
// int main()
// {
//    size_t k, n;
//    std::cin >> n >> k;
//    std::queue<int> container;
//
//    for (size_t i = 0; i < n; i++)
//    {
//       int value;
//       std::cin >> value;
//       container.push(value);
//       if (container.size() == k)
//       {
//          std::multiset<int> window;
//          window.insert(container.begin(), container.end());
//          std::cout << *window.begin() << "\n";
//          window.clear();
//          container.pop_front();
//       }
//    }
//
//    return 0;
// }


#include <iostream>
#include <set>
#include <queue>

int main()
{
   size_t k, n;
   std::cin >> n >> k;
   std::queue<int> container;
   std::multiset<int> window;

   for (size_t i = 0; i < n; i++)
   {
      int value;
      std::cin >> value;
      container.push(value);
      window.insert(value);
      if (container.size() == k)
      {
         std::cout << *window.begin() << "\n";
         window.erase(window.find(container.front()));
         container.pop();
      }
   }

   return 0;
}
