import seaborn as sns


class Colors:
    COLORS = {
        'red': 'tab:red',
        'blue': 'tab:blue',
        'orange': 'tab:orange',
        'green': 'tab:green',
        'purple': 'tab:purple',
        'brown': 'tab:brown',
        'pink': 'tab:pink',
        'cyan': 'tab:cyan'
    }

    COLOR_VALUES = list(COLORS.values())

    # COLORS = sns.cubehelix_palette(10, rot=0)

    GRAYS = [
        'silver',
        'grey',
        'dimgray'
    ]

    def __init__(self):
        self.color = -1
        self.gray = -1

    def next_color(self):
        self.color = (self.color + 1) % len(self.COLORS)
        return self.COLOR_VALUES[self.color]

    def next_gray(self):
        self.gray = (self.gray + 1) % len(self.GRAYS)
        return self.GRAYS[self.gray]

    @staticmethod
    def get_color(color):
        return Colors.COLORS.get(color, color)
