#include "intro_sort.hpp"
#include "insertion_sort.hpp"
#include "heap_sort.hpp"
#include "median_of_three.hpp"
#include "swap.hpp"
#include "quick_partition.hpp"

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
void intro_sort::sort(int arr[], const size_t n, const size_t depth, const comparator& comp)
{
	if (n < MAX_DEPTH)
	{
		insertion_sort::sort(arr, n, comp);
		return;
	}

	if (depth == 0)
	{
		heap_sort::sort(arr, n, comp);
	}

	const size_t median = median_of_three_index(arr, n, comp);
	swap(&arr[median], &arr[n-1]);

	const size_t pivot = quick_partition::partition(arr, n, comp);
	sort(arr, pivot, depth - 1, comp);
	sort(arr+pivot+1, n - (pivot + 1), depth - 1, comp);
}
