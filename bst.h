template<typename T>
class Node{
    private:
        T data;
        Node<T>* left;
        Node<T>* right;
        template<typename U>
        friend class BST;
    public:
        Node(T data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};


template<typename T>
class BST{
  private:
    Node<T> * root;
    
    // Recursive insertion method
    void insert(Node<T> * & node, T data){
      if(node== NULL){                          //O(1)
        node = new Node(data);                  //O(1)
      }else{
        if(data < node->data){
          insert(node->left, data);
        }else if(data > node->data){
          insert(node->right, data);
        }
        
      }
    }
    // recursive lenght() 
    int length(Node<T> * & node){
      if(node == NULL) return 0;                          //O(1)
      else return(length(node->left) + 1 + length(node->right));
    }
    // recursive max()
    int max(Node<T> * & node){
      if(node == NULL) return 0;                          //O(1)
      int node_data = node->data;
      int left_max = max(node->left);
      int right_max = max(node->right);
      if(left_max>=node_data) return left_max;            //O(1)
      if(right_max>=node_data) return right_max;          //O(1)
      return node_data;                                   //O(1)
    }
    // recursive min()
    int min(Node<T> * & node){
      if(node == NULL) return 10000000;                   //O(1)
      int node_data = node->data;
      int left_min = min(node->left);                     //O(n)
      int right_min = min(node->right);                   //O(n)
      if(left_min<=node_data) return left_min;            //O(1)
      if(right_min<=node_data) return right_min;          //O(1)
      return node_data;                                   //O(1)
    }   
    // recursive preOrden()
    void preOrden(Node<T> * & node){
      if(node != NULL){                                   //O(1)
        cout << node-> data << ":";                       //O(1)
        preOrden(node->left);                             //O(n)
        preOrden(node->right);                            //O(n)
      }
    }
    // recurisve postOrden
    void postOrden(Node<T> * & node){
      if(node != NULL){
        postOrden(node->left);
        postOrden(node->right);
        cout << node-> data << ":";
      }
    }
    // recursive inOrden()
    void inOrden(Node<T> * & node){
      if(node != NULL){
        inOrden(node->left);
        cout << node-> data << ":";
        inOrden(node->right);
        
      }
    } 
    // recursive search
    bool search(Node<T> * & node, T data){
      if(node == NULL) return false;                          //O(1)
      if(data == node->data) return true;
      if(data < node->data) return search(node->left, data);  //O(1)
      if(data > node->data) return search(node->right, data); //O(1)
    }
    // recursive height
    int height(Node<T> * & node){
      if(node == NULL) return 0;
      else{
        int right_height = height(node->right);
        int left_height  = height(node->left);
        if(left_height>right_height) return left_height + 1;
        else return right_height+1;
      }
    }
    // recurisve levels
    void levels(Node<T> * & node, int level){
      if(node == NULL) return;
      if(level == 1) cout << node->data << ":";
      else if(level>1){
        levels(node->left, level-1);
        levels(node->right, level-1);
      }
    }
    // recursive ancestors
    void ancestors(Node<T> * & node, int value){
      if(node == NULL) return;
      if(!search(node, value)) return;
      cout << node->data << ":";
      if(search(node->left, value)) ancestors(node->left, value);
      else if(search(node->right, value)) ancestors(node->right, value);
    }
    // recurise level
    int level(Node<T> * & node, int value){
      if(node == NULL) return 0;
      if(!search(node, value)) return 0;
      if(search(node->left, value)) return 1+ level(node->left, value);
      else if(search(node->right, value)) return 1+ level(node->right, value);
      else return 1;
    }
    // recursive flatten
    LinkedList<T> flatten(Node<T> * & node, LinkedList<T> & lista_ligada){
      if(node != NULL){                                   //O(1)
        lista_ligada.addLast(node->data);
        flatten(node->left, lista_ligada);                             //O(n)
        flatten(node->right, lista_ligada);                            //O(n)
      }
      return lista_ligada;
    }

  public:
    BST(){
      root = NULL;                              //O(1)
    }
    
    bool isEmpty(){
      return root == NULL;                      //O(1)
    }
    
    void insert(T data){
      if(isEmpty()){                            //O(1)
        root = new Node(data);                  //O(1)
      }else{
        insert(root, data);
      }
    }

    /*
    Method to get the number of elements in binary tree.
    Uses a recursive method.
    */
    int length(){
      if(isEmpty()) return 0;                     //O(1)
      else return length(root);                   //O(1)
    }

    /*
    Method to get the max value element in the binary tree.
    Uses a recursive method.
    */
    int max(){
      if(isEmpty()) return 0;                     //O(1)
      else return max(root);                      //O(1)
    }
    /*
    Method to get the min value element in the binary tree.
    Uses a recursive method.
    */
    int min(){
      if(isEmpty()) return 0;                      //O(1)
      else return min(root);                      //O(1)
    }
    /*
    Method to check existance of value in vinary tree. Has 
    a recursive method.
    */
    bool search(T data){
      if(isEmpty()) return 0;                   //O(1)
      else return search(root, data);          //O(1)
    }


    /*
    Method to print binary tree. Uses a private method(function
    overloaded).
    */
    void preOrden(){
      preOrden(root);
      cout << endl;                           //O(1)
    }

    void postOrden(){
      postOrden(root);
      cout << endl;
    }
    void inOrden(){
      inOrden(root);
      cout << endl;
    }

    /*
    Method to get the maximun hight of binary tree
    */
    int height(){
      return height(root); 
    }

    /*
    Method to print binary tree, level by level, from left to 
    right. Applied an stack for managing this method.
    */
    void levels(){
      int h = height();
      for(int i = 1; i<h; i++)levels(root, i);
      cout << endl;
    }
    /*
    Method to print the route taken for location of some value
    */
    void ancestors(int value){
      ancestors(root, value);
      cout << endl;
    }
    void path(int value){
      ancestors(root, value);
      cout << endl;
    }
    /*
    Method to get the level in which a value is found
    */
    int level(int value){
      return level(root, value);
    }
    /*
    Mehtod to transform binary tree into linked list, 
    following pre-order sequence
    */
    LinkedList<T> flatten(){
      LinkedList<T>  lista_ligada = LinkedList<T>();
      return flatten(root, lista_ligada); // a linked list 
    }
};