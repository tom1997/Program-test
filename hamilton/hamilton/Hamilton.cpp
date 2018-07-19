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
        int vcount, ecount;        //��¼����������������
        bool digraph;            //����Ƿ�����ͼ
        vector <vector <bool> > adj;        //�ڽӾ�������
    public:
        Graph(int V, bool di = false) : adj(V), vcount(V), digraph(di)
        {
            for(int i=0; i<V; i++)
                adj[i].assign(V, false);    // V * V �ٽӾ���Ĵ�С 
        }
        //~Graph();
        int V() const {return vcount;}
 
        int E() const {return ecount;}
 
        bool directed() const { return digraph; }
 
        void insert(Edge e)
        {
            int v=e.v, w=e.w;
            if(adj[v][w] == false) ecount++;
            adj[v][w] = true;                        // v-w �����
            if(!digraph) adj[w][v] = true;            //����ͼ�� w-v Ҳ�����
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
 
class Graph::adjIterator        //�ٽӾ����ʾ�ĵ�����
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
                if(G.adj[v][i] == true) return i;    //adj[v][0..v-1] ��¼�� v �� 0..v �����Ƿ�����
            return -1;    //û���ҵ�
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
        bool searchR(int v, int w, int d) //d��ʾ�������
        {
            if(v == w) return (d==0);
            visited[v] = true;
            Graph::adjIterator ite(G, v);
            for(int t=ite.begin(); !ite.end(); t=ite.next())    //v������ȥ���Ķ���
                if(!visited[t])
                    if(searchR(t, w, d-1))
                    {
                        cout << v << " -> " << t << endl;    //�������·��
                        return true;
                    }
            visited[v] = false;        //ʹ��������false
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
    cout << sp.exist();        //������ 0 �� 1
	system("pause");
 
    return 0;
}