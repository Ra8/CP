def gcd(a, b):
    while a > 1 and b > 1:
        a, b = max(a, b), min(a, b)
        a, b = b, a % b
    if a == 1 or b == 1:
        return 1
    if a == 0:
        return b
    if b == 0:
        return a

def test():
    assert gcd(5, 10) == 5
    assert gcd(2, 3) == 1
    assert gcd(5, 8) == 1
    assert gcd(6, 8) == 2
    assert gcd(30, 70) == 10

if __name__ == "__main__":
    test()