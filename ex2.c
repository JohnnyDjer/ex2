/******************
Name:Jonathan Djerassi	
ID:
Assignment: ex2
*******************/

#include <stdio.h>


#define INPUT_VALIDATION 1
#include <stdio.h>

int main() {
    int option;
    int numFromUser, smileNumber, cheerNumber, maxNumber;
    int isPrime = 0;
    int i, j;

    while (INPUT_VALIDATION) {
        // Display menu

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
            scanf("%*[^\n]");   // Discards any characters up to the newline
            scanf("%*c");
            continue;
        }

        switch (option) {
            //Happy Face
            case 1: {
                char eyes, nose, mouth;
                int size;
                printf("Enter symbols for the eyes, nose, and mouth:\n");

                scanf(" %c %c %c", &eyes, &nose, &mouth);

                // Get face size
                printf("Enter face size:\n");
                while (INPUT_VALIDATION) {
                    scanf("%*[^\n]");
                    scanf("%*c");
                    if (scanf("%d", &size) != 1 || size <= 0 || size % 2 == 0) {
                        printf("The face's size must be an odd and positive number, please try again:\n");

                        continue;
                    }
                    break;
                }

                // Calculate number of spaces
                int spacesBetweenEyes = size - 2;
                int spacesBeforeNose = size / 2;

                // Print face structure

                // 1. Print top row (eyes)

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
                    for(j=0; j<spacesBetweenEyes+2; j++) {
                        printf("%c", mouth);
                    }
                    printf("/\n");
                    break;;
                }
                continue;

                case 2: {
                    printf("Enter a number:\n");
                    while (INPUT_VALIDATION) {
                        scanf("%*[^\n]"); // Discard any extra input
                        scanf("%*c");
                        if (scanf("%d", &numFromUser) != 1 || numFromUser <= 0) {
                            printf("Only positive number is allowed, please try again:\n");
                            continue;
                        }
                        break;
                    }

                    int sumLeft = 0, sumRight = 0;
                    int digitCount = 0, middle, temp, i;

                    temp = numFromUser;
                    while (temp > 0) {
                        digitCount++;
                        temp /= 10;
                    }

                    middle = digitCount / 2;

                    temp = numFromUser;
                    for (i = 0; i < middle; i++) {
                        sumLeft += temp % 10;
                        temp /= 10;
                    }

                    if (digitCount % 2 != 0) {
                        temp /= 10;
                    }

                    for (i = 0; i < middle; i++) {
                        sumRight += temp % 10;
                        temp /= 10;
                    }

                    if (sumLeft == sumRight) {
                        printf("This number is balanced and brings harmony!\n");
                    } else {
                        printf("This number isn't balanced and destroys harmony.\n");
                    }
                    continue;
                }

                case 3: {
                    printf("Enter a number:\n");
                    while (INPUT_VALIDATION) {
                        scanf("%*[^\n]"); // Discard any extra input
                        scanf("%*c");
                        if (scanf("%d", &numFromUser) != 1 || numFromUser <= 0) {
                            printf("Only positive number is allowed, please try again:\n");
                            continue;
                        }
                        break;
                    }

                    int sumDivisors = 0;
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

                case 4: {
                    printf("Enter a number:\n");
                    while (INPUT_VALIDATION) {
                        scanf("%*[^\n]"); // Discard any extra input
                        scanf("%*c");
                        if (scanf("%d", &numFromUser) != 1 || numFromUser <= 0) {
                            printf("Only positive number is allowed, please try again:\n");
                            continue;
                        }
                        break;
                    }

                    isPrime = 1;
                    for (i = 2; i * i <= numFromUser; i++) {
                        if (numFromUser % i == 0) {
                            isPrime = 0;
                            break;
                        }
                    }

                    int reversed = 0;
                    int temp = numFromUser;
                    while (temp > 0) {
                        reversed = reversed * 10 + temp % 10;
                        temp /= 10;
                    }

                    int is_reversed_prime = 1;
                    for (i = 2; i * i <= reversed; i++) {
                        if (reversed % i == 0) {
                            is_reversed_prime = 0;
                            break;
                        }
                    }

                    if (isPrime && is_reversed_prime) {
                        printf("This number completes the circle of joy!\n");
                    } else {
                        printf("The circle remains incomplete.\n");
                    }
                    continue;
                }

                case 5: {
                    printf("Enter a number:\n");
                    while (INPUT_VALIDATION) {
                        scanf("%*[^\n]"); // Discard any extra input
                        scanf("%*c");
                        if (scanf("%d", &numFromUser) != 1 || numFromUser <= 0) {
                            printf("Only positive number is allowed, please try again:\n");
                            continue;
                        }
                        break;
                    }

                    printf("Between 1 and %d only these numbers bring happiness: ", numFromUser);

                    for (i = 1; i <= numFromUser; i++) {
                        int temp = i;
                        int nextNum;

                        while (temp != 1 && temp != 4) {
                            nextNum = 0;
                            while (temp > 0) {
                                int digit = temp % 10;
                                nextNum += digit * digit;
                                temp /= 10;
                            }
                            temp = nextNum;
                        }

                        if (temp == 1) {
                            printf("%d ", i);
                        }
                    }
                    printf("\n");
                    continue;
                }

                case 6: {
                    printf("Enter a smile and cheer number:\n");

                    while (INPUT_VALIDATION) {
                        // Clear the buffer if any previous input is left
                        scanf("%*[^\n]");
                        scanf("%*c");
                        // Read two integers for smile and cheer

                        if (scanf(" smile : %d, cheer : %d", &smileNumber, &cheerNumber) != 2 || smileNumber <= 0 || cheerNumber <= 0 || smileNumber == cheerNumber) {
                            // Ensure valid input: two positive integers, and they must be different
                            printf("Only 2 different positive numbers in the given format are allowed for the festival, please try again:\n");
                        } else {
                            break;  // Valid input, break out of the loop
                        }
                    }

                    // Get the maximum number for the festival
                    printf("Enter maximum number for the festival:\n");
                    while (INPUT_VALIDATION) {

                        // Clear the buffer before reading the next input
                        scanf("%*[^\n]");
                        scanf("%*c");
                        if (scanf("%d", &maxNumber) != 1 || maxNumber <= 0) {
                            printf("Only positive maximum number is allowed, please try again:\n");
                        } else {
                            break;  // Valid input, break out of the loop
                        }
                    }

                    // Print the festival results
                    for (i = 1; i <= maxNumber; i++) {
                        if (i % smileNumber == 0 && i % cheerNumber == 0) {
                            printf("Festival!\n");
                        } else if (i % smileNumber == 0) {
                            printf("Smile!\n");
                        } else if (i % cheerNumber == 0) {
                            printf("Cheer!\n");
                        } else {
                            printf("%d \n", i);  // If no conditions met, print the number
                        }
                    }

                    continue; // Continue to the next option
                }

                case 7:
                    printf("Thank you for your journey through Numeria!\n");
                return 0;

                default:
                    printf("This option is not available, please try again.\n");
                break;
            }
        }
    }
}
