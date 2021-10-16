#include "dual_pivot_quick_sort.hpp"
#include "dual_pivot_quick_partition.hpp"
#include "simple_dual_pivot_selector.hpp"

/**
 * ?? (??)
 *
 * œrednia z³o¿onoœæ czasowa - ??
 * z³o¿onoœæ pamiêciowa      - ??
 * stabilny                  - TAK ??
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
 *
 * CIEKAWOSTKI
 *   - sortowanie typów podstawowych w javie wykorzystuje algorytm Dual Pivot Quick Sort
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
