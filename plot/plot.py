from metadata import *
from mapper import *


class Plot:

    def __init__(self, json, path, n):
        path = path.type(json['type'])
        self.plotter = map_plotter(json['type'])
        self.metadata = Metadata(json['metadata'], n)
        sortings = [map_sorting(s, path, self.metadata) for s in json['sortings']]
        functions = [map_function(f, self.metadata.n) for f in json['functions']]
        self.lines = sortings + functions

    def draw(self, ax):
        self.plotter.draw(ax, self.metadata, self.lines)
