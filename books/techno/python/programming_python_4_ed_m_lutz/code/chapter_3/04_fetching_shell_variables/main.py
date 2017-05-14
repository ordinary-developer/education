if __name__ == '__main__':
    import os

    print(os.environ.keys())
    print(list(os.environ.keys()))
    print(os.environ['PATH'])

    print(os.environ['PATH'])
    for src_dir in os.environ['PATH'].split(os.pathsep):
        print(src_dir)

    import sys
    print(sys.path[:3])
    print(sys.path)

