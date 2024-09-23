#include <iostream>

template <typename InIter1, typename InIter2, typename OutIter>
OutIter SetDifference(InIter1 first1, InIter1 last1,
                      InIter2 first2, InIter2 last2,
                      OutIter out)
{
   auto it1 = first1;
   auto it2 = first2;

   while (it1 != last1)
   {
      while (it2 != last2 && *it2 < *it1)
      {
         ++it2;
      }

      if (it2 == last2 || *it1 < *it2) {
         *out = *it1;
         ++out;
      } else if (it2 != last2) {
         ++it2;
      }
      ++it1;
   }
   return out;
}

int main()
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
