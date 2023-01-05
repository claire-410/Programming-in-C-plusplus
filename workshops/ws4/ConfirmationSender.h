// Name:  Reziyemu Sulaiman
// Seneca Student ID: 106-153-208
// Seneca email: rsulaiman2@myseneca.ca
// Date of completion: 2022-10-13
//
// I have done all the coding by myself and only copied the code that my classmate provided to complete my workshops and assignments.


#ifndef SDDS_CONFIRMATIONSENDER_H
#define SDDS_CONFIRMATIONSENDER_H

#include "Reservation.h"
namespace sdds {
   class ConfirmationSender
   {
      const Reservation** m_reservations{};
      size_t m_count{};

   public:
      ConfirmationSender() = default;
      ConfirmationSender(const ConfirmationSender& cs);
      ConfirmationSender(ConfirmationSender&& cs);
      ~ConfirmationSender();
      ConfirmationSender& operator=(const ConfirmationSender& cs);
      ConfirmationSender& operator=(ConfirmationSender&& cs);
      ConfirmationSender& operator+=(const Reservation& res);
      ConfirmationSender& operator-=(const Reservation& res);
      friend std::ostream& operator<<(std::ostream& os,
         const ConfirmationSender& cs);
   };
} 

#endif //! SDDS_CONFIRMATIONSENDER_H