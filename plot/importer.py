import pandas as pd


def import_data(input, xcolumn, ycolumn):
    df = pd.read_csv(input, names=['sorting', 'n', 'comparisons', 'swaps', 'assigns'])
    return df[xcolumn], df[ycolumn]
