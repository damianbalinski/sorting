#include "quick_sort.hpp"
#include "quick_partition.hpp"

// TODO opis
/*
 * Algorytm quick sort sk�ada si� z dw�ch krok�w. Pierwszym z nich jest partycja
 * tablicy na dwie cz�ci. Nast�pnie rekurencyjnie sortujemy ka�d� z otrzymanych
 * cz�ci.
 */
/**
 * SORTOWANIE SZYBKIE (QUICK SORT)
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
void quick_sort::sort(int arr[], const size_t n, const comparator& comp)
{
    if (n > 1)
    {
        const size_t pivot = quick_partition::partition(arr, n, comp);
        sort(arr, pivot, comp);
    	sort(arr+(pivot+1), n-(pivot+1), comp);
    }
}
