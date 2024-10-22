#ifndef SOME_LONG_STUFF_H
#define SOME_LONG_STUFF_H

#include <chrono>
#include <iostream>
#include <string>
#include <utility>

class TimerGuard
{
private:
   std::chrono::time_point<std::chrono::high_resolution_clock> m_start;
   std::string m_msg;
   std::ostream& m_out;

public:
   TimerGuard(std::string message = "", std::ostream& out = std::cout) :
      m_start(std::chrono::high_resolution_clock::now()),
      m_msg(std::move(message)),
      m_out(out)
   {
   }

   ~TimerGuard()
   {
      auto end = std::chrono::high_resolution_clock::now();
      std::chrono::duration<double> diff = end - m_start;
      m_out << m_msg << " " << diff.count() << "\n";
   }
};

#endif //SOME_LONG_STUFF_H
