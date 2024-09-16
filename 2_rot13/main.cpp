#include <iostream>

using namespace std;

string rot13(string msg)
{
   unsigned int step = 13;
   for (auto& s : msg) {
      unsigned int code = (int)s;
      if (code >= (int)'A' && code <= (int)'Z') {
         if (code + step > (int)'Z')
         {
            s = (char) (code + step - (int)'Z' + (int)'A' - 1);
         }
         else
            s = (char)(code + step);
      }

      if (code >= (int)'a' && code <= (int)'z') {
         if (code + step > (int)'z')
            s = (char)(code + step - (int)'z' + (int)'a' - 1);
         else
            s = (char)(code + step);
      }
   }

   return msg;
}


int main()
{
//  char c;
//  std::cout<<"enter symbol:"<<std::endl;
//  std::cin>>c;
//
//  int code;
//  code = c - 'A';
//
//  std::cout<<"code of symbol is "<< (char)(c+1) <<
//       " and difference with 'A' is " << code << std::endl;
//  // в предыдущей строчке приведение к int нужно, иначе не сработает ООП-магия,
//  // т.к. cout - это очень хитрый объект, определяющий по типу выводимого
//  // выражения как его отобразить на экране

   cout << "Rot13: " << rot13("test") << endl;
   cout << "Rot13: " << rot13("Test") << endl;
   cout << "Rot13: " << rot13("AbCd") << endl;

   cout << "Rot13: " << (int)(('b'-'a'+13) % 26) << endl;

  return 1;
}