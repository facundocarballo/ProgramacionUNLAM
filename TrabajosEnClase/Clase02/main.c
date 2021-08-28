#include <stdio.h>
#include <stdlib.h>
#include "Date/dates.c"

Date insertDate()
{
    Date date;
    printf("Please enter a date: (M/D/Y)\n");
    scanf("%d/%d/%d", &date.month, &date.day, &date.year);
    fflush(stdin);
    while (!isValidDate(date))
    {
        printf("This date is invalid. Please enter a valid date (M/D/Y)\n");
        scanf("%d/%d/%d", &date.month, &date.day, &date.year);
        fflush(stdin);
    }
    return date;
}

int main()
{
    // TODO: Add pointers to all the structures type Date that we send between functions.
    Date date = insertDate();
    printf("Date: %0.2d-%0.2d-%d\n", date.day, date.month, date.year);
    if (isValidDate(date) == true)
    {
        printf("The date is valid.\n");
        Date newAddDate = addDate(date, 100);             
        Date theReducedDate = reduceDate(date, 100);
        int differenceBTWdates = differenceToDates(date, newAddDate);
        int dayWeek = dayOfTheWeek(date);
        printf("Difference in days between two dates: %d\n", differenceBTWdates);
        printf("Day of the week: %d\n", dayWeek);
    }
    else
    {
        printf("The date isn't valid :(\n");
    }
    return 0;
}

