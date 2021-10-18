#include "GetActors.h"

Actor getActorFromFile(const std::string filename)
{
    std::ifstream fin(filename);
    std::string name;
    std::string role;

    if (!fin)
    {
        throw -1;
    }

    std::getline(fin, name);
    std::getline(fin, role);

    return Actor(name, role);
}

std::vector<Actor> getActors(const std::vector<std::string> filenames)
{
    std::vector<Actor> actors;

    for (int i = 0; i < filenames.size(); i++)
    {
        actors.push_back(getActorFromFile(filenames[i]));
    }

    return actors;
}

