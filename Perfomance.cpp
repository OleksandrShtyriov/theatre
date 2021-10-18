#include "Perfomance.h"

std::vector<Actor> Perfomance::getActors() const
{
    return actors;
}

std::string Perfomance::getName() const
{
    return name;
}

void Perfomance::addActor(const Actor actor)
{
    actors.push_back(actor);
}

void Perfomance::setActors(const std::vector<Actor> actors)
{
    this->actors = actors;
}

void Perfomance::setName(const std::string name)
{
    this->name = name;
}

std::string Perfomance::show() const
{
    std::string result = name + ":\n";

    for (int i = 0; i < actors.size(); i++)
    {
        result += "\t" + actors[i].show() + ".\n";
    }

    return result;
}

Perfomance Perfomance::operator+(const Actor& actor)
{
    Perfomance newPerfomance = Perfomance(actors, name);
    newPerfomance.addActor(actor);
    
    return newPerfomance;
}

Perfomance Perfomance::operator+=(const Actor& actor)
{
    addActor(actor);

    return *this;
}

Perfomance Perfomance::operator--(int)
{
    actors.pop_back();
    return *this;
}

std::ostream& operator << (std::ostream& out, Perfomance& perf)
{
    out << perf.show();
    return out;
}

