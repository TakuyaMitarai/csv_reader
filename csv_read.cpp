#include "csv_read.h"
#include <stdio.h>

Csv_read::Csv_read()
{
    int i;

    //Dataクラスを生成
    data = new Data* [EXECUTION_TIMES];
    for(i = 0; i < EXECUTION_TIMES; i++) {
      data[i] = new Data();
   }
}

Csv_read::~Csv_read()
{
    int i;

    //Dataの消去
   for(i = 0; i < EXECUTION_TIMES; i++) {
      delete data[i];
   }
   delete [] data;
}

//csvファイル読み取り関数
void Csv_read::csv_read()
{
    int i, j;
    FILE *fp;

    fp = fopen("result.csv", "r" );

    if( fp == NULL ){
    printf( "%sファイルが開けません¥n", "result.csv");
    }

    //csvファイルデータの格納
    fscanf(fp, "%[^,],%s", buf[0], buf[1]);
    for(j = 0; j < EXECUTION_TIMES; j++){
        for(i = 0; i < GEN_MAX; i++){
            fscanf(fp, "%d,%lf", &data[j]->gen_count[i], &data[j]->fitness[i]);
        }
    }
    fclose( fp );
}

//読み取ったデータを出力
void Csv_read::csv_print()
{
    printf("%s, %s\n", buf[0], buf[1]);
    for(int j = 0; j < EXECUTION_TIMES; j++){
        for(int i = 0; i < GEN_MAX; i++){
            printf("%d,%f\n", data[j]->gen_count[i], data[j]->fitness[i]);
        }
        printf("\n");
    }
}