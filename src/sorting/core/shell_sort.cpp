#include "shell_sort.hpp"

/**
 * SORTOWANIE SHELLA (SHELL SORT)
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
void shell_sort::sort(int arr[], const size_t n, const operation& oper, const gapper& gapper)
{
	for (size_t gap = gapper(n); gap > 0; gap = gapper(gap))
	{
        for (size_t i = gap; i < n; i++)
        {
            const int key = oper.assign(arr[i]);
            size_t j = i;

            while (j >= gap && oper.gt(arr[j-gap], key))
            {
                arr[j] = oper.assign(arr[j-gap]);
                j -= gap;
            }

            arr[j] = oper.assign(key);
        }
	}
}
