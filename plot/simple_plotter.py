from plotter import *


class SimplePlotter(Plotter):

    def draw(self, ax, invariants, lines):
        for l in lines:
            ax.plot(l.x, l.y, label=l.label)

        self.limits(ax, invariants)
        self.labels(ax, invariants)
        self.legend(ax, invariants)
        self.grid(ax, invariants)
