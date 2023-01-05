// Name:  Reziyemu Sulaiman
// Seneca Student ID: 106-153-208
// Seneca email: rsulaiman2@myseneca.ca
// Date of completion: 2022-10-23
//
// I have done all the coding by myself and only copied the code that my classmate provided to complete my workshops and assignments.




#include <iomanip>
#include <iostream>
#include <string>

#include "Movie.h"

using namespace std;

namespace sdds {

	void Movie::trim(const string& res, string& local) const {
		size_t start{}, end{};

		for (size_t i = 0; i < res.size(); i++) {
			if (res[i] != ' ') {
				start = i;
				break;
			}
		}

		for (size_t i = res.size() - 1; i >= 0u; i--) {
			if (res[i] != ' ') {
				end = i;
				break;
			}
		}

		for (size_t i = start; i < end + 1; i++) {
			local += res[i];
		}
	}

	Movie::Movie(const string& strMovie) {
		auto posS = strMovie.find(',');
		auto author = strMovie.substr(0, posS);
		trim(author, m_title);

		auto posE = strMovie.find(',', posS + 1);
		auto title = strMovie.substr(posS + 1, posE - posS - 1);
		m_year = stoi(title);

		posS = posE;
		posE = strMovie.find('.', posE + 1);
		auto desc = strMovie.substr(posS + 1, posE - posS);
		trim(desc, m_desc);
	}

	const string& Movie::title() const {
		return m_title;
	}

	ostream& operator<<(ostream& os, const Movie& res) {
		return os << setw(40) << res.m_title << " | " << setw(4)
			<< res.m_year << " | " << res.m_desc << endl;
	}
}