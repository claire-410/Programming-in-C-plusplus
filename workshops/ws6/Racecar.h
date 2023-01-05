// Name:  Reziyemu Sulaiman
// Seneca Student ID: 106-153-208
// Seneca email: rsulaiman2@myseneca.ca
// Date of completion: 2022-11-10
//
// I have done all the coding by myself and only copied the code that my classmate provided to complete my workshops and assignments.


#ifndef SDDS_RACECAR_H
#define SDDS_RACECAR_H
#include "Car.h"

namespace sdds {
   class Racecar : public Car
   {
      double m_booster{};

   public:
      Racecar(std::istream& in);
      void display(std::ostream& out) const;
      double topSpeed() const;
   };
} 

#endif 