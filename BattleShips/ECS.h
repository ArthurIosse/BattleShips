#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>

class Component;
class Entity;

using ComponentID = std::size_t;

inline ComponentID getComponentID()
{
    static ComponentID lastID = 0;
    return latsID++;
}

template<typename T> inline ComponentID getComponentID() noexcept
{
    static ComponentID typeID = getComponentID();
    return typeID;
}

