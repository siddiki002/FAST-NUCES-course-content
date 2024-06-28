#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class edge
{
    public:
        char initial_node,terminate_node;
        edge(char in, char ter){
            initial_node = in;
            terminate_node = ter;
        }
};
class Vertex
{
    public:
    char label;
    vector<edge> edges;
    int degree;
        
            Vertex(char lab){
                label = lab;
                degree = 0;
            }
            void add_edge(char ter_node){
                edge temp(label,ter_node);
                edges.push_back(temp);
            }
            void traverse_vertex(){
                cout<<label<<"->";
                for (int i = 0; i < edges.size(); i++)
                {
                    cout<<edges[i].terminate_node;
                    if (i!=edges.size()-1){
                        cout<<"->";
                    }
                }
                
            }
};

class graph
{
    vector<Vertex> vertices;
    public:
        void add_vertex(char ch){
            vertices.push_back(ch);
        }
        void add_edge(char in_node, char ter_node){
            for (int i = 0; i < vertices.size(); i++)
            {
                if (vertices[i].label==in_node){
                    vertices[i].add_edge(ter_node);
                }
                if (vertices[i].label==ter_node){   //because undirected
                    vertices[i].add_edge(in_node);
                }
            }
            
        }
        void show_connections(){
            for (int i = 0; i < vertices.size(); i++)
            {
                vertices[i].traverse_vertex();
                cout<<endl;
            }
            
        }
        void print_adjacency_matrix()
        {
            int **adj_mat = new int*[vertices.size()];
            for (int i = 0; i < vertices.size(); i++)
            {
                adj_mat[i] = new int[vertices.size()];
                for (int j = 0; j < vertices.size(); j++)
                {
                    adj_mat[i][j] = 0;
                }
                
            }
            for (int i = 0; i < vertices.size(); i++)
            {
                for (int j = 0; j < vertices[i].edges.size(); j++)
                {
                    adj_mat[(vertices[i].edges[j].initial_node)-65][(vertices[i].edges[j].terminate_node)-65] = 1;
                }
                
            }
            //return (adj_mat);
            for (int i = 0; i < vertices.size(); i++)
            {
                for (int j = 0; j < vertices.size(); j++)
                {
                    cout<<adj_mat[i][j]<<" ";
                }
                cout<<endl;
            }
            
            
        }
        void recursive_bfs(queue<char> &q,bool* visited,int i){
            if (q.empty()){
                return;
            }
            char src = q.front();
            cout<<src<<" ";
            q.pop();
            for (int j = 0; j < vertices[i].edges.size(); j++)
            {
                int u = vertices[i].edges[j].terminate_node;
                u-=65;
                if (!visited[u]){
                    visited[u] = true;
                    q.push(vertices[i].edges[j].terminate_node);
                }
            }
            recursive_bfs(q,visited,i+1);
        }
        void call_recursive_bfs(){
            bool *visited = new bool[vertices.size()];
            for (int i = 0; i < vertices.size(); i++)
            {
                visited[i] = false;
            }
            visited[0] = true;      //0 means 'A'
            queue<char> q;
            q.push(vertices[0].label);
            recursive_bfs(q,visited,0);

        }
        
        void dfs(int u,bool* visited)
        {
            visited[u] = true;
            char src = u;
            src+=65;
            cout<<src<<" ";
            vector<edge>::iterator i;
            for (i = vertices[u].edges.begin();i!=vertices[u].edges.end();++i){
                edge temp = (*i);
                int v = temp.initial_node;
                v=-65;
                if (!visited[v]){
                    dfs(v,visited);
                }
            }
        }
        void call_recursive_dfs(char ch)
        {
            int u = ch;
            u-=65;
            bool* visited = new bool[vertices.size()];
            for (int i = 0; i < vertices.size(); i++)
            {
                visited[i] = false;
            }
            dfs(u,visited);
        }
        void bfs()
        {
            bool *visited = new bool[vertices.size()];
            for (int i = 0; i < vertices.size(); i++)
            {
                visited[i] = false;
            }
            visited[0] = true;      //0 means 'A'
            queue<char> q;
            q.push(vertices[0].label);
            for (int i = 0; i < vertices.size(); i++)
            {
                while(!q.empty()){
                    char src = q.front();
                    cout<<src<<" ";
                    q.pop();
                    for (int j = 0; j < vertices[i].edges.size(); j++)
                    {
                        int u = vertices[i].edges[j].terminate_node;
                        u-=65;
                        if (!visited[u]){
                            visited[u] = true;
                            q.push(vertices[i].edges[j].terminate_node);
                        }
                    }
                    
                }
                

            }
            
            
        }
};

int main()
{
    graph obj;
    obj.add_vertex('A');
    obj.add_vertex('B');
    obj.add_vertex('C');
    obj.add_vertex('D');
    obj.add_edge('A','B');
    obj.add_edge('A','C');
    obj.add_edge('D','A');
    obj.add_edge('B','C');
    obj.add_edge('D','C');
    obj.add_edge('A','A');
    //obj.show_connections();
    //obj.print_adjacency_matrix();
    // obj.bfs();
    obj.call_recursive_dfs('A');
}