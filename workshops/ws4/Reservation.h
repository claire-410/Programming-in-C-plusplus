// Name:  Reziyemu Sulaiman
// Seneca Student ID: 106-153-208
// Seneca email: rsulaiman2@myseneca.ca
// Date of completion: 2022-10-13
//
// I have done all the coding by myself and only copied the code that my classmate provided to complete my workshops and assignments.



#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H



#include <iostream>
#include <string>

constexpr int SIZE{ 11 }; 

namespace sdds {

   class Reservation
   {
      char m_id[SIZE]{};
      std::string m_name{};
      std::string m_email{};
      unsigned m_guestCount{};
      unsigned char m_day{};  // between 1-28
      unsigned char m_hour{}; // between 1-24
   public:
      Reservation()=default;
      Reservation(const std::string& res);
      void update(int day, int time);
      friend std::ostream& operator<<(std::ostream&, const Reservation&);
   };

} 


#endif 