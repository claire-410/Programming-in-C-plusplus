// Name:  Reziyemu Sulaiman
// Seneca Student ID: 106-153-208
// Seneca email: rsulaiman2@myseneca.ca
// Date of completion: 2022-11-10
//
// I have done all the coding by myself and only copied the code that my classmate provided to complete my workshops and assignments.


#ifndef SDDS_VEHICLE_H
#define SDDS_VEHICLE_H
#include <iostream>
#include <string>

namespace sdds {
   class Vehicle
   {
   public:
      virtual double topSpeed() const = 0;
      virtual void display(std::ostream&) const = 0;
      virtual std::string condition() const = 0;
      virtual ~Vehicle() {};
   };
} 

#endif