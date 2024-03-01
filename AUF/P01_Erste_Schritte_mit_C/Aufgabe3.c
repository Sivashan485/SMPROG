#define  NUM_ROWS 5; //defined amount of rows
#define  STARTVALUE 200;
#define DIFFERENCE 200;
#include <stdio.h>

int main(void){
    double btcRate = 0; //amount of BTC to Convert in CHF.
    int numRows = NUM_ROWS; //amount of Rows
    int currentvalue = STARTVALUE; //default value at start
    double convertedValue = 0; //convertedvalue


    printf("Enter conversion rate 1.00 BTC -> CHF " );
    scanf("%lf", &btcRate); //enter CHF -> BTC Rate

    for(int i = 0; i<numRows; i++){
        convertedValue = currentvalue/btcRate;
        printf("\t %d \t CHF \t <-> \t %f \t BTC\n",((currentvalue)), convertedValue ); //print value
        currentvalue = currentvalue+DIFFERENCE;  // changing the current value
    }

    return 0;
}

