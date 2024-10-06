#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include <string>

int main() {
   std::priority_queue<int> pq;

   std::string cmd;
   while (std::cin >> cmd) {
      if (cmd == "ADD") {
         int val;
         std::cin >> val;
         pq.push(val);
      } else if (cmd == "EXTRACT") {
         if (pq.empty()) {
            std::cout << "CANNOT" << "\n";
            continue;
         }

         std::cout << pq.top() << "\n";
         pq.pop();
      } else if (cmd == "CLEAR") {
         pq = std::priority_queue<int>();
      }
   }

   return 0;
}
