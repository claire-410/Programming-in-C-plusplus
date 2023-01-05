// Name:  Reziyemu Sulaiman
// Seneca Student ID: 106-153-208
// Seneca email: rsulaiman2@myseneca.ca
// Date of completion: 2022-12-03
//
// I have done all the coding by myself and only copied the code that my classmate provided to complete my workshops and assignments.


#include "Workstation.h"

namespace sdds 
{
   std::deque<CustomerOrder> g_pending{};
   std::deque<CustomerOrder> g_completed{};
   std::deque<CustomerOrder> g_incomplete{};

    Workstation::Workstation(const std::string& str) : Station(str)
    {}

    void Workstation::fill(std::ostream& os)
    {
       if (!m_orders.empty()) {
          if (m_orders.size()) {
             m_orders.front().fillItem(*this, os);
          }
       }
    }

    bool Workstation::attemptToMoveOrder()
    {
       bool flag = false;

       if (!m_orders.empty()) {
          CustomerOrder& order = m_orders.front();

          if (order.isItemFilled(this->getItemName()) || this->getQuantity() == 0) {
             if (m_pNextStation) {
                *m_pNextStation += (std::move(order));
             }
             else 
             {
                if (order.isOrderFilled()) {
                   g_completed.push_back(std::move(order));
                }
                else {
                   g_incomplete.push_back(std::move(order));
                }
             }
             flag = true;
             m_orders.pop_front();
          }
       }

       return flag;
    }

    void Workstation::setNextStation(Workstation* station)
    {
       m_pNextStation = station;
    }

    Workstation* Workstation::getNextStation() const
    {
       return m_pNextStation;
    }

    void Workstation::display(std::ostream& os) const
    {
       if (!m_pNextStation)
       {
          os << getItemName() << " --> " << "End of Line" << std::endl;
       }
       else
       {
          os << getItemName() << " --> " << m_pNextStation->getItemName() << std::endl;
       }
    }

    Workstation& Workstation::operator+=(CustomerOrder&& newOrder)
    {
       m_orders.push_back(std::move(newOrder));
       return *this;
    }


}