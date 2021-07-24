#include "bubble_sort.hpp"
#include "swap.hpp"

/**
 * SORTOWANIE B�BELKOWE (BUBBLE SORT)
 *
 * �rednia z�o�ono�� czasowa - O(n^2)
 * z�o�ono�� pami�ciowa      - O(1)
 * stabilny                  - ??
 * stabilny numerycznie      - ??
 * dzia�a w miejscu          - TAK
 * 
 * IDEA ALGORYTMU
 * Kolejno por�wnujemy ze sob� s�siednie elementy, zamieniaj�c je ewentualnie
 * miejscami, zgodnie z porz�dkiem sortowania. Po ka�dej iteracji element najwi�kszy
 * zostaje przeniesiony na koniec tablicy, zatem w nast�pnej iterazji rozpatrujemy
 * tablic� o jeden element kr�tsz�. Po n iteracjach otrzymujemy posortowan� tablic�.
 * 
 * OPIS ALGORYTMU
 * Algorytm sk�ada si� z dw�ch p�tli zagnie�d�onych. P�tla zewn�trzna okre�la
 * ile element�w zosta�o posortowanych. P�tla wewn�trzna przechodzi po elementach
 * jeszcze nieposortowanych, por�wnuje kolejne s�siednie elementy parami oraz
 * ewentualnie zamienia je miejscami, zachowuj�c porz�dek sortowania.
 *
 * Z�O�ONO�� CZASOWA OPTYMISTYCZNA O(??)
 *
 * Z�O�ONO�� CZASOWA PESYMISTYCZNA O(??)
 *
 * Z�O�ONO�� CZASOWA �REDNIA O(n^2)
 * O(n) - p�tla zewn�trzna
 * O(n) - p�tla wewn�trzna
 *
 * Z�O�ONO�� PAMI�CIOWA O(1)
 * O(1) - nie potrzebuje dodatkowej pami�ci
 */
void bubble_sort::sort(int arr[], const size_t n, const comparator& comp)
{
	for (size_t i = 0; i < n-1; i++)
		for (size_t j = 0; j < n-i-1; j++)
			if (comp.gt(arr[j],arr[j + 1]))
				swap(&arr[j], &arr[j + 1]);
}
