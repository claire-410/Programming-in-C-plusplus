// Name:  Reziyemu Sulaiman
// Seneca Student ID: 106-153-208
// Seneca email: rsulaiman2@myseneca.ca
// Date of completion: 2022-09-19
//
// I confirm that I am the only author of this file
// and the content was created entirely by me except the code provided by professor.

#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include <string>
#include <iomanip>
#include "carads.h"

using namespace std;
double g_taxrate;
double g_discount;

namespace sdds {
   static int counter = 0;

   void listArgs(int argc, char* argv[])
   {
      cout << "Command Line:" << '\n';
      cout << "--------------------------" << '\n';

      for (auto i = 0; i < argc; i++) {
         cout << "  " << i + 1 << ": " << argv[i] << endl;
      }
      cout << "--------------------------" << endl << endl;
   }


   std::istream& operator>>(std::istream& is, Cars& car)
   {
      car.read(is);

      return is;
   }


   void operator>>(const Cars& car1, Cars& car2)
   {
      car2 = car1;
   }


   Cars::Cars()
   {
      this->m_brand = "";
      this->m_model[0] = '\0';
      this->m_year = 0;
      this->m_price = 0.0;
      this->m_status = 0;
      this->m_isPromo = false;
      this->m_afterdisc = 0;
   }

   Cars::Cars(const Cars& other)
   {
      *this = other;
   }

   Cars::~Cars()
   {
      this->m_brand = "";
   }


   Cars& Cars::operator=(const Cars& other)
   {
      if (this != &other) {
         this->m_brand = other.m_brand;
         for (auto i = 0; i < 15; i++) {
            this->m_model[i] = other.m_model[i];
         }
         this->m_year = other.m_year;
         this->m_price = other.m_price;
         this->m_status = other.m_status;
         this->m_isPromo = other.m_isPromo;
      }

      return *this;
   }


   Cars::operator bool() const
   {
      return this->m_status == 'N';
   }


   void Cars::read(std::istream& is)
   {
      char status = '\0';

      if (is.good()) {
         is >> this->m_status;
         is.ignore();
         getline(is, this->m_brand, ',');
         is.getline(this->m_model, 15, ',');
         is >> this->m_year;
         is.ignore();
         is >> this->m_price;
         is.ignore();
         is >> status;
         this->m_isPromo = (status == 'Y' ? true : false);
      }
   }


   void Cars::display(bool reset)
   {
      if (reset) {
         counter = 0;
      }

      this->m_price = this->m_price + (this->m_price * g_taxrate);

      if (this->m_isPromo) {
         this->m_afterdisc = this->m_price - (this->m_price * g_discount);
      }
      else {
         this->m_afterdisc = 0;
      }

      if (this->m_brand != "" && this->m_model[0] != '\0') {
         counter++;
         cout << left << setw(2) << counter << ". ";
         cout << left << setw(10) << this->m_brand << "| ";
         cout << left << setw(15) << this->m_model << "| ";
         cout << this->m_year << " |";
         cout << fixed;
         cout << right << setw(12) << setprecision(2);
         cout << this->m_price << "|";
         cout << fixed;
         if (this->m_afterdisc != 0) {
            cout << right << setw(12) << setprecision(2);
            cout << this->m_afterdisc << endl;
            cout << fixed;
         }
         else {
            cout << endl;
         }
      }

   }


   char Cars::getStatus() const
   {
      return this->m_status;
   }





}