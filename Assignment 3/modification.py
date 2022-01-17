import pandas as pd

# read csv file
df = pd.read_csv('weather_data_2sites_original.csv')

# convert to datetime format
df['timestamp'] = pd.to_datetime(df.timestamp)

# get day first
df['timestamp'] = df['timestamp'].dt.strftime('%d/%m/%Y %H:%M:%S')

# rename id column
df.rename( columns={'Unnamed: 0':'id'}, inplace=True )

# save the modified CSV data
df.to_csv('weather_data_2sites.csv', index=False)
