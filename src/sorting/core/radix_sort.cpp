#include "radix_sort.hpp"
#include "maximum.hpp"
#include "counting_sort.hpp"
#include "radix_indexer.hpp"

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
void radix_sort::sort(int arr[], const size_t n, const operation& oper)
{
	const int max = maximum(arr, n, oper);

	for (int exp = 1; max/exp > 0; exp *= 10)
		counting_sort::sort(arr, n, oper, radix_indexer(10, exp));
}
