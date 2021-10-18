#include "ActorsVector.h"

ActorsVector::ActorsVector(const std::vector<std::string> filenames)
{
    actors = getActors(filenames);
}

std::vector<Actor> ActorsVector::getVector() const
{
    return actors;
}

