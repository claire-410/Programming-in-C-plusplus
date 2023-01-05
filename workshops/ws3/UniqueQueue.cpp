#include "UniqueQueue.h"


namespace sdds {
   template <> bool UniqueQueue<double>::push(const double& item) {
      bool unique = true;
      bool flag = false;
      for (std::size_t i = 0; i < Queue<double, 100u>::size(); i++) {
         if (std::fabs(item) <= std::fabs(Queue<double, 100u>::operator[](i)) + 0.005 &&
            std::fabs(item) >= std::fabs(Queue<double, 100u>::operator[](i)) - 0.005) {
            unique = false;
         }
      }
      if (unique) {
         flag = Queue<double, 100u>::push(item);
      }
      return flag;
   }





















}