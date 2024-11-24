/******************
Name:Jonathan Djerassi	
ID:303013098
Assignment: ex2
*******************/

#include <stdio.h>

int main() {
	    int option;
    int numFromUser, smileNumber, cheerNumber, maxNumber;
    int   isPrime = 0;
    int digitCount, sumLeft, sumRight, sumDivisors, reversed;
    int   nextNum, i, j, digit, middle, spacesBeforeNose, spacesBetweenEyes;

    while (1) {

        // Display menu6
        printf("Choose an option:\n");
        printf("\t1. Happy Face\n");
        printf("\t2. Balanced Number\n");
        printf("\t3. Generous Number\n");
        printf("\t4. Circle Of Joy\n");
        printf("\t5. Happy Numbers\n");
        printf("\t6. Festival Of Laughter\n");
        printf("\t7. Exit\n");

        // Take user input for option
        if (scanf("%d", &option) != 1 || option < 1 || option > 7) {
            printf("This option is not available, please try again.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (option) {
	// Case 1: Draw Happy Face with given symbols for eyes, nose and mouse
	/* Example:
	* n = 3:
	* 0   0
	*   o
	* \___/
	*/
    case 1: {
                char eyes, nose, mouth;
                int size;

                printf("Enter symbols for the eyes, nose, and mouth:\n");
                scanf(" %c %c %c", &eyes, &nose, &mouth);

                // Get face size
                while (1) {
                    printf("Enter face size (odd and positive):\n");
                    if (scanf("%d", &size) != 1 || size <= 0 || size % 2 == 0) {
                        printf("The face's size must be an odd and positive number, please try again:\n");
                        while (getchar() != '\n'); // Clear input buffer
                        continue;
                    }
                    break;
                }

                // Calculate number of spaces
                spacesBetweenEyes = size - 2;
                spacesBeforeNose = size / 2;

                // Print face structure
                // 1. Print top row (eyes)
                /* for (i = 0; i < spaces_before_nose; i++) {
                     printf(" "); // Print top spaces
                 }*/
                printf("%c", eyes);
                for (i = 0; i < spacesBetweenEyes; i++) {
                    printf(" "); // Space between eyes
                }
                printf("%c\n", eyes);

                // 2. Print nose row
                for (i = 0; i < spacesBeforeNose; i++) {
                    printf(" ");
                }
                printf("%c\n", nose);

                // 3. Print mouth row

                for (i = 0; i < spacesBeforeNose; i++) {
                    printf("\\");
                    for(j=0; j<spacesBetweenEyes; j++) {
                        printf("%c", mouth);
                    }
                    printf("/\n");
            break;;
                }
                continue;


	// Case 2: determine whether the sum of all digits to the left of the middle digit(s)
	// and the sum of all digits to the right of the middle digit(s) are equal
	/* Examples:
	Balanced: 1533, 450810, 99
	Not blanced: 1552, 34
	Please notice: the number has to be bigger than 0.
	*/
	    case 2: {
                    // Get a number from the user and ensure it's positive
                    while(1) {
                        printf("Enter a number:\n");
                        scanf("%d", &numFromUser);
                        if(numFromUser <= 0) {
                            printf("Only positive number is allowed, please try again:\n");
                        } else {
                            break;  // Valid number entered, exit loop
                        }
                    }

                    // Initialize variables
                    int sumLeft = 0, sumRight = 0;
                    int digitCount = 0, middle, temp, i;

                    // Step 1: Count the digits and determine the middle
                    temp = numFromUser;
                    while (temp > 0) {
                        digitCount++;  // Increment the digit count
                        temp /= 10;  // Remove the last digit
                    }

                    middle = digitCount / 2;  // The middle index of the number

                    // Step 2: Calculate the sum of the left half and right half of the digits
                    temp = numFromUser;  // Reset temp to the original number
                    for (i = 0; i < middle; i++) {
                        sumLeft += temp % 10;  // Add the last digit to the left sum
                        temp /= 10;  // Remove the last digit
                    }

                    // Skip the middle digit if there's an odd number of digits
                    if (digitCount % 2 != 0) {
                        temp /= 10;  // Skip the middle digit
                    }

                    // Calculate the sum of the right half of the digits
                    for (i = 0; i < middle; i++) {
                        sumRight += temp % 10;  // Add the last digit to the right sum
                        temp /= 10;  // Remove the last digit
                    }

                    // Step 3: Check if the left and right sums are equal
                    if (sumLeft == sumRight) {
                        printf("This number is balanced and brings harmony!\n");
                    } else {
                        printf("This number isn't balanced and destroys harmony.\n");
                    }

                    continue;
                }

	// Case 3: determine whether the sum of the proper divisors (od an integer) is greater than the number itself
	/* Examples:
	Abudant: 12, 20, 24
	Not Abudant: 3, 7, 10
	Please notice: the number has to be bigger than 0.
	*/
	    case 3: {
                    // Get number and check if generous (abundant)
                    while(3){
                    printf("Enter a number:\n");
                    scanf("%d", &numFromUser);
                        if(numFromUser<=0) {
                            printf("Only positive number is allowed, please try again:\n");
                        }else {
                            break;
                        }}

                    sumDivisors = 0;
                    for (i = 1; i <= numFromUser / 2; i++) {
                        if (numFromUser % i == 0) {
                            sumDivisors += i;
                        }
                    }

                    if (sumDivisors > numFromUser) {
                        printf("This number is generous!\n");
                    } else {
                        printf("This number does not share.\n");
                    }
                    continue;
                }

	// Case 4: determine wether a number is a prime.
	/* Examples:
	This one brings joy: 3, 5, 11
	This one does not bring joy: 15, 8, 99
	Please notice: the number has to be bigger than 0.
	*/
    case 4: {
                    // Get number and check if prime and reverse also prime (Circle of Joy)
                    while(4){
                    printf("Enter a number:\n");
                    scanf("%d", &numFromUser);
                        if(numFromUser<=0) {
                            printf("Only positive number is allowed, please try again:\n");
                        }else {
                            break;
                        }}

                    // Check if prime
                    isPrime = 1;
                    for (i = 2; i * i <= numFromUser; i++) {
                        if (numFromUser % i == 0) {
                            isPrime = 0;
                            break;
                        }
                    }

                    // Reverse the number
                    reversed = 0;
                    int temp = numFromUser;
                    while (temp > 0) {
                        reversed = reversed * 10 + temp % 10;
                        temp /= 10;
                    }

                    // Check if reversed number is prime
                    int is_reversed_prime = 1;
                    for (i = 2; i * i <= reversed; i++) {
                        if (reversed % i == 0) {
                            is_reversed_prime = 0;
                            break;
                        }
                    }

                    // Check if both are prime
                    if (isPrime && is_reversed_prime) {
                        printf("This number completes the circle of joy!\n");
                    } else {
                        printf("The circle remains incomplete.\n");
                    }
                    continue;
                }

	// Happy numbers: Print all the happy numbers between 1 to the given number.
	// Happy number is a number which eventually reaches 1 when replaced by the sum of the square of each digit
	/* Examples:
	Happy :) : 7, 10
	Not Happy :( : 5, 9
	Please notice: the number has to be bigger than 0.
	*/
	     case 5: {
                    // Get maximum number and print happy numbers up to it
                    while(1) {
                        printf("Enter a number:\n");
                        scanf("%d", &numFromUser);
                        if(numFromUser <= 0) {
                            printf("Only positive number is allowed, please try again:\n");
                        } else {
                            break;  // Valid input, exit loop
                        }
                    }

                    printf("Between 1 and %d only these numbers bring happiness: ", numFromUser);

                    for (i = 1; i <= numFromUser; i++) {
                        int temp = i;
                        int nextNum;

                        // Check if the number is a happy number
                        while (temp != 1 && temp != 4) {  // If we reach 4, it's a known unhappy cycle
                            nextNum = 0;

                            // Sum the squares of the digits of the current number
                            while (temp > 0) {
                                int digit = temp % 10;
                                nextNum += digit * digit;
                                temp /= 10;
                            }

                            temp = nextNum;  // Move to the next number
                        }

                        // If we reach 1, it's a happy number
                        if (temp == 1) {
                            printf("%d ", i);
                        }
                    }

                    printf("\n");
                    continue;
                }

	// Festival of Laughter: Prints all the numbers between 1 the given number:
	// and replace with "Smile!" every number that divided by the given smile number
	// and replace with "Cheer!" every number that divided by the given cheer number
	// and replace with "Festival!" every number that divided by both of them
	/* Example:
	6, smile: 2, cheer: 3 : 1, Smile!, Cheer!, Smile!, 5, Festival!
	*/
		       case 6:{


                    // Get smile number, cheer number, and max number for festival

while(6) {
    printf("Enter a smile and cheer number:\n");
    // Check for valid numbers
    if( scanf(" %d %d", &smileNumber, &cheerNumber) != 2 || smileNumber<=0 || cheerNumber<=0 || smileNumber == cheerNumber) {
        printf("Only 2 different positive numbers are allowed for the festival, please try again:\n");

        while(getchar() !='\n');
        continue;
    }break;
}



                    // Get maximum number for the festival
                    while(6) {
                        printf("Enter maximum number for the festival:\n");
                        if(scanf("%d", &maxNumber)!= 1 || maxNumber<=0 || maxNumber<=0) {
                            printf("Only positive number is alowed, please try again:");
                            while(getchar() !='\n');
                            continue;
                        }
                        break;
                    }

                    // Loop through and print festival numbers
                    for (i = 1; i <= maxNumber; i++) {
                        if (i % smileNumber == 0 && i % cheerNumber == 0) {
                            printf("Festival!\n");
                        } else if (i % smileNumber == 0) {
                            printf("Smile!\n");
                        } else if (i % cheerNumber == 0) {
                            printf("Cheer!\n");
                        } else {
                            printf("%d \n", i);
                        }
                    }
                    printf("\n");
                    continue;
                }

                case 7:
                    printf("Thank you for your journey through Numeria!\n");
                return 0;
            }
        }
	return 0;
}
