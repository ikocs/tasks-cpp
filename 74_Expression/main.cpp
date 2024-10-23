#include <iostream>
#include <memory>
#include <string>
#include <utility>

class Expression
{
public:
   virtual int Evaluate() const = 0;
   virtual std::string ToString() const = 0;
   virtual ~Expression()
   {
   }
};

using ExpressionPtr = std::shared_ptr<Expression>;

class ConstExp final : public Expression
{
public:
   ConstExp(const int value) : m_value(value)
   {
   }
   ~ConstExp() override {}

   int Evaluate() const override
   {
      return m_value;
   }
   std::string ToString() const override
   {
      return std::to_string(m_value);
   }

private:
   const int m_value;
};

ExpressionPtr Const(int x)
{
   return std::make_shared<ConstExp>(x);
}

class BinaryOperation : public Expression
{
protected:
   ExpressionPtr left;
   ExpressionPtr right;

public:
   BinaryOperation(ExpressionPtr left, ExpressionPtr right) : left(std::move(left)), right(std::move(right)) {}
};

class SumExp final : public BinaryOperation
{
public:
   SumExp(ExpressionPtr ex1, ExpressionPtr ex2) : BinaryOperation(std::move(ex1), std::move(ex2))
   {
   }
   ~SumExp() override {}


   int Evaluate() const override
   {
      return left->Evaluate() + right->Evaluate();
   }

   std::string ToString() const override
   {
      return left->ToString() + " + " + right->ToString();
   }

};

ExpressionPtr Sum(ExpressionPtr left, ExpressionPtr right)
{
   return std::make_shared<SumExp>(left, right);
}

std::string Parentheses(ExpressionPtr exp)
{
   if (dynamic_cast<SumExp*>(exp.get()))
   {
      return "(" + exp->ToString() + ")";
   }
   else
   {
      return exp->ToString();
   }
}

class ProductExp final : public BinaryOperation
{
public:
   ProductExp(ExpressionPtr ex1, ExpressionPtr ex2) : BinaryOperation(std::move(ex1), std::move(ex2))
   {
   }
   ~ProductExp() override {}

   int Evaluate() const override
   {
      return left->Evaluate() * right->Evaluate();
   }
   std::string ToString() const override
   {
      return Parentheses(left) + " * " + Parentheses(right);
   }
};

ExpressionPtr Product(ExpressionPtr left, ExpressionPtr right)
{
   return std::make_shared<ProductExp>(left, right);
}

int main() {
   ExpressionPtr ex1 = Sum(Product(Const(3), Const(4)), Const(5));
   std::cout << ex1->ToString() << "\n";  // 3 * 4 + 5
   std::cout << ex1->Evaluate() << "\n";  // 17

   ExpressionPtr ex2 = Product(Const(6), ex1);
   std::cout << ex2->ToString() << "\n";  // 6 * (3 * 4 + 5)
   std::cout << ex2->Evaluate() << "\n";  // 102
}
