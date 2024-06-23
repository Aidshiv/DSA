from collections import defaultdict

visited = defaultdict(lambda: False)
J1, J2, Litre = 0, 0, 0
path = []

def Water_Jug_Problem(X, Y):
    global J1, J2, Litre, path
    if (X == Litre and Y == 0) or (Y == Litre and X == 0):
        path.append((X, Y))
        return True
    if visited[(X, Y)] == False:
        path.append((X, Y))
        visited[(X, Y)] = True
        if (
            Water_Jug_Problem(X, 0) or
            Water_Jug_Problem(0, Y) or
            Water_Jug_Problem(J1, 0) or
            Water_Jug_Problem(X, J2) or
            Water_Jug_Problem(X + min(Y, (J1 - X)), Y - min(Y, (J1 - X))) or
            Water_Jug_Problem(X - min(X, (J2 - Y)), Y + min(X, (J2 - Y))):
        ):
            return True
        path.pop()
    return False

J1 = 4
J2 = 3
Litre = 2

print("Path is as follows")
Water_Jug_Problem(0, 0)
for state in path:
    print("({0}, {1})".format(state[0], state[1]))