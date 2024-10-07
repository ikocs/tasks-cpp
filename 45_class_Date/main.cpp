#include <iostream>

class Date
{
public:
   Date(const int day, const int month, const int year)
   {
      if (year >= 1970 && year <= 2099
         && month >= 1 && month <= 12
         && day >= 1 && day <= getDayOnMonth(month))
      {
         m_year = year;
         m_month = month;
         m_day = day;
      }
   }

   int GetYear() const { return m_year; }
   int GetMonth() const { return m_month; }
   int GetDay() const { return m_day; }
private:
   int m_year{1970};
   int m_month{1};
   int m_day{1};

   int getDayOnMonth(int mount) const
   {
      switch (m_month)
      {
      case 1:
      case 3:
      case 5:
      case 7:
      case 8:
      case 10:
      case 12:
         return 31;
      case 2:
         if ((m_year % 400 == 0 || m_year % 100 != 0) && m_year % 4 == 0) {
            return 29;
         } else {
            return 28;
         }
      default:
         return 30;
      }
   }

};

int main()
{
   Date d(1,2,1978);

   std::cout << d.GetYear() << " " << d.GetMonth() << " " << d.GetDay() << std::endl;
   return 0;
}
