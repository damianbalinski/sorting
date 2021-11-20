from simple_plotter import *
from density_plotter import *
from math import log
from line import *
import pandas as pd
from matplotlib.lines import Line2D
from colors import *


def map_plotter(type):
    return {
        'simple': SimplePlotter(),
        'average': SimplePlotter(),
        'cost_factor': SimplePlotter(),
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
        function.get('label', ''),
        colors.next_gray(),
        function.get('linestyle', 'solid')
    )


def map_sorting(sorting, path, colors, metadata):
    path = path.generator(sorting['generator']).algorithm(sorting['algorithm'])
    df = pd.read_csv(path.get_path(), names=['n', 'comparisons', 'swaps', 'assigns', 'time', 'all', 'factor'])
    return Line(
        [0] + list(df[metadata.xcolumn]),
        [0] + list(df[metadata.ycolumn]),
        sorting.get('label', ''),
        colors.next_color() if sorting.get('color') is None else colors.get_color(sorting.get('color')),
        sorting.get('linestyle', 'solid')
    )


def map_custom_legend(custom_legend):
    if custom_legend is None:
        return None
    else:
        return [Line2D([0], [0], color=Colors.get_color(l['color']), linestyle=l['linestyle'], label=l['label'], lw=1) for l in custom_legend]
