#include <iostream>
#include <vector>


std::vector<std::vector<int>> Transpose(const std::vector<std::vector<int>>& matrix)
{
   std::vector transpose(matrix[0].size(), std::vector(matrix.size(), 0));

   for (size_t i = 0; i < transpose.size(); ++i)
      for (size_t j = 0; j < transpose[0].size(); ++j)
         transpose[i][j] = matrix[j][i];

   return transpose;
}


int main()
{
   auto l = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
   auto ll = {{1, 2}, {3, 4}, {5, 6}};
   Transpose({{1, 2}, {3, 4}, {5, 6}});


   return 0;
}
