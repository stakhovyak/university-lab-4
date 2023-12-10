// Node class to represent 
// a node of the linked list.
template <typename T>
class Node
{ 
 public: 
  T data; 
  Node* next; 
  
  // Default constructor 
  explicit Node();

  // Default destructor
  virtual ~Node() = default;
  
  // Parameterised Constructor 
  explicit Node(int data);
}; 
