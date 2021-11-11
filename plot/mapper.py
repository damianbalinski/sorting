from simple_plotter import *
from density_plotter import *
from math import log
from line import *
import pandas as pd


def map_plotter(type):
    return {
        'simple': SimplePlotter(),
        'average': SimplePlotter(),
        'density': DensityPlotter(),
    }[type]


def map_expression(expression):
    return {
        'n': lambda n: n,
        'n*n': lambda n: (n**2.001),
        '1/2n*n': lambda n: 0.5*(n**2.001),
        '1/4n*n': lambda n: 0.25*(n**2.001),
        'log(n)': lambda n: log(n) if n > 0 else 0,
        'nlog(n)': lambda n: n*log(n) if n > 0 else 0,
    }[expression]


def map_function(function, colors, n):
    step = max(1, n // 100)
    rng = range(0, n + step, step)
    exp = map_expression(function['expression'])
    dy = exp(n) / 100

    return Line(
        [n for n in rng],
        [exp(n)+dy for n in rng],
        function['label'],
        colors.next_gray()
    )


def map_sorting(sorting, path, colors, metadata):
    path = path.generator(sorting['generator']).algorithm(sorting['algorithm'])
    df = pd.read_csv(path.get_path(), names=['n', 'comparisons', 'swaps', 'assigns', 'time', 'all'])
    return Line(
        [0] + list(df[metadata.xcolumn]),
        [0] + list(df[metadata.ycolumn]),
        sorting['label'],
        colors.next_color()
    )
