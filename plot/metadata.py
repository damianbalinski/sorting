from mapper import *


class Metadata:

    def __init__(self, json, n):
        self.title = json['title']
        self.xlabel = json['xlabel']
        self.ylabel = json['ylabel']
        self.xcolumn = json['xcolumn']
        self.ycolumn = json['ycolumn']
        self.legend = json['legend']
        self.lines = map_custom_legend(json.get('custom_legend'))
        self.ymin = json.get('ymin', 0)
        self.ymax = json.get('ymax')
        self.xmin = json.get('xmin', 0)
        self.xmax = json.get('xmax', n)
        self.n = n
