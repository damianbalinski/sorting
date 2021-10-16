#include "dual_pivot_quick_sort.hpp"
#include "dual_pivot_quick_partition.hpp"
#include "simple_dual_pivot_selector.hpp"

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
 *
 * CIEKAWOSTKI
 *   - sortowanie typ�w podstawowych w javie wykorzystuje algorytm Dual Pivot Quick Sort
 */
void dual_pivot_quick_sort::sort(int arr[], const size_t n, const operation& oper)
{
	if (n > 1)
	{
		const size_t* pivots = dual_pivot_quick_partition::partition(arr, n, oper, simple_dual_pivot_selector());
		const size_t n1 = pivots[0];
		const size_t n2 = pivots[1] - pivots[0] - 1;
		const size_t n3 = n - pivots[1] - 1;
		
		sort(arr, n1, oper);
		sort(arr+pivots[0]+1, n2, oper);
		sort(arr+pivots[1]+1, n3, oper);
		delete [] pivots;
	}
}
