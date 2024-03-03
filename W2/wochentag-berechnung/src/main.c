 /* ----------------------------------------------------------------------------
 * --  _____       ______  _____                                              -
 * -- |_   _|     |  ____|/ ____|                                             -
 * --   | |  _ __ | |__  | (___    Institute of Embedded Systems              -
 * --   | | | '_ \|  __|  \___ \   Zuercher Hochschule Winterthur             -
 * --  _| |_| | | | |____ ____) |  (University of Applied Sciences)           -
 * -- |_____|_| |_|______|_____/   8401 Winterthur, Switzerland               -
 * ----------------------------------------------------------------------------
 */
/**
 * @file
 * @brief Lab P02 weekday
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>







// *** TASK1: typedef enum types for month_t (Jan=1,...Dec} ***
// BEGIN-STUDENTS-TO-ADD-CODE

typedef enum  { JAN=1, FEB, MAR, APR, MAI, JUN, JUL, AUG, SEP, OKT, NOV, DEZ } month_t; 


// END-STUDENTS-TO-ADD-CODE




// *** TASK1: typedef struct for date_t ***
// BEGIN-STUDENTS-TO-ADD-CODE

typedef struct date_t
{
    int year; 
    month_t month;
    int day;

} date_t;

typedef enum {Sun =0, Mon =1 , TUE =2, WED, THU, FRI, SAT } weekday_t;


// END-STUDENTS-TO-ADD-CODE

int is_leap_year(date_t date);
int istHunderterJahr(int jahr);
int isYearValid(date_t date);
int isMonthValid(date_t date);
int tageFuerFeb( date_t date);
int isDayValid( date_t date_t);
int get_month_length( date_t date);
int is_valid_date(date_t date);
date_t readDate(void);
int is_gregorian_date(date_t date);
weekday_t calculate_weekday(date_t date);
 print_weekday(weekday_t day);



// *** TASK2: typedef enum weekday_t (Sun=0, Mon, ...Sat) ***
// BEGIN-STUDENTS-TO-ADD-CODE


// END-STUDENTS-TO-ADD-CODE

/**
 * @brief   TASK1: Checks if the given date is a leap year.
 * @returns 0 = is not leap year, 1 = is leap year
 */
// BEGIN-STUDENTS-TO-ADD-CODE

//Returns 0 = False and 1 = True
int is_leap_year(date_t date){
    int jahr = date.year;

    //checking 100s years
    if(istHunderterJahr(jahr)==1 && jahr%400==0){
        return 1;
    }
    //checking other years
    else if(istHunderterJahr(jahr)==0 && jahr%4==0){
        return 1;
    }
    return 0;    
}


/**
 This method checks if year modulo 100 == 0
*/
int istHunderterJahr(int jahr){
    if(jahr%100==0){
        return 1;
    }else{
        return 0; 
    }
}

// END-STUDENTS-TO-ADD-CODE


/**
 * @brief   TASK1: Calculates the length of the month given by the data parameter
 * @returns 28, 29, 30, 31 if a valid month, else 0
 */
// BEGIN-STUDENTS-TO-ADD-CODE


/*
    Year needs to be greater than 1599 and smaller than 10000; 
*/
int isYearValid(date_t date){
    if(date.year>=1582 && date.year <10000){
        return 1;
    }
    printf("\nERROR: Year is unvalid!!! VALID-> 1582-10000 \n");
    return 0; 
}

/*
   valid months are between 1-12
*/
int isMonthValid(date_t date){
    if(date.month>0 && date.month<13){
        return 1;
    }
    printf("\nERROR: Month is unvalid!!! VALID-> 1-12 \n");
    return 0; 
}


/**
 Exception for FEB  28 /29 
*/
int tageFuerFeb( date_t date){
    if (is_leap_year(date) == 1){
        return 29;
    }else{
        return 28;
    }
}

/*
    check if day is valid one
    When day is valid return =1 else 0
*/
int isDayValid( date_t date_t){
    int tagMonat = get_month_length(date_t);
    if(tagMonat>=date_t.day){
        return 1;
    }
    printf("\nERROR: Day is unvalid for month %d!!! VALID-> 1-%d\n",date_t.month,tagMonat);
    return 0;
    
}


/*
    Months with their day's
*/
int get_month_length( date_t date){
    month_t monat = date.month;
  switch (monat) {
        case JAN:
            return 31;
            break;
        case MAI:
            return 31;
        break;
        case JUL:
            return 31;
        break;
        case AUG:
            return 31;
        break;
        case OKT:
            return 31;
        break;
        case NOV: 
            return 30;
        break;
        case DEZ:
            return 31;
        break;
        case MAR:
            return 31;
        break;
        case APR:
            return 30;
        break;
        case JUN:
            return 30;
        break;
        case SEP:
            return 30;
        break;
        case FEB:
            return tageFuerFeb(date);
        break;
        default:
            return 0;
        break;
  }
}

// END-STUDENTS-TO-ADD-CODE

/**
 * @brief   TASK1: Checks if the given date is in the gregorian date range
 * @returns 0 = no, 1 = yes
 */
// BEGIN-STUDENTS-TO-ADD-CODE

/**
 * This method checks if its valid min gregorien_date and max year of 9999 
*/
int is_gregorian_date(date_t date){
    if(isYearValid(date)==1)
    {
        if(date.year==1582){
            if(  date.month>= OKT){
                if(date.month ==OKT ){
                    if(date.day>=15){
                        return 1;
                    }else{
                        return 0;
                    }
                }
                return 1;
                
            }
            return 0;
        }
        return 1;
    }
    printf("ERROR: Gregorian min date is 15.OKT.1582");
    return 0;
}

int is_valid_date(date_t date){
    if(isMonthValid(date) ==1 
        &&isDayValid(date)==1 && is_gregorian_date(date)==1){
        return 1;
    }else{
        return 0;
    }
}

/*
    reads date entry
*/
date_t readDate(void){
    int year, month, day;
    int dateIsVaild = 0;
    date_t date;
    do{
        printf("Enter date in following formate YEAR-Month-Day :");
        scanf("%d-%d-%d",&year, &month,&day);
        date.year = year;
        date.month = month;
        date.day = day;
        dateIsVaild = is_valid_date(date);
    }while(0==dateIsVaild);
    return date;

}


  weekday_t calculate_weekday(date_t date){
    //assert(is_valid_date(date));
    weekday_t we = 1;
    
    int month = date.month,day = date.day, year = date.year;
    int m = 1 + (month + 9) % 12;
    int a = (month < 3) ? year - 1 : year;
    int y = a % 100;
    int c = a / 100;

    // Berechnung des Wochentags
    int weekday  = ((day + (13 * m - 1) / 5 + y + y / 4 + c / 4 - 2 * c) % 7 + 7) % 7;
    
    return weekday;
}

 print_weekday(weekday_t day){
  //  printf("TAG %d",day);
    
}


// END-STUDENTS-TO-ADD-CODE


/**
 * @brief   TASK1: Checks if the given date is a valid date.
 * @returns 0 = is not valid date, 1 = is valid date
 */
// BEGIN-STUDENTS-TO-ADD-CODE


// END-STUDENTS-TO-ADD-CODE


/**
 * @brief   TASK2: calculated from a valid date the weekday
 * @returns returns a weekday in the range Sun...Sat
 */
// BEGIN-STUDENTS-TO-ADD-CODE


// END-STUDENTS-TO-ADD-CODE



/**
 * @brief   TASK2: print weekday as 3-letter abreviated English day name
 */
// BEGIN-STUDENTS-TO-ADD-CODE


// END-STUDENTS-TO-ADD-CODE

/**
 * @brief   main function
 * @param   argc [in] number of entries in argv
 * @param   argv [in] program name plus command line arguments
 * @returns returns success if valid date is given, failure otherwise
 */
int main(int argc, const char *argv[])
{
    date_t date = readDate();
    weekday_t weekday = calculate_weekday(date);
    print_weekday(weekday);

    //printDate(date);
    // TASK1: parse the mandatory argument into a date_t variable and check if the date is valid
    // BEGIN-STUDENTS-TO-ADD-CODE


    // END-STUDENTS-TO-ADD-CODE


    // TASK2: calculate the weekday and print it in this format: "%04d-%02d-%02d is a %s\n"
    // BEGIN-STUDENTS-TO-ADD-CODE


    // END-STUDENTS-TO-ADD-CODE

    return EXIT_SUCCESS;
}

