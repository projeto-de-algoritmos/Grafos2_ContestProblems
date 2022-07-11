// Resolução do problema "Reduzindo Detalhes em um Mapa"
// no site: https://www.beecrowd.com.br/judge/pt/problems/view/2404
// problema da OBI - Olimpíada Brasileira de Informática 2011 Fase 2 Nível 2
#include <bits/stdc++.h>
#define MAX 550
using namespace std;
using ii = pair<int, int>;
vector<ii> adj[MAX];
set<int> visited;

// para o padrão, nas inserções tanto nas priority queue como no vector
// coloquei (peso, no)
int prim(int N){
    int pesoTotal = 0;
    
    visited.insert(1);
    priority_queue<ii, vector<ii>, greater<ii>> fila;
    for(auto aresta : adj[1]){
        fila.push(ii(aresta.first, aresta.second)); 
    }
    while((int)visited.size() < N){
        int tamanho = visited.size();
        ii topo = fila.top();
        fila.pop();
        visited.insert(topo.second);
        if(visited.size() != tamanho){
            visited.insert(topo.second);
            for(ii aresta : adj[topo.second]){
                if(visited.count(aresta.second) == 0)
                    fila.push(ii(aresta.first, aresta.second));
            }
            pesoTotal+=topo.first;
        }
    }

    return pesoTotal;
}

int main(){
    int N, M, U, V, C;
    scanf("%d %d", &N, &M);
    for(int i=0; i<M; i++){
        scanf("%d %d %d", &U, &V, &C);
        adj[U].push_back(ii(C, V));
        adj[V].push_back(ii(C, U));
    }
    printf("%d\n", prim(N));
    return 0;
}