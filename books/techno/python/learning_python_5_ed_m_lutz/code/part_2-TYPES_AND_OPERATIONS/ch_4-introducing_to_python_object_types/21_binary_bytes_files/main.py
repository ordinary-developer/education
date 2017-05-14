if __name__ == '__main__':
    import struct
    packed = struct.pack('>i4sh', 7, b'spam', 8)
    print(packed)
    print(str(packed))
    print(repr(packed))
    file = open('data.bin', 'wb')
    file.write(packed)
    file.close()

    data = open('data.bin', 'rb').read()
    print(data)
    print(str(data))
    print(repr(data))
    print(data[4:8])
    print(list(data))
    print(struct.unpack('>i4sh', data))
