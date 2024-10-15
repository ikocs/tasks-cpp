/// Вам требуется реализовать класс Queue, аналогичный адаптеру std::queue.
/// Он является обёрткой над некоторым стандартным контейнером и реализует интерфейс очереди.
/// Класс должен быть шаблонным. Первый шаблонный параметр T — тип хранимых элементов. Второй шаблонный параметр
/// — контейнер, используемый для хранения элементов (по умолчанию — std::deque<T>):
///
/// Предусмотрите в классе следующее:
/// 1. Конструктор по умолчанию, создающий пустую очередь.
/// 2. Константную функцию front, которая возвращает элемент, стоящий в начале очереди.
/// 3. Неконстантную функцию front, которая возвращает по ссылке элемент, стоящий в начале очереди
///    — тем самым давая возможность его изменить.
/// 4. Функцию pop, которая убирает элемент из начала очереди (и ничего не возвращает).
/// 5. Функцию push, которая кладёт переданный элемент в конец очереди.
/// 6. Функцию size, которая возвращает количество элементов.
/// 7. Функцию empty, которая возвращает true тогда и только тогда, когда очередь пуста.
/// 8. Операторы == и != для сравнения двух очередей.

#include <iostream>
#include <deque>

template<typename T, typename Container = std::deque<T>>
class Queue
{
public:
   Queue()
   {
      //data();
   }

private:
   Container data;

public:
   const T& operator[] (size_t i) const {
      return data[i];
   }

   T& operator[] (size_t i) {
      return data[i];
   }

   const T& front () const
   {
      return data.front();
   }

   T& front()
   {
      return data.front();
   }

   void pop()
   {
      data.erase(data.begin());
   }

   void push(const T& value)
   {
      data.push_back(value);
   }

   size_t size() const
   {
      return data.size();
   }

   bool empty() const
   {
      if (data.size() == 0)
         return true;

      return false;
   }
};

template <typename T1, typename T2>
bool operator== (const Queue<T1>& lhs, const Queue<T2>& rhs)
{
   const size_t s1 = lhs.size();
   const size_t s2 = rhs.size();

   if (s1 != s2)
      return false;

   for (size_t i = 0; i != s1; ++i)
   {
      if (!(lhs[i] == rhs[i]))
         return false;
   }

   return true;
}

template <typename T1, typename T2>
bool operator!= (const Queue<T1>& lhs, const Queue<T2>& rhs)
{
   return !(lhs == rhs);
}


int main()
{
   Queue<int> q;

   std::cout << "Hello, World!" << std::endl;
   return 0;
}
