// Resolução do problema Desvio de Rota
// no site: https://www.beecrowd.com.br/judge/pt/problems/view/1123
// problema da Maratona de Programação da SBC 2010
#include <bits/stdc++.h>
#define MAX 260
#define oo 1000000010
using namespace std;
using ii = pair<int, int>;
vector<ii> adj[MAX];
int dist[MAX];

//aqui há um dijkstra padrão
void dijkstra(int s, int N, int C)
{
  bitset<MAX> visitado(0); // bits para saber se um lugar foi visitado
  for (int i = 0; i <= N; ++i)
  { // for para botar maxima distancia
    dist[i] = oo;
  }
  dist[s] = 0;
  priority_queue<ii, vector<ii>, greater<ii>> fila; // fila, o primeiro elemento como peso e segudo como destino
  pair<int, int> parInicial(0, s);                  // par inicial
  fila.push(parInicial);                            // colocando par inicial na lista
  while (!fila.empty() && visitado[C] == 0)
  {
    auto cidade = fila.top(); // primeiro elemento da fila
    fila.pop();               // exclui o primeiro elemnto
    if (visitado[cidade.second] == 0)
    { // se ele não foi visitado
      visitado[cidade.second] = 1;
      for (auto w : adj[cidade.second])
      { // pega cada elemento da lista
        if (dist[w.first] > w.second + dist[cidade.second])
        {
          dist[w.first] = w.second + dist[cidade.second];
          ii alvo(dist[w.first], w.first);
          fila.push(alvo);
        }
      }
    }
  }
}


int main()
{
  while (1)
  {
    int N, M, C, K, U, V, P;
    // N = quantidade de cidades
    // M = numero de estradas
    // C = numero de cidades na rota de servico
    // K = cidade em que o veiculo foi consertado
    // U = cidade1
    // V = cidade2
    // P = peso da aresta entre cidade1 e cidade2
    scanf("%d %d %d %d", &N, &M, &C, &K);
    if (!(N || M || C || K))
    {
      break;
    }
    for (int i = 0; i < M; i++)
    {
      scanf("%d %d %d", &U, &V, &P);
      // Se U e V forem maiores do que C-1, então podem se conectar mutuamente
      if (V >= C-1 && U >=C-1)
      {
        ii aresta(V, P);
        ii aresta2(U, P);
        adj[U].push_back(aresta);
        adj[V].push_back(aresta2);
      }
      // se somente um deles for maior do que C-1, a conexaõ é do maior para o menor
      else if (V > C-1)
      {
        ii aresta2(U, P);
        adj[V].push_back(aresta2);
      }
      else if (U > C-1){
        ii aresta2(V, P);
        adj[U].push_back(aresta2);
      }
      // Caso ambos sejam menores, só pode haver a conexão do menor para o maior se a diferença entre eles for 1
      // E não pode haver do maior para o menor
      else if(U-V==-1){
        ii aresta2(V, P);
        adj[U].push_back(aresta2);        
      }
      else if(V-U==-1){
        ii aresta2(U, P);
        adj[V].push_back(aresta2);        
      }
    }

    dijkstra(K, N, C - 1);
    printf("%d\n", dist[C - 1]);

    for (int i = 0; i < N; i++)
    {
      adj[i].clear();
    }
  }
  return 0;
}