# codility_MaxCounters
![image](https://github.com/Shinichi0713/codility_MaxCounters/assets/61480734/8e8d6f77-bb68-4afa-8027-adfed2f127c9)


#　ここがポイント
forの中で、配列をつくってはいけません。<br>
となると、maxに更新は・・・？
全体更新する値を保持して起き、最後に、更新値より小さい要素を書き換えてしまいます
こうすると、速度劣化を防げます
