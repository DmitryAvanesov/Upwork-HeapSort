#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

// the global counter that shows number of iterations
long long int counter;

void fixheap(int a[], int left, int right)
{
	int x = a[left];
	int i, j;

	for (i = left, j = 2 * i + 1; j <= right; i = j, j = 2 * i + 1)
	{
		// incrementimg the counter on each iteration
		counter++;

		if (j < right)
		{
			if (a[j + 1] > a[j])
				j++;
		}
		if (x >= a[j])
			break;
		a[i] = a[j];
	}

	a[i] = x;
}

void heapSort(int a[], int n)
{
	if (n > 1)
	{
		for (int left = n / 2 - 1; left >= 0; left--)
		{
			fixheap(a, left, n - 1);
		}

		swap(a[0], a[n - 1]);
		// setting the counter to zero before the 2nd phase
		counter = 0;

		for (int right = n - 2; right >= 1; right--)
		{
			fixheap(a, 0, right);
			swap(a[0], a[right]);
		}
	}
}

int main()
{
	int range = 1000000;
	int numberOfIterations = 27;
	long long int *table = new long long int[numberOfIterations];
	// we'll calculate k for each number of iterations to see if it approximates
	double *k = new double[numberOfIterations];

	for (int i = 1; i <= numberOfIterations; i++)
	{
		// array size
		int n = pow(2, i) - 1;
		int *a = new int[n];

		// filling the array with random numbers
		for (int j = 0; j < n; j++)
		{
			a[j] = rand() % range;
		}

		heapSort(a, n);
		table[i] = counter;

		// calculating k
		k[i] = counter / (n * log(n));
	}

	// printing info to the console
	for (int i = 1; i <= numberOfIterations; i++)
	{
		cout << std::fixed << std::setprecision(2) << "n=" << i << ": " << table[i] << " (k ~ " << k[i] << ")\n";
	}

	// as we can see, k approximates to 1.31

	return 0;
}
