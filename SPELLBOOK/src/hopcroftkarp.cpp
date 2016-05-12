/*
 G = G1 ∪ G2 ∪ {NIL}
 where G1 and G2 are partition of graph and NIL is a special null vertex
*/
  
function BFS ()
    for v in G1
        if Pair_G1[v] == NIL
            Dist[v] = 0
            Enqueue(Q,v)
        else
            Dist[v] = ∞
    Dist[NIL] = ∞
    while Empty(Q) == false
        v = Dequeue(Q)
        if Dist[v] < Dist[NIL] 
            for each u in Adj[v]
                if Dist[ Pair_G2[u] ] == ∞
                    Dist[ Pair_G2[u] ] = Dist[v] + 1
                    Enqueue(Q,Pair_G2[u])
    return Dist[NIL] != ∞

function DFS (v)
    if v != NIL
        for each u in Adj[v]
            if Dist[ Pair_G2[u] ] == Dist[v] + 1
                if DFS(Pair_G2[u]) == true
                    Pair_G2[u] = v
                    Pair_G1[v] = u
                    return true
        Dist[v] = ∞
        return false
    return true

function Hopcroft-Karp
    for each v in G
        Pair_G1[v] = NIL
        Pair_G2[v] = NIL
    matching = 0
    while BFS() == true
        for each v in G1
            if Pair_G1[v] == NIL
                if DFS(v) == true
                    matching = matching + 1
    return matching
