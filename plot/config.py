from importer import *


class Plot:
    def __init__(self, label, x, y):
        self.label = label
        self.x = x
        self.y = y


class Config:
    def __init__(self, config):
        self.title = config['title']
        self.x_label = config['xlabel']
        self.y_label = config['ylabel']
        self.output = config['output']
        self.plots = []

        for p in config['plots']:
            x, y = import_data(p['input'], config['xcolumn'], config['ycolumn'])
            self.plots.append(Plot(p['label'], x, y))

        for p in config['super_plots']:
            n = config['n']
            step = max(1, n//100)
            x = list(range(0, n+step, step))
            y = list(map(p['function'], x))
            self.plots.append(Plot(p['label'], x, y))
