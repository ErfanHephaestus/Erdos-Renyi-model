# Erdos-Renyi-model
This model create base on G(N , P) model in ALBERT-LÁSZLÓ BARABÁSI NETWORK SCIENCE: Each pair of N labeled nodes is connected with probability P
A random network consists of N nodes where each node pair is connected with probability p.
To construct a random network we follow these steps:
1) Start with N isolated nodes.
2) Select a node pair and generate a random number between 0 and 1.
If the number exceeds p, connect the selected node pair with a link,
otherwise leave them disconnected.
3) Repeat step (2) for each of the N(N-1)/2 node pairs.
The network obtained after this procedure is called a random graph or
a random network. Two mathematicians, Pál Erdős and Alfréd Rényi, have
played an important role in understanding the properties of these networks. In their honor a random network is called the Erdős-Rényi network
