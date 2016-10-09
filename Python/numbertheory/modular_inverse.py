
def modular_inverse(a, n):
    t, new_t = 0, 1
    r, new_r = n, a
    while new_r != 0:
        q = r // new_r
        t, new_t = new_t, t - (q * new_t)
        r, new_r = new_r, r - (q * new_r)
    if r > 1:
        return None
    if t < 0:
        t += n
    return t


def test():
    assert modular_inverse(3, 11) == 4
    assert modular_inverse(3, 7) == 5
    assert modular_inverse(2, 6) == None


if __name__ == "__main__":
    test()