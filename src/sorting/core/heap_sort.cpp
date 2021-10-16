#include "heap_sort.hpp"
#include "swap.hpp"

/**
 * ?? (??)
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
void heap_sort::sort(int arr[], const size_t n, const operation& oper, const heap& heap)
{
	heap(arr, n, oper);

	for (size_t i = n; i > 0; i--)
	{
		swap(&arr[0], &arr[i-1]);
		heap.heapify(arr, i-1, 0, oper);
	}
}
