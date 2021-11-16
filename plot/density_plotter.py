from plotter import *
import numpy as np
import scipy.stats as stats


class DensityPlotter(Plotter):

    def draw(self, ax, metadata, lines):
        for l in lines:
            data = np.array(l.y)
            kde = stats.gaussian_kde(data)
            # min = np.quantile(data, 0.0001)
            # max = np.quantile(data, 0.9999)
            min = metadata.xmin
            max = metadata.xmax
            x = np.linspace(min, max, num=300)
            y = kde(x)
            ax.plot(x, y, color=l.color, label=l.label, linestyle=l.linestyle)

        self.limits(ax, metadata)
        self.labels(ax, metadata)
        self.legend(ax, metadata)
        self.grid(ax, metadata)

    def limits(self, ax, metadata):
        ax.set_ylim(ymin=0)
        ax.set_xlim(xmin=metadata.xmin, xmax=metadata.xmax)

