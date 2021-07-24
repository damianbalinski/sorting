#include "selection_sort.hpp"
#include "swap.hpp"

/**
 * SORTOWANIE PRZEZ WYBIERANIE (SELECTION SORT)
 *
 * œrednia z³o¿onoœæ czasowa - O(n^2)
 * z³o¿onoœæ pamiêciowa      - O(1)
 * stabilny                  - NIE (zmiana kolejnosci podczas operacji swap)
 * stabilny numerycznie      - ??
 * dzia³a w miejscu          - TAK
 *
 * IDEA ALGORYTMU
 * Algorytm sk³ada siê z n iteracji. W ka¿dej iteracji wyszukujemy elementu
 * najmniejszego wg. danego porz¹dku w tablicy, oraz zamieniamy go z elementem
 * stoj¹cym na pierwszej pozycji. Po skoñczonej iteracji element stoj¹cy na
 * pierwszej pozycji znajduje siê na odpowiednim miejscu, dlatego nastêpn¹ iteracjê
 * zaczynamy z tablic¹ pomniejszon¹ o ten element.
 *
 * OPIS ALGORYTMU
 * Algorytm sk³ada siê z dwóch pêtli zagnie¿d¿onych. Pêtla zewnêtrzna for okreœla
 * indeks, od którego zaczyna siê nieposortowana tablica. W danej iteracji wszystkie
 * elementy przed indeksem i s¹ ju¿ posortowane. W trakcie iteracji przechodzimy
 * tablicê elementów jeszcze nie posortowanych, szukaj¹c najmniejszego z nich.
 * Nastêpnie zamieniamy ten element z elementem stoj¹cym na pierwszej pozycji
 * w tablicy elementów jeszcze nie posortowanych oraz przechodzimy do nastêpnej
 * iteracji z tablic¹ pomniejszon¹ o pierwszy element.
 *
 * Z£O¯ONOŒÆ CZASOWA OPTYMISTYCZNA O(n^2) - tablica posortowana
 * O(n) - pêtla zewnêtrzna
 * O(n) - pêtla wewnêtrzna
 * 
 * Z£O¯ONOŒÆ CZASOWA PESYMISTYCZNA O(n^2) - tablica posortowana w odwrotnym porz¹dku
 * O(n) - pêtla zewnêtrzna
 * O(n) - pêtla wewnêtrzna
 * 
 * Z£O¯ONOŒÆ CZASOWA ŒREDNIA O(n^2)
 * O(n) - pêtla zewnêtrzna
 * O(n) - pêtla wewnêtrzna
 *
 * Z£O¯ONOŒÆ PAMIÊCIOWA O(1)
 * O(1) - nie potrzebuje dodatkowej pamiêci
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
