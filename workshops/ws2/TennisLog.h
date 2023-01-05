#ifndef _TENNISLOG_H_
#define _TENNISLOG_H_

#include <iostream>


namespace sdds {

   struct TennisMatch {
      std::string t_id{""};    // Tournament ID
      std::string t_name{""};  // Tournament Name
      unsigned int m_id{0u};    // Match ID
      std::string m_winner{ "" };  // Winner of the match
      std::string m_loser{ "" };  // Loser of the match
      operator bool()const;
   };

   std::ostream& operator<<(std::ostream& os, const TennisMatch& tennisMatch);


   class TennisLog {
      TennisMatch* matches{nullptr};
      unsigned int count{0u};
   public:
      TennisLog() = default;
      TennisLog(const char* filename);
      // Rule of 5
      TennisLog(const TennisLog& src);   // copy constructor
      TennisLog(TennisLog&& src) noexcept;   // move constructor
      TennisLog& operator=(const TennisLog& src);  // copy assignment
      TennisLog& operator=(TennisLog&& src) noexcept;       // move assignment
      ~TennisLog();
      // member functions
      void addMatch(const TennisMatch& other);
      TennisLog findMatches(const char* name)const;    
      TennisMatch operator[](size_t index)const;  //
      operator size_t()const;

   };












}



#endif