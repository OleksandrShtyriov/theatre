#ifndef ACTORSVECTOR_H_
#define ACTORSVECTOR_H_

#include <vector>

#include "Actor.h"
#include "GetActors.h"

class ActorsVector
{
    private:
        std::vector<Actor> actors;
    public:
        ActorsVector() { }
        ActorsVector(const std::vector<std::string> filenames);

        std::vector<Actor> getVector() const;
};

#endif

