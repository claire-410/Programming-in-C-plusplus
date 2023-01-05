// Name:  Reziyemu Sulaiman
// Seneca Student ID: 106-153-208
// Seneca email: rsulaiman2@myseneca.ca
// Date of completion: 2022-10-13
//
// I have done all the coding by myself and only copied the code that my classmate provided to complete my workshops and assignments.


#include "Restaurant.h"

namespace sdds {
   
   void Restaurant::deallocate() {
      for (size_t i = 0; i < m_count; i++) {
         delete m_reservations[i];
      }
      delete[] m_reservations;
   }

  
   Restaurant::~Restaurant() { deallocate(); }

   
   Restaurant::Restaurant(const Reservation* reservations[], size_t count) {
     
      m_reservations = new Reservation * [count];
      for (size_t i = 0; i < count; i++) {
         m_reservations[i] = new Reservation;
         *m_reservations[i] = *reservations[i];
      }
      m_count = count;
   }

   
   Restaurant::Restaurant(const Restaurant& restaurant) { *this = restaurant; }

  
   Restaurant::Restaurant(Restaurant&& restaurant) {
      *this = std::move(restaurant);
   }

   
   Restaurant& Restaurant::operator=(const Restaurant& restaurant) {
      if (this != &restaurant) {
         deallocate();
         m_reservations = new Reservation * [restaurant.m_count];
         for (size_t i = 0; i < restaurant.m_count; i++) {
            m_reservations[i] = new Reservation;
            *m_reservations[i] = *restaurant.m_reservations[i];
         }
         m_count = restaurant.m_count;
      }
      return *this;
   }

   
   Restaurant& Restaurant::operator=(Restaurant&& restaurant) {
      if (this != &restaurant) {
         deallocate();
         m_count = restaurant.m_count;
         m_reservations = restaurant.m_reservations;
         restaurant.m_reservations = nullptr;
         restaurant.m_count = 0;
      }
      return *this;
   }

   
   size_t Restaurant::size() const { return m_count; }

 
   std::ostream& operator<<(std::ostream& os, const Restaurant& restaurant) {
      static unsigned called = 0;
      called++;
      os << "--------------------------\nFancy Restaurant (" << called
         << ")\n--------------------------\n";
      if (restaurant.m_count > 0) {
         for (size_t i = 0; i < restaurant.m_count; i++) {
            os << *restaurant.m_reservations[i];
         }
      }
      else {
         os << "This restaurant is empty!\n";
      }

      os << "--------------------------\n";

      return os;
   }

} 