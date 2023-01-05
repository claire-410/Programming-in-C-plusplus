// Name:  Reziyemu Sulaiman
// Seneca Student ID: 106-153-208
// Seneca email: rsulaiman2@myseneca.ca
// Date of completion: 2022-10-23
//
// I have done all the coding by myself and only copied the code that my classmate provided to complete my workshops and assignments.



#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

#include "SpellChecker.h"

using namespace std;

namespace sdds {

	void SpellChecker::trim(const string& res, string& local) const {
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

	SpellChecker::SpellChecker(const char* filename) {
		ifstream file(filename);
		if (!file) {
			throw "Bad file name!";
		}

		std::string words{};
		do {
			getline(file, words);

			if (file) {
				string local{};

				size_t pos = words.find(' ');
				local = words.substr(0, pos);
				m_badWords[m_size] = local;

				pos = words.find(' ', pos);
				local = words.substr(pos);
				trim(local, m_goodWords[m_size]);

				//kvPair({ m_badWords[m_size] }, { 0 });
				kvPair.insert(std::make_pair(m_badWords[m_size], 0));
				++m_size;
			}
		} while (file);
		file.close();
	}

	void SpellChecker::operator()(std::string& text) {

		size_t pos = 0;
		for (size_t i = 0; i < m_size; i++) {
			pos = text.find(m_badWords[i]);

			while (pos != string::npos) {
				text.replace(pos, m_badWords[i].size(), m_goodWords[i]);
				kvPair.at(m_badWords[i]) += 1;
				pos = text.find(m_badWords[i]);
			}
		}
	}

	void SpellChecker::showStatistics(std::ostream& out) const {
		out << "Spellchecker Statistics\n";
		for (const auto& badWord : m_badWords) {
			out << setw(15) << right << badWord << ": "
				<< kvPair.at(badWord) << " replacements\n";
		}
	}
}