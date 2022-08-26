/*
 * Homework Menu System
 * Yes! You can turn in ONE file even if there are multiple programs required for the assignment
 Josh Wallace 11/04/2018*/
 


#include <stdio.h>   //header file for input/output
#define TEST 4
#define SCORES 10
#define SIZE 10

int menu(void);   //prototype definition
/*Place the function prototypes for your programs here! */
void hello(void);
void grades(void);
void sum_fun(void);
int sump(int * start, int * end);
int min(int ar []);
int max(int ar []);

int main(void)
{
    int selection = menu();  //variable declaration and initialization via call to menu()
    //The line above also serves as the 'priming' read for the following while loop
    
    
    while(selection != 99) {
    
        // The switch statement is similar to a chained if-else except conditions fall through in C!
        switch(selection) {

        case 1:
           hello();  
           break;  
           
        case 2:
            grades();
           break;
         
        case 3: sum_fun();
           break;

        case 4:
        
           break;  
           
         default: /* Optional - but a good idea expecially if you have no other error catching! */
            printf("Please enter a valid selection.\n");
        }
        
    selection = menu();    // get the next menu selection, otherwise, you have an eternal loop!
    }
    
   return 0;
}
 
int menu(void) {
    int choice;
    printf("***************************\n");
    printf(" 1. Hello \n");
    printf(" 2. Grades \n");
    printf(" 3. Sum Fun\n");
    printf(" 4. \n");
    printf("99. Exit\n");
    printf("Please select number and press enter:\n");
    printf("***************************\n");
    scanf("%d", &choice);
    return choice;   
}
void hello(void) {
    printf("Hello, World!!!\n");
}

void grades(void) {
float subtot, total;
int test, scores;
const float grade[TEST][SCORES] = {
        {65,75,85,95,74,74,98,75,85,65},
        {88,65,75,78,99,88,87,76,98,100},
        {78,65,78,82,93,81,99,97,82,65},
        {68,82,75,65,100,85,87,85,95,85}    };
        
    printf("TEST      AVERAGE\n");
    for (test = 0; test < TEST; test++){           
    for (scores = 0, subtot = 0; scores < SCORES; scores++)
            subtot += grade[test][scores];
        printf("%d %12.1f\n", test+1, subtot / SCORES);
    }
    printf("\n");
    
    printf("STUDENT AVERAGES: \n");
    printf("STU1    STU2    STU3    STU4    STU5    STU6    STU7    STU8    STU9    STU10 \n");
    for (scores = 0; scores < SCORES; scores++) {           
    for (test = 0, subtot = 0; test < TEST; test++)
            subtot += grade[test][scores];
            printf("%.1f    ", subtot / TEST);
    }
    printf("\n");
}

void sum_fun(void) {
    int marbles[SIZE] = {20,10,5,39,4,16,19,26,31,20};
    long answer;
    
    answer = sump(marbles, marbles + SIZE);
    printf("The total number of marbles is %ld.\n", answer);
    printf("The size of the marbles is %zd bytes. \n", sizeof marbles);
    printf("The smallest number is %d\n", min(marbles));
    printf("The largest number is %d\n", max(marbles));
}

int sump(int * start, int * end)
{
    int total = 0;
    
    while (start < end)
    {
        total += *start; // add value to total
        start++;         // advance pointer to next element
    }
    
    return total;
}

int min(int ar []){
    int min;
  for (int i = 0; i < SIZE; i++){
      if (ar[i] < ar[1])
      min = ar[i];
  }
  return min;

}

int max(int ar []){
  int max = ar[0];
  for (int i = 0; i < SIZE; i++){
      if (max < ar[i])
      max = ar[i];
  }
  return max;

}


