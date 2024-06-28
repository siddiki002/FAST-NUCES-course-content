#include <iostream>
#include <vector>

using namespace std;

class edge
{
    public:
        int in_node,ter_node,weight;
        edge(int in, int ter, int w){
            in_node = in;
            ter_node = ter;
            weight = w;
        }
};
class Node
{
    public:
        int val;
        vector<edge> edges;
        Node* next;
            Node(){next = NULL;}
            Node(int val){
                this->val = val;
                next = NULL;
            }
            void traverse(){
                for (int i = 0; i < edges.size(); i++)
                {
                    cout<<"----->"<<edges[i].ter_node<<" weight is: "<<edges[i].weight<<" ";
                }
                
            }
            void add_edge(int ter, int w){
                edge temp(val,ter,w);
                edges.push_back(temp);
            }
};

class Linkedlist
{
    public:
    Node* head;
    
        Linkedlist(){head=NULL;}
        void insert_vertex(int val){
            Node* new_node = new Node(val);
            Node* temp = head;
            if (head==NULL){
                head = new_node;
            }
        }
        void add_edge(int ter, int w){
            head->add_edge(ter,w);
        }
        void traverse(){
            cout<<head->val;
            head->traverse();
        }
};
class Vertex
{
    public:
        int label;
        vector<edge> edges;
        Vertex(){}
        Vertex(int l){
            label = l;
        }
        void add_edge(int ter, int w){
            edge temp(label,ter,w);
            edges.push_back(temp);
        }
        void print(){
            for (int i = 0; i < edges.size(); i++)
            {
                // cout<<"-- weight = "<<edges[i].weight<<"-->"<<edges[i].ter_node<<"   ";
                cout<<"--->"<<edges[i].ter_node<<" Weight is: "<<edges[i].weight<<"   ";
            }
            
        }
};

class graph
{
    vector<Linkedlist> table;
    public:
        void add_vertex(int val){
            Linkedlist temp;
            temp.insert_vertex(val);
            table.push_back(temp);
        }
        void add_edge(int initial, int terminal, int weight){
            for (int i = 0; i < table.size(); i++)
            {
                if (table[i].head->val==initial){
                    table[i].head->add_edge(terminal,weight);
                }
            }
            
        }
        void traverse_graph(){
            for (int i = 0; i < table.size(); i++)
            {
                table[i].traverse();
                cout<<endl;
            }
            
        }

    // vector<Vertex> vertices;
    // public:
    //     void add_vertex(int v){
    //         vertices.push_back(v);
    //     }
    //     void add_edge(int initial, int terminal, int weight){
    //         for (int i = 0; i < vertices.size(); i++)
    //         {
    //             if (vertices[i].label==initial){
    //                 vertices[i].add_edge(terminal,weight);
    //             }
    //         }
            
    //     }
    //     void traverse_graph(){
    //         for (int i = 0; i < vertices.size(); i++)
    //         {
    //             cout<<vertices[i].label;
    //             vertices[i].print();
    //             cout<<endl;
    //         }
            
    //     }
};

int main()
{
    graph g1;
    g1.add_vertex(0);
    g1.add_vertex(1);
    g1.add_vertex(2);
    g1.add_vertex(3);
    g1.add_edge(0,1,4);
    g1.add_edge(0,2,5);
    g1.add_edge(1,3,11);
    g1.add_edge(2,3,14);
    g1.add_edge(2,1,15);
    //g1.add_edge(1,3,11);
    g1.add_edge(3,2,10);
    g1.traverse_graph();
}