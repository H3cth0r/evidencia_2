 template<typename T>

/*
Esta es la clase “NodeLL”, es la que nos permite crear diferentes 
NodeLLs de manera sencilla. Como se puede observar según sus 
atributos, esta clase guarda la dirección del siguiente elemento o 
NodeLL de la lista y el dato que se desea guardar.
*/
class NodeLL{
    private:
        T data;
        NodeLL<T>* next;
        NodeLL<T>* prev;
        template<typename U>
        friend class LinkedList;
    public:
        NodeLL(T data){
            this->data = data;                                                              //O(1)
            next = NULL;                                                                    //O(1)
            prev = NULL;                                                                   //O(1)
        }
};

/*
Esta es la clase “LinkedList”. Esta clase nos permite generar la 
lista, al guardar como parámetro la ubicación del “head” de la 
lista. De igual manera, la clase mantiene varios métodos que nos 
permiten controlar varios aspectos de la lista. Con todos los 
métodos que fueron agregados, se pueden realizar acciones como 
agregar elementos en distintas posiciones de la lista, imprimir la 
lista, obtener el tamaño de la lista, buscar algún dato o eliminar 
algún NodeLL. En resumen, esta clase le da toda la funcionalidad a 
la lista ligada.
*/
template<typename T>
class LinkedList{
  private:                                                           NodeLL<T> *head;              
    NodeLL<T> *last;                                                                          
    int lengthRecursive(NodeLL<T> * h ){
      if (h == NULL) // caso base                                                          //O(1)
        return 0;                                                                          //O(1)
      else
                  //caso recursivo
        return 1 + lengthRecursive(h->next);
    }

  public:

    int the_size = 0;

    LinkedList(){
      head = last = NULL;                                                                   //O(1)
    }

    /*Method to look for last value of list and set it last*/

    
    // Agregar
                                                                //O(1)
    /*
    Este método nos permite agregar elementos a la primera 
    posición de la lista, empujando hacia atrás a los elementos 
    anteriormente guardados y cambiando de head al elemento que 
    está siendo agregado.
    */
    void addFirst(T dato){
      NodeLL<T> * nuevo = new NodeLL(dato);
      if(head == NULL){// si es vacía la lista                                            O(1)
        head = last = nuevo;                                                            //O(1)
        head=nuevo;
      }else{ // al menos tiene uno
         nuevo->next = head;                                                            //O(1)
         head = nuevo;                                                                  //O(1)
      }
    }

    /*
    El método print nos permite imprimir de manera sencilla, todos O(1)
    los elementos dentro de la lista. La función recorre la lista 
    y va imprimiendo dato por dato.
    */
    //
    void print(){
      NodeLL<T> * auxiliar = head;                                                         //O(1)
      while(auxiliar != NULL){                                                           //O(n)
        cout << auxiliar->data << ":";                                                  //O(1)
        auxiliar = auxiliar->next;                                                      //O(1)
      }
      cout << endl;                                                                     //O(1)
    }
    
    
    /*Completa y agrega complejidad de cada función*/

    /*
    Este método nos permite agregar un NodeLL al final de la lista  O(1)
    que tenemos; se cambia el NULL del anterior último NodeLL, por 
    la dirección del nuevo NodeLL a agregar y el nuevo tomo NULL 
    como dirección.
    */
    void addLast(T dato){
      // creando nuevo NodeLL 
      NodeLL<T> * nuevo = new NodeLL(dato);                                                 //O(1)
      nuevo->next = NULL;                                                               //O(1)

      // Checar si la lista esta vacia
      if(head == NULL){                                                                 //O(1)
        head = last = nuevo;                                                            //O(1)
        nuevo->next = nuevo->prev = NULL;
      }else{  // if not is_empty
        last->next = nuevo;
        nuevo->prev = last;                                                             //O(1)
        nuevo->next = NULL;
        last = nuevo;                                                                   //O(1)
      }
    }

    /* El método reverse imprime la lista de atrás hacia adelante.*/
    void reverse(){
      NodeLL<T> * auxiliar = last;                                                       //O(1)
       while(auxiliar != NULL){                                                        //O(n)
        cout << auxiliar->data << ":";                                                 //O(1)
        auxiliar = auxiliar->prev;                                                     //O(1)
      }
      cout << endl;                                                                   //O(1)

    }

    /* Este método tiene la misma función que el método “size”, 
    pero este realiza la operación por recursión. No recibe ningún 
    parámetro*/
    int length (){
        return lengthRecursive(head);                               //O(1)   
    }


    /*
    El método size nos permite obtener el tamaño de nuestra lista,    O(n)
    recorriendo NodeLL por NodeLL, sumando al contador, hasta llegar 
    al NodeLL con NULL como dirección de siguiente NodeLL.
    */
    int size(int count = 1){
      NodeLL<T> * auxiliar = head;                                                            //O(1)
      while(auxiliar->next != NULL){
        count ++;                                                                           //O(n)
        auxiliar = auxiliar->next;                                                         //O(1)
      }
      return count;                                                                        //O(1)
    }

    /*
    Este método permite agregar un NodeLL a cualquier ubicación de        O(1)
    nuestra liga, solamente recibe como parámetro el índice de la 
    ubicación donde se quiere guardar.
    */
    void addAt(T dato, int index){

      int size = this->size();                                                            //O(1)

      if(index<0 || index > size + 1) cout << "Invalid input, try again" << endl;         //O(1)
      else{
        // if index is the first position
        if(index == 0){                                                                    //O(1)
          addFirst(dato);
          return;
        }
        NodeLL<T> * nuevo = new NodeLL(dato);                                                 //O(1)
        nuevo->data = dato;                                                               //O(1)
        nuevo->next = NULL;                                                              //O(1)

        NodeLL<T> * auxiliar = head;                                                      //O(1)

        while(--index>0)auxiliar = auxiliar->next;                                      //O(n)

        nuevo->next = auxiliar->next;                                                   //O(1)
        auxiliar->next = nuevo;                                                         //O(1)

      }
    }


/* El método “is empty” es bastante útil para poder comprobar de 
manera rápida si la lista está vacía. Útil para poder utilizar en 
otros métodos*/                                                    
    //O(1)
    bool is_empty(){                                                                     //O(1)
      if(head==NULL) return true;                                                        //O(1)
      else return false;                                                                 //O(1)
    }


    /*El método contains es útil para encontrar valores en nuestra 
    lista, según el tipo de dato. Solo se ingresa el valor que se 
    quiere encontrar en la lista, como parámetro*/
    bool contains(T data){
      NodeLL<T> * auxiliar = head;                                                            //O(1)
      bool result = false;                                                                 //O(1)
      while(auxiliar->next != NULL){                                                       //O(n)
        if(auxiliar->data == data) result = true;                                          //O(1)
        auxiliar = auxiliar->next;                                                        //O(1)
      } 
      return result;                                                                      //O(1)
    }


    /*
    Este método nos permite obtener el valor de cierto NodeLL,   O(n)
    según su índice, el cual recibe como parámetro.
    */
    T get(int index){ 

      if(size()-1< index||index<0) throw index;   

      NodeLL<T> * auxiliar = head;                                                            //O(1)
      T dato;                                                                               //O(1)

      for(int i = 0; i < index; i++){                                                       //O(n)
        auxiliar = auxiliar->next;                                                          //O(1)
      }
      return auxiliar->data;                                                                //O(1)
    }

    /*El método “index of” nos permite obtener la 
    localización por índice de un valor que queramos 
    encontrar en la lista. Recibe el dato del que se quiere 
    obtener el índice, como parámetro*/
    int indexOf(T value){                                                                   //O(1)
      if(contains(value) != true) throw value; // excception not found value                //O(1)
      NodeLL<T> * auxiliar = head;                                                            //O(1)

      int index;                                                                            //O(1)
      for(int i = 0; i < size(); i ++){                                                     //O(n)
        if(auxiliar->data == value) index = i;                                              //O(1)
        auxiliar = auxiliar->next;                                                          //O(1)
      }
      return index;                                                                         //O(1)
    }

    /*Este método realiza la misma operación que  el método 
    anterior, la diferencia es que  este método empieza a 
    recorrer la lista desde su último índice en la lista.*/
    int lastIndexOf(T value){                                                 //O(n)
      if(contains(value) != true) throw value; // excception not found value                //O(1)
      NodeLL<T> * auxiliar = last;                                                            //O(1)

      int index;                                                              
      for(int i = 0; i< size(); i++){                                                       //O(n)
        if(auxiliar->data == value) index = i;                                              //O(1)
        auxiliar = auxiliar->prev;                                                          //O(1)
      }
      return (size()-index)-1;                                                              //O(1)
    }


    /*
    Esta función no permite eliminar el primer NodeLL de nuestra        //O(1)
    lista, cambiando al head, como el siguiente valor de la lista.
    */
    T remove_front(){
      if(head == NULL) throw -1;             //O(1) Check if empty
      else if(head==last){//O(1)
        T dato = head->data;//O(1)

        head = last = NULL;//O(1)
        return dato;//O(1)
      }
      else{
        T dato = head->data;
        head = head->next;
        head->prev = NULL;
        return dato;
      }
    }


    void remove_l(){
      if(head == NULL) return;             //O(1) Check if empty
      else if(head==last){//O(1)
        T dato = head->data;//O(1)

        head = last = NULL;//O(1)
        return;//O(1)
      }
      else{
        T dato = head->data;
        head = head->next;
        head->prev = NULL;
        return;
      }
    }

    /*
    Como bien lo dice el nombre del método, este nos permite         O(1) 
    eliminar el último valor de nuestra lista.
    */

    T remove_last(){
      if(head == NULL) return NULL;
      if(head->next == NULL){
        T dato = head->data;
        delete head;
        delete last;
        return dato;
      }
      NodeLL<T> * second_last = head;
      while(second_last->next->next != NULL) second_last = second_last->next;
      
      T dato = second_last->next->data;
      delete (second_last->next);
      second_last->next = NULL;
      last = second_last;
      return dato;
    }
  

    // Este método nos permite eliminar un nodo que queramos sacar 
    // de la lista ligada de manera sencilla, solo se tiene que 
    // ingresar el index del nodo.
    T remove_index(int index){
      if(is_empty()) throw -1;  // O(1)
      else if(head == last){
        return remove_front();  // O(n)
      }
      else if(index == length()-1){
        return remove_last();   // O(n)
      }
      else if(index == 0){
        return remove_front();   // O(n)
      }
      else{
        NodeLL<T> * temp = head;    // O(1)
        for(int i = 0; i < index-1; i++) temp = temp->next; // O(n)
        T dato = temp->next->data;  // O(1)
        temp->next = temp->next->next; // O(1)
        delete(temp->next->prev);       // O(1)
        temp->next->prev = temp; // O(1)
        return dato;              // O(1)
      }
    }


    /*Este método regresa de manera rápida el primer valor 
    de la  lista, osea el head*/
    T getFirst(){                               //O(1)
      if(is_empty()!=true){                                                                 //O(1)
        return head->data;                                                                  //O(1)
        }
      else return 0;                                                                       //O(1)
    }

    /*Este método regresa de manera rápida el primer valor de la  lista, osea el last*/
    T getLast(){                                //O(1)
      if(is_empty()!=true){                                                               //O(1)
         
        return last->data;                                                                //O(1)
      }
      else return NULL;                                                                   //O(1)
    }
    /*Este método regresa de manera rápida el primer valor 
    de la  lista, osea el head*/
    T peekFirst(){                              //O(1)
      if(is_empty()!=true) return head->data;                                            //O(1)
      else return NULL;                                                                  //O(1)
    }
    /*Este método regresa de manera rápida el primer valor de la  lista, osea el last*/
    T peekLast(){                               //O(1)
      if(is_empty()!=true){                                                             //O(1)
         
        return last->data;                                                              //O(1)       
      }
      else return NULL;                                                                 //O(1)
    }

    /*
    Esta función nos permite agregar “empujar '' a una pila de datos, 
    de tal modo que se va agregando una nueva “capa” de datos al stack.
    */
    void push(T dato){
      addFirst(dato);
    }


    /*
    Este método elimina el último valor agregado a la pila. Además
     regresar el dato del nodo de la pila que se está eliminando.
    */
    T pop(){
      return remove_front();                                                             //O(1)
    }


    /*
    El método regresa el valor del último elemento agregado a la pila.
    */
    T peek(){
      if(is_empty()) throw -1;
      else return head->data;                                                             //O(1)
    }


    /*
    El método agrega una nodo a la fila de datos.
    */
    void queue(T dato){
      addLast(dato);
    }
    
    /*
    El método elimina el elemento que sigue en turno para ser eliminado, 
    en este caso, el último valor en la lista ligada.
    */
    T dequeue(){
      return remove_front();                                                              //O(1)
    }

    /*
    El método elimina el mayor número que se encuentre en la lista.
    */
    T dequeueMax(){                                       
      if(is_empty()) throw -1;                      // O(1)
      else if (head == last) return remove_front(); // O(n)
      else{
        NodeLL<T> * auxiliar = head;                  // O(1)                                 
        T dato=0;                                   // O(1)
        int loc = 0;
        int lengtho = length();                     // O(n)

        for(int i = 0; i < lengtho; i++){           // O(n)
          if(auxiliar->data > dato){
            dato = auxiliar->data;                  // O(1)
            loc = i;                                // O(1)
          }
          auxiliar = auxiliar->next;                // O(1)
        }
        if(loc == 0){
          return remove_front();                    // O(n)
        } 
        else if(loc == length()-1) return remove_last();  // O(n)
        else{
          return remove_index(loc);                 // O(n)
        }
        
      }
    }


    /*
    El método elimina el menor número que se encuentre en la lista.
    */
    T dequeueMin(){                                       
      if(is_empty()) throw -1;                      // O(1)
      else if (head == last) return remove_front(); // O(n)
      else{
        NodeLL<T> * auxiliar = head;                  // O(1)                                   
        T dato=10000;                               // O(1)
        int loc = 0;                                // O(1)
        int lengtho = length();                     // O(1)

        for(int i = 0; i < lengtho; i++){           // 0(1)
          if(auxiliar->data < dato){                
            dato = auxiliar->data;                  // O(1)
            loc = i;                                // O(1)
          }
          auxiliar = auxiliar->next;                // O(1)
        }
        if(loc == 0){
          return remove_front();                    // O(n)
        } 
        else if(loc == length()-1) return remove_last(); // O(n)
        else{
          return remove_index(loc);                 // O(n)
        } 
      }
    }

    // Este metodo utiliza el algoritmo de bubble sort para
    // ordenar todos los valores de la lista ligada
    // direction == 0 : menor a mayor
    // direction == 1 : mayor a menor
    void bubble_sort(int direction = 0){
      T data_handler;                       // O(1)
      NodeLL<T> * auxiliar, * auxiliar_2; // current node, next node

      for(int i = length()-2; i >= 0; i--){  // O(n)
        auxiliar = head;                    // O(1)
        auxiliar_2 = auxiliar->next;        // O(1)

        for(int j = 0; j <= i; j++){        // O(n)
          if(direction == 0){
            if(auxiliar->data > auxiliar_2->data){
              data_handler = auxiliar->data; // O(1)
              auxiliar->data = auxiliar_2->data;  // O(1)
              auxiliar_2->data = data_handler;    // O(1)
            }
          }else{
            if(auxiliar->data < auxiliar_2->data){
              data_handler = auxiliar->data;      // O(1)
              auxiliar->data = auxiliar_2->data;  // O(1)
              auxiliar_2->data = data_handler;    // O(1)
            }
          }
          auxiliar = auxiliar_2;                  // O(1)
          auxiliar_2 = auxiliar_2->next;          // O(1)
        }
      }
    }


    /*El método merge permite agregar a la lista todo los 
    valores de otra lista. El método recibe  como parámetro un 
    objeto de tipo lista ligada.*/
    void merge(LinkedList<T> lista){                                          //O(1)
      // connect last s10 to head s02 and then make last s02 equal to last s01 
      last->next = lista.head;                                                             //O(1)
      last = lista.last;                                                                   //O(1)
    }




    // Sobrecarga de operador para imprimir la lista.
    /*
    friend ostream& operator<< (ostream & salida, const LinkedList<T>& lista){  //O(1)
          NodeLL<T> * auxiliar = lista.head;                                                  //O(1)
          while(auxiliar != NULL){                                                         //O(n)
            salida << auxiliar->data << ":";                                               //O(1)
            auxiliar = auxiliar->next;                                                     //O(1)
          }
          return salida;                                                                   //O(1)
    }
    */
    friend ostream& operator << (ostream & salida, const LinkedList<T>& lista){
      salida << lista.the_size << " ";
      return salida;
    }
    // sobrecarga de operador para comparar todos los valores
    // de una lista ligada con un entero.
    friend LinkedList<T> operator <(const LinkedList<T>&lista, int value){ //O(1)
      NodeLL<T> * auxiliar = lista.head;                                                     //O(1)
      LinkedList<T> list;                                                                  //O(1)
      while(auxiliar!=NULL){                                                              //O(n)
        if(auxiliar->data.getLife()<value) list.addLast(auxiliar->data.getLife());       //O(1)
        auxiliar = auxiliar->next;                                                      //O(1)
      }
      return list;                                                                      //O(1)
    }

    bool operator < (const LinkedList<T> & lista){
      return lista.the_size > this->the_size;
    }

    bool operator > (const LinkedList<T> & lista){
      return lista.the_size < this->the_size;
    }
};
/*
template<typename T>                                              //O(1)
ostream& operator<< (ostream & salida, const LinkedList<T>& lista){

      NodeLL<T> * auxiliar = lista->head;                                               //O(1)
      while(auxiliar != NULL){
        salida << auxiliar->data << ":";                                              //O(n)
        auxiliar = auxiliar->next;                                                    //O(1)
      }
      return salida;                                                                  //O(1)
}
*/