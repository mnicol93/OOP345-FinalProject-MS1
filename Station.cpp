// Name: Marc Nicolas Oliva
// Seneca Student ID: 130943202
// Seneca email: mnicolas-oliva@myseneca.ca
// Date of completion: 2021-07-11
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <iostream>
#include <iomanip>
#include "Utilities.h"
#include "Station.h"

namespace sdds {
	unsigned int Station::m_widthField{ 0 };
	unsigned int Station::m_idGenerator{ 0 };

	Station::Station(): m_stationId(0), m_itemName(""), m_description(""),
		m_nextItem(0u), m_stock(0u) { }

	Station::Station(const std::string& str)
	{
		size_t nPos{ 0u };
		bool more{ false };
		Utilities util;

		m_stationId = ++m_idGenerator;

		m_itemName = util.extractToken(str, nPos, more);
		m_nextItem = stoi(util.extractToken(str, nPos, more));
		m_stock = stoi(util.extractToken(str, nPos, more));
		m_description = util.extractToken(str, nPos, more);

		if (m_widthField > util.getFieldWidth())
			m_widthField = util.getFieldWidth();

	}

	const std::string& Station::getItemName() const
	{
		return m_itemName;
	}

	size_t Station::getNextSerialNumber()
	{
		m_nextItem++;
		return m_nextItem - 1;
	}

	size_t Station::getQuantity() const
	{
		return m_stock;
	}

	void Station::updateQuantity()
	{
		(m_stock > 0) ? m_stock-- : m_stock = 0;
	}

	void Station::display(std::ostream& os, bool full)
	{
		os << "[" << std::setw(3) << std::setprecision(3) << std::setfill('0') << std::right << m_stationId << "] Item: " << std::setfill(' '); 

		if (full) {
			os << std::setw(15) << std::left << m_itemName <<  "["  << std::setw(6) << std::right << std::setfill('0') <<
				m_nextItem << "] Quantity: " << std::setfill(' ') << std::setw(15) << 
				std::left << m_stock <<  "Description: " << m_description << std::endl;
		}
		else {
			os << std::setw(15)<< std::left << m_itemName
				  << "["<< std::setw(6) << std::right << std::setfill('0') << m_nextItem << "]" << std::endl;
		}
	}
	

}