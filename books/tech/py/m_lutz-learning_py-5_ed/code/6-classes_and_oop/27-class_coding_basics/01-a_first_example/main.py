# classes generate multiple instance objects
def example_01(): 
    print("example 01 (classes generate multiple instance objects) =>")

    class FirstClass:
        def setdata(self, value):
            self.data = value
        def display(self):
            print(self.data)

    x = FirstClass()
    y = FirstClass()

    x.setdata("King Arthur")
    y.setdata(3.14159)

    x.display()
    y.display()

    x.data = "New value"
    x.display()

    x.anothername = "spam"


if __name__ == '__main__':
    example_01()