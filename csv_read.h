#pragma once

#include "data.h"

class Csv_read
{
public:
    Csv_read();
    ~Csv_read();
    char buf[2][10];
    void csv_read();
    void csv_print();
    Data **data;
};