#include <iostream>
#include <vector>
#include <cstdint>

template<typename T>
class AdvancedVector : public std::vector<T>
{
public:
   AdvancedVector() : std::vector<T>()
   {
   }

   template<typename Iter>
   AdvancedVector(Iter start, Iter stop) : std::vector<T>(start, stop) {}

   const T& operator[](std::int64_t index) const
   {
      if (index < 0)
         return this->at(this->size() + index);

      return this->at(index);
   }

   T& operator[](std::int64_t index)
   {
      if (index < 0)
         return this->at(this->size() + index);

      return this->at(index);
   }
};

int main()
{
   std::vector<int> v{1,2,3,4,5};
   AdvancedVector<int> v1;
   auto v2{v1};
   AdvancedVector<int> v3(v.begin(), v.end());

   AdvancedVector<int> v4 = v3;

   bool is_eq1 = v4 == v3;
   bool is_eq2 = v4 != v3;
   auto is_empty = v4.empty();
   auto ss = v4.size();



   std::cout << v3[-1] << std::endl;
   return 0;
}
