#ifndef FIGURES_H
#define FIGURES_H

class Figure
{
public:
   virtual ~Figure() = default;

   [[nodiscard]] virtual int Perimeter() const = 0;
};

class Triangle final : public Figure
{
public:
   Triangle(const int a, const int b, const int c)
      : m_a(a), m_b(b), m_c(c)
   {
   }
   ~Triangle() override = default;

   [[nodiscard]] int Perimeter() const override
   {
      return m_a + m_b + m_c;
   }

private:
   int m_a{0}, m_b{0}, m_c{0};
};


class Rectangle final : public Figure
{
public:
   Rectangle(const int a, const int b) : m_a(a), m_b(b)
   {}
   ~Rectangle() override = default;

   [[nodiscard]] int Perimeter() const override
   {
      return m_a*2 + m_b*2;
   }

private:
   int m_a{0}, m_b{0};
};

#endif //FIGURES_H
