#include <iostream>
#include <vector>
 
using namespace std;
 
struct Edge
{
    int v, w;
    Edge(int v=-1, int w=-1) : v(v), w(w) {}
};
 
class Graph
{
    private:
        int vcount, ecount;        //记录顶点总数，边总数
        bool digraph;            //标记是否有向图
        vector <vector <bool> > adj;        //邻接矩阵数组
    public:
        Graph(int V, bool di = false) : adj(V), vcount(V), digraph(di)
        {
            for(int i=0; i<V; i++)
                adj[i].assign(V, false);    // V * V 临接矩阵的大小 
        }
        //~Graph();
        int V() const {return vcount;}
 
        int E() const {return ecount;}
 
        bool directed() const { return digraph; }
 
        void insert(Edge e)
        {
            int v=e.v, w=e.w;
            if(adj[v][w] == false) ecount++;
            adj[v][w] = true;                        // v-w 做标记
            if(!digraph) adj[w][v] = true;            //无向图中 w-v 也做标记
        }
 
        int remove(Edge e)
        {
            int v=e.v, w=e.w;
            if(adj[v][w]==true) ecount--;
            adj[v][w] = false;
            if(!digraph) adj[w][v] = false;
        }
 
        bool edge(int v, int w) const { return adj[v][w]; }
 
        class adjIterator;
        friend class adjIterator;
};
 
class Graph::adjIterator        //临接矩阵表示的迭代器
{
    private:
        const Graph &G;
        int i, v;
    public:
        adjIterator(const Graph& G, int v) : G(G), v(v), i(-1)
        {}
 
        int begin()
        {
            i=-1;
            return next();
        }
 
        int next()
        {
            for(i++; i<G.V(); i++)
                if(G.adj[v][i] == true) return i;    //adj[v][0..v-1] 记录着 v 到 0..v 各点是否相连
            return -1;    //没有找到
        }
 
        int end()
        {
            return i>=G.V();
        }
};
 
class hpath
{
    private:
        const Graph &G;
        vector <bool> visited;
        bool found;
        bool searchR(int v, int w, int d) //d表示顶点个数
        {
            if(v == w) return (d==0);
            visited[v] = true;
            Graph::adjIterator ite(G, v);
            for(int t=ite.begin(); !ite.end(); t=ite.next())    //v所有能去到的顶点
                if(!visited[t])
                    if(searchR(t, w, d-1))
                    {
                        cout << v << " -> " << t << endl;    //输出搜索路径
                        return true;
                    }
            visited[v] = false;        //使用完重置false
            return false;
        }
    public:
        hpath(const Graph& G, int v, int w) : G(G), visited(G.V(), false)
        {
            found = searchR(v, w, G.V()-1);
        }
        bool exist()
        {
            return found;
        }
};
 
 
 
int main()
{
    Graph g(7, false);
 
    g.insert(Edge(0, 1));
    g.insert(Edge(0, 2));
    g.insert(Edge(0, 5));
    g.insert(Edge(0, 6));
 
    g.insert(Edge(1, 2));
    g.insert(Edge(2, 3));
    g.insert(Edge(2, 4));
    g.insert(Edge(3, 4));
    g.insert(Edge(4, 5));
    g.insert(Edge(4, 6));
 
    hpath sp(g, 1, 6);
    cout << sp.exist();        //输出结果 0 或 1
	system("pause");
 
    return 0;
}