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
}

void Graphics::AsciiHandler::displayAscii(int x, int y)
{
    terminal_print(x, y, _asciiData.data());
}
