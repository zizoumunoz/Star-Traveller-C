#pragma once

namespace Interfaces
{
    class IHasUserInput
    {
    public:
        virtual ~IHasUserInput() = default;
        virtual void handleInput() = 0;
    };
}
