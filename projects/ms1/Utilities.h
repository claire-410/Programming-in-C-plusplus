// Name:  Reziyemu Sulaiman
// Seneca Student ID: 106-153-208
// Seneca email: rsulaiman2@myseneca.ca
// Date of completion: 2022-11-19
//
// I have done all the coding by myself and only copied the code that my classmate provided to complete my workshops and assignments.


#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H
#include <string>

namespace sdds
{
	class Utilities {
		size_t m_widthField{ 1 };
		static char m_delimiter;
	public:
		void setFieldWidth(size_t newWidth);
		size_t getFieldWidth() const;
		std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
		static void setDelimiter(char newDelimiter);
		static char getDelimiter();
		std::string trim(std::string& str) const;
	};

}

#endif