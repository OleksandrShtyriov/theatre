#ifndef PERFOMANCE_H_
#define PERFOMANCE_H_

#include <iostream>
#include <vector>

#include "Actor.h"

class Perfomance
{
    private:
        std::vector<Actor> actors;
        std::string name;
    public:
        Perfomance(const std::vector<Actor> a, const std::string n) : actors(a), name(n) { }

        std::vector<Actor> getActors() const;
        std::string getName() const;

        void addActor(const Actor actor);
        void setActors(const std::vector<Actor> actors);
        void setName(const std::string name);

        std::string show() const;

        Perfomance operator + (const Actor& actor);
        Perfomance operator += (const Actor& actor);
        Perfomance operator -- (int);

        friend std::ostream& operator << (std::ostream& out, Perfomance& perf);
};

#endif

