#ifndef GETACTORS_H_
#define GETACTORS_H_

#include <fstream>
#include <vector>

#include "Actor.h"

Actor getActorFromFile(const std::string filename);
std::vector<Actor> getActors(const std::vector<std::string> filenames);

#endif

