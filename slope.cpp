#include "csv_read.h"
#include <stdio.h>

#define DELIMITER 10

int main()
{
    int i, j;
    double ave[GEN_MAX];
    double slope[GEN_MAX];
    double slope_DEL_EXE[GEN_MAX/10];
    int delimiter_count;
    int count_0 = 0;
    int count_0_1 = 0;

    Csv_read* csv;
    csv = new Csv_read();
    csv->csv_read();
    //csv->csv_print();

    //averageの初期化
    for(i= 0; i < GEN_MAX; i++){
        ave[i] = 0;
    }
    
    //合計値算出
    for(i = 0; i < EXECUTION_TIMES; i++){
        for(j = 0; j < GEN_MAX; j++){
            ave[j] += csv->data[i]->fitness[j];
        }
    }

    //平均値算出
    for(i = 0; i < GEN_MAX; i++){
        ave[i] /= EXECUTION_TIMES;
        slope[i] = ave[i];
        //printf("%d, %f\n", i, slope[i]);
    }

    //平均値がある定数を下回るまでカウントし、出力
    for(i = 0; i< GEN_MAX - 1; i++) {
        if(slope[i] > 0.03){
            count_0++;
        }
    }
    printf("GENは%d\n", count_0);

    delete csv;
}