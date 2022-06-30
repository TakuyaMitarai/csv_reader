#pragma once

#define GEN_MAX     400
#define EXECUTION_TIMES 50

class Data
{
public:
    Data();
    ~Data();
    int gen_count[GEN_MAX];
    double fitness[GEN_MAX];
};