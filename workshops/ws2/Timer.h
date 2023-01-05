#ifndef _TIMER_H_
#define _TIMER_H_

#include <chrono>


namespace sdds {

   class Timer
   {
      std::chrono::time_point<std::chrono::system_clock> m_start;
   public:
      void start();
      long long stop();
   };

}


#endif