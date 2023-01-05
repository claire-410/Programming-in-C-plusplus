// Name:  Reziyemu Sulaiman
// Seneca Student ID: 106-153-208
// Seneca email: rsulaiman2@myseneca.ca
// Date of completion: 2022-11-10
//
// I have done all the coding by myself and only copied the code that my classmate provided to complete my workshops and assignments.


#include "Utilities.h"
#include "Car.h"
#include "Luxuryvan.h"
#include "Racecar.h"
#include "Van.h"
#include <sstream>

namespace sdds {

   std::string& trim(std::string& str) {
      bool trimmed = false;

      while (!trimmed) {
         trimmed = true;
         if (str.find(' ') == 0) {
            trimmed = false;
            str.erase(str.begin());
         }
         if (str.size() > 0 &&
            str.substr(str.size() - 1, 1).find(' ') != std::string::npos) {
            str.erase(str.end() - 1);
            trimmed = false;
         }
      }
      return str;
   }


   Vehicle* createInstance(std::istream& is) {
      Vehicle* v{};
      std::string line{};
      std::getline(is, line);
      if (line.length() > 0) {
         std::istringstream ss(line);
         line = trim(line);
         if (line[0] == 'c' || line[0] == 'C') {
            v = new Car(ss);
         }
         else if (line[0] == 'v' || line[0] == 'V') {
            v = new Van(ss);
         }
         else if (line[0] == 'r' || line[0] == 'R') {
            v = new Racecar(ss);
         }
         else if (line[0] == 'l' || line[0] == 'L') {
            v = new Luxuryvan(ss);
         }
         else {
            throw("Unrecognized record type: [" + line.substr(0, 1) + "]");
         }
      }
      return v;
   }
} 