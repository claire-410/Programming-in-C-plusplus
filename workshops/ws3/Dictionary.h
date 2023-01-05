#ifndef _DICTIONARY_H
#define _DICTIONARY_H

#include <string>


namespace sdds {
   class Dictionary
   {
      std::string m_term{};
      std::string m_definition{};
   public:
      Dictionary() = default;
      const std::string& getTerm() const { return m_term; }
      const std::string& getDefinition() const { return m_definition; }
      Dictionary(const std::string& term, const std::string& definition) : m_term{ term }, m_definition{ definition } {}
      bool operator==(const Dictionary& dic) const;
   };

   std::ostream& operator<<(std::ostream& os, const Dictionary& dic);


}

















#endif




