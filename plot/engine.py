from path_test import *
from path_plot import *
from plot import *
import matplotlib.pyplot as plt


class Engine:

    def __init__(self, json):
        path = TestPath().prefix(json['prefix'])
        self.title = json['title']
        self.output = json['output']
        self.plots = [Plot(p, path) for p in json['plots']]

    def draw(self):
        plt.style.use('science')
        fig, axes = plt.subplots(2, 1)

        for i, plot in enumerate(self.plots):
            plot.draw(axes[i])

        path = PlotPath().filename(self.output)
        fig.savefig(path.get_path(), dpi=300)
