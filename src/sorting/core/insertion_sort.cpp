#include "insertion_sort.hpp"

// TODO poprawic opis

/**
 * SORTOWANIE PRZEZ WSTAWIANIE (INSERTION SORT)
 * 
 * �rednia z�o�ono�� czasowa - O(n^2)
 * z�o�ono�� pami�ciowa      - O(1)
 * stabilny                  - TAK
 * stabilny numerycznie      - ??
 * dzia�a w miejscu          - TAK
 *
 * IDEA ALGORYTMU
 * Algorytm sk�ada si� z n itracji. W k-tej iteracji bierzemy tablic� rozmiaru k+1,
 * gdzie pierwszych k-element�w jest posortowan� tablic� z poprzedniej iteracji,
 * za� k+1-ty element jest kluczem, kt�ry nale�y wstawi� do tej tablicy zgodnie
 * z porz�dkiem sortowania. Pod koniec k-tej iteracji pierwszych k+1 element�w
 * tablicy jest posortowanych, zatem po n-1 iteracjach ca�a tablica jest posortowana.
 * 
 * OPIS ALGORYTMU
 * P�tl� for zaczynamy od tablicy rozmiaru 2, poniewa� tablica jednoelementowa
 * jest zawsze posortowana. W k-tej iteracji rozpatrujemy tablic� rozmiaru k+1,
 * w kt�rej pierwszych k-element�w jest posortowanych z poprzedniej iteracji, za�
 * ostatni element jest kluczem, kt�ry nale�y wstawi� do tej tablicy zgodnie z
 * porz�dkiem sortowania. Wewn�trz p�tli while przechodzimy oraz przesuwamy w
 * prawo elementy tablicy od elementu przedostatniego (indeks i-1) do elementu
 * pierwszego (indeks 0). Przesuwanie ko�czymy, gdy natrafimy na element
 * mniejszy/r�wny od klucza. Po wyj�ciu z p�tli while w zwolnionym miejscu
 * wstawiamy klucz, otrzymuj�c posortowan� tablic� d�ugo�ci k+1.
 * 
 * Z�O�ONO�� CZASOWA OPTYMISTYCZNA O(n) - tablica posortowana
 * O(n) - zewn�trzna petla for
 * O(1) - wewn�trzna p�tla while
 * 
 * Z�O�ONO�� CZASOWA PESYMISTYCZNA O(n^2) - tablica posortowana w odwrotnym porz�dku
 * O(n) - zewn�trzna p�tla for
 * O(n) - wewn�trzna p�tla while
 * 
 * Z�O�ONO�� CZASOWA �REDNIA O(n^2) - elementy w losowym porz�dku
 * O(n)   - zewn�trzna p�tla for
 * O(n/2) - wewn�trzna p�tla while
 *
 * Z�O�ONO�� PAMI�CIOWA O(1)
 * O(1) - nie potrzebuje dodatkowej pami�ci
 */
void insertion_sort::sort(int arr[], const size_t n, const comparator& comp)
{
    for (size_t i = 1; i < n; i++)
    {
        const int key = arr[i];
        size_t j = i;

        while (j >= 1 && comp.gt(arr[j-1], key))
        {
            arr[j] = arr[j-1];
            j--;
        }

        arr[j] = key;
    }
}
