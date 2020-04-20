class FirstClass:
    var_in_all_objects = 0
    def setdata(self, value):
        self.data = value
    def display(self):
        print(self.data)
    def static_method():
        print('static_method')

      
if __name__ == '__main__':
    x = FirstClass()
    y = FirstClass()
    x.setdata("King Arthur")
    y.setdata(3.14159)

    FirstClass.var_in_all_objects = 'abc'
    x.var_in_all_objects = 15
    print(FirstClass.var_in_all_objects)
    print(x.var_in_all_objects)
    print(y.var_in_all_objects)

    x.var_in_all_objects = 'str'
    print(x.var_in_all_objects)

    x.display()
    y.display()

    FirstClass.static_method()

    x.data = "new value"
    x.display()
    
    x.anothername = "spam"
    print(x.anothername)
