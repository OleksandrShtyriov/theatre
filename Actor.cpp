#include "Actor.h"

std::string Actor::getName() const
{
    return name;
}

std::string Actor::getRole() const
{
    return role;
}

void Actor::setName(const std::string name)
{
    this->name = name;
}

void Actor::setRole(const std::string role) const
{
    this->role = role;
}

std::string Actor::show() const
{
    std::string result = ""; 

    result = name + " as " + role;
    return result;
}

std::ostream& operator<<(std::ostream& out, Actor& actor)
{
    out << actor.show();
    return out;
}

