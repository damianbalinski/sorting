#include "bucket_sort.hpp"
#include "comparator.hpp"
#include "array_utils.hpp"
#include <vector>

size_t const bucket_sort::MAX = 1024;

size_t const bucket_sort::BUCKETS = 10;

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
void bucket_sort::sort(int arr[], const size_t n, const bucket_indexer& indexer, const sorting& sort)
{
	std::vector<int>* const buckets = new std::vector<int>[indexer.buckets];

	for (size_t i = 0; i < n; i++)
		buckets[indexer(arr, i)].push_back(arr[i]);

	for (size_t b = 0; b < indexer.buckets; b++)
		sort(buckets[b].data(), buckets[b].size(), asc_comparator());

	size_t k = 0;
	for (size_t b = 0; b < indexer.buckets; b++)
	{
		const size_t n = buckets[b].size();
		arr_copy(arr + k, buckets[b].data(), n);
		k += n;
	}
	
	delete [] buckets;
}
