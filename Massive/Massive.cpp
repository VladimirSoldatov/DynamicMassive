#include <iostream>
using namespace std;
 
int** create_massive(int n, int m)
{
	int** temp = new int* [n];//Этажи int*(arr[])
	for (int i = 0; i < n; i++)
	{
		temp[i] = new int[m];
	}
	return temp;
}
void insert_values(int** massive, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			massive[i][j] = i;
		}

	}
}

void show_massive(int **massive, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << massive[i][j] << "\t";
		}
		cout << "\n\n";
	}
	cout << endl;
}
int** addRow(int** massive, int &n, int m)
{
	int** temp = new int* [n + 1];
	for (int i = 0; i < n + 1; i++)
	{
		temp[i] = new int[m];
		for (int j = 0; j <m; j++)
		{
			if (i < n)// заполняем имеющиеся
			{
				temp[i][j] = massive[i][j];
			}
			else//заполняем дополнительн
			{
				temp[i][j] = 0;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		delete[]massive[i];
	}
	delete[] massive;
	n++;
	return temp;
}
int** addColumn(int ** massive, int n, int &m)
{
	m++;
	int** temp = new int* [n];
	for (int i = 0; i < n; i++)
	{
		temp[i] = new int[m];
		for (int j = 0; j < m; j++)
		{
			if (j < m - 1)// заполняем имеющиеся
			{
				temp[i][j] = massive[i][j];
			}
			else//заполняем дополнительн
			{
				temp[i][j] = 0;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		delete[]massive[i];
	}
	delete[] massive;
	return temp;

}
int main()
{
	int N, M;
	printf("Enter N - Height");
	scanf_s("%i", &N);//Высота
	printf("Enter M - Height");
	scanf_s("%i", &M);//Ширина
	int** arr = create_massive(N, M);//Этажи int*(arr[])
	insert_values(arr, N,M);
	show_massive(arr, N, M);
	arr = addRow(arr, N, M);
	show_massive(arr, N, M);
	arr = addColumn(arr, N, M);
	show_massive(arr, N, M);

}
