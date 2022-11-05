using namespace std;

struct dato{
  int key;
  string linea;
  string ip;
  string ip2;
  string ip3;
  string ip4;
  string ip5;
  long ipp;
}; 

class Node{
private:
  dato data;
  Node *prev; 
  Node *next;
public: 
  Node(dato data);
  Node(dato data, Node* prev, Node* next);
  dato getData();
  void setData(dato data);
  Node* getPrev();
  void setPrev(Node* data);
  Node* getNext();
  void setNext(Node* data);
};

Node::Node(dato data){
  this->data = data;
  this->next = nullptr;
  this->prev = nullptr;
}
Node::Node(dato data, Node* prev, Node* next){
  this->data = data;
  this->prev = prev;
  this->next = next;
}
dato Node::getData(){
  return data;
}

Node* Node::getPrev(){
  return prev;
}
Node* Node::getNext(){
  return next;
}
void Node::setData(dato data){
  this->data = data;
}
void Node::setPrev(Node* prev){
  this->prev = prev;
}
void Node::setNext(Node* next){
  this->next = next;
}
//La complejidad de los nodos anteriores es de : O(1)