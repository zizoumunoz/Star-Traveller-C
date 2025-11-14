#include <utility>

namespace Graphics
{
    class Cursor
    {
    public:
        char _symbol;
        bool _isBlinker;
        std::pair<int, int> _coords;
    };
}
