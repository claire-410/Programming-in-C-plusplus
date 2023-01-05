// Name:  Reziyemu Sulaiman
// Seneca Student ID: 106-153-208
// Seneca email: rsulaiman2@myseneca.ca
// Date of completion: 2022-11-17
//
// I have done all the coding by myself and only copied the code that my classmate provided to complete my workshops and assignments.



#include "CrimeStatistics.h"
#include <fstream>
#include <numeric>
#include <algorithm>
#include <cstring>

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

  
   CrimeStatistics::CrimeStatistics(const char* filename) {
      std::ifstream file(filename);

      if (file) {
         while (file) {
            Crime crime{};
            char buffer[26];
            std::string token{};
            file.get(buffer, 26);
            token = std::string(buffer);
            token = trim(token);
            crime.province = token;
            file.get(buffer, 26);
            token = std::string(buffer);
            token = trim(token);
            crime.district = token;
            file.get(buffer, 26);
            token = std::string(buffer);
            token = trim(token);
            crime.crime = token;
            file.get(buffer, 6);
            crime.year = atoi(buffer);
            file.get(buffer, 6);
            crime.numCases = atoi(buffer);
            file.get(buffer, 6);
            crime.m_resolved = atoi(buffer);
            std::getline(file, token);
            m_crimes.push_back(crime);
         }
      }
      else {
         throw("Error: Invalid file name!");
      }

   }

   void CrimeStatistics::display(std::ostream& out) const {
      for (auto it = m_crimes.cbegin(); it < m_crimes.cend(); it++) {
         out << *it << std::endl;
      }
      unsigned total{};
     
      total = std::accumulate(m_crimes.cbegin(), m_crimes.cend(), 0, [](unsigned x, Crime y) {
         return x + y.numCases;
         });
      out << "----------------------------------------------------------------------------------------" << std::endl;
      out << "|                                                                 Total Crimes:";
      out.width(7);
      out << std::right << total << " |" << std::endl;
      
      total = std::accumulate(m_crimes.cbegin(), m_crimes.cend(), 0, [](unsigned x, Crime y) {
         return x + y.m_resolved;
         });
      out << "|                                                         Total Resolved Cases:";
      out.width(7);
      out << std::right << total << " |" << std::endl;
   }

   void CrimeStatistics::sort(const char* field) {
      if (strcmp(field, "Province") == 0) {
         std::sort(m_crimes.begin(), m_crimes.end(), [](Crime m, Crime n) {
            return m.province < n.province;
            });
      }
      else if (strcmp(field, "Crime") == 0) {
         std::sort(m_crimes.begin(), m_crimes.end(), [](Crime m, Crime n) {
            return m.crime < n.crime;
            });
      }
      else if (strcmp(field, "Cases") == 0) {
         std::sort(m_crimes.begin(), m_crimes.end(), [](Crime m, Crime n) {
            return m.numCases < n.numCases;
            });
      }
      else if (strcmp(field, "Resolved") == 0) {
         std::sort(m_crimes.begin(), m_crimes.end(), [](Crime m, Crime n) {
            return m.m_resolved < n.m_resolved;
            });
      }
   }

   bool CrimeStatistics::inCollection(const char* crime) const {
      return std::count_if(m_crimes.cbegin(), m_crimes.cend(), [=](Crime c) {
         return c.crime == crime;
         }) > 0;
   }

   std::list<Crime> CrimeStatistics::getListForProvince(const char* province) const {
      std::size_t size = std::count_if(m_crimes.cbegin(), m_crimes.cend(), [=](Crime c) {
         return c.province.compare(province) == 0;
         });
      std::list<Crime> temp(size);
      std::copy_if(m_crimes.cbegin(), m_crimes.cend(), temp.begin(), [=](Crime c) {
         return strcmp(c.province.c_str(), province) == 0;
         });
      return temp;
   }

   void CrimeStatistics::cleanList() {
      std::vector<Crime> temp(m_crimes.size());
      std::transform(m_crimes.cbegin(), m_crimes.cend(), temp.begin(), [](Crime c) {
         if (c.crime.compare("[None]") == 0) {
            c.crime = "";
         }
         return c;
         });
      m_crimes = temp;
   }

   std::ostream& operator<<(std::ostream& out, const Crime& crime) {
      out << "| ";
      out.width(21);
      out.fill(' ');
      out << std::left << crime.province << " | ";
      out.width(15);
      out << crime.district << " | ";
      out.width(20);
      out << crime.crime << " | ";
      out.width(6);
      out << std::right << crime.year << " | ";
      out.width(4);
      out << crime.numCases << " | ";
      out.width(3);
      out << crime.m_resolved << " |";
      return out;
   }
}


