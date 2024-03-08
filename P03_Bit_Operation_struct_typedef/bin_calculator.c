#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define OPERAND_BUFFER_SIZE 10

typedef struct {
    unsigned  operand1, operand2;
    char  operation;
    /*Students: The Expression struct should hold the two operands and
    the operation (use a char for the operation)
    */
} Expression;



int bits_per_int() {
    return sizeof(unsigned int) * 8;
}

unsigned int parse_operand(char operand_str[]) {
    unsigned int operand;
    if (operand_str[0] == '0' && operand_str[1] == 'x') {
        sscanf(&operand_str[2], "%x", &operand);
    } else if (operand_str[0] == '0') {
        sscanf(&operand_str[1], "%o", &operand);
    } else {
        sscanf(operand_str, "%u", &operand);
    }
    return operand;
}

void print_binary(unsigned int value) {
    int binear[32];
    int i = 0;
    
    for(int i=0 ; i<32; i++){
        binear[i] = 0;
    }
    // Umwandlung in Binärzahl durch Bitmanipulation
    while (value > 0) {
        binear[i] = value % 2;
        value = value / 2;
        i++;
    }
    printf("\n");
    for (int j = 31; j >= 0; j--) {
        if((j+1)%8==0){
            printf("%s", " ' ");
        }
        printf("%d", binear[j]);
    }
    
    // Students: Print a single number as a binary string
}

void print_bit_operation_bin(Expression expression, unsigned int result) {
    printf("BIN: ");
    print_binary(expression.operand1);
    print_binary(expression.operand2);
    printf( "%c", expression.operation);
    printf("\n   -----------------------------------");
    print_binary(result);
    /* 
    Students: Print the entire operation in bin including the result

    Bin:
    00000000'00000000'00000000'00001100
    00000000'00000000'00000000'00001111 ^
    -----------------------------------
    00000000'00000000'00000000'00000011
    */
   
}

void print_bit_operation_hex(Expression expression, unsigned int result) {
    printf("\nHex: 0x%02X %c 0x%02X = 0x%02X" ,expression.operand1, expression.operation ,expression.operand2,result);

    /* 
    Students: Print the entire operation in hex including the result

    Hex:
    0x0c ^ 0x0f = 0x03
    */
}

void print_bit_operation_dec(Expression expression, unsigned int result) {
    printf("\nDEC: %u %c %u = %u" ,expression.operand1, expression.operation ,expression.operand2,result);
    /* 
    Students: Print the entire operation in hex including the result

    Dec:
    12 ^ 15 = 3
    */
}

unsigned int bit_operation(Expression expression) {
    
    if(expression.operation == '|'){
        return (unsigned int)(expression.operand1 | expression.operand2);
    }
    if(expression.operation == '&'){
        return (unsigned int)(expression.operand1 & expression.operand2);
    }
    if(expression.operation == '<'){
        return (unsigned int)(expression.operand1 < expression.operand2);
    }
    if(expression.operation == '^'){
        return (unsigned int)(expression.operand1 ^ expression.operand2);
    }
    if(expression.operation == '>'){
        return (unsigned int)(expression.operand1 > expression.operand2);
    }
    return 0;
    // Students: Do the actual bit operation and return the result
}

int main(){
    char operand1_str[10];
    char operand2_str[10];
    char operation;

    unsigned int operand1, operand2;

    do {
        printf("Geben sie die Bit-Operation ein:\n");

        scanf("%s %c %s", operand1_str, &operation, operand2_str);
        
        operand1 = parse_operand(operand1_str);
        operand2 = parse_operand(operand2_str);
        
        //Expression expression = ... ;   // Students: Create an expression
        Expression expression;
        expression.operand1 = operand1;
        expression.operand2 = operand2;
        expression.operation = operation;

        unsigned int result = bit_operation(expression);
        print_bit_operation_bin(expression, result);
        print_bit_operation_hex(expression, result);
        print_bit_operation_dec(expression, result);

        while(getchar() != '\n');
        printf("\nMöchten sie weiter machen oder abbrechen? [(n)ext|(q)uit] ");

    } while(getchar() == 'n');

    printf("Byebye..\n");
    return EXIT_SUCCESS;
}
