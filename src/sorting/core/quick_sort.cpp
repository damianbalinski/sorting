#include "quick_sort.hpp"
#include "quick_partition.hpp"

// TODO opis
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
void quick_sort::sort(int arr[], const size_t n, const comparator& comp)
{
    if (n > 1)
    {
        const size_t pivot = quick_partition::partition(arr, n, comp);
        sort(arr, pivot, comp);
    	sort(arr+(pivot+1), n-(pivot+1), comp);
    }
}
