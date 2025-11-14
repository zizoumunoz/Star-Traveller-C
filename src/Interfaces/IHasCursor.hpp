#include <utility>
namespace Interfaces
{
    class IHasCursor
    {
    public:
        virtual void moveRelative(int x, int y) = 0;
        virtual void setPosition(int x, int y) = 0;
        virtual std::pair<int, int> getPosition() = 0;
        virtual ~IHasCursor();
    };
}