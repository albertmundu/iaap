#include <iostream>
#include <map>
#include <utility>
using namespace std;

class DisjointSet {
private:
    class Node {
    public:
        int vertex;
        int rank;
        class Node*parent;
    };
    map<int, Node*>* mp;
public:
    DisjointSet(){
        this->mp=new map<int,Node*>;
    }
    void makeset(int vertex){
        Node* new_node=new Node;
        new_node->vertex=vertex;
        new_node->rank=0;
        new_node->parent=new_node;
        auto p=make_pair(vertex,new_node);
        mp->insert(p);
    }
    Node* get(int vertex){
        return mp->find(vertex)->second;
    }

    Node* findset(Node*node){
        Node*p=node->parent;
        if(p==node)
            return p;
        node->parent=findset(node->parent);
        return node->parent;
    }
    int findset(int vertex){
        return findset(get(vertex))->vertex;
    }
    void unionset(int vertex1,int vertex2){
        Node*n1=get(vertex1);
        Node*n2=get(vertex2);
        Node*p1=findset(n1);
        Node*p2=findset(n2);
        if(p1==p2)
            return;
        if(p1->rank>=p2->rank){
            p1->rank=(p1->rank==p2->rank)?p1->rank+1:p1->rank;
            p2->parent=p1;
        }
        else
            p1->parent=p2;
    }
    ~DisjointSet(){
        mp->clear();ed
    }
};
int main() {
    DisjointSet *ds=new DisjointSet;
    for(int i=1;i<=10;i++) ds->makeset(i);
    ds->unionset(2,4);
    ds->unionset(1,3);
    ds->unionset(4,9);
    ds->unionset(8,6);
    ds->unionset(7,6);
    ds->unionset(7,5);

    for(int i=1;i<=10;i++){
        cout<<i<<" -> "<<ds->findset(i)<<endl;
    }
    delete ds;
    return 0;
}
