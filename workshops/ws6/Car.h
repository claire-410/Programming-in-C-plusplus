// Name:  Reziyemu Sulaiman
// Seneca Student ID: 106-153-208
// Seneca email: rsulaiman2@myseneca.ca
// Date of completion: 2022-11-10
//
// I have done all the coding by myself and only copied the code that my classmate provided to complete my workshops and assignments.


#ifndef SDDS_CAR_H
#define SDDS_CAR_H

#include "Vehicle.h"

namespace sdds {
   class Car : public Vehicle
   {
      enum Condition { New, Used, Broken };
      std::string m_maker{};
      Condition m_condition{};
      double m_topSpeed{};

   public:
      Car() = default;
      Car(std::istream& is);
      std::string condition() const;
      double topSpeed() const;
      void display(std::ostream& out) const;
   };
} 

#endif 