#pragma once

#include "data.h"

class Csv_read
{
public:
    Csv_read();
    ~Csv_read();
    char buf[2][10]; //カラム名の格納変数
    void csv_read(); //csvファイル読み取り関数
    void csv_print(); //読み取ったデータを出力
    Data **data; //Dataクラスの宣言
};