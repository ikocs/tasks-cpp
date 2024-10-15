#include <iostream>
#include <vector>

template<typename T>
class Table
{
public:
   Table(const size_t n_row, const size_t n_col)
   {
      resize(n_row, n_col);
   }

   void resize(const size_t n_row, const size_t n_col)
   {
      data.resize(n_row);
      for (auto& row : data)
         row.resize(n_col);
   }

   std::pair<size_t, size_t> size() const
   {
      if (data.empty())
         return std::make_pair(0, 0);

      return std::make_pair(data.size(), data[0].size());
   }

private:
   std::vector<std::vector<T>> data;

public:
   const std::vector<T>& operator[] (size_t i) const {
      return data[i];
   }

   // Перегрузка по константности
   // Первая версия будет применяться к константным матрицам, а вторая — к неконстантным.
   std::vector<T>& operator[] (size_t i) {
      return data[i];
   }
};

int main()
{
   Table<int> t(3,4);
   t[1][2] = 7;

   std::cout << t[0][0] << " " << t[1][2] << " - " << t.size().first << "," << t.size().second << std::endl;

   t.resize(5,6);
   std::cout << t[0][0] << " " << t[1][2] << " - " << t.size().first << "," << t.size().second << std::endl;

   return 0;
}
