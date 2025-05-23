import pandas as pd

json_data = [
  { "HotelName": "丰居旅店忠孝館", "Description": "位於臺北市的旅館", "ServiceInfo": "接駁服務、健身房、SPA", "Price": 2420, "PostalAddress": { "City": "臺北市", "Town": "大安區", "StreetAddress": "復興南路1段126巷1號3樓" } },
  { "HotelName": "松河璞旅", "Description": "位於臺北市的旅館", "ServiceInfo": "接駁服務、健身房", "Price": 2600, "PostalAddress": { "City": "臺北市", "Town": "松山區", "StreetAddress": "松河街112號1樓至8樓" } },
  { "HotelName": "二十輪旅店大安店", "Description": "優雅質感生活", "ServiceInfo": "SPA、游泳池、酒吧", "Price": 4500, "PostalAddress": { "City": "臺北市", "Town": "大安區", "StreetAddress": "大安路一段183號" } },
  { "HotelName": "城市商旅南東館", "Description": "時尚沉穩設計", "ServiceInfo": "健身房、酒吧、會議室", "Price": 3000, "PostalAddress": { "City": "臺北市", "Town": "松山區", "StreetAddress": "南京東路五段411號" } },
  { "HotelName": "在家行旅", "Description": "鄰近台北火車站", "ServiceInfo": "接駁服務、健身房", "Price": 1000, "PostalAddress": { "City": "臺北市", "Town": "中山區", "StreetAddress": "中山北路二段65巷2弄3號" } }
]

df = pd.DataFrame(json_data)

money_input = int(input())

filtered_df = df[df['Price'] <= money_input]

for _, row in filtered_df.iterrows():
    hotel_name = row['HotelName']
    city = row['PostalAddress']['City']
    print(f"旅館名稱: {hotel_name}, 城市: {city}")
