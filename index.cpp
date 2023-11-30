#include <iostream>
#include <vector>
#include <chrono>

void merge(std::vector<int> &arr, int left, int mid, int right)
{
    int f1 = mid - left + 1;
    int f2 = right - mid;

    // Create temporary arrays
    std::vector<int> L(f1), R(f2);

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < f1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < f2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[left+right]
    int i = 0;
    int j = 0;
    int k = left;

    while (i < f1 && j < f2)
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
    while (i < f1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < f2)
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
        int mid = left + (right - left) / 2;

        // Sort both halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted arrays
        merge(arr, left, mid, right);
    }
}

std::vector<int> generateData(int size)
{
    std::vector<int> data;
    for (int i = 0; i < size; ++i)
    {
        data.push_back(rand() % 1000); // Adjust range as needed
    }
    return data;
}

// do not use unless the dataset is small enough to print in the console
void printData(std::vector<int> &unsorted)
{
    // Print the array
    std::cout << "Array: ";
    for (int i = 0; i < unsorted.size(); i++)
    {
        std::cout << unsorted[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::cout << "Testing Merge Sort Algorithm Efficiency" << std::endl;

    // Note: These are way to big for printing, make them smaller if need to see arrays' content
    std::vector<int> sizes = {1000, 10000, 100000, 1000000, 10000000};

    for (int size : sizes)
    {

        // Create a vector, starting frmo 100 random integers
        std::vector<int> unsorted = generateData(size);
        int n = unsorted.size();

        // printData(unsorted);

        // initialize the system clock
        auto start = std::chrono::high_resolution_clock::now();

        // Call the mergeSort function
        mergeSort(unsorted, 0, n - 1);

        // stop the clock after function ended
        auto stop = std::chrono::high_resolution_clock::now();

        // end - start = elapsed time
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

        std::cout << "Size: " << n << ", Time taken: " << duration.count() << " miliseconds" << std::endl;

        // printData(unsorted);
    }
    return 0;
}
