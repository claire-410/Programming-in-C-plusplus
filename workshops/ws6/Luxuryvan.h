// Name:  Reziyemu Sulaiman
// Seneca Student ID: 106-153-208
// Seneca email: rsulaiman2@myseneca.ca
// Date of completion: 2022-11-10
//
// I have done all the coding by myself and only copied the code that my classmate provided to complete my workshops and assignments.


#ifndef SDDS_LUXURYVAN_H
#define SDDS_LUXURYVAN_H
#include "Van.h"

namespace sdds {
   class Luxuryvan : public Van
   {
      std::string m_consumption{};

   public:
      Luxuryvan(std::istream& in);
      void display(std::ostream& out) const;
      std::string consumption() const;
   };
} 

#endif 