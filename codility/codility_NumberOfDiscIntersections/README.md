# codility_NumberOfDiscIntersections

![image](https://github.com/Shinichi0713/codility_NumberOfDiscIntersections/assets/61480734/908bf454-e82a-41ab-9951-afd30a813d70)

# ポイント
そのまま円の交差を求めようとするとforのネストが必要。。。<br>

そこで使うのが"スイープラインアルゴリズム"<br>
スイープラインアルゴリズムは、幾何学的な問題を解決するための一般的なテクニックで、空間を一方向に「スイープ」（または走査）し、その過程で問題を解決します。この場合、スイープラインは左から右へと移動し、円の開始点と終了点を「訪れ」ます。

このアルゴリズムのキーは、円の開始点を訪れるときに、その円が他のすべてのアクティブな円と交差するという事実を利用しています。これは、円の開始点が他のすべてのアクティブな円の内部にあるためです。したがって、新しい円の開始点を訪れるたびに、その円は他のすべてのアクティブな円と交差し、交差点の数を増やします。

このアプローチの利点は、すべての円のペアを個別に調べる必要がないため、計算時間を大幅に削減できることです。その代わりに、このアルゴリズムは円の開始点と終了点を一度だけ訪れ、その過程で交差点の数を効率的に計算します。

# スイープラインアルゴリズム

問題：
```
There is a car with capacity empty seats. The vehicle only drives east (i.e., it cannot turn around and drive west).

You are given the integer capacity and an array trips where trips[i] = [numPassengersi, fromi, toi] indicates that the ith trip has numPassengersi passengers and the locations to pick them up and drop them off are fromi and toi respectively. The locations are given as the number of kilometers due east from the car's initial location.

Return true if it is possible to pick up and drop off all passengers for all the given trips, or false otherwise.

 

Example 1:

Input: trips = [[2,1,5],[3,3,7]], capacity = 4
Output: false
Example 2:

Input: trips = [[2,1,5],[3,3,7]], capacity = 5
Output: true
 

Constraints:

1 <= trips.length <= 1000
trips[i].length == 3
1 <= numPassengersi <= 100
0 <= fromi < toi <= 1000
1 <= capacity <= 105
```
解答
```
def check_car_pooling(trips, capacity):
    trace = [0] * 1001
    # 各地点の乗客をトレース
    for n, pick_in, pick_out in trips:
        trace[pick_in] += n
        trace[pick_out] -= n
    # 乗客が定員を超えるか確認
    for n in trace:
        capacity -= n
        if capacity < 0:
            return False
    return True

print(check_car_pooling([[2,1,5],[3,3,7]], 4)) # False
```

