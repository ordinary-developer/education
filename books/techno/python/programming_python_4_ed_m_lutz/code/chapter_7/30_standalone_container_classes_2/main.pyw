from tkinter import *
import hellopackage


class HelloPackage(hellopackage.HelloPackage):

    def __getattr__(self, name):
        return getattr(self.top, name)


if __name__ == '__main__':
    HelloPackage().mainloop()
