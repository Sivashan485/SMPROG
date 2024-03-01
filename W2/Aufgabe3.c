#include <stdio.h>
#include <string.h>

enum month_t { JAN=1, FEB, MAR, APR, MAI, JUN, JUL, AUG, SEP, OKT, NOV, DEZ };
// Vorwärtsdeklaration der Funktionen
int istSchaltjahr(int jahr);
int istHunderterJahr(int jahr);
int tageFuerFeb(int jahr);
int tageProMonat( int jahr, enum month_t monat);
int gibIntWert(const char *typ, int min, int max);


//Returns 0 = False and 1 = True
int istSchaltjahr(int jahr){

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



/*
    Year needs to be greater than 1599 and smaller than 10000; 
*/
int isYearValid(int year){
    if(year>=1599 && year <10000){
        return 1;
    }
    return 0; 
}

/*
   valid months are between 1-12
*/
int isMonthValid(int month){
    if(month>0 && month<13){
        return 1;
    }
    return 0; 
}

/**
 Exception for FEB  28 /29 
*/
int tageFuerFeb(int jahr){
    if (istSchaltjahr(jahr) == 1){
        return 29;
    }else{
        return 28;
    }
}

/*

*/
int tageProMonat( int jahr,enum  month_t monat){
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
            return tageFuerFeb(jahr);
        break;
        default:
            return -1; // Fehlerfall
            break;
  }
}
/*
*/
int gibIntWert(const char *typ, int min, int max){
    char input[100];
    int wert;
    while (1) {
        printf("Geben Sie %s (%d-%d) ein: ", typ, min, max);
        fgets(input, sizeof(input), stdin);
        // fgets liest auch die Zeilenumbrüche ein, deshalb entfernen wir diese
        input[strcspn(input, "\n")] = 0;
        wert = atoi(input);
        if (wert >= min && wert <= max) {
            return wert;
        } else {
            printf("Falsche Eingabe. Bitte geben Sie eine Zahl zwischen %d und %d ein.\n", min, max);
        }
    }
}

int main(int argc, char *argv[]) {
    int monat, jahr;
     
    //  Monat einlesen und Bereich ueberpruefen
    monat = gibIntWert("Monat", 1, 12);
    jahr  = gibIntWert("Jahr", 1600, 9999);
	
    //  Ausgabe zum Test
    printf("Monat: %d, Jahr: %d \n", monat, jahr);    
    
    //  Ausgabe zum Test (hier mit dem ternaeren Operator "?:")
    printf("%d ist %s Schaltjahr\n", jahr, istSchaltjahr(jahr) ? "ein" : "kein");

	// Ausgabe
	printf("Der Monat %02d-%d hat %d Tage.\n", monat, jahr, tageProMonat(jahr, monat));
   
    return 0;
}

