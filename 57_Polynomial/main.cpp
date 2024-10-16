#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
class Polynomial
{
private:
   std::vector<T> m_coefficients;
   inline static const T valueTypeZero{0};
   using ConstIter = typename std::vector<T>::const_iterator;

   void Normalize()
   {
      while (!m_coefficients.empty() && m_coefficients.back() == valueTypeZero)
      {
         m_coefficients.pop_back();
      }
   }

   std::vector<T>& GetCoefficients()
   {
      return m_coefficients;
   }

public:

   Polynomial(const std::vector<T>& coefficients) : m_coefficients{coefficients}
   {
      Normalize();
   }

   Polynomial(const T& coefficient = {})
   {
      if (coefficient != valueTypeZero)
         m_coefficients.push_back(coefficient);
   }

   template<typename Iter>
   Polynomial(Iter first, Iter last) : m_coefficients{first, last}
   {
      Normalize();
   }

   const std::vector<T>& GetCoefficients() const
   {
      return m_coefficients;
   }

   size_t Dimension() const {
      return m_coefficients.size();
   }

   int Degree() const
   {
      return static_cast<int>(GetCoefficients().size()) - 1;
   }

   friend bool operator== (const Polynomial& lhs, const Polynomial& rhs)
   {
      return lhs.GetCoefficients() == rhs.GetCoefficients();
   }

   friend bool operator!= (const Polynomial& lhs, const Polynomial& rhs)
   {
      return !(lhs == rhs);
   }

   const T& operator[] (size_t i) const {
      if (static_cast<int>(i) > Degree())
         return valueTypeZero;

      return GetCoefficients()[i];
   }

   T operator() (const T& value) const
   {
      T result = valueTypeZero;

      for (auto i = Degree(); i >=0; --i)
      {
         result *= value;
         result += GetCoefficients()[i];
      }

      return result;
   }

   Polynomial<T>& operator += (const Polynomial<T>& other) {
      if (other.Degree() > Degree()) {
         GetCoefficients().resize(other.Degree() + 1);
      }

      for (int i = 0; i <= Degree() && i <= other.Degree(); ++i) {
         GetCoefficients()[i] += other.GetCoefficients()[i];
      }

      Normalize();

      return *this;
   }

   Polynomial<T>& operator -= (const Polynomial<T>& other) {
      if (other.Degree() > Degree()) {
         GetCoefficients().resize(other.Degree() + 1);
      }

      for (int i = 0; i <= Degree() && i <= other.Degree(); ++i) {
         GetCoefficients()[i] -= other.GetCoefficients()[i];
      }

      Normalize();

      return *this;
   }

    Polynomial<T>& operator *= (const Polynomial<T>& other) {
        if (Degree() == -1 || other.Degree() == -1) {
            GetCoefficients().resize(0);
            return *this;
        }

        std::vector<T> tmp(Degree() + other.Degree() + 1);
        for (int i = 0; i <= Degree(); ++i) {
            for (int j = 0; j <= other.Degree(); ++j) {
                tmp[i + j] += GetCoefficients()[i] * other.GetCoefficients()[j];
            }
        }
        GetCoefficients() = std::move(tmp);
        Normalize();
        return *this;
    }

   friend Polynomial<T> operator+(Polynomial<T> v1, const Polynomial<T>& v2)
   {
      return v1 += v2;
   }

   friend Polynomial<T> operator-(Polynomial<T> v1, const Polynomial<T>& v2)
   {
      return v1 -= v2;
   }

   friend Polynomial<T> operator*(Polynomial<T> v1, const Polynomial<T>& v2)
   {
      return v1 *= v2;
   }

   ConstIter begin() const
   {
      return GetCoefficients().cbegin();
   }

   ConstIter end() const
   {
      return GetCoefficients().cend();
   }
};

template <typename T>
std::ostream& operator<< (std::ostream& out, const Polynomial<T>& v)
{
   for (auto i = v.Degree(); i >= 0; --i)
   {
      out << v[i];
      if (i != 0)
      {
         out << ' ';
      }
   }

   return out;
}

int main()
{
   Polynomial<int> p1(0);
   Polynomial<int> p2(std::vector<int>{2,0,1});

   auto p3 = p1 + p2;
   std::cout << p3 << std::endl;

   auto p4 = p1 - p2;
   std::cout << p4 << std::endl;

   auto p5 = p1 * p2;
   std::cout << p5 << std::endl;

   return 0;
}
