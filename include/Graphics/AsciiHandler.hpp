#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include "BearLibTerminal.h"

namespace Graphics
{
    class AsciiHandler
    {
    public:
        void loadFromFile(std::string fileName);
        void displayAscii(int x, int y);
    private:
        std::string _asciiData;
    };
}
