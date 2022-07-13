#pragma once

#define GEN_MAX     200
#define EXECUTION_TIMES 150

class Data
{
public:
    Data();
    ~Data();
    int gen_count[GEN_MAX]; //カラム1のデータ格納変数
    double fitness[GEN_MAX]; //カラム2のデータ格納変数
};