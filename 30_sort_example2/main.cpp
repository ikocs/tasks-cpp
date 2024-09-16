#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <valarray>

int main()
{
   short n;
   std::cin >> n;
   std::vector<std::pair<short, short>> dots(n);

   for (short i = 0; i < n; i++)
   {
      short x, y;
      std::cin >> x >> y;
      dots[i] = std::make_pair(x, y);
   }

   std::sort(dots.begin(), dots.end(),
      [](const std::pair<short, short>& lhs, const std::pair<short, short>& rhs)
      {return std::sqrt(lhs.first * lhs.first + lhs.second * lhs.second)
         < std::sqrt(rhs.first * rhs.first + rhs.second * rhs.second);});

   for (const auto& d : dots)
      std::cout << d.first << ' ' << d.second << '\n';

   return 0;
}
