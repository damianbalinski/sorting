#include "merge_sort.hpp"
#include "array_utils.hpp"

/**
 * SORTOWANIE PRZEZ SCALANIE (MERGE SORT)
 *
 * œrednia z³o¿onoœæ czasowa - ??
 * z³o¿onoœæ pamiêciowa      - ??
 * stabilny                  - ??
 * stabilny numerycznie      - ??
 * dzia³a w miejscu          - ??
 *
 * IDEA ALGORYTMU
 * ??
 *
 * OPIS ALGORYTMU
 * ??
 *
 * Z£O¯ONOŒÆ CZASOWA OPTYMISTYCZNA ??
 *
 * Z£O¯ONOŒÆ CZASOWA PESYMISTYCZNA ??
 *
 * Z£O¯ONOŒÆ CZASOWA ŒREDNIA ??
 * ?? - pêtla zewnêtrzna
 * ?? - pêtla wewnêtrzna
 *
 * Z£O¯ONOŒÆ PAMIÊCIOWA ??
 * ?? - nie potrzebuje dodatkowej pamiêci
 */
void merge_sort::sort(int arr[], const size_t n, const comparator& comp)
{
	if (n > 1)
	{
		const size_t n1 = n / 2;
		const size_t n2 = n - n1;
		
		sort(arr, n1, comp);
		sort(arr+n1, n2, comp);

		int* buff = new int[n1];
		merge(arr, buff, n1, n2, comp);
		delete [] buff;
	}
}

void merge_sort::merge(int arr[], int buff[], const size_t n1, const size_t n2, const comparator& comp)
{
	int* left = arr_copy(buff, arr, n1);
	int* right = arr + n1;

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
}
