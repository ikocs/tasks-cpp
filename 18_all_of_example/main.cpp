#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
   vector<int> v1{1,3,5,7,19,99,123,89};
   vector<int> v2{1,3,5,7,19,99,123,89,8};
   short delimeter = 2;

   if(all_of(v1.cbegin(), v1.cend(),
             [&](const auto& value){ return value % delimeter != 0; }))
      cout << "V1 - correct vector" << endl;
   else
      cout << "V1 - NOT correct vector" << endl;

   if(all_of(v2.cbegin(), v2.cend(),
             [&](const auto& value){ return value % delimeter != 0; }))
      cout << "V2 - correct vector" << endl;
   else
      cout << "V2 - NOT correct vector" << endl;

   return 0;
}
