class Metadata:

    def __init__(self, json, n):
        self.title = json['title']
        self.xlabel = json['xlabel']
        self.ylabel = json['ylabel']
        self.xcolumn = json['xcolumn']
        self.ycolumn = json['ycolumn']
        self.legend = json['legend']
        self.n = n
