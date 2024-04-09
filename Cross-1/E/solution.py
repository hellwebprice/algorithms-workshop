import sys

input = sys.stdin.buffer.readline


def read_int():
    return int(input())


def read_str():
    return input()


def read_array(sep=None, maxsplit=-1):
    return input().split(sep, maxsplit)


def read_int_list(sep=None, maxsplit=-1):
    return [int(x) for x in input().split(sep, maxsplit)]


def write(*args, **kwargs):
    sep = kwargs.get("sep", " ")
    end = kwargs.get("end", "\n")
    sys.stdout.write(sep.join(str(a) for a in args) + end)


def write_array(array, **kwargs):
    sep = kwargs.get("sep", " ")
    end = kwargs.get("end", "\n")
    sys.stdout.write(sep.join(str(a) for a in array) + end)


t = read_int()
for _ in range(t):
    n = read_int()
    p = read_int_list()

    result = 0
    indeces = sorted(enumerate(p), key=lambda x: x[1])
    for i, (index, _) in enumerate(indeces[1:]):
        result += index < indeces[i][0]
    write(result)
