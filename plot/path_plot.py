from os import getenv


class PlotPath:

    def __init__(self):
        self.__directory = getenv('PLOT_DIRECTORY')

    def filename(self, f):
        self.__filename = f
        return self

    def get_path(self):
        return '{}/{}.svg'.format(self.__directory, self.__filename)
