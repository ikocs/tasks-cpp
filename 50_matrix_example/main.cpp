#include <vector>
#include <iostream>

template <typename T>
class Matrix {
private:
   std::vector<std::vector<T>> data;

   void MakeRectangle() {
      // Вычисляем максимальную длину строки
      size_t maxSize = 0;
      for (const auto& row : data) {
         if (row.size() > maxSize) {
            maxSize = row.size();
         }
      }

      for (auto& row : data) {
         row.resize(maxSize);
      }
   }

public:
   Matrix(const std::vector<std::vector<T>>& d): data(d) {
      MakeRectangle();
   }

   Matrix(size_t rows, size_t columns) {
      data.resize(rows);
      for (auto& row : data) {
         row.resize(columns);
      }
   }

   size_t GetRows() const {
      return data.size();
   }

   size_t GetColumns() const {
      // У пустого вектора data обращаться к нулевому элементу нельзя
      if (data.empty()) {
         return 0;
      }
      return data[0].size();
   }

   const std::vector<T>& operator[] (size_t i) const {
      return data[i];
   }

   // Перегрузка по константности
   // Первая версия будет применяться к константным матрицам, а вторая — к неконстантным.
   std::vector<T>& operator[] (size_t i) {
      return data[i];
   }

   using const_iterator = decltype(data.cbegin());
   const_iterator begin() const {
      return data.cbegin();
   }

   const_iterator end() const {
      return data.cend();
   }

   Matrix<T>& operator+= (const Matrix<T>& other) {
      const size_t rows = GetRows();
      const size_t columns = GetColumns();
      if (rows != other.GetRows() || columns != other.GetColumns()) {
         throw std::invalid_argument("Matrices have different size!");
      }
      for (size_t i = 0; i != rows; ++i) {
         for (size_t j = 0; j != columns; ++j) {
            data[i][j] += other.data[i][j];
         }
      }
      return *this;
   }

   // Шаблонный оператор внутри шаблонного класса
   // Параметр T2 никак не связан с параметром T
   template <typename T2>
   bool operator== (const Matrix<T2>& other) const {
      const size_t rows = GetRows();
      const size_t columns = GetColumns();

      if (rows != other.GetRows() || columns != other.GetColumns()) {
         return false;
      }

      for (size_t i = 0; i != rows; ++i) {
         for (size_t j = 0; j != columns; ++j) {
            if (!((*this)(i, j) == other(i, j))) {
               return false;
            }
         }
      }

      return true;
   }
};

template <typename T>
std::ostream& operator<< (std::ostream& out, const Matrix<T>& matrix) {
   const size_t rows = matrix.GetRows();
   const size_t columns = matrix.GetColumns();
   for (size_t i = 0; i != rows; ++i) {
      for (size_t j = 0; j != columns; ++j) {
         if (j > 0) {
            out << "\t";
         }
         out << matrix[i][j];
      }
      out << "\n";
   }
   return out;
}

template <typename T>
std::istream& operator>> (std::istream& in, Matrix<T>& matrix) {
   const size_t rows = matrix.GetRows();
   const size_t columns = matrix.GetColumns();
   for (size_t i = 0; i != rows; ++i) {
      for (size_t j = 0; j != columns; ++j) {
         in >> matrix(i, j);
      }
   }
   return in;
}

template <typename T>
Matrix<T> operator+ (const Matrix<T>& m1, const Matrix<T>& m2) {
   auto tmp = m1;
   tmp += m2;
   return tmp;
}

template <typename T1, typename T2>
bool operator!= (const Matrix<T1>& m1, const Matrix<T2>& m2) {
   return !(m1 == m2);
}

int main() {
   Matrix<int> m({
       {1, 2, 3},
       {4, 5, 6},
   });

   std::cout << m.GetRows() << "\n";  // 2
   std::cout << m.GetColumns() << "\n";  // 3
}