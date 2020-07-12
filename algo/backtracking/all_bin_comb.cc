/*

Program to print all possible binary digits, given no of digits.

*/#include <stdio.h>

void printBin(int *num, int current, int size)
{
    int i;
    if (current == -1)
    {
        int i;
        for (i = 0; i < size; i++)
        {
            printf("%d", num[i]);
        }
        printf("\n");
        return;
    }

    printBin(num, current - 1, size);

    int arr[size];
    for (i = 0; i < size; ++i)
    {
        arr[i] = num[i];
    }
    arr[current] = 0;
    printBin(arr, current - 1, size);
}

void generateAllBits(int n)
{
    int i;
    int binary_num[n];
    for (i = 0; i < n; i++)
    {
        binary_num[i] = 1;
    }
    printBin(binary_num, n - 1, n);
}

int main()
{
    int n;
    scanf("%d", &n);
    generateAllBits(n);
    return 0;
}