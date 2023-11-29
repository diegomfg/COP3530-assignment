#include <iostream>
#include <vector>

void merge(std::vector<int> &arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    std::vector<int> L(n1), R(n2);

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[left..right]
    int i = 0;    // Initial index of first subarray
    int j = 0;    // Initial index of second subarray
    int k = left; // Initial index of merged subarray

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(std::vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        // Same as (left+right)/2, but avoids overflow for large left and right
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

int main()
{
    // Let's create an unsorted vector to test our merge sort
    std::vector<int> unsorted = {12, 11, 13, 5, 6, 7};

    // Get the size of the vector
    int n = unsorted.size();

    std::cout << "Unsorted array: ";
    for (int i = 0; i < n; i++)
        std::cout << unsorted[i] << " ";
    std::cout << std::endl;

    // Call the mergeSort function
    mergeSort(unsorted, 0, n - 1);

    std::cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        std::cout << unsorted[i] << " ";
    std::cout << std::endl;

    std::cout << "Press a key to exit" << getchar() << std::endl;
    return 0;
}
