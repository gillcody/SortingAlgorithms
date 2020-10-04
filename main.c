/*
Author: Cody Gill
File Name: main.c
*/
#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include "main.h"

void printMenu()
{
        printf("\n#################################\n");
        printf("#           Sort Menu           #\n");
        printf("#################################\n");
        printf(" 1 - Heap Sort\n");
	printf(" 2 - Insertion Sort\n");
	printf(" 3 - Merge Sort\n");
	printf(" 4 - Quick Sort\n");
	printf(" 5 - Selection Sort\n");	
	printf(" 6 - Radix Sort\n");
	printf(" 7 - Bubble Sort\n");
        printf(" 0 - Quit\n");
        printf("Enter selection for preferred method of sorting: ");

}

int main (int argc, char *argv[])
{
        int choice; //the sort method the user would like to use
        int type; //whether the user wants to search for a string or int
        int search; //whether the user would like to use linear or binary search
        int userInt; //the int that user would like to serach for
        char userString[5]; //the string the user would like to search for
        int i;
        char a[][MAX_LEN] = {"AAAAA", "a", "AAA", "aaaa", "AAa", "AAAAa", "AAa", "A", "aa", "Aaa"};
        int b[] = {654, 18, 81, 4, 92, 68, 145, 8, 99, 36};
        int n = sizeof(b)/sizeof(b[0]);
	printf("%d\n", n);

        while(TRUE)
        {
                printMenu();
                scanf("%d", &choice);
                printf("\n");

                switch(choice)
                {
                        case 1:
                                printf("Would you like to sort via int or string?\n");
                                printf("Enter 1 for int, 2 for string: ");
                                scanf("%d", &type);

                                if (type == 1)
                                {
                                        heapSort_int(b, n);
                                        printf("\nSorted array is:\n");

                                        for(i = 0; i < n; i++)
                                        {
                                                printf("%d ", b[i]);
                                        }

                                        printf("\nEnter the value you would like to search for: ");
                                        scanf("%d", &userInt);
                                        printf("\n");
                                        printf("Would you like to use linear or binary search?\n");
                                        printf("Enter 1 for linear, 2 for binary: ");
                                        scanf("%d", &search);
                                        printf("\n");

                                        if (search == 1)
                                        {
                                                if (linearSearchIterative_int(b, n, userInt) == -1)
                                                {
                                                        printf("Integer not found.\n");
                                                }
                                                else
                                                {
                                                        printf("%d is in position %d of the array.\n", userInt, 
                                                        linearSearchIterative_int(b, n, userInt));
                                                }
                                        }
                                        else if (search == 2)
                                        {
                                                if (BinarySearchIterative_int(b, n, userInt) == -1)
                                                {
                                                        printf("Integer not found.\n");
                                                }
                                                else
                                                {
                                                        printf("%d is in position %d of the array.\n", userInt, 
                                                        BinarySearchIterative_int(b, n, userInt));
                                                }

                                        }
                                        else
                                        {
                                                printf("Invalid entry.");
                                        }
                                }
                                else if (type == 2)
                                {
                                        heapSort_str(a, n);
                                        printf("\nSorted array is:\n");
                                        for (i = 0; i < n; i++)
                                        {
                                                printf("%s ", a[i]);
                                        }
                                        printf("\nEnter the string you would like to search for: ");
                                        scanf("%s", userString);
                                        printf("\n");
                                        printf("Would you like to use linear or binary search?\n");
                                        printf("Enter 1 for linear, 2 for binary: ");
                                        scanf("%d", &search);
                                        printf("\n");

                                        if (search == 1)
                                        {
						if (linearSearchIterative_str(a, n, userString) == -1)
						{
							printf("String not found.\n");
						}
						else
						{
							printf("%s is in position %d of the array.\n", userString, 
                                                        linearSearchIterative_str(a, n, userString));
						}
                                        }
					else if (search == 2)
					{
						if (BinarySearchIterative_str(a, n, userString) == -1)
						{
							printf("String not found.\n");
						}
						else
						{
							printf("%s is in position %d of the array.\n", userString, 
                                                        BinarySearchIterative_str(a, n, userString));

						}
					}
					else 
					{
						printf("Invalid entry.");
					}

                                }
                                else
                                {
                                        printf("Invalid entry.\n");
                                }
                                printf("\n");
                                break;

			case 2:
				printf("Would you like to sort via int or string?\n");
                                printf("Enter 1 for int, 2 for string: ");
                                scanf("%d", &type);

                                if (type == 1)
                                {
                                        insertionSort_int(b, n);
                                        printf("\nSorted array is:\n");

                                        for(i = 0; i < n; i++)
                                        {
                                                printf("%d ", b[i]);
                                        }

                                        printf("\nEnter the value you would like to search for: ");
                                        scanf("%d", &userInt);
                                        printf("\n");
                                        printf("Would you like to use linear or binary search?\n");
                                        printf("Enter 1 for linear, 2 for binary: ");
                                        scanf("%d", &search);
                                        printf("\n");

                                        if (search == 1)
                                        {
                                                if (linearSearchIterative_int(b, n, userInt) == -1)
                                                {
                                                        printf("Integer not found.\n");
                                                }
                                                else
                                                {
                                                        printf("%d is in position %d of the array.\n", userInt, 
                                                        linearSearchIterative_int(b, n, userInt));
                                                }
                                        }
					else if (search == 2)
                                        {
                                                if (BinarySearchIterative_int(b, n, userInt) == -1)
                                                {
                                                        printf("Integer not found.\n");
                                                }
                                                else
                                                {
                                                        printf("%d is in position %d of the array.\n", userInt, 
                                                        BinarySearchIterative_int(b, n, userInt));
                                                }

                                        }
                                        else
                                        {
                                                printf("Invalid entry.");
                                        }
                                }
				else if (type == 2)
                                {
                                        InsertionSort_str(a, n);
                                        printf("\nSorted array is:\n");
                                        for (i = 0; i < n; i++)
                                        {
                                                printf("%s ", a[i]);
                                        }
                                        printf("\nEnter the string you would like to search for: ");
                                        scanf("%s", userString);
                                        printf("\n");
                                        printf("Would you like to use linear or binary search?\n");
                                        printf("Enter 1 for linear, 2 for binary: ");
                                        scanf("%d", &search);
                                        printf("\n");

                                        if (search == 1)
                                        {
                                                if (linearSearchIterative_str(a, n, userString) == -1)
                                                {
                                                        printf("String not found.\n");
                                                }
                                                else
                                                {
                                                        printf("%s is in position %d of the array.\n", userString, 
                                                        linearSearchIterative_str(a, n, userString));
                                                }
                                        }
                                        else if (search == 2)
                                        {
                                                if (BinarySearchIterative_str(a, n, userString) == -1)
                                                {
                                                        printf("String not found.\n");
                                                }
                                                else
                                                {
                                                        printf("%s is in position %d of the array.\n", userString, 
                                                        BinarySearchIterative_str(a, n, userString));

                                                }
                                        }
                                        else
                                        {
                                                printf("Invalid entry.");
                                        }

                                }
                                else
                                {
                                        printf("Invalid entry.\n");
                                }
                                printf("\n");
				break;

			case 3:
				printf("Would you like to sort via int or string?\n");
                                printf("Enter 1 for int, 2 for string: ");
                                scanf("%d", &type);

                                if (type == 1)
                                {
                                        mergeSort_int(b, 0, n - 1);
                                        printf("\nSorted array is:\n");

                                        for(i = 0; i < n; i++)
                                        {
                                                printf("%d ", b[i]);
                                        }

                                        printf("\nEnter the value you would like to search for: ");
                                        scanf("%d", &userInt);
                                        printf("\n");
                                        printf("Would you like to use linear or binary search?\n");
                                        printf("Enter 1 for linear, 2 for binary: ");
                                        scanf("%d", &search);
                                        printf("\n");

                                        if (search == 1)
                                        {
                                                if (linearSearchIterative_int(b, n, userInt) == -1)
                                                {
                                                        printf("Integer not found.\n");
                                                }
                                                else
                                                {
                                                        printf("%d is in position %d of the array.\n", userInt, 
                                                        linearSearchIterative_int(b, n, userInt));
                                                }
                                        }
                                        else if (search == 2)
                                        {
                                                if (BinarySearchIterative_int(b, n, userInt) == -1)
                                                {
                                                        printf("Integer not found.\n");
                                                }
                                                else
                                                {
                                                        printf("%d is in position %d of the array.\n", userInt, 
                                                        BinarySearchIterative_int(b, n, userInt));
                                                }

                                        }
                                        else
                                        {
                                                printf("Invalid entry.");
                                        }
                                }
				else if (type == 2)
                                {
                                        mergeSort_str(a, 0, n -1);
                                        printf("\nSorted array is:\n");
                                        for (i = 0; i < n; i++)
                                        {
                                                printf("%s ", a[i]);
                                        }
                                        printf("\nEnter the string you would like to search for: ");
                                        scanf("%s", userString);
                                        printf("\n");
                                        printf("Would you like to use linear or binary search?\n");
                                        printf("Enter 1 for linear, 2 for binary: ");
                                        scanf("%d", &search);
                                        printf("\n");

                                        if (search == 1)
                                        {
                                                if (linearSearchIterative_str(a, n, userString) == -1)
                                                {
                                                        printf("String not found.\n");
                                                }
                                                else
                                                {
                                                        printf("%s is in position %d of the array.\n", userString, 
                                                        linearSearchIterative_str(a, n, userString));
                                                }
                                        }
                                        else if (search == 2)
                                        {
                                                if (BinarySearchIterative_str(a, n, userString) == -1)
                                                {
                                                        printf("String not found.\n");
                                                }
                                                else
                                                {
                                                        printf("%s is in position %d of the array.\n", userString, 
                                                        BinarySearchIterative_str(a, n, userString));

                                                }
                                        }
                                        else
                                        {
                                                printf("Invalid entry.");
                                        }

                                }
                                else
                                {
                                        printf("Invalid entry.\n");
                                }
                                printf("\n");
                                break;

			case 4:
				printf("Would you like to sort via int or string?\n");
                                printf("Enter 1 for int, 2 for string: ");
                                scanf("%d", &type);

                                if (type == 1)
                                {
                                        quickSort_int(b, 0, n - 1);
                                        printf("\nSorted array is:\n");

                                        for(i = 0; i < n; i++)
                                        {
                                                printf("%d ", b[i]);
                                        }

                                        printf("\nEnter the value you would like to search for: ");
                                        scanf("%d", &userInt);
                                        printf("\n");
                                        printf("Would you like to use linear or binary search?\n");
                                        printf("Enter 1 for linear, 2 for binary: ");
                                        scanf("%d", &search);
                                        printf("\n");

                                        if (search == 1)
                                        {
                                                if (linearSearchIterative_int(b, n, userInt) == -1)
                                                {
                                                        printf("Integer not found.\n");
                                                }
                                                else
                                                {
                                                        printf("%d is in position %d of the array.\n", userInt, 
                                                        linearSearchIterative_int(b, n, userInt));
                                                }
                                        }
                                        else if (search == 2)
                                        {
                                                if (BinarySearchIterative_int(b, n, userInt) == -1)
                                                {
                                                        printf("Integer not found.\n");
                                                }
                                                else
                                                {
                                                        printf("%d is in position %d of the array.\n", userInt, 
                                                        BinarySearchIterative_int(b, n, userInt));
                                                }

                                        }
                                        else
                                        {
                                                printf("Invalid entry.");
                                        }
                                }
				else if (type == 2)
                                {
                                        quickSort_str(a, 0, n - 1);
                                        printf("\nSorted array is:\n");
                                        for (i = 0; i < n; i++)
                                        {
                                                printf("%s ", a[i]);
                                        }
                                        printf("\nEnter the string you would like to search for: ");
                                        scanf("%s", userString);
                                        printf("\n");
                                        printf("Would you like to use linear or binary search?\n");
                                        printf("Enter 1 for linear, 2 for binary: ");
                                        scanf("%d", &search);
                                        printf("\n");

                                        if (search == 1)
                                        {
                                                if (linearSearchIterative_str(a, n, userString) == -1)
                                                {
                                                        printf("String not found.\n");
                                                }
                                                else
                                                {
                                                        printf("%s is in position %d of the array.\n", userString, 
                                                        linearSearchIterative_str(a, n, userString));
                                                }
                                        }
                                        else if (search == 2)
                                        {
                                                if (BinarySearchIterative_str(a, n, userString) == -1)
                                                {
                                                        printf("String not found.\n");
                                                }
                                                else
                                                {
                                                        printf("%s is in position %d of the array.\n", userString, 
                                                        BinarySearchIterative_str(a, n, userString));

                                                }
                                        }
                                        else
                                        {
                                                printf("Invalid entry.");
                                        }

                                }
                                else
                                {
                                        printf("Invalid entry.\n");
                                }
                                printf("\n");
                                break;

			case 5:
				printf("Would you like to sort via int or string?\n");
                                printf("Enter 1 for int, 2 for string: ");
                                scanf("%d", &type);

                                if (type == 1)
                                {
                                        selectionSort_int(b, n);
                                        printf("\nSorted array is:\n");

                                        for(i = 0; i < n; i++)
                                        {
                                                printf("%d ", b[i]);
                                        }

                                        printf("\nEnter the value you would like to search for: ");
                                        scanf("%d", &userInt);
                                        printf("\n");
                                        printf("Would you like to use linear or binary search?\n");
                                        printf("Enter 1 for linear, 2 for binary: ");
                                        scanf("%d", &search);
                                        printf("\n");

                                        if (search == 1)
                                        {
                                                if (linearSearchIterative_int(b, n, userInt) == -1)
                                                {
                                                        printf("Integer not found.\n");
                                                }
                                                else
                                                {
                                                        printf("%d is in position %d of the array.\n", userInt, 
                                                        linearSearchIterative_int(b, n, userInt));
                                                }
                                        }
                                        else if (search == 2)
                                        {
                                                if (BinarySearchIterative_int(b, n, userInt) == -1)
                                                {
                                                        printf("Integer not found.\n");
                                                }
                                                else
                                                {
                                                        printf("%d is in position %d of the array.\n", userInt, 
                                                        BinarySearchIterative_int(b, n, userInt));
                                                }

                                        }
                                        else
                                        {
                                                printf("Invalid entry.");
                                        }
                                }
				else if (type == 2)
                                {
                                        selectionSort_str(a, n);
                                        printf("\nSorted array is:\n");
                                        for (i = 0; i < n; i++)
                                        {
                                                printf("%s ", a[i]);
                                        }
                                        printf("\nEnter the string you would like to search for: ");
                                        scanf("%s", userString);
                                        printf("\n");
                                        printf("Would you like to use linear or binary search?\n");
                                        printf("Enter 1 for linear, 2 for binary: ");
                                        scanf("%d", &search);
                                        printf("\n");

                                        if (search == 1)
                                        {
                                                if (linearSearchIterative_str(a, n, userString) == -1)
                                                {
                                                        printf("String not found.\n");
                                                }
                                                else
                                                {
                                                        printf("%s is in position %d of the array.\n", userString, 
                                                        linearSearchIterative_str(a, n, userString));
                                                }
                                        }
                                        else if (search == 2)
                                        {
                                                if (BinarySearchIterative_str(a, n, userString) == -1)
                                                {
                                                        printf("String not found.\n");
                                                }
                                                else
                                                {
                                                        printf("%s is in position %d of the array.\n", userString, 
                                                        BinarySearchIterative_str(a, n, userString));

                                                }
                                        }
                                        else
                                        {
                                                printf("Invalid entry.");
                                        }

                                }
                                else
                                {
                                        printf("Invalid entry.\n");
                                }
                                printf("\n");
                                break;

			case 6:
				printf("Would you like to sort via int or string?\n");
                                printf("Enter 1 for int, 2 for string: ");
                                scanf("%d", &type);

                                if (type == 1)
                                {
                                        radixSort_int(b, n);
                                        printf("\nSorted array is:\n");

                                        for(i = 0; i < n; i++)
                                        {
                                                printf("%d ", b[i]);
                                        }

                                        printf("\nEnter the value you would like to search for: ");
                                        scanf("%d", &userInt);
                                        printf("\n");
                                        printf("Would you like to use linear or binary search?\n");
                                        printf("Enter 1 for linear, 2 for binary: ");
                                        scanf("%d", &search);
                                        printf("\n");

                                        if (search == 1)
                                        {
                                                if (linearSearchIterative_int(b, n, userInt) == -1)
                                                {
                                                        printf("Integer not found.\n");
                                                }
                                                else
                                                {
                                                        printf("%d is in position %d of the array.\n", userInt, 
                                                        linearSearchIterative_int(b, n, userInt));
                                                }
                                        }
                                        else if (search == 2)
                                        {
                                                if (BinarySearchIterative_int(b, n, userInt) == -1)
                                                {
                                                        printf("Integer not found.\n");
                                                }
                                                else
                                                {
                                                        printf("%d is in position %d of the array.\n", userInt, 
                                                        BinarySearchIterative_int(b, n, userInt));
                                                }

                                        }
                                        else
                                        {
                                                printf("Invalid entry.");
                                        }
                                }
				else if (type == 2)
                                {
                                        radix_sort_string(a, n);
                                        printf("\nSorted array is:\n");
                                        for (i = 0; i < n; i++)
                                        {
                                                printf("%s ", a[i]);
                                        }
                                        printf("\nEnter the string you would like to search for: ");
                                        scanf("%s", userString);
                                        printf("\n");
                                        printf("Would you like to use linear or binary search?\n");
                                        printf("Enter 1 for linear, 2 for binary: ");
                                        scanf("%d", &search);
                                        printf("\n");

                                        if (search == 1)
                                        {
                                                if (linearSearchIterative_str(a, n, userString) == -1)
                                                {
                                                        printf("String not found.\n");
                                                }
                                                else
                                                {
                                                        printf("%s is in position %d of the array.\n", userString, 
                                                        linearSearchIterative_str(a, n, userString));
                                                }
                                        }
                                        else if (search == 2)
                                        {
                                                if (BinarySearchIterative_str(a, n, userString) == -1)
                                                {
                                                        printf("String not found.\n");
                                                }
                                                else
                                                {
                                                        printf("%s is in position %d of the array.\n", userString, 
                                                        BinarySearchIterative_str(a, n, userString));

                                                }
                                        }
                                        else
                                        {
                                                printf("Invalid entry.");
                                        }

                                }
                                else
                                {
                                        printf("Invalid entry.\n");
                                }
                                printf("\n");
                                break;

			case 7:
				printf("Would you like to sort via int or string?\n");
                                printf("Enter 1 for int, 2 for string: ");
                                scanf("%d", &type);

                                if (type == 1)
                                {
                                        bubbleSort_int(b, n);
                                        printf("\nSorted array is:\n");

                                        for(i = 0; i < n; i++)
                                        {
                                                printf("%d ", b[i]);
                                        }

                                        printf("\nEnter the value you would like to search for: ");
                                        scanf("%d", &userInt);
                                        printf("\n");
                                        printf("Would you like to use linear or binary search?\n");
                                        printf("Enter 1 for linear, 2 for binary: ");
                                        scanf("%d", &search);
                                        printf("\n");

                                        if (search == 1)
                                        {
                                                if (linearSearchIterative_int(b, n, userInt) == -1)
                                                {
                                                        printf("Integer not found.\n");
                                                }
                                                else
                                                {
                                                        printf("%d is in position %d of the array.\n", userInt, 
                                                        linearSearchIterative_int(b, n, userInt));
                                                }
                                        }
					else if (search == 2)
                                        {
                                                if (BinarySearchIterative_int(b, n, userInt) == -1)
                                                {
                                                        printf("Integer not found.\n");
                                                }
                                                else
                                                {
                                                        printf("%d is in position %d of the array.\n", userInt, 
                                                        BinarySearchIterative_int(b, n, userInt));
                                                }

                                        }
                                        else
                                        {
                                                printf("Invalid entry.");
                                        }
                                }
				 else if (type == 2)
                                {
                                        bubbleSort_str(a, n);
                                        printf("\nSorted array is:\n");
                                        for (i = 0; i < n; i++)
                                        {
                                                printf("%s ", a[i]);
                                        }
                                        printf("\nEnter the string you would like to search for: ");
                                        scanf("%s", userString);
                                        printf("\n");
                                        printf("Would you like to use linear or binary search?\n");
                                        printf("Enter 1 for linear, 2 for binary: ");
                                        scanf("%d", &search);
                                        printf("\n");

                                        if (search == 1)
                                        {
                                                if (linearSearchIterative_str(a, n, userString) == -1)
                                                {
                                                        printf("String not found.\n");
                                                }
                                                else
                                                {
                                                        printf("%s is in position %d of the array.\n", userString, 
                                                        linearSearchIterative_str(a, n, userString));
                                                }
                                        }
                                        else if (search == 2)
                                        {
                                                if (BinarySearchIterative_str(a, n, userString) == -1)
                                                {
                                                        printf("String not found.\n");
                                                }
                                                else
                                                {
                                                        printf("%s is in position %d of the array.\n", userString, 
                                                        BinarySearchIterative_str(a, n, userString));

                                                }
                                        }
                                        else
                                        {
                                                printf("Invalid entry.");
                                        }

                                }
                                else
                                {
                                        printf("Invalid entry.\n");
                                }
                                printf("\n");
				break;

                        case 0:
                                printf("Goodbye.\n");
                                return 0;

                        default:
                                printf("Not a valid option.\n");
                                break;


                }
        }
}

