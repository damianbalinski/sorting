#include "intro_sort.hpp"
#include "insertion_sort.hpp"
#include "heap_sort.hpp"
#include "partition_result.hpp"

/**
 * SORTOWANIE INTROSPEKTYWNE (INTRO SORT)
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
void intro_sort::sort(int arr[], const size_t n, const size_t depth, const operation& oper) const
{
	if (n < MAX_DEPTH)
	{
		insertion_sort::sort(arr, n, oper);
		return;
	}

	if (depth == 0)
	{
		heap_sort::sort(arr, n, oper);
		return;
	}

	const partition_result r = (*partition)(arr, n, oper);
	sort(r.arr1, r.n1, depth-1, oper);
	sort(r.arr2, r.n2, depth-1, oper);
}
