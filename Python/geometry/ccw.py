# Check clockwise / counter clockwise / colinearity of points

def turn(p, q, r):
    result = (r[0] - q[0]) * (p[1] - q[1]) - (r[1] - q[1]) * (p[0] - q[0])
    if result < 0:
        # P->Q->R is a right turn
        return -1
    if result > 0:
        # P->Q->R is a left turn
        return 1
    # P - Q - R are collinear 
    return 0


def ccw(p, q, r):
    """
    Check if p, q, r make a counter clockwise turn
    """
    return turn(p, q, r) > 0


def intersect(a, b, c, d):
    """
    return if segment a-b intersects segment c-d
    """
    return (ccw(a, b, c) * ccw(a, b, d) <= 0) and (ccw(c, d, a) * ccw(c, d, b) <= 0)


