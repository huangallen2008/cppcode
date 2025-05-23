import pandas as pd

data = {
    'Date': ['1/3/2023', '1/3/2023', '1/3/2023', '1/3/2023', '1/3/2023', '1/3/2023', '1/3/2023', '1/3/2023', '2/3/2023', '2/3/2023'],
    'Item': ['chai', 'chai', 'juice', 'coffee', 'coffee', 'chai', 'coldrink', 'others', 'chai', 'juice'],
    'Amount': [7, 20, 15, 12, 12, 25, 10, 10, 7, 15]
}
df = pd.DataFrame(data)

results = {'chai': 0, 'juice': 0, 'coffee': 0, 'coldrink': 0, 'others': 0}

filtered_df = df[df['Date'] == '1/3/2023']

grouped = filtered_df.groupby('Item')['Amount'].sum()

for item in results:
    if item in grouped:
        results[item] = grouped[item]

print(results)
