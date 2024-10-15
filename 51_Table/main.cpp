/// Table
/// Вам надо написать шаблонный класс Table для электронной таблицы.
/// Для простоты будем считать, что все ячейки таблицы имеют один и тот же тип данных T.
/// Таблица должна уметь менять свой размер по требованию пользователя.
/// Вновь созданные ячейки должны заполняться значениями по умолчанию типа T.

/// Требования к классу такие:
/// 1. Класс должен называться Table.
/// 2. У класса должен быть шаблонный параметр T — тип элемента в ячейке.
/// 3. У класса должен быть конструктор, получающий на входе два числа типа size_t, — начальные размеры таблицы.
/// 4. У класса должны быть константная и неконстантная версии оператора[], возвращающего нечто такое,
///    к чему снова можно было бы применить оператор[]. То есть, должны работать конструкции
///    вида std::cout << table [i][j]; и table[i][j] = value; Проверять корректность индексов при этом не нужно.
/// 6. У класса должна быть функция resize, получающая на вход два параметра типа size_t и меняющая размер таблицы.
///    Старые данные, умещающиеся в новый размер, должны при этом сохраниться.
/// 7. У класса должна быть функция size, возвращающая std::pair<size_t, size_t> — размер таблицы(в том же порядке,
///    в котором эти аргументы передавались в конструктор).

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
