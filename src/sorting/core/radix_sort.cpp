#include "radix_sort.hpp"
#include "maximum.hpp"
#include "counting_sort.hpp"
#include "radix_indexer.hpp"

/**
 * ?? (??)
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
void radix_sort::sort(int arr[], const size_t n, const operation& oper)
{
	const int max = maximum(arr, n, oper);

	for (int exp = 1; max/exp > 0; exp *= 10)
		counting_sort::sort(arr, n, oper, radix_indexer(10, exp));
}
