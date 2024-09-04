import pandas as pd
from matplotlib import pyplot as plt


def main():
    """This program plots the counts of null values in different columns."""

    FILE_NAME = 'C:/Users/Rohan/code/ug-semester-2/src/cvac/diabetes.csv'
    dataset = pd.read_csv(FILE_NAME)

    print(dataset.head(20))

    missing_values = dataset.isnull().sum()

    plt.plot(figsize=(10, 6))
    missing_values.plot(kind='bar', color='green')

    plt.title('Count of Missing Values by Columns')

    plt.xlabel('Columns')
    plt.ylabel('Count of Missing Values')

    plt.xticks(rotation=45, ha='right')
    plt.tight_layout()

    plt.show()


if __name__ == '__main__':
    main()
