#include <stdio.h>
#define N 3
#define M 5

void store(double (*arr)[M], int n);
double average_row(const double(*arr)[M], int rows);
double average_all(const double(*arr)[M], int rows);
double find_max(const double(*arr)[M], int rows);
void show(const double(*arr)[M], int n);

int main()
{
	double array[N][M];
	store(array, N);

	printf("Array:\n");
	show(array, N);

	for (int row = 0; row < N; row++)
	{
		printf("Average for row %d is %g.\n", row + 1, average_row(array,row));
	}

	printf("Average is %g.\n", average_all(array, N));
	printf("Maximum is %g.\n", find_max(array, N));
	printf("Done.\n");
}

void store(double(*arr)[M], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("Please enter %d numbers for %d row\n", M, i + 1);
		for (int j = 0; j < M; j++)
		{
			scanf_s("%lf", &arr[i][j]);
		}
	}
}

void show(const double(*arr)[M], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < M; j++)
		{
			printf("%g ", arr[i][j]);
		}
		printf("\n");
	}
}

double average_row(const double(*arr)[M], int rows)
{
	double total = 0;
	for (int i = 0; i < M; i++)
	{
		total += arr[rows][i];
	}
	return (total/M);
}

double average_all(const double(*arr)[M], int rows)
{
	double all = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < M; j++)
		{
			all += arr[i][j];
		}
	}
	return (all / (rows * M));
}

double find_max(const double(*arr)[M], int rows)
{
	double max = arr[0][0];
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (max < arr[i][j])
				max = arr[i][j];
		}
	}
	return max;
}