import itertools
__author__ = 'mdippel'


def gen_permutations(arr):
    """
    yield all permutations of arr
    """
    for perm in itertools.permutations(arr):
        yield perm

def find_subsets(S, m):
    """
    return all m sized subsets of S
    """
    return itertools.combinations(S, m)


def test():
    arr = [1,2,3,4]
    perms = [perm for perm in gen_permutations(arr)]
    assert len(perms) == 4*3*2*1

if __name__ == "__main__":
    test()

