#include "comb_sort.hpp"
#include "bubble_sort.hpp"

/**
 * SORTOWANIE SHELLA (SHELL SORT)
 *
 * �rednia z�o�ono�� czasowa - ??
 * z�o�ono�� pami�ciowa      - ??
 * stabilny                  - ??
 * stabilny numerycznie      - ??
 * dzia�a w miejscu          - ??
 *
 * IDEA ALGORYTMU
 * ??
 *
 * OPIS ALGORYTMU
 * ??
 *
 * Z�O�ONO�� CZASOWA OPTYMISTYCZNA ??
 *
 * Z�O�ONO�� CZASOWA PESYMISTYCZNA ??
 *
 * Z�O�ONO�� CZASOWA �REDNIA ??
 * ?? - p�tla zewn�trzna
 * ?? - p�tla wewn�trzna
 *
 * Z�O�ONO�� PAMI�CIOWA ??
 * ?? - nie potrzebuje dodatkowej pami�ci
 */
void comb_sort::sort(int arr[], const size_t n, const operation& oper, const gapper& gapper)
{
	for (size_t gap = gapper(n); gap > 0; gap = gapper(gap))
		for (size_t i = 0; i < n-gap; i++)
			if (arr[i] > arr[i+gap])
				oper.swap(&arr[i], &arr[i+gap]);

	bubble_sort::sort(arr, n, oper);
}
