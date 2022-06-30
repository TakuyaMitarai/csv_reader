#include "csv_read.h"
#include <stdio.h>

#define DELIMITER 10

int main()
{
    int i, j;
    double ave[GEN_MAX];
    double slope[GEN_MAX-1];
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
        //printf("%d, %f\n", i, ave[i]);
    }

    //傾き算出
    for(i = 0; i< GEN_MAX - 1; i++) {
        slope[i] = ave[i+1] - ave[i];
        //printf("%d, %f\n", i, slope[i]);
    }

    //0の個数算出
    for(i = 0; i< GEN_MAX - 1; i++) {
        if(slope[i] == 0){
            count_0++;
        }
    }
    printf("0の個数は%d\n", count_0);

    //区切り箇所表示
    /*
    count_0 = 0; //count_0の初期化
    for(i = 0; i< GEN_MAX - 1; i++) {
        if(slope[i] == 0){
            count_0++;
        }
        if(count_0 == DELIMITER){
            printf("DELIMITERが%dのときEXECUTION_TIMESが%d\n", DELIMITER, i);
            break;
        }
    }
    */

   //区切りを10刻みで変えた時の変化を求める
    j = 0;
    for(delimiter_count = 10; delimiter_count < count_0; delimiter_count += 15) {
        for(i = 0; i< GEN_MAX - 1; i++) {
            if(slope[i] == 0){
                count_0_1++;
            }
            if(count_0_1== delimiter_count){
                slope_DEL_EXE[j] = i;
                printf("DELIMITERが%dのときEXECUTION_TIMESが%f\n", delimiter_count, slope_DEL_EXE[j]);
                j++;
                break;
            }
        }
        count_0_1 = 0;
    }
    //傾き
    i = 0;
    for(delimiter_count = 10; delimiter_count < count_0 - 15; delimiter_count += 15){
        slope_DEL_EXE[i] = (slope_DEL_EXE[i+1] - slope_DEL_EXE[i]) / 15;
        printf("%d~%dのときの傾きは%f\n",delimiter_count,delimiter_count + 15, slope_DEL_EXE[i]);
        i++;
    }//このfor文は省略できる

    //区切りを20刻みで変えた時の変化を求める
    j = 0;
    for(delimiter_count = 10; delimiter_count < count_0; delimiter_count += 20) {
        for(i = 0; i< GEN_MAX - 1; i++) {
            if(slope[i] == 0){
                count_0_1++;
            }
            if(count_0_1== delimiter_count){
                slope_DEL_EXE[j] = i;
                printf("DELIMITERが%dのときEXECUTION_TIMESが%f\n", delimiter_count, slope_DEL_EXE[j]);
                j++;
                break;
            }
        }
        count_0_1 = 0;
    }
    //傾き
    i = 0;
    for(delimiter_count = 10; delimiter_count < count_0 - 20; delimiter_count += 20){
        slope_DEL_EXE[i] = (slope_DEL_EXE[i+1] - slope_DEL_EXE[i]) / 20;
        printf("%d~%dのときの傾きは%f\n",delimiter_count,delimiter_count + 20, slope_DEL_EXE[i]);
        i++;
    }//このfor文は省略できる
}