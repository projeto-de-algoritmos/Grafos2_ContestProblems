// Resolução do problema As Aventuras do Calango Atômico
// no site: https://www.beecrowd.com.br/judge/pt/problems/view/3119
#include <bits/stdc++.h>
#define MAX 100100
#define oo 1000000000001
using namespace std;
using ii = pair<long long int, long long int>;
vector<ii> adj[MAX];
long long int dist[MAX];

// aqui há um dijkstra padrão
void dijkstra(long long int s, long long int N, long long int C)
{
  bitset<MAX> visitado(0); // bits para saber se um lugar foi visitado
  for (long long int i = 0; i <= N; ++i)
  { // for para botar maxima distancia
    dist[i] = oo;
  }
  dist[s] = 0;
  priority_queue<ii, vector<ii>, greater<ii>> fila;    // fila, o primeiro elemento como peso e segudo como destino
  pair<long long int, long long int> parInicial(0, s); // par inicial
  fila.push(parInicial);                               // colocando par inicial na lista
  while (!fila.empty() && visitado[C] == 0)
  {
    auto cenario = fila.top(); // primeiro elemento da fila
    fila.pop();                // exclui o primeiro elemnto
    if (visitado[cenario.second] == 0)
    { // se ele não foi visitado
      visitado[cenario.second] = 1;
      for (auto w : adj[cenario.second])
      { // pega cada elemento da lista
        if (dist[w.first] > w.second + dist[cenario.second])
        {
          dist[w.first] = w.second + dist[cenario.second];
          ii alvo(dist[w.first], w.first);
          fila.push(alvo);
        }
      }
    }
  }
}

int main()
{
  long long int F, soma = 0;
  scanf("%lld", &F);
  long long int C, T, A, B, D;
  for (int i = 0; i < F; i++)
  {
    scanf("%lld %lld", &C, &T);
    for (long long int j = 0; j < T; j++)
    {
      scanf("%lld %lld %lld", &A, &B, &D);
      ii aresta(B, D);
      adj[A].push_back(aresta);
    }
    dijkstra(1, C + 1, C);
    soma += dist[C];
    for (long long int i = 0; i <= C; i++)
    {
      adj[i].clear();
    }
  }
  printf("%lld\n", soma);
  return 0;
}