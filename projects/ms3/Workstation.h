// Name:  Reziyemu Sulaiman
// Seneca Student ID: 106-153-208
// Seneca email: rsulaiman2@myseneca.ca
// Date of completion: 2022-12-03
//
// I have done all the coding by myself and only copied the code that my classmate provided to complete my workshops and assignments.


#ifndef SDDS_WORKSTATION_H
#define SDDS_WORKSTATION_H

#include <deque>
#include <iostream>
#include "Station.h"
#include "CustomerOrder.h"

namespace sdds {
   extern std::deque<CustomerOrder> g_pending;
   extern std::deque<CustomerOrder> g_completed;
   extern std::deque<CustomerOrder> g_incomplete;

   class Workstation: public Station
   {
      std::deque<CustomerOrder> m_orders;
      Workstation* m_pNextStation{};
   public:
      Workstation(const std::string& str);
      Workstation(const Workstation&) = delete;
      Workstation& operator=(const Workstation&) = delete;
      Workstation(Workstation&&) = delete;
      Workstation& operator=(Workstation&&) = delete;

      void fill(std::ostream& os);
      bool attemptToMoveOrder();
      void setNextStation(Workstation* station = nullptr);
      Workstation* getNextStation() const;
      void display(std::ostream& os) const;
      Workstation& operator+=(CustomerOrder&& newOrder);

   };
}

#endif