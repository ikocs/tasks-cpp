#include <iostream>
#include <vector>

std::pair<size_t, size_t> MatrixArgMax(const std::vector<std::vector<int>>& matrix)
{
   int max_val{matrix[0][0]};
   std::pair<size_t, size_t> max_index{};
   for (size_t row = 0; row < matrix.size(); ++row)
      for (size_t col = 0; col < matrix[row].size(); ++col)
      {
         if (matrix[row][col] > max_val)
         {
            max_val = matrix[row][col];
            max_index.first = row;
            max_index.second = col;
         }
      }

   return max_index;
}

int main()
{
   size_t lines, rows;
   std::cin >> lines >> rows;

   std::vector<std::vector<int>> matrix(lines, std::vector<int>(rows, 0));
   for (size_t row = 0; row < lines; ++row)
      for (size_t col = 0; col < rows; ++col)
         std::cin >> matrix[row][col];

   auto mm = MatrixArgMax(matrix);

   std::cout << mm.first << " " << mm.second << std::endl;
   return 0;
}
