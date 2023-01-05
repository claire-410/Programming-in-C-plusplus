
// Name:  Reziyemu Sulaiman
// Seneca Student ID: 106-153-208
// Seneca email: rsulaiman2@myseneca.ca
// Date of completion: 2022-10-23
//
// I have done all the coding by myself and only copied the code that my classmate provided to complete my workshops and assignments.


#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H

#include <exception>
#include <iostream>
#include <string>

namespace sdds {

	template <typename T>
	class Collection {
		std::string m_name{};
		T* m_collection{};
		size_t m_size{};
		void (*m_observer) (const Collection<T>&, const T&) = nullptr;
	public:
		Collection(const std::string& name);

		Collection(const Collection<T>& other) = delete;
		Collection& operator=(const Collection<T>& other) = delete;
		Collection(Collection<T>&& other) = delete;
		Collection& operator=(Collection<T>&& other) = delete;

		~Collection();
		const std::string& name() const;
		size_t size() const;
		void setObserver(void (*observer)(const Collection<T>&, const T&));
		Collection<T>& operator+=(const T& item);
		T& operator[](size_t idx) const;
		T* operator[](const std::string& title) const;
	};

	template <typename T>
	Collection<T>::Collection(const std::string& name) : m_name{ name }
	{};

	template <typename T>
	Collection<T>::~Collection() {
		delete[] m_collection;
	}

	template <typename T>
	const std::string& Collection<T>::name() const {
		return m_name;
	}

	template <typename T>
	size_t Collection<T>::size() const {
		return m_size;
	}

	template <typename T>
	void Collection<T>::setObserver
	(void (*observer)(const Collection<T>&, const T&)) {
		m_observer = observer;
	}

	template <typename T>
	Collection<T>& Collection<T>::operator+=(const T& item) {

		for (size_t i = 0; i < m_size; i++) {
			if (m_collection[i].title() == item.title()) {
				return *this;
			}
		}

		T* local = new T[m_size + 1];

		for (size_t i = 0; i < m_size; i++) {
			local[i] = m_collection[i];
		}

		local[m_size] = item;
		delete[] m_collection;
		m_collection = local;
		++m_size;

		if (m_observer)
			m_observer(*this, m_collection[m_size - 1]);

		return *this;
	}

	template <typename T>
	T& Collection<T>::operator[](size_t idx) const {
		if (idx >= m_size) {
			std::string local = "Bad index [" + std::to_string(idx) + "]. "
				+ "Collection has [" + std::to_string(idx) + "] items.";
			throw std::out_of_range(local);
		}
		return m_collection[idx];
	}

	template <typename T>
	T* Collection<T>::operator[](const std::string& title) const {
		for (size_t i = 0; i < m_size; i++) {
			if (m_collection[i].title() == title) {
				return &m_collection[i];
			}
		}
		return nullptr;
	}

	template <typename T>
	std::ostream& operator<<
		(std::ostream& out, const Collection<T>& other) {
		for (size_t i = 0; i < other.size(); i++) {
			out << other[i];
		}
		return out;
	}
}

#endif

