def aStarAlgo(start_node, stop_node, Graph_nodes, heuristic):
    open_set = {start_node}
    closed_set = set()
    g = {start_node: 0}               
    parents = {start_node: start_node}
    while len(open_set) > 0:
        n = None
        for v in open_set:
            if n == None or g[v] + heuristic(v) < g.get(n, float('inf')) + heuristic(n):
                n = v
        if n == stop_node or Graph_nodes.get(n) == None:
            pass
        else:
            for (m, weight) in get_neighbors(n, Graph_nodes):
                
                if m not in open_set and m not in closed_set:
                    open_set.add(m)
                    parents[m] = n
                    g[m] = g[n] + weight                
                else:
                    if g.get(m, float('inf')) > g[n] + weight:
                        g[m] = g[n] + weight
                        parents[m] = n
                        if m in closed_set:
                            closed_set.remove(m)
                            open_set.add(m)
        if n == None:
            print('Path does not exist!')
            return None
        if n == stop_node:
            path = []
            while parents[n] != n:
                path.append(n)
                n = parents[n]
            path.append(start_node)
            path.reverse()
            print('Path found: {}'.format(path))
            return path
        open_set.remove(n)
        closed_set.add(n)
    print('Path does not exist!')
    return None
def get_neighbors(v, Graph_nodes):
    if v in Graph_nodes:
        return Graph_nodes[v]
    else:
        return None