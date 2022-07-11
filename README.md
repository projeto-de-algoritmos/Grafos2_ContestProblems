# Constest Problems

**Número da Lista**: X<br>
**Conteúdo da Disciplina**: Grafos 2<br>

## Alunos
|Matrícula | Aluno |
| -- | -- |
| 18/0015834  |  Eliseu Kadesh Rosa Assunção Júnior |
| 18/0037242  |  Rodrigo Tiago Costa Lima |

## Sobre 
O projeto consiste em resolver problemas de maratonas/competições de programação. Para isso pesquisamos na plataforma [beecrowd](https://www.beecrowd.com.br/). Escolhemos tal plataforma, pois é mais simples encontrar problemas ligados a grafos nela.

## Screenshots


## Instalação 
**Linguagem**: C++<br>

## Uso 
Existem dois arquivos para cada questão, um .cpp para a compilação e outro .txt em que há algum caso de teste designado para a questão.

### [As Aventuras do Calango Atômico](https://www.beecrowd.com.br/judge/pt/problems/view/3119)
Dificuldade: 5

Resolução: Esse problema tem sua dificuldade no fato de termos que somar o tempo que o Calango Atômico leva até chegar na Calanguete percorrendo algumas fases, visto que teremos um grafo por fase.
Utilizamos o algoritmo de Dijkstra para descobrir o menor tempo do nó 1 até o último nó em todos os grafos e então somamos os tempos e mostramos a solução. 

### [Desvio de Rota](https://www.beecrowd.com.br/judge/pt/problems/view/1123)
Dificuldade: 4.

Problema da Maratona de Programação da SBC 2010.

Como resolver: 
* Esse problema é um pouco mais dificil, porque recebemos 7 tipos de  entradas:
    * N = a quantidade de nós do grafo não direcionado
    * M = a quantidade de arestas
    * C = número de nós na rota (o destino torna-se C-1)
    * K = nó de inicio
    * U = cidade U (nó)
    * V = cidade V (nó)
    * P = pedágio pago de cidade U para cidade V e vice-versa (peso da aresta)
* A questão principal está na hora de montarmos o grafo:
    * caso o nó U e o nó V sejam maiores ou iguais a C-1, pode-se fazer a ligação de U para V e de V para U
    * caso algum deles seja menor do que C-1, deve-se fazer a ligação somente do maior para o menor
    * caso ambos sejam menores do que C-1, deve-se fazer a ligação do menor para o maior, mas somente se o maior for o próximo nó.
* A partir disso, pode-se usar o algoritmo de Dijkstra.

## Outros 
Quaisquer outras informações sobre seu projeto podem ser descritas abaixo.
