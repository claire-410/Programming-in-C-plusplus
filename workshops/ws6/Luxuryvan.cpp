

#include "Luxuryvan.h"
#include "Utilities.h"

namespace sdds {
   Luxuryvan::Luxuryvan(std::istream& in) : Van(in) {
      std::string temp{};
      std::getline(in, temp);
      temp = trim(temp);
      if (temp[0] != 'e') {
         throw("Invalid record!");
      }
      m_consumption = temp;
   }
   void Luxuryvan::display(std::ostream& out) const {
      Van::display(out);
      out << (m_consumption[0] == 'e' ? " electric van  *" : "");
   }
   std::string Luxuryvan::consumption() const { return m_consumption; }
} 