// Name:  Reziyemu Sulaiman
// Seneca Student ID: 106-153-208
// Seneca email: rsulaiman2@myseneca.ca
// Date of completion: 2022-11-10
//
// I have done all the coding by myself and only copied the code that my classmate provided to complete my workshops and assignments.


#include "Van.h"
#include "Utilities.h"

namespace sdds {
  
   Van::Van(std::istream& is) {
      std::string token{};
      std::getline(is, token, ',');
      std::getline(is, token, ',');
      token = trim(token);
      m_maker = token;

      
      std::getline(is, token, ',');
      token = trim(token);
      if (token[0] == 'p') {
         m_type = Pickup;
      }
      else if (token[0] == 'm') {
         m_type = Minibus;
      }
      else if (token[0] == 'c') {
         m_type = Camper;
      }
      else {
         throw("Invalid record!");
      }

     
      std::getline(is, token, ',');
      token = trim(token);
      if (token[0] == 'd') {
         m_purpose = Delivery;
      }
      else if (token[0] == 'p') {
         m_purpose = Passenger;
      }
      else if (token[0] == 'c') {
         m_purpose = Camping;
      }
      else {
         throw("Invalid record!");
      }

     
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

   std::string Van::condition() const {
      return (m_condition == New ? "new"
         : (m_condition == Used ? "used" : "broken"));
   }

   
   std::string Van::type() const {
      return (m_type == Pickup ? "pickup"
         : (m_type == Minibus ? "mini-bus" : "camper"));
   }

  
   std::string Van::usage() const {
      return (m_purpose == Delivery
         ? "delivery"
         : (m_purpose == Passenger ? "passenger" : "camping"));
   }

  
   double Van::topSpeed() const { return m_topSpeed; }

  
   void Van::display(std::ostream& out) const {
      out << "| ";
      out.width(8);
      out << std::right << m_maker << " | ";
      out.width(12);
      out << std::left
         << (m_type == Pickup ? "pickup"
            : (m_type == Minibus ? "mini-bus" : "camper"))
         << " | ";
      out.width(12);
      out << std::left
         << (m_purpose == Delivery
            ? "delivery"
            : (m_purpose == Passenger ? "passenger" : "camping"))
         << " | ";
      out.width(6);
      out << std::left
         << (m_condition == New ? "new"
            : (m_condition == Used ? "used" : "broken"))
         << " | ";
      out.precision(2);
      out.width(6);
      out << std::fixed << m_topSpeed << " |";
   }
} 