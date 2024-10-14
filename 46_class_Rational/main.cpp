#include <iostream>
#include <numeric>

class Rational
{
public:
   Rational(const int numerator = 0, const int denominator = 1) :
   m_numerator(numerator), m_denominator(denominator)
   {
      if (denominator == 0)
         m_denominator = 1;

      this->Normalize();
   }

   ~Rational() = default;

   int Numerator() const { return m_numerator; }
   int Denominator() const { return m_denominator; }

   // operators
   Rational operator+ () const
   {
      return {this->Numerator(), this->Denominator()};
   }

   Rational operator- () const
   {
      return {-this->Numerator(), this->Denominator()};
   }

   Rational& operator+= (const Rational& rhs)
   {
      m_numerator = m_numerator * rhs.Denominator() + rhs.Numerator() * m_denominator;
      m_denominator = m_denominator * rhs.Denominator();
      Normalize();

      return *this;
   }

   Rational& operator-= (const Rational& rhs)
   {
      m_numerator = m_numerator * rhs.Denominator() - rhs.Numerator() * m_denominator;
      m_denominator = m_denominator * rhs.Denominator();
      Normalize();

      return *this;
   }

   Rational& operator*= (const Rational& rhs)
   {
      m_numerator = m_numerator * rhs.Numerator();
      m_denominator = m_denominator * rhs.Denominator();
      Normalize();

      return *this;
   }

   Rational& operator/= (const Rational& rhs)
   {
      const auto tmp = rhs.Numerator();
      m_numerator = m_numerator * rhs.Denominator();
      m_denominator = m_denominator * tmp;
      Normalize();

      return *this;
   }

   bool operator==(const Rational& rhs) const
   {
      return m_numerator == rhs.Numerator() && m_denominator == rhs.Denominator();
   }

   bool operator!=(const Rational& rhs) const
   {
      return !(*this == rhs);
   }

private:
   int m_numerator;
   int m_denominator;

   void Normalize()
   {
      const auto _gcd = std::gcd(m_numerator, m_denominator);
      m_numerator /= _gcd;
      m_denominator /= _gcd;

      if (m_denominator < 0)
      {
         m_numerator *= -1;
         m_denominator *= -1;
      }
   }
};

// Сложение
Rational operator+ (const Rational& rhs, const Rational& lhs)
{
   return Rational{rhs.Numerator() * lhs.Denominator() + lhs.Numerator() * rhs.Denominator(),
                   rhs.Denominator() * lhs.Denominator()};
}

Rational operator+ (const Rational& rhs, const int lhs)
{
   return Rational{rhs.Numerator() + lhs * rhs.Denominator(),
      rhs.Denominator()};
}

Rational operator+ (const int rhs, const Rational& lhs)
{
   return lhs + rhs;
}

// Вычитание
Rational operator- (const Rational& rhs, const Rational& lhs)
{
   return Rational{rhs.Numerator() * lhs.Denominator() - lhs.Numerator() * rhs.Denominator(),
                   rhs.Denominator() * lhs.Denominator()};
}

Rational operator- (const Rational& rhs, const int lhs)
{
   return Rational{rhs.Numerator() - lhs * rhs.Denominator(), rhs.Denominator()};
}

Rational operator- (const int rhs, const Rational& lhs)
{
   return lhs - rhs;
}

// Деление
Rational operator/ (const Rational& rhs, const Rational& lhs)
{
   return Rational{rhs.Numerator() * lhs.Denominator(),
      rhs.Denominator() * lhs.Numerator()};
}

Rational operator/ (const int rhs, const Rational& lhs)
{
   return Rational{lhs.Numerator(), lhs.Denominator() * rhs};
}

Rational operator/ (const Rational& rhs, const int lhs)
{
   return lhs / rhs;
}

// Умножение
Rational operator*(const Rational& rhs, const Rational& lhs)
{
   return {rhs.Numerator() * lhs.Numerator(),
            rhs.Denominator() * lhs.Denominator()};
}

Rational operator*(int rhs, const Rational& lhs)
{
   return {rhs * lhs.Numerator(), lhs.Denominator()};
}

Rational operator*(const Rational& rhs, int lhs)
{
   return lhs * rhs;
}

int main()
{
   Rational r1{1,3};
   Rational r2{2,6};
   r1 = r1 / -5;

   std::cout << r1.Numerator() << "/" << r1.Denominator() << std::endl;
   return 0;
}
