#include <chrono>
#include <iostream>

constexpr int DEFAULT_DATE_DAY = 1;
constexpr int DEFAULT_DATE_MONTH = 1;
constexpr int DEFAULT_DATE_YEAR = 1970;

bool isLeapYear(int year)
{
   return (!(year % 4) && year % 100) || !(year % 400);
}

int getDayOnMonth(int month, int year)
{
   switch (month)
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
      if (isLeapYear(year)) {
         return 29;
      } else {
         return 28;
      }
   default:
      return 30;
   }
}

int getDayOnYear(int year)
{
   if (isLeapYear(year))
      return 366;

   return 365;
}

class Date
{
public:
   Date(const int day, const int month, const int year) : m_day(day), m_month(month), m_year(year)
   {
      if (!IsCorrectDate())
      {
         m_year = DEFAULT_DATE_YEAR;
         m_month = DEFAULT_DATE_MONTH;
         m_day = DEFAULT_DATE_DAY;
      }
   }

   int GetYear() const { return m_year; }
   int GetMonth() const { return m_month; }
   int GetDay() const { return m_day; }

   Date operator+ (int d) const
   {
      d = this->GetTotalDays() + d;
      int month = DEFAULT_DATE_MONTH;
      int year = DEFAULT_DATE_YEAR;

      while (d > getDayOnYear(year))
      {
         d -= getDayOnYear(year);
         ++year;
      }

      while (d > getDayOnMonth(month, year))
      {
         d -= getDayOnMonth(month, year);
         ++month;
      }

      return Date{d, month, year};
   }

   Date operator- (int d) const
   {
      d = this->GetTotalDays() - d;
      int month = DEFAULT_DATE_MONTH;
      int year = DEFAULT_DATE_YEAR;

      while (d > getDayOnYear(year))
      {
         d -= getDayOnYear(year);
         ++year;
      }

      while (d > getDayOnMonth(month, year))
      {
         d -= getDayOnMonth(month, year);
         ++month;
      }

      return Date{d, month, year};
   }

   int operator- (const Date& rhs) const
   {
      return GetTotalDays() - rhs.GetTotalDays();
   }
private:
   bool IsCorrectDate() const {
      return GetMonth() <= 12 && GetMonth() >= 1
             && GetDay() <= getDayOnMonth(GetMonth(), GetYear())
             && GetDay() > 0;
   }

   int GetTotalDays() const
   {
      int totalDays = 0;
      for (int i = DEFAULT_DATE_YEAR; i < this->GetYear(); ++i)
      {
         totalDays += 365;
         if (isLeapYear(i))
            totalDays += 1;
      }

      for (int i = 1; i < this->GetMonth(); ++i)
      {
         totalDays += getDayOnMonth(i, this->GetYear());
      }

      totalDays += this->GetDay();
      return totalDays;
   }

   int m_day{DEFAULT_DATE_DAY};
   int m_month{DEFAULT_DATE_MONTH};
   int m_year{DEFAULT_DATE_YEAR};
};

int main()
{
   Date d(10,2,1999);


   std::cout << d.GetYear() << " " << d.GetMonth() << " " << d.GetDay() << std::endl;
   return 0;
}
