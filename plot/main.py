from simple_plot import *
from config import *

config = Config({
    'title': 'Liczba poszczególnych operacji \nw zależności od wielkości tablicy',
    'xlabel': 'liczba elementów w tablicy',
    'ylabel': 'liczba operacji',
    'output': 'quick_sort_test4.png',

    'plots': [
        {'label': 'comparisons',
         'xcolumn': 'n',
         'ycolumn': 'comparisons',
         'input': 'quick_sort_10000.csv'},

        {'label': 'swaps',
         'xcolumn': 'n',
         'ycolumn': 'swaps',
         'input': 'quick_sort_10000.csv'},

        {'label': 'assigns',
         'xcolumn': 'n',
         'ycolumn': 'assigns',
         'input': 'quick_sort_10000.csv'},
    ]
})

simple_plot(config)
