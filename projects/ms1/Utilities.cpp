// Name:  Reziyemu Sulaiman
// Seneca Student ID: 106-153-208
// Seneca email: rsulaiman2@myseneca.ca
// Date of completion: 2022-11-19
//
// I have done all the coding by myself and only copied the code that my classmate provided to complete my workshops and assignments.


#include <cstring>
#include "Utilities.h"

namespace sdds
{
	char Utilities::m_delimiter{ '\0' };

	void Utilities::setFieldWidth(size_t newWidth) {
		m_widthField = newWidth;
	}

	size_t Utilities::getFieldWidth() const {
		return m_widthField;
	}

	std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
		std::string token = str;
		char del = token.at(next_pos);
		if (del == m_delimiter)
		{
			more = false;
			throw std::string("Delimiter not found at") + std::to_string(next_pos);
		}
		else
		{
			token = str.substr(next_pos, str.size());
			token = token.substr(0, token.find_first_of(m_delimiter));
			next_pos += (token.size() + 1);
			if (next_pos >= str.size())
			{
				more = false;
			}
			m_widthField = m_widthField < token.size() ? token.size() : m_widthField;
		}
		return trim(token);
	}

	void Utilities::setDelimiter(char newDelimiter) {
		m_delimiter = newDelimiter;
	}

	char Utilities::getDelimiter() {
		return m_delimiter;
	}

	std::string Utilities::trim(std::string& str) const {
		str.erase(0, str.find_first_not_of(' '));
		str.erase(str.find_last_not_of(' ') + 1);
		return str;
	}



}