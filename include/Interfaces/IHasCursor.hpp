#include <utility>
namespace Interfaces
{
    class IHasCursor
    {
    public:
        virtual void cursorMoveRelative(int x, int y) = 0;
        virtual void cursorSetPos(int x, int y) = 0;
        virtual void cursorMoveConstrained(int x, int y,
                                           std::pair<int, int> xConstrain,
                                           std::pair<int, int> yConstrain) = 0;
        virtual std::pair<int, int> cursorGetPos() = 0;
        virtual void renderCursor() = 0;
    };
}