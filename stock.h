#ifndef STOCK_H
#define STOCK_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

  typedef struct{
    char code[8];
    float price;
    float avg_price[256]; //vector to compute average price
    int index_avg_price;
    int nstocks; // stocks available for sell.
    float min;
    float max;
    float begin;
    float end;
    int begin_flag;
  }Stock;

  Stock newStock(char code[], float price, int nstocks);

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* STOCK_H */