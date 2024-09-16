#include <iostream>
#include <string>
#include <map>
#include <vector>

std::string decomp(int n) {
   std::string result = "2";

   std::map<unsigned, unsigned> values;
   std::vector<unsigned> primes;

   for(unsigned i = 2; i <= n; ++i) {
      values[i] += false;

      for (unsigned j = 2; j < i; ++j){
         if (i % j == 0) {
            values[i] = true;
            break;
         }
      }

      if (!values[i])
         primes.push_back(i);
   }


   for(unsigned i = 2; i <= n; ++i) {
      if (!values[i]) {
         if (i > 2)
            result += (" * " + std::to_string(i));
         unsigned power = 1;
         for (unsigned j = i+i; j <= n; j += i) {
            unsigned j_to_del = j;
            while (j_to_del % i == 0) {
               j_to_del /= i;
               power += 1;
            }
         }
         if(power > 1)
            result += ("^" + std::to_string(power));
      }
   }

   return result;
}

int main()
{
   std::cout << decomp(14) << std::endl;
   return 0;
}
