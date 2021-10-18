#include "PerfomanceVector.h"

PerfomanceVector::PerfomanceVector(const std::string filename)
{
    std::ifstream fin(filename);
    std::string tempName;
    std::vector<Actor> emptyVector;

    while (fin >> tempName)
    {
        perfomances.push_back(Perfomance(emptyVector, tempName));
    }

    fin.close();
}

std::vector<Perfomance> PerfomanceVector::getVector() const
{
    return perfomances;
}

Perfomance& PerfomanceVector::operator[](const std::string name)
{
    for (int i = 0; i < perfomances.size(); i++)
    {
        if (perfomances[i].getName() == name)
        {
            return perfomances[i];
        }
    }

    std::cout << name << "\n";
    throw -1;
}

PerfomanceVector PerfomanceVector::operator--(int)
{
    perfomances.pop_back();
    return *this;
}

