# queueを実装してみて練習する
# 先入れ先出し


class Queue:
    def __init__(self):
        self.queue = []

    def enque(self, data_input):
        self.queue.append(data_input)

    def deque(self):
        data_output = self.queue.pop(0)
        return data_output

    def __len__(self):
        return len(self.queue)

if __name__ == "__main__":
    queue = Queue()
    queue.enque("A")
    print(queue.deque())
    print(len(queue))
