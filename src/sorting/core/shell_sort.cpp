#include "shell_sort.hpp"

/**
 * SORTOWANIE SHELLA (SHELL SORT)
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
void shell_sort::sort(int arr[], const size_t n, const comparator& comp, const gapper& gapper)
{
	for (size_t gap = n/2; gap > 0; gap = gapper(gap))
	{
        for (size_t i = gap; i < n; i++)
        {
            const int key = arr[i];
            size_t j = i;

            while (j >= gap && comp.gt(arr[j-gap], key))
            {
                arr[j] = arr[j-gap];
                j -= gap;
            }

            arr[j] = key;
        }
	}
}
