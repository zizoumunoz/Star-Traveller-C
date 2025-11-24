namespace Interfaces
{
    class IHasUserInput
    {
    public:
        virtual ~IHasUserInput() = default;
        virtual int handleInput(int key) = 0;
    };
}
