#include "../const.h"
#ifndef FECHAS_H
#define FECHAS_H

typedef struct
{
    int day;
    int month;
    int year;
} Date;

bool isValidDate(const Date date);
Date addDate(Date date, const int days);
Date reduceDate(const Date date, const int days);
int differenceToDates(const Date date1, const Date date2);
int dayOfTheWeek(const Date date);

#endif