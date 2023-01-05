#ifndef _UNIQUEQUEUE_H
#define _UNIQUEQUEUE_H

#include <cmath>
#include "Queue.h"


namespace sdds {
   template <typename T> 
   class UniqueQueue : public Queue<T, 100u>
   {
   public:
      UniqueQueue() = default;
      ~UniqueQueue() {}
      virtual bool push(const T& item) {
         bool unique = true;
         bool flag = false;

         for (size_t i = 0; i < Queue<T, 100u>::size(); i++) {
            if (item == Queue<T, 100u>::operator[](i)) {
               unique = false;
            }
         }
         if (unique) {
            flag = Queue<T, 100u>::push(item);
         }
         return flag;
      };
   };



   template <> 
   inline bool UniqueQueue<double>::push(const double& item) {
      bool unique = true;
      bool flag = false;
      for (size_t i = 0; i < Queue<double, 100u>::size(); i++) {
         if (std::fabs(item) <=
            std::fabs(Queue<double, 100u>::operator[](i)) + 0.005 &&
            std::fabs(item) >=
            std::fabs(Queue<double, 100u>::operator[](i)) - 0.005) {
            unique = false;
         }
      }
      if (unique) {
         flag = Queue<double, 100u>::push(item);
      }
      return flag;
   }










}























#endif



