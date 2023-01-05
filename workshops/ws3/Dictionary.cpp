#include <iostream>
#include "Dictionary.h"


namespace sdds {

   bool Dictionary::operator==(const Dictionary& dic) const
   {
      return m_term.compare(dic.m_term) == 0 && m_definition.compare(dic.m_definition) == 0;
   }



   std::ostream& operator<<(std::ostream& os, const Dictionary& dic)
   {
      os.width(20);
      os << std::right << dic.getTerm();
      os << ": " << dic.getDefinition();


      return os;

   }

}