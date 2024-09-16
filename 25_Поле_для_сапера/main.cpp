#include <iostream>
#include <vector>

struct Shift {
   int x = 0;
   int y = 0;
};

const std::vector<Shift> SHIFTS = {
   {-1, -1},
   {-1,  0},
   {-1,  1},
   { 0,  1},
   { 1,  1},
   { 1,  0},
   { 1, -1},
   { 0, -1},
};

int main()
{
   short lines{1}, cols{1}, mines{0};

   std::cin >> lines >> cols >> mines;
   std::vector<std::vector<int>> pole(lines + 2, std::vector<int>(cols + 2, 0));

   constexpr int mineLabel = -1;

   for (int i = 0; i < mines; ++i)
   {
      int ln, cl;
      std::cin >> ln >> cl;

      pole[ln][cl] = mineLabel;

      for (const auto& s : SHIFTS)
      {
         auto& cell = pole[ln + s.x][cl + s.y];
         if (cell != mineLabel)
            ++cell;
      }
   }

   for (short l = 1; l <= lines; ++l)
   {
      for (short c = 1; c <= cols; ++c)
      {
         if (c > 1)
            std::cout << " ";

         if (pole[l][c] == mineLabel)
            std::cout << "*";
         else
            std::cout << pole[l][c];
      }
      std::cout << "\n";
   }



   return 0;
}
