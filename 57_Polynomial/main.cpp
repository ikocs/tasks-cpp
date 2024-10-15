#include <iostream>
#include <vector>

template <typename T>
class Polynomial
{
private:
   std::vector<T> m_coefficients;

public:
   Polynomial(const std::vector<T>& coefficients)
   {
      m_coefficients = coefficients;
   }

   Polynomial(const T& coefficient)
   {
      m_coefficients.push_back(coefficient);
   }

   template<typename Iter>
   Polynomial(Iter first, Iter last)
   {
      for (; first != last; ++first)
      {
         m_coefficients.push_back(*first);
      }
   }

   bool Empty()
   {
      return m_coefficients.empty();
   }

   int Degree()
   {
      if (Empty())
         return 1;

      return m_coefficients.size() - 1;
   }

   bool operator==(const Polynomial& rhs) const
   {
      return m_coefficients == rhs.m_coefficients;
   }

   T& operator [] (size_t i) {
      if (i >= m_coefficients.size())
         return 0;

      return m_coefficients[i];
   }

   const T& operator [] (size_t i) const {
      if (i >= m_coefficients.size())
         return 0;

      return m_coefficients.at(i);
   }
};

template <typename T>
bool operator==(const Polynomial<T>& lhs, const T& rhs)
{
   if (lhs.Empty()) return false;
   return lhs[0] == rhs;
}

template <typename T>
bool operator==(const T& lhs, const Polynomial<T>& rhs)
{
   if (rhs.Empty()) return false;
   return lhs == rhs[0];
}

int main()
{
   std::cout << "Hello, World!" << std::endl;
   return 0;
}
