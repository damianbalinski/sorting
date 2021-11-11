#include "dual_pivot_quick_sort.hpp"
#include "dual_pivot_quick_partition.hpp"

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
