#include "selection_sort.hpp"
#include "swap.hpp"

/**
 * SORTOWANIE PRZEZ WYBIERANIE (SELECTION SORT)
 *
 * �rednia z�o�ono�� czasowa - O(n^2)
 * z�o�ono�� pami�ciowa      - O(1)
 * stabilny                  - NIE (zmiana kolejnosci podczas operacji swap)
 * stabilny numerycznie      - ??
 * dzia�a w miejscu          - TAK
 *
 * IDEA ALGORYTMU
 * Algorytm sk�ada si� z n iteracji. W ka�dej iteracji wyszukujemy elementu
 * najmniejszego wg. danego porz�dku w tablicy, oraz zamieniamy go z elementem
 * stoj�cym na pierwszej pozycji. Po sko�czonej iteracji element stoj�cy na
 * pierwszej pozycji znajduje si� na odpowiednim miejscu, dlatego nast�pn� iteracj�
 * zaczynamy z tablic� pomniejszon� o ten element.
 *
 * OPIS ALGORYTMU
 * Algorytm sk�ada si� z dw�ch p�tli zagnie�d�onych. P�tla zewn�trzna for okre�la
 * indeks, od kt�rego zaczyna si� nieposortowana tablica. W danej iteracji wszystkie
 * elementy przed indeksem i s� ju� posortowane. W trakcie iteracji przechodzimy
 * tablic� element�w jeszcze nie posortowanych, szukaj�c najmniejszego z nich.
 * Nast�pnie zamieniamy ten element z elementem stoj�cym na pierwszej pozycji
 * w tablicy element�w jeszcze nie posortowanych oraz przechodzimy do nast�pnej
 * iteracji z tablic� pomniejszon� o pierwszy element.
 *
 * Z�O�ONO�� CZASOWA OPTYMISTYCZNA O(n^2) - tablica posortowana
 * O(n) - p�tla zewn�trzna
 * O(n) - p�tla wewn�trzna
 * 
 * Z�O�ONO�� CZASOWA PESYMISTYCZNA O(n^2) - tablica posortowana w odwrotnym porz�dku
 * O(n) - p�tla zewn�trzna
 * O(n) - p�tla wewn�trzna
 * 
 * Z�O�ONO�� CZASOWA �REDNIA O(n^2)
 * O(n) - p�tla zewn�trzna
 * O(n) - p�tla wewn�trzna
 *
 * Z�O�ONO�� PAMI�CIOWA O(1)
 * O(1) - nie potrzebuje dodatkowej pami�ci
 */
void selection_sort::sort(int arr[], const size_t n, const comparator& comp)
{
    for (size_t i = 0; i < n-1; i++)
    {
        size_t min = i;
        for (size_t j = i + 1; j < n; j++)
            if (comp.lt(arr[j], arr[min]))
                min = j;
        swap(&arr[i], &arr[min]);
    }
}
