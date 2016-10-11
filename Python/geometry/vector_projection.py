def dot_product(x, y):
    total = 0
    for a, b in zip(x, y):
        total += a * b
    return total

def project(v, s):
    """
    project v onto the line spanned by s
    """
    factor = float(dot_product(v, s)) / float(dot_product(s, s))
    output = [s[0] * factor, s[1] * factor]
    return output

def reflect(v, s):
    """
    reflect v over the line defined by s
    """
    projection = project(v, s)
    difference = [v[0] - projection[0], v[1] - projection[1]]
    answer = [projection[0] - difference[0], projection[1] - difference[1]]
    return answer


def test():
    assert project([2, 3], [1, 2]) == [1.6, 3.2]
    assert project([23, 45], [1, 0]) == [23, 0]
    assert project([23, 45], [0, 1]) == [0, 45]

    assert reflect([1, 2], [1, 0]) == [1, -2]
    assert reflect([1, 2], [0, 1]) == [-1, 2]

    assert reflect([1, 2], [1, -1]) == [-2, -1]

if __name__ == "__main__":
    test()