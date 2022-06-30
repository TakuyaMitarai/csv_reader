#include "csv_read.h"
#include <stdio.h>

int main()
{
    Csv_read* csv;
    csv = new Csv_read();
    csv->csv_read();
    csv->csv_print();
}