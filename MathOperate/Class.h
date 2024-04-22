#pragma once

#include "Class.g.h"

namespace winrt::MathOperate::implementation
{
    struct Class : ClassT<Class>
    {
        Class() = default;

        int32_t MyProperty();
        void MyProperty(int32_t value);
        void Add(int32_t a, int32_t b, int32_t& c);
    };
}

namespace winrt::MathOperate::factory_implementation
{
    struct Class : ClassT<Class, implementation::Class>
    {
    };
}
