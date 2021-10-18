#ifndef PERFOMANCEVECTOR_H_
#define PERFOMANCEVECTOR_H_

#include <fstream>

#include "Perfomance.h"

class PerfomanceVector
{
    private:
        std::vector<Perfomance> perfomances;
    public:
        PerfomanceVector(const std::string filename);

        std::vector<Perfomance> getVector() const;

        Perfomance& operator [] (const std::string name);
        PerfomanceVector operator -- (int);
};

#endif

