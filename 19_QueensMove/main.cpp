#include <iostream>
#include <cmath>

int main()
{
   int x_old, y_old, x_new, y_new;
   std::cin >> x_old >> y_old >> x_new >> y_new;

   if (x_new == x_old || y_new == y_old || std::abs(x_new-x_old) == std::abs(y_new - y_old))
   {
      std::cout << "YES\n";
   }
   else
   {
      std::cout << "NO\n";
   }

   return 0;
}
