def _compute_kmp_table(w):
    """
    compute the table necessary for the running of the KMP algorithm
    creates a table T, such that, if we matched the first i - 1 characters of w,
    T[i] indicates how many characterrs we need to back track to ensure proper matching
    while linearly scanning a containing string S

    example:
    in searching S, we matched w[0]. w[1], w[2], ..., but mismatched w[i]
    our current position in S is pos
    T[i] will tell us how many characters back from pos we have already matched, without
    having to decrement pos
    :param w:
    :return:
    """
    T = [-1 for _ in range(len(w) + 1)]
    pos = 1 # current pos computing in T
    cnd = 0 # the zero based index in W of the next character of the current candidate substring

    while pos < len(w):
        if w[pos] == w[cnd]:
            T[pos] = T[cnd]
            pos += 1
            cnd += 1
        else:
            T[pos] = cnd
            cnd = T[cnd]
            while cnd >= 0 and w[pos] != w[cnd]:
                cnd = T[cnd]
            pos += 1
            cnd += 1

    # finally add the case for a complete match
    T[pos] = cnd
    return T


def kmp_search(S, w):
    """
    perform KMP string matching
    yields the starting index of all occurances of w in S
    :param S:
    :param w:
    :return:
    """

    m = 0 # beginning of the current match in S
    i = 0 # position of the current character in w
    T = _compute_kmp_table(w)

    while m + i < len(S):
        if w[i] == S[m + i]: # next character matches
            i += 1
            if i == len(w): # we have a complete match
                yield m
                # we can now skip the pos in S based on T[i]
                # go to the char we just matched, and step back T[i] steps
                m = m + i - T[i]
                i = T[i]
                assert i != -1
        else: # There is a character mismatch
            if T[i] == -1:
                # We use the same logic for advancing m, since T[i] = -1
                m = m + i + 1
                # but we have to set i to be the start of w now
                # When T[i] == -1, assume we havent matched any characters and move to the next char
                i = 0
            else:
                # Use the same logic to advance m
                m = m + i - T[i]

                # Then assume we have matched T[i] characters up till now
                # the only difference between T[i] = 0 and T[i] = -1 is whether or
                # not we advance a character
                i = T[i]
                assert i != -1

def test_kmp():

    S = "ABC ABCDAB ABCDABCDABDE"
    w = "ABCDABD"
    T = _compute_kmp_table(w)
    assert tuple(T) == (-1, 0, 0, 0, -1, 0, 2, 0), tuple(T)
    starts = [i for i in kmp_search(S, w)]
    assert len(starts) == 1
    assert starts[0] == 15

    S = "AAAAAAAAAAAAAAAAB"
    w = "AAAB"
    T = _compute_kmp_table(w)
    assert tuple(T) == (-1, -1, -1, 2, 0), tuple(T)
    starts = [i for i in kmp_search(S, w)]
    assert len(starts) == 1
    assert starts[0] == 13

    S = "ABABDABACDABABCABAB"
    w = "ABABCABAB"
    T = _compute_kmp_table(w)
                       # A  B   A  B   C   A   B   A  B  -all-
    assert tuple(T) == (-1, 0, -1, 0, 2, -1, 0, -1, 0, 4), tuple(T)
    starts = [i for i in kmp_search(S, w)]
    assert len(starts) == 1
    assert starts[0] == 10


if __name__ =="__main__":
    test_kmp()