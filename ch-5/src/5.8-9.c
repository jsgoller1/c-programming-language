#include "5.8-9.h"
#include <stdio.h>
#include <stdlib.h>

/*
Exercise 5-8. There is no error checking in day_of_year or month_day.
Remedy this defect.

Exercise 5-9. Rewrite the routines day_of _year and month_day with
pointers instead of indexing.

Wikipedia algorithm for determining a leap year:
if (year is not divisible by 4) then (it is a common year)
else if (year is not divisible by 100) then (it is a leap year)
else if (year is not divisible by 400) then (it is a common year)
else (it is a leap year)
*/

static char *daytab[2];

// set day of year from month & day
int day_of_year(const int year, const int month, int day) {
  int i, leap;

  // Reject invalid year and month values
  if (year < 0) {
    printf("day_of_year() - error: invalid year.\n");
    return -1;
  }
  if ((month < 1) || (month > 12)) {
    printf("day_of_year() - error: invalid month.\n");
    return -1;
  }

  // See algorithm at top for leap year calculation
  leap = ((year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0)));

  // Reject invalid days of months; you cannot compute "the 31st of February".
  // This also covers any day value larger than 31.
  if ((day < 1) || (day > daytab[leap][month])) {
    printf("day_of_year() - error: invalid day.\n");
    return -1;
  }

  for (i = 1; i < month; i++) {
    day += daytab[leap][i];
  }
  return day;
}

// set month, day, from day of year
int month_day(const int year, int yearday, int *const pmonth, int *const pday) {
  int i, leap;

  // Reject invalid year or yearday values
  if (year < 0) {
    printf("month_day() - error: invalid year.\n");
    return -1;
  }
  if ((yearday < 1) || (yearday > 365)) {
    printf("month_day() - error: invalid yearday.\n");
    return -1;
  }

  // See algorithm at top for leap year calculation
  leap = ((year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0)));

  for (i = 1; yearday > daytab[leap][i]; i++) {
    yearday -= daytab[leap][i];
  }
  *pmonth = i;
  *pday = yearday;

  return 0;
}

int main() {
  int year, month, day, yearday;
  int *pday, *pmonth;
  pday = malloc(sizeof(int));
  pmonth = malloc(sizeof(int));

  // daytab is an array of pointers to arrays of chars; these could now
  // be of different lengths as opposed to a "true" array of arrays
  char non_leap_arr[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  char leap_arr[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  daytab[0] = non_leap_arr;
  daytab[1] = leap_arr;

  // Valid conversion
  year = 2010;
  month = 6;
  day = 12;
  yearday = day_of_year(year, month, day);
  month_day(year, yearday, pmonth, pday);
  printf("%d/%d/%d was day #%d.\n", month, day, year, yearday);
  printf("day %d of year %d was %d/%d.\n\n", yearday, year, *pmonth, *pday);

  // Invalid day
  day = 2000;
  yearday = day_of_year(year, month, day);
  month_day(year, yearday, pmonth, pday);
  printf("%d/%d/%d was day #%d.\n", month, day, year, yearday);
  printf("day %d of year %d was %d/%d.\n\n", yearday, year, *pmonth, *pday);

  // Invalid month
  month = 87;
  yearday = day_of_year(year, month, day);
  month_day(year, yearday, pmonth, pday);
  printf("%d/%d/%d was day #%d.\n", month, day, year, yearday);
  printf("day %d of year %d was %d/%d.\n\n", yearday, year, *pmonth, *pday);

  // Invalid year
  year = -2587;
  yearday = day_of_year(year, month, day);
  month_day(year, yearday, pmonth, pday);
  printf("%d/%d/%d was day #%d.\n", month, day, year, yearday);
  printf("day %d of year %d was %d/%d.\n\n", yearday, year, *pmonth, *pday);
  return 0;
}
