#include "Graphics/Cursor.hpp"

Graphics::Cursor::Cursor(char symbol, bool isBlinker, std::pair<int, int> coords)
    : _symbol(symbol), _isBlinker(isBlinker), _coords(coords)
{
}
