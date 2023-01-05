
// Name:  Reziyemu Sulaiman
// Seneca Student ID: 106-153-208
// Seneca email: rsulaiman2@myseneca.ca
// Date of completion: 2022-10-23
//
// I have done all the coding by myself and only copied the code that my classmate provided to complete my workshops and assignments.


#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H

#include <map>

namespace sdds {
	constexpr size_t size = 6;

	class SpellChecker {
		std::map<std::string, size_t>kvPair{};
		size_t m_size{};
		std::string m_badWords[size]{};
		std::string m_goodWords[size]{};
		void trim(const std::string& res, std::string& local) const;
	public:
		SpellChecker(const char* filename);
		void operator()(std::string& text);
		void showStatistics(std::ostream& out) const;
	};
}

#endif