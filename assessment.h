#ifndef ASSESSMENT_H_
#define ASSESSMENT_H_

/* 1. Write a C function to find and return the maximum of two integers */
int maximum(int a, int b);

/* 2. Implement a C function to check if a given number is even or odd */
int is_even(int num);

/* 3. Create a C function that calculates and returns the factorial of a given positive integer */
int factorial(int n);

/* 4. Write a C function to check if a given character is a vowel or a consonant */
int is_vowel(char ch);

/* 5. Implement a C function that swaps the values of two integer variables */
void swap(int *a, int *b);

/* 6. Create a C function to compute the n-th Fibonacci number using recursion */
int fibonacci(int n);

/* 7. Write a C function to reverse an array of integers in-place */
void reverse_array(int arr[], int size);

/* 8. Implement a C function to find and return the largest element in an integer array */
int find_max(int arr[], int size);

/* 9. Create a C function to check if a given string is a palindrome */
int is_palindrome(char str[]);

/* 10. Write a C function that sorts an array of integers in ascending order using the bubble sort algorithm */
void bubble_sort(int arr[], int size);

/* 11. Create a C function that calculates and returns the sum of elements in an integer array */
int array_sum(int arr[], int size);

/* 12. Write a C function to check if a given number is prime */
int is_prime(int num);

/* 13. Implement a C function to find and return the second largest element in an integer array */
int find_second_largest(int arr[], int size);

/* 14. Create a C function to compute the power of a given base raised to an exponent using recursion */
int power(int base, int exponent);

/* 15. Write a C function that finds and returns the first occurrence of a target value in an integer array */
int find_target(int arr[], int size, int target);

/* 31. Implement a C function to find and return the k-th smallest element in an unsorted integer array */
int find_kth_smallest(int arr[], int size, int k);

/* 32. Write a C function that converts a binary search tree (BST) to a sorted doubly linked list */
struct TreeNode *convert_to_dll(struct TreeNode *root);

/* 33. Create a C function to compute the factorial of a given positive integer using recursion */
int factorial_recursive(int n);

/* 34. Implement a C function that merges two sorted arrays into a single sorted array */
void merge_sorted_arrays(int arr1[], int size1, int arr2[], int size2, int result[]);

/* 35. Write a C function to reverse a linked list in-place */
struct ListNode *reverse_linked_list(struct ListNode *head);
void printdll(struct TreeNode *root);
void convert(struct TreeNode *root, struct TreeNode **newroot);
#endif
