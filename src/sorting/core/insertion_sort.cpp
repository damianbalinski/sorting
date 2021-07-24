#include "insertion_sort.hpp"
#include "types.hpp"
#include <cstddef>

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
 * Algorytm sk³ada siê z n itracji. W k-tej iteracji bierzemy tablicê rozmiaru k+1,
 * gdzie pierwszych k-elementów jest posortowan¹ tablic¹ z poprzedniej iteracji,
 * zaœ k+1-ty element jest kluczem, który nale¿y wstawiæ do tej tablicy zgodnie
 * z porz¹dkiem sortowania. Pod koniec k-tej iterazji pierwszych k+1 elementów
 * tablicy jest posortowanych, zatem po n-1 iteracjach ca³a tablica jest posortowana.
 * 
 * OPIS ALGORYTMU
 * Pêtlê for zaczynamy od tablicy rozmiaru 2, poniewa¿ tablica jednoelementowa
 * jest zawsze posortowana. W k-tej iteracji rozpatrujemy tablicê rozmiaru k+1,
 * w której pierwszych k-elementów jest posortowanych z poprzedniej iteracji, zaœ
 * ostatni element jest kluczem, który nale¿y wstawiæ do tej tablicy zgodnie z
 * porz¹dkiem sortowania. Wewn¹trz pêtli while przechodzimy oraz przesuwamy w
 * prawo elementy tablicy od elementu przedostniego (indeks i-1) do elementu
 * pierwszego (indeks 0). Przesuwanie koñczymy, gdy natrafimy na element
 * mniejszy/równy od klucza. Po wyjœciu z pêtli while w zwolnionym miejscu
 * wstawiamy klucz, otrzymuj¹c posortowan¹ tablicê d³ugoœci k+1.
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
void insertion_sort::sort(int arr[], const size_t n, const comparator& comp)
{
    for (size_t i = 1; i < n; i++)
    {
        const int key = arr[i];
        number j = i - 1;

        while (j >= 0 && comp.gt(arr[j], key))
        {
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = key;
    }
}
