#include <iostream>
#include <cmath>
using namespace std;

void combSort(float arr[], int n, float shrink_factor = 1.5)
{
    int gap = n;
    bool swapped = true;

    while (gap != 1 || swapped)
    {
        gap = int(((float)gap / shrink_factor));
        if (gap < 1)
        {
            gap = 1;
        }
        swapped = false;

        for (int i = 0; i < n - gap; i++)
        {
            if (arr[i] > arr[i + gap])
            {
                swap(arr[i], arr[i + gap]);
                swapped = true;
            }
        }
    }
}

int main()
{
    float prices[] = {2399.00, 4999.00, 89.99, 9999.99, 7499.99, 6999.49, 1299.49};
    int n = sizeof(prices) / sizeof(prices[0]);

    cout << "--------------\n";
    cout << "Original Prices: ";
    for (int i = 0; i < n; i++)
    {
        cout << prices[i] << " ";
    }

    combSort(prices, n); // the third argument i.e. shrink_factor is optional and has a default value of 1.5!

    cout << "\nSorted prices: ";
    for (int i = 0; i < n; i++)
    {
        cout << prices[i] << " ";
    }
    cout << "\n------------------------------------------------------------------\n";

    return 0;
}
