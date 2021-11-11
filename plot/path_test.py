from os import getenv


class TestPath:

    def __init__(self):
        self.__directory = getenv('TEST_DIRECTORY')

    def prefix(self, p):
        self.__prefix = p
        return self

    def type(self, t):
        self.__type = t
        return self

    def generator(self, g):
        self.__generator = g
        return self

    def algorithm(self, a):
        self.__algorithm = a
        return self

    def get_path(self):
        return '{}/{}_{}_{}_{}.csv'.format(self.__directory, self.__prefix, self.__type, self.__generator, self.__algorithm)
