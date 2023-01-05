#define _CRT_SECURE_NO_WARNINGS


#include "Timer.h"


namespace sdds {

   void Timer::start()
   {
      m_start = std::chrono::system_clock::now();
   }


   long long Timer::stop()
   {
      auto end = std::chrono::system_clock::now();
      auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - m_start);

      return duration.count();
   }

}