def cout_graph(f):
    txt = open(f)
#    first_line = txt.readline()
 #   n, blue, red = first_line.split()
    n = int(txt.readline())
    graph = []
    while (n>0):
        edges  = map(int, txt.readline().split(' '))
        graph.append(edges)
        n = n-1
    return graph


