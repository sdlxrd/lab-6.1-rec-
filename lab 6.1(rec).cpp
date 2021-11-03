#include <iostream>
#include <time.h>
#include <iomanip>

using namespace std;

void Create(int* a, const int size, const int Low, const int High, int i)
{
	a[i] = Low + rand() % (High - Low + 1);
	if (i < size - 1)
		Create(a, size, Low, High, i + 1);
}
void Print(int* a, const int size, int i)
{
	cout << setw(4) << a[i];
	if (i < size - 1)
		Print(a, size, i + 1);
	else
		cout << endl;
}
int Count(int* a, const int size, int i)
{
	if (i == size)
	{
		return 0;
	}
	if (abs(a[i]) % 2 != 0 && abs(i % 13 != 0))
	{
		return Count(a, size, i + 1) + 1;
	}
	return Count(a, size, i + 1);
}


void Zero(int* a, const int size, int i)
{
	if (i == size)
	{
		return;
	}
	if (abs(a[i]) % 2 != 0 && abs(i % 13 != 0))
	{
		a[i] = 0;
	}
	Zero(a, size, i + 1);
}

int Sum(int* a, const int size, int i)
{
	if (i < size)
	{
		if (abs(a[i]) % 2 != 0 && abs(i % 13 != 0))
			return a[i] + Sum(a, size, i + 1);
		else
			return Sum(a, size, i + 1);
	}
	else
		return 0;
}
int main()
{
	srand((unsigned)time(NULL)); 
	const int n = 25;
	int a[n];

	int Low = 15;
	int High = 94;
	
	Create(a, n, Low, High, 0);
	Print(a, n, 0);
	
	cout << endl;
	cout << endl;
	cout << "Sum   =   " << Sum(a, n, 0) << endl;
	cout << "Count =   " << Count(a, n, 0) << endl;
	cout << endl;
	cout << endl;

	Zero(a, n, 0);
	Print(a, n, 0);

	return 0;
}