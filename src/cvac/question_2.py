import matplotlib.pyplot as plt
import pandas as pd


def main():
    # Load the CSV data
    FILE_NAME = 'C:/Users/Rohan/code/ug-semester-2/src/cvac/survival.csv'
    dataset = pd.read_csv(FILE_NAME)
    
    print(dataset.head(10))

    # Calculate the survival rates
    survival_counts = dataset['Survived'].value_counts()
    survival_percentage = (survival_counts / survival_counts.sum()) * 100

    # Plotting the survival percentage
    plt.figure(figsize=(8, 6))
    survival_percentage.plot(kind='pie', color=['green', 'red'])
    plt.title('Survival Percentage on the Accident')
    plt.xlabel('Survived (1 = Yes, 0 = No)')
    plt.ylabel('Percentage (%)')
    plt.xticks(rotation=0)
    plt.show()


if __name__ == '__main__':
    main()
