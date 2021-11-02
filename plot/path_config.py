from os import getenv


class ConfigPath:

    def __init__(self):
        self.__directory = getenv('CONFIG_DIRECTORY')

    def filename(self, f):
        self.__filename = f
        return self

    def get_path(self):
        return '{}/{}'.format(self.__directory, self.__filename)
