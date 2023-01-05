// Name:  Reziyemu Sulaiman
// Seneca Student ID: 106-153-208
// Seneca email: rsulaiman2@myseneca.ca
// Date of completion: 2022-12-03
//
// I have done all the coding by myself and only copied the code that my classmate provided to complete my workshops and assignments.


#ifndef SDDS_LINEMANAGER_H
#define SDDS_LINEMANAGER_H

#include <vector>
#include <iostream>
#include "Workstation.h"

namespace sdds 
{
   class LineManager {
      std::vector<Workstation*> m_activeLine;
      size_t m_cntCustomerOrder{};
      Workstation* m_firstStation{};
   public:
      LineManager(const std::string& file, const std::vector<Workstation*>& stations);
      void reorderStations();
      bool run(std::ostream& os);
      void display(std::ostream& os) const;   
   };

}

#endif