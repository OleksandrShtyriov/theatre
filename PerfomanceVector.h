#ifndef PERFOMANCEVECTOR_H_
#define PERFOMANCEVECTOR_H_

#include <fstream>

#include "Perfomance.h"
#include "Repository.h"

class PerfomanceVector : public Repository<Perfomance>
{
    public:
        PerfomanceVector(const std::string filename, const int cap = DEFAULT_CAPACITY);

        Perfomance& operator [] (const std::string name);
        PerfomanceVector operator -- (int);
};

#endif

