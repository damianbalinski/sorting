#include "dual_pivot_quick_sort.hpp"
#include "dual_pivot_quick_partition.hpp"

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
void dual_pivot_quick_sort::sort(int arr[], const size_t n, const operation& oper) const
{
	if (n > 1)
	{
		const multi_pivot_partition_result r = (*partition)(arr, n, 2, oper);
		sort(r.arrs[0], r.ns[0], oper);
		sort(r.arrs[1], r.ns[1], oper);
		sort(r.arrs[2], r.ns[2], oper);
	}
}
