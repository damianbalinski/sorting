#include "counting_sort.hpp"
#include "array_utils.hpp"
#include "assert.hpp"

int counting_sort::MAX = 1024;

/**
 * ?? (??)
 *
 * �rednia z�o�ono�� czasowa - ??
 * z�o�ono�� pami�ciowa      - ??
 * stabilny                  - TAK ??
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
void counting_sort::sort(int arr[], const size_t n, const int max)
{
	check_arr_in_range_right_open(arr, n, max);
	
	int* res = new int[n];
	size_t* count = new size_t[max+1]();

	for (size_t i = 0; i < n; i++)
		count[arr[i]]++;

	for (int i = 1; i < max; i++)
		count[i] += count[i-1];

	for (size_t i = n; i > 0; i--)
	{
		const size_t j = i-1;
		res[count[arr[j]]-1] = arr[j];
		count[arr[j]]--;
	}

	arr_copy(arr, res, n);
	delete [] res;
	delete [] count;
}
