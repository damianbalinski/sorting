from simple_plot import *
from config import *

config = Config({
    'title': 'Liczba poszczególnych operacji \nw zależności od wielkości tablicy',
    'xlabel': 'liczba elementów w tablicy',
    'ylabel': 'liczba operacji',
    'xcolumn': 'n',
    'ycolumn': 'comparisons',
    'output': 'quick_sort_test6.png',

    'plots': [
        {
            'label': 'bubble sort',
            'input': 'C:/Users/d.balinski/src/cpp/sorting/test/test02_bubble_sort.csv',
        },
        {
            'label': 'merge sort',
            'input': 'C:/Users/d.balinski/src/cpp/sorting/test/test02_merge_sort.csv',
        },
        {
            'label': 'bubble sort',
            'input': 'C:/Users/d.balinski/src/cpp/sorting/test/test02_bubble_sort.csv',
        },
        {
            'label': 'comb sort',
            'input': 'C:/Users/d.balinski/src/cpp/sorting/test/test02_comb_sort.csv',
        },
        {
            'label': 'dual pivot quick sort',
            'input': 'C:/Users/d.balinski/src/cpp/sorting/test/test02_dual_pivot_quick_sort.csv',
        },
        {
            'label': 'heap sort',
            'input': 'C:/Users/d.balinski/src/cpp/sorting/test/test02_heap_sort.csv',
        },
        {
            'label': 'insertion sort',
            'input': 'C:/Users/d.balinski/src/cpp/sorting/test/test02_insertion_sort.csv',
        },
        {
            'label': 'merge sort',
            'input': 'C:/Users/d.balinski/src/cpp/sorting/test/test02_merge_sort.csv',
        },
        {
            'label': 'quick sort',
            'input': 'C:/Users/d.balinski/src/cpp/sorting/test/test02_quick_sort.csv',
        },
        {
            'label': 'radix sort',
            'input': 'C:/Users/d.balinski/src/cpp/sorting/test/test02_radix_sort.csv',
        },
        {
            'label': 'selection sort',
            'input': 'C:/Users/d.balinski/src/cpp/sorting/test/test02_selection_sort.csv',
        },
        {
            'label': 'shell sort',
            'input': 'C:/Users/d.balinski/src/cpp/sorting/test/test02_shell_sort.csv',
        },
        {
            'label': 'intro sort',
            'input': 'C:/Users/d.balinski/src/cpp/sorting/test/test02_intro_sort.csv',
        },
        {
            'label': 'quick sort',
            'input': 'C:/Users/d.balinski/src/cpp/sorting/test/test02_quick_sort.csv',
        },
        {
            'label': 'quick merge sort',
            'input': 'C:/Users/d.balinski/src/cpp/sorting/test/test02_quick_merge_sort.csv',
        },
    ]
})

simple_plot(config)
