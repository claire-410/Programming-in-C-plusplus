

#include "Car.h"
#include "Utilities.h"

namespace sdds {
  
   Car::Car(std::istream& is) {
      std::string token{};
      std::getline(is, token, ',');

      
      std::getline(is, token, ',');
      token = trim(token);
      m_maker = token;

     
      std::getline(is, token, ',');
      token = trim(token);
      if (token.find_first_not_of(' ') == std::string::npos) {
         m_condition = New;
      }
      else if (token[0] == 'n') {
         m_condition = New;
      }
      else if (token[0] == 'u') {
         m_condition = Used;
      }
      else if (token[0] == 'b') {
         m_condition = Broken;
      }
      else {
         throw("Invalid record!");
      }

     
      std::getline(is, token, ',');
      token = trim(token);
      try {

         m_topSpeed = std::stod(token);
      }
      catch (...) {
         throw("Invalid record!");
      }
      
   }

   
   std::string Car::condition() const {
      return (m_condition == New ? "new"
         : (m_condition == Used ? "used" : "broken"));
   }

  
   double Car::topSpeed() const { return m_topSpeed; }

   
   void Car::display(std::ostream& out) const {
      out << "| ";
      out.width(10);
      out << std::right << m_maker << " | ";
      out.width(6);
      out << std::left
         << (m_condition == New ? "new"
            : (m_condition == Used ? "used" : "broken"))
         << " | ";
      out.precision(2);
      out.width(6);
      out << std::fixed << topSpeed() << " |";
   }
} 