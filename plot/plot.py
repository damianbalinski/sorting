from metadata import *
from mapper import *
from colors import *


class Plot:

    def __init__(self, json, path, n):
        path = path.type(json['type'])
        colors = Colors()
        self.plotter = map_plotter(json['type'])
        self.metadata = Metadata(json['metadata'], n)
        sortings = [map_sorting(s, path, colors, self.metadata) for s in json['sortings']]
        functions = [map_function(f, colors, self.metadata.n) for f in json['functions']]
        self.lines = functions + sortings

    def draw(self, ax):
        self.plotter.draw(ax, self.metadata, self.lines)
