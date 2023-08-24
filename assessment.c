
#include "assessment.h"
#include "ListNode.h"
#include "TreeNode.h"
#include <math.h>
#include <cctype>
#include <string.h>
int maximum(int a,int b)
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
    for (int i = 2; i*i <= num; i++)
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
            return i; // assuming first number has index 0
    }
    return -1;
}
int find_kth_smallest(int arr[], int size, int k)
{
    bubble_sort(arr, size);
    return arr[k - 1];
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
void printdll(struct TreeNode *root)
{
    while (root)
    {
        printf("%d ", root->data);
        root = root->right;
    }
}