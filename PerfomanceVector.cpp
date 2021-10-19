#include "PerfomanceVector.h"

PerfomanceVector::PerfomanceVector(const std::string filename, const int cap) : Repository(cap)
{
    std::ifstream fin(filename);
    std::string tempName;
    std::vector<Actor> emptyVector;

    while (fin >> tempName)
    {
        (*this) += Perfomance(emptyVector, tempName);
    }

    fin.close();
}

Perfomance& PerfomanceVector::operator[](const std::string name)
{
    for (int i = 0; i < length; i++)
    {
        if (elements[i].getName() == name)
        {
            return elements[i];
        }
    }

    throw -1;
}

PerfomanceVector PerfomanceVector::operator--(int)
{
    *this -= length - 1;
    return *this;
}

