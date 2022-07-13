#include "csv_read.h"
#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;

#define DELIMITER 10

int main()
{
    FILE *fp1;
    int i, j;
    double ave[GEN_MAX];
    double slope[GEN_MAX];
    double slope_DEL_EXE[GEN_MAX/10];
    int delimiter_count;
    int count_0 = 0;
    int count_0_1 = 0;

    fp1 = fopen("ave.txt", "w");

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

    fprintf(fp1, "GEN, FIT\n");
    //平均値算出
    for(i = 0; i < GEN_MAX; i++){
        ave[i] /= EXECUTION_TIMES;
        slope[i] = ave[i];
        printf("%d, %f\n", i, slope[i]);
        fprintf(fp1,"%d,%f\n", i+1, slope[i]);
    }

    //二乗の平均算出
    double doub_ave = 0;
    for(i = 0; i < EXECUTION_TIMES; i++) {
        doub_ave += csv->data[i]->fitness[GEN_MAX-1] * csv->data[i]->fitness[GEN_MAX-1];
    }
    doub_ave /= EXECUTION_TIMES;
    //分散算出
    double variance;
    variance = doub_ave - ave[GEN_MAX-1] * ave[GEN_MAX-1];
    cout << "分散は" << variance << endl; 
    cout << "標準偏差は" << sqrt(variance) << endl; 

    //平均値がある定数を下回るまでカウントし、出力
    /*for(i = 0; i< GEN_MAX - 1; i++) {
        if(slope[i] > 0.03){
            count_0++;
        }
    }
    printf("GENは%d\n", count_0);*/

    delete csv;
    fclose(fp1);
}