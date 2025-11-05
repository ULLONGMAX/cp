/*
Heavy-light decomposition is a fairly general technique that allows us to effectively
solve many problems that come down to queries on a tree.

The essence of this tree decomposition is to split the tree into several paths (called
HEAVY PATHS) so that we can reach the ROOT vertex from any v by traversing at most
log(n) paths (THEOREM).
In addition, NONE of these paths should intersect with another.

So this is similar to EulerTour in the way that this technique also FLATTENS THE TREE.
*/
vector<int> parent, depth, heavy, head, pos;
int cur_pos;

int dfs(int v, vector<vector<int>> const& adj) {
    int size = 1; // subtree size of current node v.
    int max_c_size = 0;
    for (int c : adj[v]) {
        if (c != parent[v]) {
            parent[c] = v, depth[c] = depth[v] + 1;
            int c_size = dfs(c, adj);
            size += c_size;
            if (c_size > max_c_size){
                // We define the HEAVIEST CHILD the one that has the largest subtree size:
                max_c_size = c_size, heavy[v] = c;
                /* so it's obvious that there is exactly ONE HEAVY CHILD for all nodes
                (except for leaves).
                */
            }
            /* the other children (that are NOT heavy) are called LIGHT CHILDREN (because
            they correspond to LIGHT EDGES).
            */
        }
    }
    return size;
}

void decompose(int v, int h, vector<vector<int>> const& adj) { // h = head of v
    head[v] = h, pos[v] = cur_pos++;
    if (heavy[v] != -1) // if v is not a leaf (only leaves have heavy[v]=-1)
        decompose(heavy[v], h, adj);
    for (int c : adj[v]) {
        if (c != parent[v] && c != heavy[v])
            decompose(c, c, adj);
    }
    /* it's obvious to note that at the end all nodes belong to ONE AND EXACTLY
    ONE HEAVY PATH.*/
}

void init(vector<vector<int>> const& adj) {
    int n = adj.size();
    parent = vector<int>(n);
    depth = vector<int>(n);
    heavy = vector<int>(n, -1); // stores the child (for all nodes) that has the HEAVIEST edge.
    // such a child is called HEAVIEST CHILD.
  
    head = vector<int>(n); // head[u] = the TOP node of the HEAVY PATH that u belongs to.
    pos = vector<int>(n); // position of each node in the FLATTENING OF THE TREE.
    cur_pos = 0;

    dfs(0, adj); // we define the root to be the 0th vertex.
    decompose(0, 0, adj);
}

// for answering queries, we can use the theorem stated at the start of this code.
