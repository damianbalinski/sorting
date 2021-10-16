#include "selection_sort.hpp"
#include "swap.hpp"
#include "maximum.hpp"

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
 * najwi�kszego wg. danego porz�dku, oraz przenosimy go na koniec tablicy.
 * Po sko�czonej iteracji ostatni element w tablicy znajduje si� na odpowiednim
 * miejscu, dlatego nast�pn� iteracj� zaczynamy z tablic� pomniejszon� o ten element.
 *
 * OPIS ALGORYTMU
 * Algorytm wykorzystuje pojedyncz� p�tl� oraz algorytm wyszukiwania maksimum.
 * Iterator p�tli for okre�la rozmiar jeszcze nie posortowanej tablicy. W danej
 * iteracji wszystkie elementy stoj�ce za indeksem i s� ju� posortowane. W trakcie
 * iteracji szukamy elementu najwi�kszego oraz zamieniamy go z elementem stoj�cym
 * na ostatniej pozycji w tablicy. Nast�pnie przechodzimy do nast�pnej iteracji
 * z tablic� pomniejszon� o ostatni element.
 *
 * Z�O�ONO�� CZASOWA OPTYMISTYCZNA O(n^2) - tablica posortowana
 * O(n) - p�tla zewn�trzna
 * O(n) - maksimum
 * 
 * Z�O�ONO�� CZASOWA PESYMISTYCZNA O(n^2) - tablica posortowana w odwrotnym porz�dku
 * O(n) - p�tla zewn�trzna
 * O(n) - maksimum
 * 
 * Z�O�ONO�� CZASOWA �REDNIA O(n^2)
 * O(n) - p�tla zewn�trzna
 * O(n) - maksimum
 *
 * Z�O�ONO�� PAMI�CIOWA O(1)
 * O(1) - nie potrzebuje dodatkowej pami�ci
 */
void selection_sort::sort(int arr[], const size_t n, const operation& oper)
{
    for (size_t i = n; i > 1; i--)
    {
        const size_t max = maximum_index(arr, i, oper);
        swap(&arr[i-1], &arr[max]);
    }
}
