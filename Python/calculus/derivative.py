__author__ = 'mdippel'


def derivative(p):
    """

    :param p: array of coefficients, p[i] is coefficient of x^i
    :return:
    """
    d = [0] * (len(p) - 1)
    for i in range(len(d)):
        d[i] = p[i+1] * (i + 1)
    return d

def integral(p):
    """

    :param p: array of coefficients, p[i] is coefficient of x^i
    :return:
    """
    q = [0] * (len(p) + 1)
    for i in range(1, len(q)):
        q[i] = p[i-1] / float(i)
    return q

def evaluate(p, x):
    s = 0
    for coefficient in p[::-1]:
        s += coefficient
        s *= x
    return s

def definite_integral(p, a, b):
    q = integral(p)
    return evaluate(q, b) - evaluate(q, a)

def tests():
    p = [1, 1, 1, 1]
    assert derivative(p) == [1, 2, 3]
    assert integral(p) == [0, 1, 1.0 / float(2), 1.0 / float(3), 1.0 / float(4)]

if __name__ == "__main__":
    tests()