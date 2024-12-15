from queue import Queue

# キューの初期化
q = Queue()

# キューに要素を追加（enqueue）
q.put('a')
q.put('b')
q.put('c')


# キューから要素を取り出す（dequeue）
print("\nQueue after elements are dequeued:")
while not q.empty():
    print(q.get())

