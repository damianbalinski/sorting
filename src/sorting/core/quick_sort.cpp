#include "quick_sort.hpp"
#include "partition_result.hpp"

/*
 * Algorytm quick sort sk³ada siê z dwóch kroków. Pierwszym z nich jest partycja
 * tablicy na dwie czêœci. Nastêpnie rekurencyjnie sortujemy ka¿d¹ z otrzymanych
 * czêœci.
 */
/**
 * SORTOWANIE SZYBKIE (QUICK SORT)
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
void quick_sort::sort(int arr[], const size_t n, const operation& oper) const
{
    if (n > 1)
    {
        const partition_result r = (*partition)(arr, n, oper);
        sort(r.arr1, r.n1, oper);
    	sort(r.arr2, r.n2, oper);
    }
}
