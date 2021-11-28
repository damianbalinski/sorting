#include "shell_sort.hpp"

void shell_sort::sort(int arr[], const size_t n, const operation& oper, const gapper& gapper)
{
	for (size_t gap = gapper(n); gap > 0; gap = gapper(gap))
	{
        for (size_t i = gap; i < n; i++)
        {
            const int key = oper.assign(arr[i]);
            size_t j = i;

            while (j >= gap && oper.gt(arr[j-gap], key))
            {
                arr[j] = oper.assign(arr[j-gap]);
                j -= gap;
            }

            arr[j] = oper.assign(key);
        }
	}
}
