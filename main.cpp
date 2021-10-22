// CPP libraries
#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <string>
#include <vector>


#include <stdio.h>      // libs for random
#include <stdlib.h>
#include <ctime>

using namespace std;

// home-made libraries
#include "linkedlist.h"
#include "bst.h"
#include "server.h"

/*
    string  month;      // three letter format : sep
    int     day;        // dd format
    string  hour;       // "hh:mm:ss" format
    string  ip;         // "###.###.###.###:#####" format
    string reason;      // failing reason
*/


// creating global binary search tree to add the LinkedList<server>, depending of size
BST linked_list_tree = BST<LinkedList<Server>>();


// random number generator
int random_number(int range){
  return 1 + (rand() % range);;
}

// vector full of random numbers function
vector<int> random_arr(){
  int number_elements = 16807;
  int random_num;
  vector<int> servers_numbers={};
  while(number_elements>0){
    random_num = random_number(number_elements);
    servers_numbers.push_back(random_num);
    number_elements -= random_num;
  }
  return servers_numbers;
}

void print_vector(vector<int> vect){
  int sum = 0;
  for(int i  : vect){ 
    cout << i << endl;
    sum += i;
  }
  cout << "-->> size: " << vect.size() << endl;
  cout << "-->> sum : " << sum << endl;
}

// split function
void split(string line, string & month, string & day, string & hour, string & ip, string & reason){
  stringstream ss(line);// object to stream the variable
  string word;          // variable to store each word in large string

  string reason_str;    // string to concatenate reason

  int counter = 1;      // to check position of word
  while(ss>>word){
    
    switch(counter){
      case 1:
        month = word;   // modify month variable
        break;
      case 2:
        day = word;     // modify day variable
        break;
      case 3:
        hour = word;    // modify hour variable
        break;
      case 4:
        ip = word;      // modify ip variable
        break;
    }
    if(counter >= 5) reason_str += " " + word; // concatenating reason
    counter ++;
  }
  reason = reason_str;
}

/*

// function to create sever and linkedlist<server> and adding it to bst
void objects_crator(string month, string day, string hour, string ip, string reason){
  // creating server class
  int d = stoi(day);
  Server auxiliar_server = Server(month, d, hour, ip, reason);
  
  // creating auxiliar linked list
  LinkedList auxiliar_linked_list = LinkedList<Server>();
  auxiliar_linked_list.addFirst(auxiliar_server);

  // adding linked list to binary tree
  linked_list_tree.insert(auxiliar_linked_list);
  
}

*/


// to integrate object into read_file, i need to a variable of class linked list to add all the servers


// function to read each line of txt
void read_file(){
  fstream txt_file;                                // creating an SStream object
  txt_file.open("bitacora.txt", ios::in);          // opening bitacora file in input mode
  
  
  
  vector <int> size_ll = random_arr();             // sizes for each linked list in binary tree
  LinkedList<Server>  auxiliar_ll;


  // server atributes definition
  string month, day, hour, ip, reason;

  if(txt_file.is_open()){                          // checking wether the file is open or not
    string line;                                   // variable to store the line
    while(getline(txt_file, line)){
      split(line, month, day, hour, ip, reason);  // splitting each line of txt and adding to
                                                  // corresponding variable.
      auxiliar_ll.addLast(Server(month, stoi(day), hour, ip, reason));
    }
    txt_file.close();                             // closing connection to bitacora file
  }

  for(int i : size_ll){
    LinkedList<Server> auxiliar;
    for(int j = 1; j <= i; j++){
      auxiliar.addFirst(auxiliar_ll.pop());
    }
    auxiliar.the_size = auxiliar.size();
    linked_list_tree.insert(auxiliar);
  }

}

/*
string month="jan", int day=1, string hour="00:00:00", string ip="192.169.1.1", string reason="save"
    string  month;      // three letter format : sep
    int     day;        // dd format
    string  hour;       // "hh:mm:ss" format
    string  ip;         // "###.###.###.###:#####" format
    string reason;      // failing reason
*/


/*
TO DO
  -> apply function of object_creator to read_file function.
*/

/*
-> create server class for each line.
-> adding server class to linkedList<server> (must have a random size)
-> adding linked list to bst depending of LL size
*/
// function to add each line to linkedlist<server>

// function to add each linkedlist to BST

int main() {
  srand(time(NULL));    // this is for initializing the clock for generating random numbers
  /*
  EXAMPLE OF RANDOM NUMBERS GENERATOR

  for(int i = 0; i < 20; i++)
  cout << random_number(15) << endl; 
  */

  read_file();
  linked_list_tree.inOrden(); 
  cout << endl;
  linked_list_tree.tree_print();

  cout << "\n" << endl;
  cout << "full?: " << linked_list_tree.is_full() << endl;
  cout << "leafs: " << linked_list_tree.leaf_count() << endl;
  cout << "perfect?: " << linked_list_tree.is_perfect() << endl;
}





/*
https://stackoverflow.com/questions/4926622/how-to-generate-different-random-numbers-in-a-loop-in-c
https://stackoverflow.com/questions/42473544/modify-a-variable-passed-by-reference
https://www.learncpp.com/cpp-tutorial/passing-arguments-by-reference/
https://www.programarya.com/Cursos/C++/Condicionales/Condicional-switch
https://www.geeksforgeeks.org/arrays-in-c-cpp/
https://www.geeksforgeeks.org/how-to-split-a-string-in-cc-python-and-java/
https://www.tutorialspoint.com/how-to-read-a-text-file-with-cplusplus
https://www.w3schools.com/cpp/cpp_files.asp
https://www.cplusplus.com/doc/tutorial/files/
https://www.javatpoint.com/how-to-split-strings-in-cpp
https://www.systutorials.com/how-to-process-a-file-line-by-line-in-c/
https://www.delftstack.com/es/howto/cpp/return-string-from-function-cpp/
https://www.w3schools.com/cpp/cpp_strings_concat.asp
https://stackoverflow.com/questions/13445688/how-to-generate-a-random-number-in-c


https://www.geeksforgeeks.org/check-whether-binary-tree-full-binary-tree-not/

https://www.programiz.com/dsa/perfect-binary-tree


*/