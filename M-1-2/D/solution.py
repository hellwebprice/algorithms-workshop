def rec(s: str):
    reverse = 0
    while s[-1 - reverse] == "R":
        reverse += 1
    if reverse:
        s = s[:-reverse]
    reverse = reverse % 2

    s = s[1:-1]
    if s.count(",") == 0:
        if reverse:
            return s[::-1]
        return s

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
    if reverse:
        nodes = nodes[::-1]

    res = []
    for node in nodes:
        if reverse:
            node += "R"
        res.append(rec(node))

    return "".join(res)


print(rec(input()))
