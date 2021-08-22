#include "merge_sort.hpp"
#include "array_utils.hpp"

// TODO przeniesc kopiowanie tablicy z metody merge do metody sort

/**
 * SORTOWANIE PRZEZ SCALANIE (MERGE SORT)
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
void merge_sort::sort(int arr[], const size_t n, const comparator& comp)
{
	if (n > 1)
	{
		const size_t n1 = n / 2;
		const size_t n2 = n - n1;
		
		sort(arr, n1, comp);
		sort(arr+n1, n2, comp);
		merge(arr, n1, n2, comp);
	}
}

void merge_sort::merge(int arr[], const size_t n1, const size_t n2, const comparator& comp)
{
	int* left = arr_copy(arr, n1);
	int* right = arr_copy(arr+n1, n2);

	size_t i, j, k;
	i = j = k = 0;

	while (i < n1 && j < n2)
	{
		if (comp.lt(left[i], right[j]))
			arr[k++] = left[i++];
		else
			arr[k++] = right[j++];
	}

	if (i < n1)
		arr_copy(arr+k, left+i, n1-i);
	else if (j < n2)
		arr_copy(arr+k, right+j, n2-j);

	delete [] left;
	delete [] right;
}
