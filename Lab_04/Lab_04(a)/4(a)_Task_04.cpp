#include <iostream>
using namespace std;

// Custom gap sequence: Hibbard's sequence (2^k - 1), covered this topic in Theory classes.
int getNextGap(int gap)
{
    int k = 1;
    while ((1 << k) - 1 < gap)
    {
        k++;
    }
    return (1 << (k - 1)) - 1;
}

void shellSort(int weights[], int n)
{
    int gap = getNextGap(n);
    while (gap > 0)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = weights[i];
            int j = i;

            while ((j >= gap) && (weights[j - gap] > temp))
            {
                weights[j] = weights[j - gap];
                j -= gap;
            }

            weights[j] = temp;
        }
        gap = getNextGap(gap);
    }
}

void printWeights(int weights[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << weights[i] << " ";
    }
    cout << "\n";
}

int main()
{
    int weights[] = {98, 68, 51, 60, 79, 75, 92, 64};
    int n = sizeof(weights) / sizeof(weights[0]);

    cout << "--------------\n";
    cout << "Original Weights: ";
    printWeights(weights, n);

    shellSort(weights, n);

    cout << "Sorted Weights: ";
    printWeights(weights, n);
    cout << "-----------------------------------------\n";

    return 0;
}
