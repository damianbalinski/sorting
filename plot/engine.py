from path_test import *
from path_plot import *
from plot import *
import numpy as np
import matplotlib
import matplotlib.pyplot as plt


class Engine:

    def __init__(self, json):
        path = TestPath().prefix(json['prefix'])
        n = json['invariants']['range']['end']
        self.title = json['title']
        self.output = json['output']
        self.grid = eval(json['grid'])
        self.size = eval(json['size'])
        self.plots = [Plot(p, path, n) for p in json['plots']]

    def draw(self):
        plt.style.use('science')
        # plt.style.use(['science', 'no-latex'])
        matplotlib.rcParams['text.latex.preamble'] = r'\usepackage{polski}'

        fig, axes = plt.subplots(*self.grid, constrained_layout=True)
        axes = self.map_axes_into_array(axes)

        for i, plot in enumerate(self.plots):
            plot.draw(axes[i])

        path = PlotPath().filename(self.output)
        fig.suptitle(self.bold(self.title))
        fig.set_size_inches(*self.size)
        fig.set_constrained_layout_pads(wspace=0.1, hspace=0.08)
        fig.savefig(path.get_path(), dpi=300)

    def map_axes_into_array(self, axes):
        return [axes] if type(axes) is not np.ndarray else axes.flatten()

    def bold(self, s):
        return '\n'.join(list(map(lambda s: r'\textbf{{{}'.format(s), s.split('\n'))))
