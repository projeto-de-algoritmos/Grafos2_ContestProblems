// Resolução do problema "Rede Ótica"
// no site: https://www.beecrowd.com.br/judge/pt/problems/view/2190
// Problema da OBI - Olimpíada Brasileira de Informática 2000
#include <bits/stdc++.h>
#define MAX 100100
#define oo 1000000000001
using namespace std;
using ii = pair<int, int>;
vector<pair<int, ii>> adj;

void addEdge(int u, int v, int w)
{
  adj.push_back({w, {u, v}});
}

struct UnionFind
{
  int *parent, *rnk;
  int n;

  // Constructor.
  UnionFind(int n)
  {
    // Allocate memory
    this->n = n;
    parent = new int[n + 1];
    rnk = new int[n + 1];

    // Initially, all vertices are in
    // different sets and have rank 0.
    for (int i = 0; i <= n; i++)
    {
      rnk[i] = 0;

      // every element is parent of itself
      parent[i] = i;
    }
  }

  // Find the parent of a node 'u'
  // Path Compression
  int find(int u)
  {
    /* Make the parent of the nodes in the path
    from u--> parent[u] point to parent[u] */
    if (u != parent[u])
      parent[u] = find(parent[u]);
    return parent[u];
  }

  // Union by rank
  void merge(int x, int y)
  {
    x = find(x), y = find(y);

    /* Make tree with smaller height
    a subtree of the other tree */
    if (rnk[x] > rnk[y])
      parent[y] = x;
    else // If rnk[x] <= rnk[y]
      parent[x] = y;

    if (rnk[x] == rnk[y])
      rnk[y]++;
  }
};

/* Functions returns weight of the MST*/

int kruskalMST(int V)
{
  int mst_wt = 0; // Initialize result

  // Sort edges in increasing order on basis of cost
  sort(adj.begin(), adj.end());

  // Create disjoint sets
  UnionFind ds(V);

  // Iterate through all sorted edges
  vector<pair<int, ii>>::iterator it;
  for (it = adj.begin(); it != adj.end(); it++)
  {
    // int aresta = it->first;
    // int aresta2= (it+1)->first
    // int aresta3 =(it+2)->first
    int u = it->second.first;
    int v = it->second.second;

    int set_u = ds.find(u);
    int set_v = ds.find(v);

    // Check if the selected edge is creating
    // a cycle or not (Cycle is created if u
    // and v belong to same set)
    if (set_u != set_v)
    {
      // Current edge will be in the MST
      // so print it
      printf("%d %d\n", it->second.first, it->second.second);

      // Update MST weight
      mst_wt += it->first;

      // Merge two sets
      ds.merge(set_u, set_v);
    }
  }

  return mst_wt;
}

int main()
{
  int n, m, x, y, z, test = 1;
  while (1)
  {
    scanf("%d %d", &n, &m);
    if ((n == 0 || m == 0))
    {
      break;
    }
    printf("Teste %d\n", test++);
    while (m--)
    {
      scanf("%d %d %d", &x, &y, &z);
      addEdge(x, y, z);
      addEdge(y, x, z);
    }
    kruskalMST(n);
    printf("\n");
    adj.clear();
  }
  return 0;
}
