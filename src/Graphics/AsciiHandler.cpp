#include "Graphics\AsciiHandler.hpp"

void Graphics::AsciiHandler::loadFromFile(std::string fileName)
{
    // Input File stream
    std::ifstream asciiFile(fileName);

    if (!asciiFile.is_open())
    {
        std::cerr << "Failed to open file \"" << fileName << "\"\n";
        return;
    }

    std::stringstream buffer;
    buffer << asciiFile.rdbuf();
    _asciiData = buffer.str();

    _height = std::count(_asciiData.begin(), _asciiData.end(), '\n') + 1;

    // calculate length
    _length = 0;

    std::stringstream asciiStream(_asciiData);
    std::string tempLine;

    while (std::getline(asciiStream, tempLine))
    {
        size_t lineLength = countUTF8codepoints(tempLine);
        if (_length < lineLength)
        {
            _length = lineLength;
        }
    }

}

size_t Graphics::AsciiHandler::countUTF8codepoints(std::string line)
{
    size_t count = 0;

    for (size_t i = 0; i < line.size();)
    {
        unsigned char c = static_cast<unsigned char>(line[i]);
        size_t char_len = 1;

        if ((c & 0b10000000) == 0b00000000)
        {
            char_len = 1;
        }
        else if ((c & 0b11100000) == 0b11000000)
        {
            char_len = 2;
        }
        else if ((c & 0b11110000) == 0b11100000)
        {
            char_len = 3;
        }
        else if ((c & 0b11111000) == 0b11110000)
        {
            char_len = 4;
        }

        i += char_len;  // advance by the size of the prev utf8 character
        ++count;
    }
    return count;
}

/*
size_t count_utf8_codepoints(const std::string& line) {
    size_t count = 0;
    for (size_t i = 0; i < line.size(); ) {
        unsigned char c = static_cast<unsigned char>(line[i]);
        size_t char_len = 1;

        if ((c & 0b10000000) == 0) char_len = 1;             // ASCII
        else if ((c & 0b11100000) == 0b11000000) char_len = 2;
        else if ((c & 0b11110000) == 0b11100000) char_len = 3;
        else if ((c & 0b11111000) == 0b11110000) char_len = 4;

        i += char_len;
        ++count;
    }
    return count;
}
*/

void Graphics::AsciiHandler::displayAscii(int x, int y)
{
    terminal_print(x, y, _asciiData.data());
}

size_t Graphics::AsciiHandler::getHeight()
{
    return _height;
}

size_t Graphics::AsciiHandler::getLength()
{
    return _length;
}
