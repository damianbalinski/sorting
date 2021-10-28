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
            x, y = import_data(p['input'], p['xcolumn'], p['ycolumn'])
            self.plots.append(Plot(p['label'], x, y))
