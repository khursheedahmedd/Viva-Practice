#include <iostream>
using namespace std;

void Subarray(int arr[], int size, int sum)
{
    int currentSum = 0;
    int start = 0;
    bool found = false;

    for (int i = 0; i < size; i++)
    {
        currentSum += arr[i];

        while (currentSum > sum && start <= i)
        {
            currentSum -= arr[start];
            start++;
        }

        if (currentSum == sum)
        {
            cout << "\nThe subarray is: ";
            for (int j = start; j <= i; ++j)
            {
                cout << arr[j] << " ";
            }
            found = true;
            break;
        }
    }
    if (!found)
        cout << "\nThe subarray is not found.";
}

int main()
{
    int size;
    cout << "\nEnter the size of the array: ";
    cin >> size;

    int *arr = new int[size];

    cout << "\nEnter the values of the array: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    int sum;
    cout << "\nEnter the number: ";
    cin >> sum;

    Subarray(arr, size, sum);

    delete[] arr;

    return 0;
}