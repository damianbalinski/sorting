#include "insertion_sort.hpp"

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
 * Algorytm sk�ada si� z n iteracji. W ka�dej iteracji do posortowanej tablicy
 * wstawiamy nowy element na odpowiedniej pozycji, otrzymuj�c posortowan� tablic�
 * o jeden element d�u�sz�. Po n-1 iteracjach ca�a tablica jest posortowana.
 * 
 * OPIS ALGORYTMU
 * P�tl� zewn�trzn� zaczynamy od elementu na pozycji 2, poniewa� tablica
 * jednoelementowa jest posortowana.  W k-tej iteracji p�tli zewn�trznej dysponujemy
 * posortowan� tablic� rozmiaru k oraz k+1-tym elementem, kt�ry nale�y wstawi� do
 * tej tablicy. W p�tli wewn�trznej przechodzimy tablic� od ko�ca, szukaj�c miejsca
 * dla nowego elementu. Element ten wstawiamy do tablicy, przesuwaj�c wszystich
 * s�siad�w wi�kszych od niego o jedno miejsce w prawo. 
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
void insertion_sort::sort(int arr[], const size_t n, const operation& oper)
{
    for (size_t i = 1; i < n; i++)
    {
        const int key = arr[i];
        size_t j = i;

        while (j >= 1 && oper.gt(arr[j-1], key))
        {
            arr[j] = arr[j-1];
            j--;
        }

        arr[j] = key;
    }
}
