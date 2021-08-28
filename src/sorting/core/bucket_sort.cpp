#include "bucket_sort.hpp"
#include "comparator.hpp"
#include "array_utils.hpp"
#include <vector>

size_t const bucket_sort::MAX = 1024;

size_t const bucket_sort::BUCKETS = 10;

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
