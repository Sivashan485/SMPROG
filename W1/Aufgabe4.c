//
// Created by Sivashan Sivakumaran on 23.02.24.
//

#include <stdio.h>

int main(void){
    //setting default values
    int characterCounter = 0;
    int wordCounter = 0;
    char sentence = 0;
    int currentCharacter=0;

    //user input as a sentence
    scanf("%c", &sentence);

    //The while loop runs until it encounters the character \n
    while ((currentCharacter = getchar()) != "\n")
    {
        //character is also \t and ' '
        ++characterCounter;
        //A Word is seperated by ' ' or a \t
        if(currentCharacter==' '||currentCharacter=='\t'){
            ++wordCounter;
        }
        //ends when it encounters \n
        if(currentCharacter=='\n'){
            break;
        }
    }

    //printing statistics
    printf("\n CHARACTERS: %d", characterCounter);
    printf("\n WORDS:  %d", wordCounter+1);

    return 0;
}
