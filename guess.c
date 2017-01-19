#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//// Helper Functions

// Generate a randum number between 0 - 100 
int getRand();

// Compare the two numbers and return if they are matched
int cmpNumber(int number, int mynumber);
 
int main() 
{
   // declarations
   int number, mynumber, guess, tries;
   int MAXTRY = 5;

   //char *z = "Atif"; 

   // printf("Hello, %s. Let's play a guessing game.\n",z);
    printf("Let's play a guessing game. I am thinking of a number between 1-100. Guess it in %d tries.\n",MAXTRY);

   // call the random number generator function
    number = getRand();

    //printf("My Number to guess: %d\n",number);

    //printf("My number is, %d", mynumber);

    // guess = 0 is not guessed guess = 1 is the number is guessed correctly
    guess = 0;
    tries = 1;
    while ((guess == 0) && (tries <= MAXTRY))
	{
	if (tries == 5)
	  {
		printf("Last Chance! Think hard.\n");
	  }
    	printf("%d Try. Guess my number: ",tries);
    	scanf("%d", &mynumber);
    	guess =	cmpNumber(number,mynumber);
	tries++;
	}
  
    if (guess == 0)
	{
	  printf("My number was: %d\n",number);
	  printf("LOSER!!!!!!\n");
	}	

    return 0;
}

int cmpNumber(int number, int mynumber)
{
  int g;
  if(number == mynumber)
	{
		printf("You WIN!!!!! You have guessed my number!\n");
		g = 1;
	}
  else if (number > mynumber)
	{
		printf("Your guess is too low!\n");
		g = 0;
	}
  else  
	{
		printf("Your guess is too high!\n");
		g = 0;
	}

  return g;
}

int getRand()
{
 int number;
 time_t t;

 srand((unsigned) time(&t));
 //number = printf("%d\n", rand() %100);
 number = rand() %100;
 return number;

}
