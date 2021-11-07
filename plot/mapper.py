from simple_plotter import *
from math import log
from line import *
import pandas as pd


def map_plotter(type):
    return {
        'simple': SimplePlotter(),
        'average': SimplePlotter(),
    }[type]


def map_expression(expression):
    return {
        'n': lambda n: n,
        'n*n': lambda n: n*n,
        'log(n)': lambda n: log(n) if n > 0 else 0,
        'nlog(n)': lambda n: n*log(n) if n > 0 else 0,
    }[expression]


def map_function(function, n):
    step = max(1, n // 100)
    rng = range(0, n + step, step)
    exp = map_expression(function['expression'])

    return Line(
        [n for n in rng],
        [exp(n) for n in rng],
        function['label'],
        function['color'],
    )


def map_sorting(sorting, path, metadata):
    path = path.algorithm(sorting['algorithm'])
    df = pd.read_csv(path.get_path(), names=['n', 'comparisons', 'swaps', 'assigns', 'time', 'all'])
    return Line(
        [0] + list(df[metadata.xcolumn]),
        [0] + list(df[metadata.ycolumn]),
        sorting['label'],
        sorting['color'],
    )
