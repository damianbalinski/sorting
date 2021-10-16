#include "selection_sort.hpp"
#include "swap.hpp"
#include "maximum.hpp"

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
 * najwiêkszego wg. danego porz¹dku, oraz przenosimy go na koniec tablicy.
 * Po skoñczonej iteracji ostatni element w tablicy znajduje siê na odpowiednim
 * miejscu, dlatego nastêpn¹ iteracjê zaczynamy z tablic¹ pomniejszon¹ o ten element.
 *
 * OPIS ALGORYTMU
 * Algorytm wykorzystuje pojedyncz¹ pêtlê oraz algorytm wyszukiwania maksimum.
 * Iterator pêtli for okreœla rozmiar jeszcze nie posortowanej tablicy. W danej
 * iteracji wszystkie elementy stoj¹ce za indeksem i s¹ ju¿ posortowane. W trakcie
 * iteracji szukamy elementu najwiêkszego oraz zamieniamy go z elementem stoj¹cym
 * na ostatniej pozycji w tablicy. Nastêpnie przechodzimy do nastêpnej iteracji
 * z tablic¹ pomniejszon¹ o ostatni element.
 *
 * Z£O¯ONOŒÆ CZASOWA OPTYMISTYCZNA O(n^2) - tablica posortowana
 * O(n) - pêtla zewnêtrzna
 * O(n) - maksimum
 * 
 * Z£O¯ONOŒÆ CZASOWA PESYMISTYCZNA O(n^2) - tablica posortowana w odwrotnym porz¹dku
 * O(n) - pêtla zewnêtrzna
 * O(n) - maksimum
 * 
 * Z£O¯ONOŒÆ CZASOWA ŒREDNIA O(n^2)
 * O(n) - pêtla zewnêtrzna
 * O(n) - maksimum
 *
 * Z£O¯ONOŒÆ PAMIÊCIOWA O(1)
 * O(1) - nie potrzebuje dodatkowej pamiêci
 */
void selection_sort::sort(int arr[], const size_t n, const operation& oper)
{
    for (size_t i = n; i > 1; i--)
    {
        const size_t max = maximum_index(arr, i, oper);
        swap(&arr[i-1], &arr[max]);
    }
}
