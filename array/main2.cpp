// Odnomerniy massiv.cpp: определяет точку входа для консольного приложения.
//В одномерном массиве, состоящем из n элементов, вычислить: 1)макс эл-т массива
//2)сумму эл-тов расположенных до последнего положительного эл-та.
//3)сжать массив удалив эл-ты в интервале (а,б) и поместив их в конец массива

#include "stdio.h"
#include "math.h"
#include <string>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
int main()
{

    float max, sum, a, b;
    int N;

    printf("VVEDITE RAZMER MASSIVA\n");
    scanf("%i", &N);
    float *arr = new float[N];

    printf("VVEDITE, a, b\n");
    scanf("%f%f", &a, &b);


    // Заполняем массив
    for (int i = 0; i < N; i++) {
        arr[i] = rand() % 20 - 10;
        }

    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }

    //находим максимальный эл-т
    max = arr[0];
    for (int i = 0; i < N; i++)if (arr[i] > max) max = arr[i];
    printf("\nmax= %f\n", max);


    //находим сумму
    int n = 0;
    sum = 0;
    int k=0;                        // **************  зачем здесь нужна переменная k?
    while (arr[n] > n && n < N){     // **************  зачем  arr[n] > n?
        sum = sum + arr[n];
        n++;
    }
    printf("sum= %f\n", sum);


    // смещение эл-тов принадлежащих по модудулю [a, b] в конец
    for (int i = 0; i < N - 1; i++) {
         for (int j = 0; j < N - i - 1; j++) {
             if (fabs(arr[j]) >= a && fabs(arr[j]) <= b) {
                 int h = arr[j];        // ***************** почему int?
                 arr[j] = arr[j+1];
                 arr[j+1] = h;

             }
         }
     }
// ********************* переделай смещение эл-тов (представлен псевдо-код)
	 k = 0;
	for i = N - 1 .... 0
		if (fabs(arr[i]) >= a && fabs(arr[i]) <= b) {
			for  j = i ...  N - 1 - k
				swap arr[j], arr[j+1]
			k++;
		}
// ********************** конец		

    // замена нулями  // *************** не нужно
    for (int i = 0; i < N; i++)
        if (fabs(arr[i]) >= a && fabs(arr[i]) <= b) k++;


    for (int i = 0; i <= k; i++)
        arr[N-i] = 0;

    //вывод массива
    for (int i = 0; i < N; ++i) {
        cout << arr[i] << " ";
    }

    //system ("pause");
    return 0;
}
