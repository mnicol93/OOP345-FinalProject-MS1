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
        std::string temp;

        if (str[next_pos] == m_delimiter) {
            more = false;
            throw("Delimiter found at new position.");
        }
        size_t startPos = next_pos;
        next_pos = str.find(m_delimiter, startPos);

        if (next_pos == std::string::npos) {
            temp = str.substr(startPos);
            more = false;
            next_pos = 0;
        }
        else {
            more = true;
            temp = str.substr(startPos, next_pos - startPos);
            next_pos++;
        }
        if (m_widthField < temp.length()) m_widthField = temp.length();

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