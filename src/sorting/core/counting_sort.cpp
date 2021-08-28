#include "counting_sort.hpp"
#include "array_utils.hpp"
#include "assert.hpp"

size_t const counting_sort::MAX = 1024;

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
 */
void counting_sort::sort(int arr[], const size_t n, const indexer& indexer)
{
	int* res = new int[n];
	size_t* count = new size_t[indexer.max]();

	for (size_t i = 0; i < n; i++)
		count[indexer(arr,i)]++;

	for (size_t i = 1; i < indexer.max; i++)
		count[i] += count[i-1];

	for (size_t i = n; i > 0; i--)
	{
		const size_t j = i-1;
		res[count[indexer(arr,j)]-1] = arr[j];
		count[indexer(arr,j)]--;
	}

	arr_copy(arr, res, n);
	delete [] res;
	delete [] count;
}
