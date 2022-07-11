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

### Questões accepted

![As Aventuras do Calango Atômico](Screenshots/AsAventurasDoCalango/ac.png)

![Desvio de Rota](Screenshots/DesvioDeRotaScreenshots/ac.png)

![Reduzindo Detalhes em um Mapa](Screenshots/ReduzindoDetalhesScreenshots/ac.png)

![Rede Ótica](Screenshots/RedeOtica/ac.png)

## Instalação 
**Linguagem**: C++<br>

## Pré-requisitos:

- g++ >= 9.4.0;
- make >= 4.2.1;

## Uso 

Existem dois arquivos para cada questão, um .cpp para a compilação e outro .txt em que há algum caso de teste designado para a questão.

Para rodar qualquer uma das questões, primeiro entre na pasta da questão.

```
  cd ./nomeDaQuestão
```

Depois usando make compile o codigo da questão

```
  make build
```

Agora execute a questão com o binário gerado com o caso de teste exemplo.

```
  make run
```

ou simplesmente compile e rode com um so comando

```
  make
```

### As Aventuras do Calango Atômico - [link](https://www.beecrowd.com.br/judge/pt/problems/view/3119)

![As Aventuras do Calango Atômico](Screenshots/AsAventurasDoCalango/questão.png)

Dificuldade: 5

Resolução: Esse problema tem sua dificuldade no fato de termos que somar o tempo que o Calango Atômico leva até chegar na Calanguete percorrendo algumas fases, visto que teremos um grafo por fase.
Utilizamos o algoritmo de Dijkstra para descobrir o menor tempo do nó 1 até o último nó em todos os grafos e então somamos os tempos e mostramos a solução. 

### Desvio de Rota - [link](https://www.beecrowd.com.br/judge/pt/problems/view/1123)

![Desvio de Rota](Screenshots/DesvioDeRotaScreenshots/questão.png)

Dificuldade: 4.

Problema da Maratona de Programação da SBC 2010.

Resolução: 
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

### Reduzindo Detalhes em um Mapa - [link](https://www.beecrowd.com.br/judge/pt/problems/view/2404)

![Reduzindo Detalhes em um Mapa](Screenshots/ReduzindoDetalhesScreenshots/questão.png)

Dificuldade: 3.

Problema da OBI - Olimpíada Brasileira de Informática 2011 Fase 2 Nível 2.

Resolução: Implemente o algoritmo de Prim.

### Rede Ótica - [link](https://www.beecrowd.com.br/judge/pt/problems/view/2190)

![Rede Ótica](Screenshots/RedeOtica/questão.png)

Dificuldade: 7.

Problema da Olimpíada Brasileira de Informática 2000.

Resolução: Esse problema consiste em determinar quais ramos devem ser construídos, de forma a possibilitar a comunicação entre todas as tabas, causando o menor impacto ambiental possível.

Para resolver esse problema usamos o algorítmo de Kruskal, para gerar a arvore geradora mínima, e com isso poder determinar as arestas do grafo que representa a comunicação entre todas as tabas, cujo o impacto ambiental é mínimo.

## Outros 
Quaisquer outras informações sobre seu projeto podem ser descritas abaixo.
