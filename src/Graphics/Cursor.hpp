#include <utility>

namespace Graphics
{
    class Cursor
    {
    public:
        Cursor(char symbol, bool isBlinker, std::pair<int, int> coords);

        char _symbol;
        bool _isBlinker;
        std::pair<int, int> _coords;
    };
}
