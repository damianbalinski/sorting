from invariants import *
from mapper import *


class Plot:

    def __init__(self, json, path):
        path = path.type(json['type'])
        self.plotter = map_plotter(json['type'])
        self.invariants = Invariants(json['invariants'])
        sortings = [map_sorting(s, path, self.invariants) for s in json['sortings']]
        functions = [map_function(f, self.invariants.n) for f in json['functions']]
        self.lines = sortings + functions

    def draw(self, ax):
        self.plotter.draw(ax, self.invariants, self.lines)
