#define _CRT_SECURE_NO_WARNINGS
#define SIZE_ARRAY 11
#include <stdlib.h>
#include <stdio.h>

//����� ����� � �������
void swap(int *arr, int i, int j);

//������� � ��������� ������������
int nextPermutation(int *arr, int arrSize);

//����� ������������
void printArray(int *arr, int arrSize);

int main()
{
	//������, ���������� ��� ����� ������������
	int numberArray[SIZE_ARRAY];
	int numberSize = 0;
	int i; //���������� ��� ������
	char n;

	while ((n = getchar()) != '\n')
	{
		if ((n < '0') || (n > '9'))
		{
			printf("bad input");

			return 0;
		}
		numberArray[numberSize] = n - '0';
		numberSize++;
	}
	
	//�������� �� ���������� �����
	int equality = 1; //������� ������ �����

	for (i = 0; i < numberSize - 1; i++)
		if (numberArray[i] == numberArray[i + 1])
			equality++;

	if (equality == numberSize)
	{
		if (numberSize != 1)
		{
			printf("bad input");

			return 0;
		}
	}

	//�������� ���������� ������������
	int repeat;
	scanf("%d", &repeat);

	//����� � ����� ������������
	while ((nextPermutation(numberArray, numberSize))&&(repeat > 0))
	{
		printArray(numberArray, numberSize);
		repeat--;
	}

	return 0;
}

void swap(int *arr, int i, int j)
{
	int s = arr[i]; 
	arr[i] = arr[j];
	arr[j] = s;
}

int nextPermutation(int *arr, int arrSize)
{
	//������������� �������
	int j = arrSize - 2;

	while (j != -1 && arr[j] >= arr[j + 1]) 
		j--;

	//�������� �� ������������� ��������� ������������
	if (j == -1)
		return 0; 
	
	//��������� �������
	int k = arrSize - 1;

	while (arr[j] >= arr[k]) 
		k--;

	swap(arr, j, k);

	//���������� ���������� �����
	int l = j + 1, r = arrSize - 1; 

	while (l<r)
		swap(arr, l++, r--);

	return 1;
}

void printArray(int *arr, int arrSize) 
{ 
	for (int i = 0; i < arrSize; i++)
		printf("%d", arr[i]);

	printf("\n");
}