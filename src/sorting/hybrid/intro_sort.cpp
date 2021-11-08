#include "intro_sort.hpp"
#include "insertion_sort.hpp"
#include "heap_sort.hpp"
#include "quick_partition.hpp"

/**
 * SORTOWANIE INTROSPEKTYWNE (INTRO SORT)
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

	const size_t pivot = (*partition)(arr, n, oper);
	sort(arr, pivot, depth - 1, oper);
	sort(arr+pivot+1, n - (pivot + 1), depth - 1, oper);
}
