
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <cctype>
#include <string.h>
struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};
struct ListNode
{
    int data;
    struct ListNode *next;
};
// Function to create a new ListNode
struct ListNode *createNode(int value)
{
    struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
    if (newNode != NULL)
    {
        newNode->data = value;
        newNode->next = NULL;
    }
    return newNode;
}

// Function to add a new ListNode to the end of the list
void append(struct ListNode **head, int value)
{
    struct ListNode *newNode = createNode(value);
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct ListNode *current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to print the elements of the linked list
void printLinkedList(struct ListNode *head)
{
    struct ListNode *current = head;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to free the memory occupied by the linked list
void freeLinkedList(struct ListNode *head)
{
    struct ListNode *current = head;
    while (current != NULL)
    {
        struct ListNode *temp = current;
        current = current->next;
        free(temp);
    }
}

// Function to create a new TreeNode
struct TreeNode *createTNode(int value)
{
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    if (newNode != NULL)
    {
        newNode->data = value;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}

// Function to construct a binary tree
struct TreeNode *constructBinaryTree()
{
    struct TreeNode *root = createTNode(1);
    root->left = createTNode(3);
    root->right = createTNode(5);
    root->left->left = createTNode(1);
    root->left->right = createTNode(2);
    root->right->left = createTNode(6);
    root->right->right = createTNode(7);
    return root;
}

// Function to perform an in-order traversal of the binary tree
void inOrderTraversal(struct TreeNode *root)
{
    if (root != NULL)
    {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

// Function to free the memory occupied by the binary tree
void freeBinaryTree(struct TreeNode *root)
{
    if (root != NULL)
    {
        freeBinaryTree(root->left);
        freeBinaryTree(root->right);
        free(root);
    }
}

int maximum(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
int is_even(int num)
{
    if (num % 2 == 0)
        return 1;
    else
        return 0;
}
int factorial(int n)
{
    if (n == 0)
        return 1;
    int factorial = n;
    for (int i = 1; i < n; i++)
    {
        factorial *= i;
    }
    return factorial;
}
int is_vowel(char ch)
{
    ch = tolower(ch);
    if (ch == 'a' || ch == 'e' || ch == 'o' || ch == 'i' || ch == 'u')
        return 1;
    else
        return 0;
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int fibonacci(int n)
{
    if (n == 1 || n == 0)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}
void reverse_array(int arr[], int size)
{
    for (int i = 0; i < size / 2; ++i)
    {
        int temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - 1 - i] = temp;
    }
}
int find_max(int arr[], int size)
{
    int max = arr[0];
    for (int i = 1; i < size; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}
int is_palindrome(char str[])
{
    int size = strlen(str);
    int i = 0, j = size - 1;
    while (i < j)
    {
        while (!isalnum(str[i]) && i < j)
            ++i;
        while (!isalnum(str[j]) && i < j)
            --j;
        if (tolower(str[i++]) != tolower(str[j--]))
            return 0;
    }
    return 1;
}
void bubble_sort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int flag = 0;
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                flag = 1;
            }
        }
        if (!flag)
            break;
    }
}
int array_sum(int arr[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum;
}
int is_prime(int num)
{
    if (num < 2)
        return 0;
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
            return 0;
    }
    return 1;
}
int find_second_largest(int arr[], int size)
{
    bubble_sort(arr, size);
    return arr[size - 2];
}
int power(int base, int exponent)
{
    long result = base;
    for (int i = 1; i < exponent; i++)
    {
        result *= base;
    }
    return result;
}
int find_target(int arr[], int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
            return i + 1; // assuming first number has index 1
    }
    return -1;
}
int find_kth_smallest(int arr[], int size, int k)
{
    bubble_sort(arr, size);
    return arr[k - 1];
}
void convert(struct TreeNode *root, struct TreeNode **newroot)
{
    if (root != NULL)
    {
        convert(root->left, newroot);
        struct TreeNode *temp = createTNode(root->data);
        if (*newroot == NULL)
            *newroot = temp;
        else
        {
            temp->left = *newroot;
            (*newroot)->right = temp;
            *newroot = temp;
        }
        convert(root->right, newroot);
    }
}
struct TreeNode *convert_to_dll(struct TreeNode *root)
{
    struct TreeNode *newroot;
    newroot = NULL;

    convert(root, &newroot);
    while (newroot && newroot->left)
    {
        newroot = newroot->left;
    }

    return newroot;
}
int factorial_recursive(int n)
{
    if (n == 0)
        return 1;
    return n * factorial_recursive(n - 1);
}
void merge_sorted_arrays(int arr1[], int size1, int arr2[], int size2, int result[])
{
    int i = 0, j = 0, k = 0;
    while (i < size1 && j < size2)
    {
        if (arr1[i] < arr2[j])
            result[k++] = arr1[i++];
        else
            result[k++] = arr2[j++];
    }
    if (i != size1)
        for (int c = i; c < size1; c++)
            result[k++] = arr1[c];
    if (j != size2)
        for (int c = j; c < size2; c++)
            result[k++] = arr2[c];
}
struct ListNode *reverse_linked_list(struct ListNode *head)
{
    struct ListNode *prev, *curr, *temp;
    curr = prev = NULL;
    temp = head;
    while (temp != NULL)
    {
        curr = temp;
        temp = temp->next;
        curr->next = prev;
        prev = curr;
    }
    return curr;
}

void printdll(struct TreeNode *root)
{
    while (root)
    {
        printf("%d ", root->data);
        root = root->right;
    }
}

int main()
{
    // Test maximum function
    printf("Maximum of 5 and 10 is %d\n", maximum(5, 10));

    // Test is_even function
    printf("Is 7 even? %d\n", is_even(7));
    printf("Is 8 even? %d\n", is_even(8));

    // Test factorial function
    printf("Factorial of 5 is %d\n", factorial(5));

    // Test is_vowel function
    printf("Is 'A' a vowel? %d\n", is_vowel('A'));
    printf("Is 'b' a vowel? %d\n", is_vowel('b'));

    // Test swap function
    int a = 5, b = 10;
    printf("Before swap: a = %d, b = %d\n", a, b);
    swap(&a, &b);
    printf("After swap: a = %d, b = %d\n", a, b);

    // Test fibonacci function
    printf("Fibonacci number at index 6 is %d\n", fibonacci(6));

    // Test reverse_array function
    int arr1[] = {1, 2, 3, 4, 5};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    reverse_array(arr1, size1);
    printf("Reversed array: ");
    for (int i = 0; i < size1; i++)
    {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    // Test find_max function
    int arr2[] = {5, 2, 8, 1, 7};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    printf("Maximum element in the array is %d\n", find_max(arr2, size2));

    // Test is_palindrome function
    char str1[] = "racecar";
    char str2[] = "hello";
    printf("Is '%s' a palindrome? %d\n", str1, is_palindrome(str1));
    printf("Is '%s' a palindrome? %d\n", str2, is_palindrome(str2));

    // Test bubble_sort function
    int arr3[] = {5, 2, 8, 1, 7};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    bubble_sort(arr3, size3);
    printf("Sorted array: ");
    for (int i = 0; i < size3; i++)
    {
        printf("%d ", arr3[i]);
    }
    printf("\n");

    // Test array_sum function
    int arr4[] = {1, 2, 3, 4, 5};
    int size4 = sizeof(arr4) / sizeof(arr4[0]);
    printf("Sum of elements in the array is %d\n", array_sum(arr4, size4));

    // Test is_prime function
    printf("Is 7 a prime number? %d\n", is_prime(7));
    printf("Is 12 a prime number? %d\n", is_prime(12));

    // Test find_second_largest function
    int arr5[] = {5, 2, 8, 1, 7};
    int size5 = sizeof(arr5) / sizeof(arr5[0]);
    printf("Second largest element in the array is %d\n", find_second_largest(arr5, size5));

    // Test power function
    printf("2 raised to the power of 5 is %d\n", power(2, 5));

    // Test find_target function
    int arr6[] = {1, 2, 3, 4, 5};
    int size6 = sizeof(arr6) / sizeof(arr6[0]);
    printf("Index of target element in the array is %d\n", find_target(arr6, size6, 3));

    // Test find_kth_smallest function
    int arr7[] = {5, 2, 8, 1, 7};
    int size7 = sizeof(arr7) / sizeof(arr7[0]);
    printf("The 3rd smallest element in the array is %d\n", find_kth_smallest(arr7, size7, 3));

    // Test convert_to_dll function
    struct TreeNode *root = createTNode(5);
    root->left = createTNode(3);
    root->right = createTNode(6);
    root->left->left = createTNode(2);
    root->left->right = createTNode(4);
    root->right->right = createTNode(7);
    struct TreeNode *head = convert_to_dll(root);
    printf("Doubly linked list: ");
    printdll(head);
    printf("\n");

    // Test factorial_recursive function
    printf("Factorial of 5 is %d\n", factorial_recursive(5));

    // Test merge_sorted_arrays function
    int arr8[] = {1, 3, 5};
    int size8 = sizeof(arr8) / sizeof(arr8[0]);
    int arr9[] = {2, 4, 6};
    int size9 = sizeof(arr9) / sizeof(arr9[0]);
    int merged_arr[6];
    merge_sorted_arrays(arr8, size8, arr9, size9, merged_arr);
    printf("Merged array: ");
    for (int i = 0; i < size8 + size9; i++)
    {
        printf("%d ", merged_arr[i]);
    }
    printf("\n");

    // Test reverse_linked_list function
    struct ListNode *node1 = createNode(1);
    node1->next = createNode(2);
    node1->next->next = createNode(3);
    node1->next->next->next = createNode(4);
    printf("Before reversing: ");
    printLinkedList(node1);
    struct ListNode *new_head = reverse_linked_list(node1);
    printf("After reversing: ");
    printLinkedList(new_head);

    return 0;
}