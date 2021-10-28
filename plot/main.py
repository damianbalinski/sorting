from math import log
from simple_plot import *
from config import *

config = Config({
    'title': 'Liczba poszczególnych operacji \nw zależności od wielkości tablicy',
    'xlabel': 'liczba elementów w tablicy',
    'ylabel': 'liczba operacji',
    'xcolumn': 'n',
    'ycolumn': 'time',
    'output': 'quick_sort_test11.png',
    'n': 10000,

    'super_plots': [
        {
            'label': 'n log(n)',
            'function': lambda n: n*log(n) if n != 0 else 0
        },
        {
            'label': 'n',
            'function': lambda n: n
        },
        {
            'label': 'n*n',
            'function': lambda n: n*n
        }
    ],

    'plots': [
        {
            'label': 'merge sort',
            'input': 'C:/Users/d.balinski/src/cpp/sorting/test/test08_merge_sort.csv',
        },
        {
            'label': 'dual pivot quick sort',
            'input': 'C:/Users/d.balinski/src/cpp/sorting/test/test08_dual_pivot_quick_sort.csv',
        },
        {
            'label': 'heap sort',
            'input': 'C:/Users/d.balinski/src/cpp/sorting/test/test08_heap_sort.csv',
        },
        {
            'label': 'radix sort',
            'input': 'C:/Users/d.balinski/src/cpp/sorting/test/test08_radix_sort.csv',
        },
        {
            'label': 'shell sort',
            'input': 'C:/Users/d.balinski/src/cpp/sorting/test/test08_shell_sort.csv',
        },
        {
            'label': 'intro sort',
            'input': 'C:/Users/d.balinski/src/cpp/sorting/test/test08_intro_sort.csv',
        },
        {
            'label': 'quick sort',
            'input': 'C:/Users/d.balinski/src/cpp/sorting/test/test08_quick_sort.csv',
        },
        {
            'label': 'quick merge sort',
            'input': 'C:/Users/d.balinski/src/cpp/sorting/test/test08_quick_merge_sort.csv',
        },
    ],
})

simple_plot(config)
