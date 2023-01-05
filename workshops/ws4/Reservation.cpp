// Name:  Reziyemu Sulaiman
// Seneca Student ID: 106-153-208
// Seneca email: rsulaiman2@myseneca.ca
// Date of completion: 2022-10-13
//
// I have done all the coding by myself and only copied the code that my classmate provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include "Reservation.h"

namespace sdds {

   std::string& trim(std::string& str) {
      bool flag = false;

      while (!flag) {
         flag = true;
         if (str.find(' ') == 0) {
            flag = false;
            str.erase(str.begin());
         }
         if (str.substr(str.size() - 1, 1).find(' ') != std::string::npos) {
            str.erase(str.end() - 1);
            flag = false;
         }
      }
      return str;
   }

  
   Reservation::Reservation(const std::string& res) {
      std::string temp = res; 

      size_t left = 0;             
      size_t right = res.find(":"); 
      std::string id = temp.substr(left, right - left); 
      id = trim(id); 
      strcpy(m_id, id.c_str());
      
      left = right;
      right = res.find(",", left + 1);
      m_name = res.substr(left + 1, right - left - 1); 
      m_name = trim(m_name);                           
      left = right;
      right = res.find(",", left + 1); 
      m_email = res.substr(left + 1, right - left - 1);
      m_email = trim(m_email);
      left = right;
      right = res.find(",", left + 1);
      m_guestCount = std::stoi(res.substr(
         left + 1, right - left - 1)); 
      left = right;
      right = res.find(",", left + 1);
      m_day = std::stoi(res.substr(left + 1, right - left - 1));
      left = right;
      right = res.find('\n', left + 1);
      m_hour = std::stoi(res.substr(left + 1));
   }

   
   void Reservation::update(int day, int time) {
      m_day = day;
      m_hour = time;
   }

   std::ostream& operator<<(std::ostream& os, const Reservation& res) {
      os << "Reservation ";
      os.width(10);
      os << std::right << res.m_id << ": ";
      os.width(20);
      os << std::right << res.m_name;
      os << std::left << "  <" << std::left << res.m_email << "> ";
      for (int i = res.m_email.length(); i <= 20; i++) {
         os << " ";
      }

      if (res.m_hour >= 6 && res.m_hour <= 9) {
         os << "Breakfast ";
      }
      else if (res.m_hour >= 11 && res.m_hour <= 15) {
         os << "Lunch ";
      }
      else if (res.m_hour >= 17 && res.m_hour <= 21) {
         os << "Dinner ";
      }
      else {
         os << "Drinks ";
      }
      os << "on day " << (int)res.m_day << " @ " << (int)res.m_hour << ":00 for "
         << res.m_guestCount
         << (res.m_guestCount == 1 ? " person.\n" : " people.\n");

      return os;
   }
} 