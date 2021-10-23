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
#include "server.h"
#include "linkedlist.h"
#include "bst.h"

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
  return 1 + (rand() % range);
}
int random_binary(){
  return (rand() % 2);
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
    auxiliar.infected = random_binary();
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

void menu(){
  cout << "[*] MENU. enter an option" << endl;
  cout << "[1] Print binary tree structure." << endl;
  cout << "[2] Print tree by level." << endl;
  cout << "[3] Print tree by pre-order." << endl;
  cout << "[4] Print tree by post_order." << endl;
  cout << "[5] Print tree in-order." << endl;
  cout << "[6] Look for an IP on network." << endl;
  cout << "[7] Print percentage of infected servers." << endl;
  cout << "[8] Print general chacteristics of BST." << endl;
  cout << "[9] exit" << endl;
  cout << ">> ";
  int option; cin >> option; cout << endl;

  switch(option){
    case 1:
      cout << "[*] PRINTING TREE STRUCTURE" << endl; 
      linked_list_tree.tree_print();
      cout  << endl;
      break;
    case 2:
      cout << "[*] PRINTING TREE BY LEVELS" << endl; 
      linked_list_tree.levels();
      cout << endl;
      break;
    case 3:
      cout << "[*] PRINTING TREE IN PRE-ORDER" << endl; 
      linked_list_tree.preOrden();
      cout << endl;
      break;
    case 4:
      cout << "[*] PRINTING TREE IN POST-ORDER" << endl; 
      linked_list_tree.postOrden();
      cout << endl;
      break;
    case 5:
      cout << "[*] PRINTING TREE IN-ORDER" << endl; 
      linked_list_tree.inOrden();
      cout << endl;
      break;
    case 6:
      {
      string ip;
      cout << "[*] please type an ip: "; cin>>ip;
      bool found = linked_list_tree.search_ip(ip);
      if(found == 1) cout << "[*] The IP was found!" << endl;
      else cout << "[*] IP not found, try another one." << endl;
      cout << endl;
      break;
      }
    case 7:
      cout << "[*] Percentage of infected servers: ";
      cout << linked_list_tree.infected_servers() << "%" << endl;
      cout << endl;
      break;
    case 8:
      cout << "[*] General view of the network(BST)." << endl;
      cout << "[*] full?: " << linked_list_tree.is_full() << endl;
      cout << "[*] leafs: " << linked_list_tree.leaf_count() << endl;
      cout << "[*] perfect?: " << linked_list_tree.is_perfect() << endl;
      cout << "[*] degenerate?: " << linked_list_tree.is_degenerate() << endl;
      cout << endl;
      break;
    case 9:
      cout << "[*] BYE-BYE!!! see ya around" << endl;
      exit(0);
      break;
    default:
      cout << "[*] Wrong input, please try again." << endl;
      cout << endl;
      menu();
      break;
  }
  menu();

}

int main() {
  srand(time(NULL));    // this is for initializing the clock for generating random numbers
  /*
  EXAMPLE OF RANDOM NUMBERS GENERATOR

  for(int i = 0; i < 20; i++)
  cout << random_number(15) << endl; 
  */

  /*
  read_file();
  linked_list_tree.inOrden(); 
  cout << endl;
  linked_list_tree.tree_print();
  

  
  cout << "\n" << endl;
  cout << "full?: " << linked_list_tree.is_full() << endl;
  cout << "leafs: " << linked_list_tree.leaf_count() << endl;
  cout << "perfect?: " << linked_list_tree.is_perfect() << endl;
  cout << "degenerate?=: " << linked_list_tree.is_degenerate() << endl;
  cout << "infected percentage: " << linked_list_tree.infected_servers() << endl;

  cout << "find ip 959.76.209.29:5196 = " << linked_list_tree.search_ip("959.76.209.29:5196") << endl;
  */
  cout << "[*] hello there ..." << endl;
  read_file();
  cout << "[*] LINKED LIST WAS LOADED SUCCESSFULLY.\n" << endl;
  cout << "[*] Please keep entering menu options while required. " << endl;
  cout << endl;

  menu();

  
  /*
  int rando;
  for(int i = 0; i < 600; i++){
    rando = random_binary();
    if(rando == 0) cout << "yes" << endl;
    else cout << "no" << endl;
  }
  */
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
https://stackoverflow.com/questions/33515678/checking-to-see-if-a-binary-search-tree-is-degenerate


*/