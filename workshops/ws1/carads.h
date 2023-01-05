// Name:  Reziyemu Sulaiman
// Seneca Student ID: 106-153-208
// Seneca email: rsulaiman2@myseneca.ca
// Date of completion: 2022-09-19
//
// I confirm that I am the only author of this file
// and the content was created entirely by me except the code provided by professor.


#ifndef _CARADS_H
#define _CARADS_H

#include <iostream>


extern double g_taxrate;
extern double g_discount;

namespace sdds {
   void listArgs(int argc, char* argv[]);

   class Cars {
      std::string m_brand;
      char m_model[15]{};
      int m_year{ 0 };
      double m_price{ 0.0 };
      char m_status;
      bool m_isPromo{};
      double m_afterdisc;
   public:
      Cars();
      Cars(const Cars& other);
      ~Cars();
      Cars& operator=(const Cars& other);
      operator bool() const;
      void read(std::istream& is);
      void display(bool reset);
      char getStatus() const;
   };

   std::istream& operator>>(std::istream& is, Cars& car);
   void operator>>(const Cars& car1, Cars& car2);

}










#endif // !_CARADS_H_

