
import random

# ランダムな湖データを生成する
def generate_lake_data(rows, cols, lake_probability=0.3):
    data = []
    for _ in range(rows):
        row = []
        for _ in range(cols):
            if random.random() < lake_probability:
                row.append(1)
            else:
                row.append(0)
        data.append(row)
    return data

def print_lake_data(data):
    for row in data:
        print(" ".join(map(str, row)))

# テスト用データの生成
rows = 10
cols = 10
lake_data = generate_lake_data(rows, cols)

# データの表示
print_lake_data(lake_data)

