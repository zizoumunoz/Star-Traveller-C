#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include "BearLibTerminal.h"

namespace Graphics
{
    class AsciiHandler
    {
    public:
        void loadFromFile(std::string fileName);
        void displayAscii(int x, int y);

        /// @brief Count characters from a utf-8 string.
        /// @param line (std::string)
        /// @return (size_t) number of utf-8 characters in line.
        size_t countUTF8codepoints(std::string line);

        size_t getHeight();
        size_t getLength();

    private:
        std::string _asciiData;
        size_t _length;
        size_t _height;
    };
}
