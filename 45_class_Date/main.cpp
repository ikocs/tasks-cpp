#include <iostream>
#include <tuple>

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
   Date(int day, int month, int year)
   {
      if (!IsCorrectDate(day, month, year))
      {
         day = 0;
      }
      else
      {
         m_day = 0;
         for (int i = DEFAULT_DATE_YEAR; i < year; ++i)
         {
            m_day += getDayOnYear(i);
         }
         m_day += DaysPassedToMonth(month, year) + day;
      }
   }

   int GetYear() const { return std::get<2>(this->ToDateTuple()); }
   int GetMonth() const { return std::get<1>(this->ToDateTuple()); }
   int GetDay() const { return std::get<0>(this->ToDateTuple()); }

   Date operator+ (int d) const
   {
      Date result(*this);
      result.SetFromDays(result.GetTotalDays() + d);
      return result;
   }

   Date operator- (int d) const
   {
      Date result(*this);
      result.SetFromDays(result.GetTotalDays() - d);
      return result;
   }

   int operator- (const Date& rhs) const
   {
      return GetTotalDays() - rhs.GetTotalDays();
   }
private:
   int m_day{0};
   // int m_month{DEFAULT_DATE_MONTH};
   // int m_year{DEFAULT_DATE_YEAR};

   bool IsCorrectDate(const int day, const int month, const int year) const {
      return month <= 12 && month >= 1
             && day <= getDayOnMonth(month, year)
             && day > 0;
   }

   bool IsCorrectDate() const {
      return IsCorrectDate(GetDay(), GetMonth(), GetYear());
   }

   int GetTotalDays() const
   {
      return m_day;
   }

   int DaysPassedToMonth(int month, int year) const {
      int result = 0;
      for (int i = 1; i < month; ++i)
      {
         result += getDayOnMonth(i, year);
      }
      return result;
   }

   std::tuple<int, int, int> ToDateTuple() const
   {
      auto d = m_day;
      int month = DEFAULT_DATE_MONTH;
      int year = DEFAULT_DATE_YEAR;

      while (d > getDayOnYear(year))
      {
         d -= getDayOnYear(year);
         ++year;
      }

      while (d > DaysPassedToMonth(month + 1, year))
         ++month;

      d -= DaysPassedToMonth(month, year);
      return {d, month, year};
   }

   void SetFromDays(int days)
   {
      m_day = days;
   }
};


int main()
{
   Date d(31,1,1970);

   std::cout << d.GetYear() << " " << d.GetMonth() << " " << d.GetDay() << std::endl;

   d = d + 1;
   std::cout << d.GetYear() << " " << d.GetMonth() << " " << d.GetDay() << std::endl;

   Date d2(1,11,1970);
   std::cout << d2.GetYear() << " " << d2.GetMonth() << " " << d2.GetDay() << std::endl;

   d2 = d2 - 1;
   std::cout << d2.GetYear() << " " << d2.GetMonth() << " " << d2.GetDay() << std::endl;

   Date d3(1,1,1970);
   std::cout << d3.GetYear() << " " << d3.GetMonth() << " " << d3.GetDay() << std::endl;
   return 0;
}
