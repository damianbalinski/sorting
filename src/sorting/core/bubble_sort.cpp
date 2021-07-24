#include "bubble_sort.hpp"
#include "swap.hpp"

/**
 * SORTOWANIE B¥BELKOWE (BUBBLE SORT)
 *
 * œrednia z³o¿onoœæ czasowa - O(n^2)
 * z³o¿onoœæ pamiêciowa      - O(1)
 * stabilny                  - ??
 * stabilny numerycznie      - ??
 * dzia³a w miejscu          - TAK
 * 
 * IDEA ALGORYTMU
 * Kolejno porównujemy ze sob¹ s¹siednie elementy, zamieniaj¹c je ewentualnie
 * miejscami, zgodnie z porz¹dkiem sortowania. Po ka¿dej iteracji element najwiêkszy
 * zostaje przeniesiony na koniec tablicy, zatem w nastêpnej iterazji rozpatrujemy
 * tablicê o jeden element krótsz¹. Po n iteracjach otrzymujemy posortowan¹ tablicê.
 * 
 * OPIS ALGORYTMU
 * Algorytm sk³ada siê z dwóch pêtli zagnie¿d¿onych. Pêtla zewnêtrzna okreœla
 * ile elementów zosta³o posortowanych. Pêtla wewnêtrzna przechodzi po elementach
 * jeszcze nieposortowanych, porównuje kolejne s¹siednie elementy parami oraz
 * ewentualnie zamienia je miejscami, zachowuj¹c porz¹dek sortowania.
 *
 * Z£O¯ONOŒÆ CZASOWA OPTYMISTYCZNA O(??)
 *
 * Z£O¯ONOŒÆ CZASOWA PESYMISTYCZNA O(??)
 *
 * Z£O¯ONOŒÆ CZASOWA ŒREDNIA O(n^2)
 * O(n) - pêtla zewnêtrzna
 * O(n) - pêtla wewnêtrzna
 *
 * Z£O¯ONOŒÆ PAMIÊCIOWA O(1)
 * O(1) - nie potrzebuje dodatkowej pamiêci
 */
void bubble_sort::sort(int arr[], const size_t n, const comparator& comp)
{
	for (size_t i = 0; i < n-1; i++)
		for (size_t j = 0; j < n-i-1; j++)
			if (comp.gt(arr[j],arr[j + 1]))
				swap(&arr[j], &arr[j + 1]);
}
