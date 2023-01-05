// Name:  Reziyemu Sulaiman
// Seneca Student ID: 106-153-208
// Seneca email: rsulaiman2@myseneca.ca
// Date of completion: 2022-10-13
//
// I have done all the coding by myself and only copied the code that my classmate provided to complete my workshops and assignments.


#ifndef SDDS_RESTAURANT_H
#define SDDS_RESTAURANT_H

#include "Reservation.h"
namespace sdds {
   class Restaurant
   {
      size_t m_count{};
      Reservation** m_reservations{};
      void deallocate();

   public:
      Restaurant(const Reservation* reservations[], size_t count);
      Restaurant(const Restaurant& restaurant);
      Restaurant(Restaurant&& restaurant);
      ~Restaurant();
      Restaurant& operator=(const Restaurant& restaurant);
      Restaurant& operator=(Restaurant&& restaurant);
      size_t size() const;
      friend std::ostream& operator<<(std::ostream&, const Restaurant& restaurant);
   };

} 

#endif 