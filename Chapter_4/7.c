#include <stdio.h>

/*
Write a program that determines the day number (1 to 366) in a year for a date that is provided as input data. As an example, January 1, 1994, is day 1. December 31, 1993, is day 365. December 31, 1996, is day 366, since 1996 is a leap year. A year is a leap year if it is divisible by four, except that any year divisible by 100 is a leap year only if it is divisible by 400. Your program should accept the month, day, and year as integers. Include a function leap that returns 1 if called with a leap year, 0 otherwise.
*/

// dibuat fungsi aja biar nggak untel-untelan di main()
int day_counter(int year, int month, int date){
    int jan = 31;
    int feb; if ((year % 4 == 0 && year % 100 !=0) || year % 400 == 0) feb = 29; else feb = 28;  // conditional for february
    int mar = 31;
    int apr = 30;
    int may = 31;
    int jun = 30;
    int jul = 31;
    int aug = 31;
    int sept = 30;
    int oct = 31;
    int nov = 30;
    int dec = 31;
    int total_days, date_checker;
    
      if (month < 1 || month > 12){
        printf("There are no months represented by the number %d\n", month);
        return 0;
        }

    // To check if the date given was valid (example, putting 30 on february isnt valid)
    switch(month){
        case 1: date_checker = jan; break;
        case 2: date_checker = feb; break;
        case 3: date_checker = mar; break;
        case 4: date_checker = apr; break;
        case 5: date_checker = may; break;
        case 6: date_checker = jun; break;
        case 7: date_checker = jul; break;
        case 8: date_checker = aug; break;
        case 9: date_checker = sept; break;
        case 10: date_checker = oct; break;
        case 11: date_checker = nov; break;
        case 12: date_checker = dec; break;
    }
    
    // Because we weren't taught to use loop, this is the mess that I shall deal with
    switch(month){
        case 1: total_days = 0 + date; break;
        case 2: total_days = jan + date; break;
        case 3: total_days = jan + feb + date; break;
        case 4: total_days = jan + feb + mar + date; break;
        case 5: total_days = jan + feb + mar + apr + date; break;
        case 6: total_days = jan + feb + mar + apr + may + date; break;
        case 7: total_days = jan + feb + mar + apr + may + jun + date; break;
        case 8: total_days = jan + feb + mar + apr + may + jun + jul + date; break;
        case 9: total_days = jan + feb + mar + apr + may + jun + jul + aug + date; break;
        case 10: total_days = jan + feb + mar + apr + may + jun + jul + aug + sept + date; break;
        case 11: total_days = jan + feb + mar + apr + may + jun + jul + aug + sept + oct + date; break;
        case 12: total_days = jan + feb + mar + apr + may + jun + jul + aug + sept + oct + nov + date; break;
    }
    if (date >= 1 && date <= date_checker) return printf("%d/%d/%d is day %d of the year\n",year, month, date, total_days);
    else return printf("Im sorry, but %d is not in the month %d year %d\n", date, month, year);
}

int main(){
    int main_year, main_month, main_date;
    printf("Input month, date, year\n// contoh: 9 11 2001\n");
    scanf("%d %d %d", &main_month, &main_date, &main_year);

    day_counter(main_year, main_month, main_date);
    return 0;
}