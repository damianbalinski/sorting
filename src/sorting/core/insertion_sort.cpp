#include "insertion_sort.hpp"

/**
 * SORTOWANIE PRZEZ WSTAWIANIE (INSERTION SORT)
 * 
 * œrednia z³o¿onoœæ czasowa - O(n^2)
 * z³o¿onoœæ pamiêciowa      - O(1)
 * stabilny                  - TAK
 * stabilny numerycznie      - ??
 * dzia³a w miejscu          - TAK
 *
 * IDEA ALGORYTMU
 * Algorytm sk³ada siê z n iteracji. W ka¿dej iteracji do posortowanej tablicy
 * wstawiamy nowy element na odpowiedniej pozycji, otrzymuj¹c posortowan¹ tablicê
 * o jeden element d³u¿sz¹. Po n-1 iteracjach ca³a tablica jest posortowana.
 * 
 * OPIS ALGORYTMU
 * Pêtlê zewnêtrzn¹ zaczynamy od elementu na pozycji 2, poniewa¿ tablica
 * jednoelementowa jest posortowana.  W k-tej iteracji pêtli zewnêtrznej dysponujemy
 * posortowan¹ tablic¹ rozmiaru k oraz k+1-tym elementem, który nale¿y wstawiæ do
 * tej tablicy. W pêtli wewnêtrznej przechodzimy tablicê od koñca, szukaj¹c miejsca
 * dla nowego elementu. Element ten wstawiamy do tablicy, przesuwaj¹c wszystich
 * s¹siadów wiêkszych od niego o jedno miejsce w prawo. 
 * 
 * Z£O¯ONOŒÆ CZASOWA OPTYMISTYCZNA O(n) - tablica posortowana
 * O(n) - zewnêtrzna petla for
 * O(1) - wewnêtrzna pêtla while
 * 
 * Z£O¯ONOŒÆ CZASOWA PESYMISTYCZNA O(n^2) - tablica posortowana w odwrotnym porz¹dku
 * O(n) - zewnêtrzna pêtla for
 * O(n) - wewnêtrzna pêtla while
 * 
 * Z£O¯ONOŒÆ CZASOWA ŒREDNIA O(n^2) - elementy w losowym porz¹dku
 * O(n)   - zewnêtrzna pêtla for
 * O(n/2) - wewnêtrzna pêtla while
 *
 * Z£O¯ONOŒÆ PAMIÊCIOWA O(1)
 * O(1) - nie potrzebuje dodatkowej pamiêci
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
