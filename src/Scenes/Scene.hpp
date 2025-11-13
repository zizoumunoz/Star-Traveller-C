#include <string>
namespace StarTraveller
{
    class Scene
    {
    public:
        virtual void update() = 0;
        virtual void render() = 0;

    protected:
        std::string _name;
    private:
    };

}