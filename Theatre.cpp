#include "Theatre.h"

using std::string;
using std::vector;

Theatre::Theatre(const string filename, const string perfFilename, const string name) : file(filename), perfFile(perfFilename)
{
    PerfomanceVector pv = PerfomanceVector(perfFilename);

    std::ifstream fin(filename);

    string actorName;
    string role;
    string perfName;
    
    for (string line; std::getline(fin, actorName);)
    {
        std::getline(fin, role);
        std::getline(fin, perfName);

        pv[perfName] += Actor(actorName, role);
    }

    this->name = name;
    perfomances = pv.getVector();
}

std::string Theatre::getFile() const
{
    return file;
}

std::string Theatre::getPerffile() const
{
    return perfFile;
}

void Theatre::refresh()
{
    if (file != "none")
    {
        Theatre(file, perfFile, name);
    }
}

vector<Perfomance> Theatre::getPerfomances() const
{
    return perfomances;
}

string Theatre::getName() const
{
    return name;
}

void Theatre::addPerfomance(const Perfomance perfomance)
{
    perfomances.push_back(perfomance);
}

void Theatre::setPerfomances(const vector<Perfomance> perfomances)
{
    this->perfomances = perfomances;
}

void Theatre::setName(const string name)
{
    this->name = name;
}

string Theatre::show() const
{
    string result = name + ":\n";

    for (int i = 0; i < perfomances.size(); i++)
    {
        result += "\t" + std::to_string(i + 1) + perfomances[i].getName() + "\n";
    }

    return result;
}

Theatre Theatre::operator+=(const Perfomance perf)
{
    perfomances.push_back(perf);
    return *this;
}

std::ostream& operator << (std::ostream& out, Theatre theatre)
{
    out << theatre.show();
    return out;
}

