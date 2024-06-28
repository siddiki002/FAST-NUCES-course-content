#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class edge
{
    public:
        int initial_node,terminal_node;
        edge(int in, int tr){
            initial_node = in;
            terminal_node = tr;
        }
};
class vertex
{
    public:
        int val;
        vector<edge> edges;
        vertex(int v){
            val = v;
        }
        void add_edge(int terminal){
            edge temp(val,terminal);
            edges.push_back(temp);
        }

};

class graph
{
    vector <vertex> vertices;
    public:
        void add_vertex(int v){
            vertices.push_back(v);
        }
        void add_edge(int in, int ter){
            for (int i = 0; i < vertices.size(); i++)
            {
                if (vertices[i].val==in){
                    vertices[i].add_edge(ter);
                }
                // for (int j = 0; j < vertices[i].edges.size(); j++)
                // {
                //     if (vertices[i].val==in){
                //         vertices[i].add_edge(ter);
                //     }
                //     // if (vertices[i].edges[j].terminal_node==ter){
                //     //     vertices[i].add_edge(in);
                //     // }
                // }
                
            }
            
        }
        bool is_cycle(int v, bool* visited, int parent){
            visited[v] = true;
            for (int i = 0; i < vertices[v].edges.size(); i++)
            {
                if (!visited[vertices[v].edges[i].terminal_node]){
                    if(is_cycle(vertices[v].edges[i].terminal_node,visited,v)){
                        return true;
                    }
                }
                else if (vertices[v].edges[i].terminal_node!=parent){
                    return true;
                }
            }
            return false;
            
        }
        void dfs_iter(int v, bool* discovered){
            stack <int> s;
            //discovered[v]=true;
            s.push(v);
            while (!s.empty()){
                v = s.top();
                s.pop();
                discovered[v] = true;
                cout<<v<<" ";
                for (int i=0;i<vertices[v].edges.size();i++){
                    if (!discovered[vertices[v].edges[i].terminal_node]){
                        discovered[vertices[v].edges[i].terminal_node] = true;
                        s.push(vertices[v].edges[i].terminal_node);
                    }
                }

            }
        }
        void call_iter_dfs(){
            bool* discovered = new bool[vertices.size()];
            for (int i = 0; i < vertices.size(); i++)
            {
                discovered[i] = false;
            }
            for (int i = 0; i < vertices.size(); i++)
            {
                if (!discovered[i]){
                    dfs_iter(i,discovered);
                }
            }
            
            
        }
        bool call_is_cycle(){
            bool* visited = new bool[vertices.size()];
            for (int i = 0; i < vertices.size(); i++)
            {
                visited[i] = false;
            }
            if (is_cycle(0,visited,-1)){
                return true;
            }
            return false;
            
        }
        void dfs(int v, bool* visited){
            visited[v] = true;
            cout<<v<<" ";
            for (int i = 0; i < vertices[v].edges.size(); i++)
            {
                // cout<<vertices[v].edges[i].terminal_node<<endl;
                // system("PAUSE");
                if (!visited[vertices[v].edges[i].terminal_node]){
                    dfs(vertices[v].edges[i].terminal_node,visited);
                }
            }
            
        }
        void call_recursive_dfs(){
            bool* visited = new bool[vertices.size()];
            for (int i = 0; i < vertices.size(); i++)
            {
                visited[i] = false;
            }
            dfs(0,visited);
            
            
        }
};

int main()
{
    graph obj;
    obj.add_vertex(0);
    obj.add_vertex(1);
    obj.add_vertex(2);
    obj.add_vertex(3);
    obj.add_vertex(4);
    obj.add_edge(0,1);
    obj.add_edge(0,4);
    obj.add_edge(1,3);
    obj.add_edge(3,2);
    //obj.add_edge(2,4);
    //obj.add_edge(0,0);
    //obj.call_recursive_dfs();
    cout<<endl;
    obj.call_iter_dfs();
    
}