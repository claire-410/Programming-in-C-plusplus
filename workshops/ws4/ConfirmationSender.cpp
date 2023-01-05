// Name:  Reziyemu Sulaiman
// Seneca Student ID: 106-153-208
// Seneca email: rsulaiman2@myseneca.ca
// Date of completion: 2022-10-13
//
// I have done all the coding by myself and only copied the code that my classmate provided to complete my workshops and assignments.


#include "ConfirmationSender.h"

namespace sdds {
   ConfirmationSender::~ConfirmationSender() { delete[] m_reservations; }

   
   ConfirmationSender::ConfirmationSender(const ConfirmationSender& cs) {
      *this = cs;
   }

  
   ConfirmationSender::ConfirmationSender(ConfirmationSender&& cs) {
      *this = std::move(cs);
   }

  
   ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& cs) {
      if (this != &cs) {
         delete[] m_reservations;
         m_count = cs.m_count;
         m_reservations = new const Reservation * [m_count];
         for (size_t i = 0; i < m_count; i++) {
            m_reservations[i] = cs.m_reservations[i];
         }
      }
      return *this;
   }

   
   ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& cs) {
      if (this != &cs) {
         delete[] m_reservations;
         m_count = cs.m_count;
         m_reservations = cs.m_reservations;
         cs.m_reservations = nullptr;
         cs.m_count = 0;
      }
      return *this;
   }

  
   ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res) {
      bool exists = false;
      for (size_t i = 0; i < m_count && !exists; i++) {
         if (m_reservations[i] == &res) {
            exists = true;
         }
      }
      
      if (!exists) {
         const Reservation** temp = new const Reservation * [m_count + 1];
         for (size_t i = 0; i < m_count; i++) {
            temp[i] = m_reservations[i];
         }
         temp[m_count++] = &res;
         delete[] m_reservations;
         m_reservations = temp;
      }
      return *this;
   }


   ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res) {
      bool exists = false;
      size_t i;
      
      for (i = 0; i < m_count && !exists; i++) {
         if (m_reservations[i] == &res) {
            exists = true;
         }
      }
      
      if (exists) {
         const Reservation** temp = new const Reservation * [m_count - 1];
         i--;
         --m_count;
         for (size_t j = i; j < m_count; j++) {
            m_reservations[j] = m_reservations[j + 1];
         }
         for (size_t j = 0; j < m_count; j++) {
            temp[j] = m_reservations[j];
         }
         delete[] m_reservations;
         m_reservations = temp;
      }

      return *this;
   }

 
   std::ostream& operator<<(std::ostream& os, const ConfirmationSender& cs) {
      os << "--------------------------\nConfirmations to "
         "Send\n--------------------------\n";
      if (cs.m_count > 0) {
         for (size_t i = 0; i < cs.m_count; i++) {
            os << *cs.m_reservations[i];
         }
      }
      else {
         os << "There are no confirmations to send!\n";
      }
      os << "--------------------------\n";

      return os;
   }
} 