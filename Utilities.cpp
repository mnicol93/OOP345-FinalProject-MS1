// Name: Marc Nicolas Oliva
// Seneca Student ID: 130943202
// Seneca email: mnicolas-oliva@myseneca.ca
// Date of completion: 2021-07-11
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <iostream>
#include "Utilities.h"

namespace sdds {
    char Utilities::m_delimiter{ '\0' };

    void Utilities::setFieldWidth(size_t newWidth)
    {
        m_widthField = newWidth;
    }

    size_t Utilities::getFieldWidth() const
    {
        return m_widthField;
    }

    std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
    {
        if (str[next_pos] == m_delimiter)
            throw("Delimiter found at new position.");
        std::string temp = str;
        temp = str.substr(next_pos, str.find_first_of(m_delimiter));

        if (str != "") {
            next_pos = str.find_first_of(m_delimiter);
            more = true;
        }
        else {
            more = false;
        }
        if (m_widthField < temp.length())
            m_widthField = temp.length();
        return temp;
    }

    void Utilities::setDelimiter(char newDelimiter)
    {
        m_delimiter = newDelimiter;
    }

    char Utilities::getDelimiter()
    {
        return m_delimiter;
    }
}