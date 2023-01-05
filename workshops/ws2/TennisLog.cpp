#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstring>
#include "TennisLog.h"

using namespace std;

namespace sdds {

   TennisMatch::operator bool() const
   {
      return (m_id != 0u && t_id != "");
   }


   std::ostream& operator<<(std::ostream& os, const TennisMatch& tennisMatch)
   {
      if (tennisMatch) {
         os << right << setw(20) << setfill('.') << "Tourney ID";
         os << " : ";
         os << left << setw(30) << setfill('.') << tennisMatch.t_id << endl;

         os << right << setw(20) << setfill('.') << "Match ID";
         os << " : ";
         os << left << setw(30) << setfill('.') << tennisMatch.m_id << endl;

         os << right << setw(20) << setfill('.') << "Tourney";
         os << " : ";
         os << left << setw(30) << setfill('.') << tennisMatch.t_name << endl;

         os << right << setw(20) << setfill('.') << "Winner";
         os << " : ";
         os << left << setw(30) << setfill('.') << tennisMatch.m_winner << endl;

         os << right << setw(20) << setfill('.') << "Loser";
         os << " : ";
         os << left << setw(30) << setfill('.') << tennisMatch.m_loser << endl;
      }
      else {
         os << "Empty Match";
      }

      return os;
   }


   TennisLog::TennisLog(const char* filename)
   {
      string str;
      unsigned int noOfMatch{ 0u };

      ifstream myFile(filename);

      if (myFile.is_open()) {
         getline(myFile, str);

         while (myFile) {
            getline(myFile, str);
            noOfMatch++;
         }
         noOfMatch--;

         matches = new TennisMatch[noOfMatch];
         myFile.clear();
         myFile.seekg(0);

         getline(myFile, str);

         while (myFile) {
            getline(myFile, str, ',');
            if (myFile) {
               matches[count].t_id = str;
               getline(myFile, str, ',');
               matches[count].t_name = str;
               getline(myFile, str, ',');
               matches[count].m_id = stoul(str);
               getline(myFile, str, ',');
               matches[count].m_winner = str;
               getline(myFile, str);
               matches[count].m_loser = str;
               count++;
            }
         }
         myFile.close();

      }
      else {
         cerr << "Error: Could not open file: " << filename << endl;
      }
   }


   TennisLog::TennisLog(const TennisLog& src)
   {
      *this = src;
   }

   TennisLog::TennisLog(TennisLog&& src) noexcept
   {
      *this = move(src);
   }

   TennisLog& TennisLog::operator=(const TennisLog& src)
   {
      if (this != &src) {
         delete[] matches;
         matches = new TennisMatch[src.count];
         for (auto i = 0u; i < src.count; i++) {
            matches[i] = src.matches[i];
         }
         count = src.count;
      }
      return *this;
   }

   TennisLog& TennisLog::operator=(TennisLog&& src) noexcept
   {
      if (this != &src) {
         delete[] matches;
         matches = src.matches;
         src.matches = nullptr;
         count = src.count;
         src.count = 0u;
      }
      return *this;
   }

   TennisLog::~TennisLog()
   {
      delete[] matches;
   }


   void TennisLog::addMatch(const TennisMatch& other)
   {
      TennisMatch* temp = new TennisMatch[count + 1];

      for (auto i = 0u; i < count; i++) {
         temp[i] = matches[i];
      }
      delete[] matches;

      matches = temp;
      matches[count] = other;
      count++;
   }


   TennisLog TennisLog::findMatches(const char* name) const
   {
      TennisLog log;

      for (auto i = 0u; i < count; i++) {
         if (strcmp(matches[i].m_winner.c_str(), name) == 0 ||
            strcmp(matches[i].m_loser.c_str(), name) == 0) {
            log.addMatch(matches[i]);
         }
      }

      return log;
   }


   TennisMatch TennisLog::operator[](size_t index) const
   {
      TennisMatch match;
      if (index >= 0 && index < count) {
         match = matches[index];
      }

      return match;
   }


   TennisLog::operator size_t() const
   {
      return count;
   }






























}