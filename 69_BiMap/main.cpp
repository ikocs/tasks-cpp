#include <stdexcept>
#include <optional>
#include <map>
#include <memory>

template<typename Key1, typename Key2, typename Value>
class BiMap
{
private:
   std::map<Key1, std::shared_ptr<Value>> m_map_primary;
   std::map<Key2, std::shared_ptr<Value>> m_map_secondary;

public:
   // Вставить значение, указав один или оба ключа.
   // Генерирует исключение std::invalid_argument("some text") в случае,
   // если оба ключа пусты, либо один из ключей уже имеется в хранилище.
   void Insert(const std::optional<Key1>&key1, const std::optional<Key2>&key2, const Value&value)
   {
      if (!key1.has_value() && !key2.has_value())
         throw std::invalid_argument("some text");

      auto p_value = std::make_shared<Value>(value);

      if (key1.has_value() && m_map_primary.contains(*key1))
      {
         throw std::invalid_argument("some text");
      }

      if (key2.has_value() && m_map_secondary.contains(*key2))
      {
         throw std::invalid_argument("some text");
      }

      if (key1.has_value())
      {
         m_map_primary[key1.value()] = p_value;
      }

      if (key2.has_value())
      {
         m_map_secondary[key2.value()] = p_value;
      }
   }

   // Получить значение по ключу первого типа.
   // Генерирует исключение std::out_of_range("some text")
   // в случае отсутствия ключа (как и функция at в std::map).
   Value& GetByPrimaryKey(const Key1&key)
   {
      return *m_map_primary.at(key);
   }
   const Value& GetByPrimaryKey(const Key1&key) const
   {
      return *m_map_primary.at(key);
   }

   // Аналогичная функция для ключа второго типа.
   Value& GetBySecondaryKey(const Key2&key)
   {
      return *m_map_secondary.at(key);
   }
   const Value& GetBySecondaryKey(const Key2&key) const
   {
      return *m_map_secondary.at(key);
   }
};

#include <iostream>
#include <string>

using namespace std;

struct Student
{
   string Surname, Name;
};

ostream& operator <<(ostream&out, const Student&s)
{
   return out << s.Surname << " " << s.Name;
}

int main()
{
   BiMap<int, string, Student> bimap; // студента можно определить либо по номеру, либо по логину
   bimap.Insert(42, {}, {"Ivanov", "Ivan"});
   bimap.Insert({}, "cshse-ami-512", {"Petrov", "Petr"});
   bimap.Insert(13, "cshse-ami-999", {"Fedorov", "Fedor"});

   cout << bimap.GetByPrimaryKey(42) << "\n"; // Ivanov Ivan

   cout << bimap.GetBySecondaryKey("cshse-ami-512") << "\n"; // Petrov Petr

   cout << bimap.GetByPrimaryKey(13) << "\n"; // Fedorov Fedor
   cout << bimap.GetBySecondaryKey("cshse-ami-999") << "\n"; // Fedorov Fedor

   // меняем значение по первичному ключу - по вторичному оно тоже должно измениться
   bimap.GetByPrimaryKey(13).Name = "Oleg";

   cout << bimap.GetByPrimaryKey(13) << "\n"; // Fedorov Oleg
   cout << bimap.GetBySecondaryKey("cshse-ami-999") << "\n"; // Fedorov Oleg
   return 0;
}
