def rec(s: str, has_black: int = False):
    s = s[1:-1]

    nodes = []
    prev = 0
    counter = 0
    for i, c in enumerate(s):
        counter += c == "("
        counter -= c == ")"
        if counter == 0 and c == ",":
            nodes.append(s[prev:i])
            prev = i + 1
    nodes.append(s[prev:])

    root, *nodes = nodes
    if root == "b":
        has_black = True

    return int(has_black and root == "w") + sum(rec(node, has_black) for node in nodes)


print(rec(input()))
