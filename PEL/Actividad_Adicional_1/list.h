#include <iostream>
// template <class T>
class Node
{
protected:
    int data;
    Node *joint;

public:
    Node(int t)
    {
        data = t;
        joint = 0;
    };
    Node(int p, Node *n)
    {
        data = p;
        joint = n;
    };
    int NodeData() const { return this->data; };
    Node *NodeJoint() const { return this->joint; };
    void SetJoint(Node *sgte) { joint = sgte; };
};

class List
{
    protected:
     Node* first; 
    public: 
    List(){first = 0;};
    void CreateList(){
        int x;
        first = 0; 
        do{
            std::cin >> x; 
            if(x!=-1){
                first = new Node(x,first);
            }
        }while(x!=-1);
    }
    void InsertInHead(int entry)
    {
        Node* node; 
        node= new Node(entry);
        node ->SetJoint(first);
        first = node;
    };
    Node* Last(){
      Node* node = first;
      if(node == 0) throw "error, empty list";
      while(node-> NodeJoint() != 0) node = node->NodeJoint();
      return node;  
    };
    void InsertInTail(int entry){
        Node* node = this->Last();
        node ->SetJoint(new Node(entry));
    };
    void InsertBetween(Node* last, int entry){
        Node* node;
        node = new Node(entry);
        node ->SetJoint(last->NodeJoint());
        last->SetJoint(node);
    }
    

};