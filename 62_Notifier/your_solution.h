#ifndef YOUR_SOLUTION_H
#define YOUR_SOLUTION_H

#include <string>

class NotifierBase
{
public:
   virtual ~NotifierBase() = default;

   virtual void Notify(const std::string& msg) const = 0;
};

class SmsNotifier final : public NotifierBase
{
public:
   SmsNotifier(const std::string& number) : m_number(number) {}
   ~SmsNotifier() override = default;

   void Notify(const std::string& msg) const override
   {
      SendSms(m_number, msg);
   }

private:
   std::string m_number;
};

class EmailNotifier final : public NotifierBase
{
public:
   EmailNotifier(const std::string& mail) : m_mail(mail) {}
   ~EmailNotifier() override = default;

   void Notify(const std::string& msg) const override
   {
      SendEmail(m_mail, msg);
   }

private:
   std::string m_mail;
};

#endif //YOUR_SOLUTION_H
