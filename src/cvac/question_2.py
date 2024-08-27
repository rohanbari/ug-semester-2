import pandas as pd
from sklearn.ensemble import RandomForestRegressor
from sklearn.model_selection import train_test_split


def main():
    """This program uses scikit-learn to predict and replace the missing values.
    """

    # Load the CSV file
    FILE_NAME = 'C:/Users/Rohan/code/ug-semester-2/src/cvac/diabetes.csv'
    dataset = pd.read_csv(FILE_NAME)

    # Display the summary of missing data
    print('\nMissing Data Summary:')
    print(dataset.isnull().sum())

    # Fill missing values in each column by predicting them
    for column in ['Glucose', 'BloodPressure', 'SkinThickness', 'Insulin', 'BMI', 'DiabetesPedigreeFunction', 'Age']:

        # Check if the column has missing values
        if dataset[column].isnull().sum() > 0:

            # Split the data into rows where the target is missing and where it is not
            df_missing = dataset[dataset[column].isnull()]
            df_not_missing = dataset[dataset[column].notnull()]

            # Define the features (all columns except the target and the 'Outcome')
            X = df_not_missing.drop(columns=['Outcome', column])
            y = df_not_missing[column]

            # Train a RandomForestRegressor on the complete cases
            model = RandomForestRegressor(n_estimators=100, random_state=42)
            model.fit(X, y)

            # Predict the missing values
            X_missing = df_missing.drop(columns=['Outcome', column])
            predicted_values = model.predict(X_missing)

            # Fill in the missing values
            dataset.loc[dataset[column].isnull(), column] = predicted_values

    # Verify that there are no more missing values
    print('\nData After Predicting Missing Values:')
    print(dataset.isnull().sum())

    # Save the cleaned data to a new CSV file
    dataset.to_csv('C:/Users/Rohan/code/ug-semester-2/src/cvac/' +
                   'cleaned_diabetes.csv', index=False)

    print('\nCleaned data saved!')


if __name__ == '__main__':
    main()
