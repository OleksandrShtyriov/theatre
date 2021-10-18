#ifndef CONFIGURATIONS_H_
#define CONFIGURATIONS_H_

#include <iostream>
#include <vector>

#include "Menu.h"
#include "Actor.h"
#include "Perfomance.h"
#include "Theatre.h"
#include "GetActors.h"
#include "ActorsVector.h"

//Theater name:
const std::string theatreName = "Cpp";

//Filenames:
const std::string perfomancesFile = "perfomances.txt";
const std::string actorsFile = "actors.txt";

Theatre theatre = Theatre(actorsFile, perfomancesFile, theatreName);

//Menu:
Menu menu = Menu(theatre);

#endif

