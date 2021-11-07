from plotter import *


class SimplePlotter(Plotter):

    def draw(self, ax, metadata, lines):
        for l in lines:
            ax.plot(l.x, l.y, color=l.color, label=l.label)

        self.limits(ax, metadata)
        self.labels(ax, metadata)
        self.legend(ax, metadata)
        self.grid(ax, metadata)
