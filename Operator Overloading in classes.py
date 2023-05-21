class MyVector:
    def __init__(self, *arg):
        self.__vector = [n for n in arg]
        for v in self.__vector:
            if type(v) == list or type(v) == tuple:
                self.__vector = [n for n in v]
            elif type(v) != int:
                raise ValueError("Non Integer Value Entered")
        self.__item_count = len(self.__vector)
        self.__index = -1

    def __iter__(self):
        return self

    def __next__(self):
        self.__index += 1
        if self.__index >= len(self.__vector):
            self._index = -1
            raise StopIteration
        else:
            return self.__vector[self.__index]

    def __str__(self):
        return "MyVector" + str(self.__vector)

    def __len__(self):
        return self.__item_count

    def __bool__(self):
        if self.__item_count <= 0 or sum([n ** 2 for n in self.__vector]) ** 0.5 == 0:
            result = False
        else:
            result = True
        return result

    def __abs__(self):
        return sum([n ** 2 for n in self.__vector]) ** 0.5

    def __getitem__(self, val):
        if isinstance(val, slice):
            return self.__vector[val]
        else:
            return self.__vector[val]

    def __setitem__(self, val, replace):
        self.__vector[val] = replace

    def __delitem__(self, val):
        del self.__vector[val]

    def __add__(self, c2):
        result = list(n + m for n, m in zip(self.__vector, c2.__vector))
        return MyVector(result)

    def __mul__(self, val):
        result = list(n * val for n in self.__vector)
        return MyVector(result)

    def __rmul__(self, val):
        result = list(n * val for n in self.__vector)
        return MyVector(result)

    def __lshift__(self, val):
        while val > self.__item_count:
            val = val - self.__item_count
        result = []
        for v in range(val, self.__item_count):
            result.append(self.__vector[v])
        for v in range(0, val):
            result.append(self.__vector[v])
        return MyVector(result)

    def __iadd__(self, c2):
        self.__vector = list(n + m for n, m in zip(self.__vector, c2.__vector))
        return MyVector(self.__vector)