class Colors:

    COLORS = [
        'tab:red',
        'tab:blue',
        'tab:orange',
        'tab:green',
        'tab:purple'
    ]

    GRAYS = [
        'silver',
        'grey',
        'dimgray'
    ]

    def __init__(self):
        self.color = -1
        self.gray = -1

    def next_color(self):
        self.color = (self.color+1) % len(self.COLORS)
        return self.COLORS[self.color]

    def next_gray(self):
        self.gray = (self.gray+1) % len(self.GRAYS)
        return self.GRAYS[self.gray]
