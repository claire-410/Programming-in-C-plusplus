// Name:  Reziyemu Sulaiman
// Seneca Student ID: 106-153-208
// Seneca email: rsulaiman2@myseneca.ca
// Date of completion: 2022-10-23
//
// I have done all the coding by myself and only copied the code that my classmate provided to complete my workshops and assignments.


#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H

#include <iostream>
#include <string>

namespace sdds {

	class Movie {
		std::string m_title{};
		size_t m_year{};
		std::string m_desc{};
		void trim(const std::string& res, std::string& local) const;
	public:
		Movie() {};
		const std::string& title() const;
		Movie(const std::string& strMovie);
		template <typename T> void fixSpelling(T& spellChecker);
		friend std::ostream& operator<<(std::ostream& os,
			const Movie& res);
	};

	template <typename T>
	void Movie::fixSpelling(T& spellChecker) {
		spellChecker(m_title);
		spellChecker(m_desc);
	}
}

#endif