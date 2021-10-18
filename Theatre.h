#ifndef THEATRE_H_
#define THEATRE_H_

#include <iostream>
#include <vector>
#include <fstream>

#include "Perfomance.h"
#include "PerfomanceVector.h"

class Theatre
{
    private:
        std::vector<Perfomance> perfomances;
        std::string name;
    public:
        Theatre(const std::vector<Perfomance> p, const std::string n) : perfomances(p), name(n) { }
        Theatre(const std::string filename, const std::string perfFilename, const std::string name);

        std::vector<Perfomance> getPerfomances() const;
        std::string getName() const;

        void addPerfomance(const Perfomance perfomance);
        void setPerfomances(const std::vector<Perfomance> perfomances);
        void setName(const std::string name);

        std::string show() const;

        Theatre operator += (const Perfomance perf);

        friend std::ostream& operator << (std::ostream& out, Theatre theatre);
};

#endif

