

#include "Racecar.h"

namespace sdds {
   Racecar::Racecar(std::istream& in) : Car(in) {
      std::string token{};
      std::getline(in, token);
      m_booster = std::stod(token);
   }
   void Racecar::display(std::ostream& out) const {
      Car::display(out);
      out << "*";
   }
   double Racecar::topSpeed() const {
      return Car::topSpeed() + (Car::topSpeed() * m_booster);
   }

} 