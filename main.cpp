#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
#include <stdio.h>
using namespace std;

template<typename X>
class BSTNode{
  public:
    int key;
    X data;
    BSTNode *left;
    BSTNode *right;
    BSTNode *parent;

    BSTNode(){
      key = 0;;
      left = NULL;
      right = NULL;
      parent = NULL;
    }

    BSTNode(X student){
      key = student.getKey();
      data = student;
      left = NULL;
      right = NULL;
      parent = NULL;
    }

    ~BSTNode(){
      delete left;
      delete right;
      delete parent;
      delete key;
      delete data;
    }

    void setData(X student){
      key = student.getKey();
      data = student;
      left = NULL;
      right = NULL;
      parent = NULL;
    }

    void setKey(){
      data->getKey();
    }
};

template<typename X>
struct ListNode {
  X data;
  ListNode *next;
  ListNode *prev;
};

template<typename X>
class DoublyLinkedList {
  private:
    ListNode<X> *front;
    ListNode<X> *back;
    int size;

  public:
    DoublyLinkedList(){
      front = NULL;
      back = NULL;
      size = 0;
    }

    DoublyLinkedList(ListNode<X> *node){
      front = node;
      back = node;
      size = 1;
    }

    ~DoublyLinkedList(){
      delete front;
      delete back;
    }

    bool isEmpty(){
      if (size == 0){
        return true;
      } else {
        return false;
      }
    }

    void setFront(ListNode<X>* tempFront){
      front = tempFront;
    }

    void setBack(ListNode<X>* tempBack){
      back = tempBack;
    }

    void setSize(int tempSize){
      size = tempSize;
    }

    ListNode<X>* getBack(){
      return back;
    }

    ListNode<X>* getFront(){
      return front;
    }

    X getMedian(){
      ListNode<X>* testNode;
      testNode = front;
      int medianPos = size / 2;
      if (size == 1){
        return front->data;
      } else if (size == 0){
        return -1;
      } else {
        for (int i = 0; i < medianPos; ++i){
          testNode->next;
        }
        return testNode->data;
      }
    }

    void cleanList(){
      front = NULL;
      back = NULL;
      size = 0;
    }

    void insertFront(X data){
      ListNode<X>* insertNode = new ListNode<X>;

      insertNode->data = data;

      if(isEmpty() == true){
        front = insertNode;
        back = insertNode;
      } else {
        front->prev = insertNode;
        insertNode->next = front;
        front = insertNode;
      }

      size++;
    }

    void insertBack(X data){
      ListNode<X>* insertNode = new ListNode<X>;

      insertNode->data = data;

      if(isEmpty() == true){
        front = insertNode;
        back = insertNode;
      } else {
        back->next = insertNode;
        insertNode->prev = back;
        back = insertNode;
      }

      size++;
    }

    ListNode<X>* removeFront(){
      ListNode<X>* removeNode;
      removeNode = front;

      if (size == 1){
        front = NULL;
        back = NULL;
      } else {
        front = front->next;
        front->prev = NULL;
        removeNode->next = NULL;
      }
      size--;
      return removeNode;
    }

    ListNode<X>* removeBack(){
      ListNode<X>* removeNode;
      removeNode = back;

      if (size == 1){
        front = NULL;
        back = NULL;
      } else {
        back = back->prev;
        back->next = NULL;
        removeNode->prev = NULL;
      }

      size--;
      return removeNode;
    }

    int search(X searchData){
      bool search = true;

      ListNode<X>* searchNode = new ListNode<X>;
      searchNode = front;
      int searchIndex = -1;

      while(search == true){
        searchIndex++;
        if (searchNode->data == searchData){
          return searchIndex;
          search = false;
        }
        searchNode = searchNode->next;
      }
      return -1;
      searchNode = searchNode->next;
    }

    bool boolSearch(X searchData){
      bool search = true;
      bool found = false;

      ListNode<X>* searchNode = new ListNode<X>;
      searchNode = front;

      while(search == true){
        if (searchNode == NULL){
          found = false;
          search = false;
          return found;
        } else if (searchNode->data == searchData){
          found = true;
          search = false;
          return found;
        }
        searchNode = searchNode->next;
      }
      searchNode = searchNode->next;
      return found;
    }

    int getSize(){
      return size;
    }

    X getAtPos(int pos){
      ListNode<X>* getNode;
      getNode = front;

      X returnData;

      if (pos == 0){
        returnData = getNode->data;
      } else {
        for (int i = 0; i < pos; i++){
          getNode = getNode->next;
        }
        returnData = getNode->data;
      }
      return returnData;
    }

    X removeAtPos(int pos){
      ListNode<X>* removeNode;
      ListNode<X>* leftNode;
      ListNode<X>* rightNode;
      removeNode = front;

      X returnData;

      if (size == 0){
        cout << "Cannot remove, the list is empty!" << endl;
        return -1;
      } else if (pos == 0){
        returnData = removeNode->data;
        removeFront();
      } else {
        for (int i = 0; i < pos; i++){
          removeNode = removeNode->next;
        }
        leftNode = removeNode->prev;
        rightNode = removeNode->next;
        if(leftNode != NULL){
          leftNode->next = rightNode;
        } else {
          rightNode->prev = NULL;
        }
        if (rightNode != NULL){
          rightNode->prev = leftNode;
        } else {
          leftNode->next = NULL;
        }
        returnData = removeNode->data;
        delete removeNode;
        size--;
      }
      return returnData;
    }

    void printList(){
      if (front == NULL){
        //cout << "" << endl;
      } else {
        ListNode<X>* printNode = new ListNode<X>;
        printNode = front;

        for (int i = 0; i < size; i++){
          cout << "This is Advisee: " << i << endl;
          cout << "Student ID: " << printNode->data << endl;
          printNode = printNode->next;
        }
      }
    }

    void printFront(){
      ListNode<X>* printNode = new ListNode<X>;
      printNode = front;
      cout << "This is Front Node: " << endl;
      cout << "Value: " << printNode->data << endl;
      cout << "\n";
    }

    void printBack(){
      ListNode<X>* printNode = new ListNode<X>;
      printNode = back;
      cout << "This is Back Node: " << endl;
      cout << "Value: " << printNode->data << endl;
      cout << "\n";
    }

};

template<typename X>
class BST{
  private:
    BSTNode<X> *root;

  public:
    BST(){
      root = NULL;
    }

    BST(BSTNode<X> *node){
      root = node;
    }

    ~BST(){
      delete root;
    }

    BST<X>* readAFacultyFile(string fileName){
      BST<X>* tempFacultyBST = new BST<X>;
      ifstream facultyTreeInfo(fileName);
      string facultyLine;
      int lineCount = 1;

      DoublyLinkedList<int>* tempAdvisees = new DoublyLinkedList<int>;

      string tempDepartment = "";
      int tempID = 0;
      string tempName = "NULL";
      string tempLevel = "NULL";
      bool hasAdvisees = false;

      while(getline(facultyTreeInfo, facultyLine)){
        if(facultyLine == "X\r" || facultyLine == "X\n" || facultyLine == "X"){
          lineCount = 2;
          hasAdvisees = false;
        }
        else if (lineCount == 2){
          tempID = stoi(facultyLine);
          lineCount++;
        }
        else if (lineCount == 3){
          tempName = facultyLine;
          lineCount++;
        }
        else if (lineCount == 4){
          tempLevel = facultyLine;
          lineCount++;
        }
        else if (lineCount == 5){
          tempDepartment = facultyLine;
          lineCount++;
        }
        else if (facultyLine == "Y\r" || facultyLine == "Y\n" || facultyLine == "Y"){
          X tempFaculty = X(tempID, tempName, tempLevel, tempDepartment);
          tempFaculty.copyList(tempAdvisees);
          tempAdvisees->cleanList();
          BSTNode<X>* myTempNode = new BSTNode<X>;
          myTempNode->setData(tempFaculty);
          tempFacultyBST->insert(myTempNode);
          lineCount = 1;
        }
        else if (lineCount > 5){
          int tempAdviseeID = stoi(facultyLine);
          tempAdvisees->insertFront(tempAdviseeID);
        }
      }
      facultyTreeInfo.close();
      return tempFacultyBST;
    }

    BST<X>* readAStudentFile(string fileName){
      BST<X>* tempStudentBST = new BST<X>;
      ifstream studentTreeInfo(fileName);
      string studentLine;
      int lineCount = 1;

      int tempID = 0;
      string tempName = "NULL";
      string tempLevel = "NULL";
      string tempMajor = "NULL";
      double tempGPA = 0.0;
      int tempAdvisor = 0;
      string testString = "";

      while(getline(studentTreeInfo, studentLine)){
        if(studentLine == "X\r" || studentLine == "X\n" || studentLine == "X"){
          lineCount = 2;
        } else if (lineCount == 2){
          tempID = stoi(studentLine);
          lineCount++;
        } else if (lineCount == 3){
          tempName = studentLine;
          lineCount++;
        } else if (lineCount == 4){
          tempLevel = studentLine;
          lineCount++;
        } else if (lineCount == 5){
          tempMajor = studentLine;
          lineCount++;
        } else if (lineCount == 6){
          tempGPA = stod(studentLine);
          lineCount++;
        } else if (lineCount == 7){
          tempAdvisor = stoi(studentLine);
          lineCount++;
        } else if (studentLine == "Y\r" || studentLine == "Y\n" || studentLine == "Y"){
          X tempStudent = X(tempID, tempName, tempLevel, tempMajor, tempGPA, tempAdvisor);
          BSTNode<X>* myTempNode = new BSTNode<X>;
          myTempNode->setData(tempStudent);
          tempStudentBST->insert(myTempNode);
          lineCount = 1;
        }
      }

      studentTreeInfo.close();

      return tempStudentBST;

    }

    void writeOutStudentFile(string fileName, BSTNode<X>* node){
      ofstream outfile;
      outfile.open(fileName, std::ios_base::app);

        if (node == NULL){
          return;
        }
        // left recursion
        writeOutStudentFile(fileName, node->left);
        //print node
        outfile << "X\n";
        outfile << (node->data).getKey() << "\n";
        outfile << (node->data).getName() << "\n";
        outfile << (node->data).getLevel() << "\n";
        outfile << (node->data).getMajor() << "\n";
        outfile << (node->data).getGPA() << "\n";
        outfile << (node->data).getAdvisor() << "\n";
        outfile << "Y\n";
        // right recursion
        writeOutStudentFile(fileName, node->right);

      outfile.close();

    }

    void writeOutFacultyFile(string fileName, BSTNode<X>* node){
      ofstream outfile;
      outfile.open(fileName, std::ios_base::app);

        if (node == NULL){
          return;
        }
        // left recursion
        writeOutFacultyFile(fileName, node->left);
        //print node
        outfile << "X\n";
        outfile << (node->data).getKey() << "\n";
        outfile << (node->data).getName() << "\n";
        outfile << (node->data).getLevel() << "\n";
        outfile << (node->data).getDepartment() << "\n";
        int numOfAdvisees = (node->data).getAdviseeCount();
        for (int i = 0; i < numOfAdvisees; ++i){
          outfile << (node->data).getAdviseeIDAtPos(i) << "\n";
        }
        outfile << "Y\n";
        // right recursion
        writeOutFacultyFile(fileName, node->right);

      outfile.close();

    }

    void printInOrder(BSTNode<X>* node){
      if (node == NULL){
        return;
      }
      // left recursion
      printInOrder(node->left);
      //print node
      (node->data).printMember();
      // right recursion
      printInOrder(node->right);
    }

    void printLevelOrder(BSTNode<X>* root){
      int h = height(root);
      int i;
      for (i = 1; i <= h; i++){
        printGivenLevel(root, i);
      }
    }

    void printGivenLevel(BSTNode<X>* root, int level){
      if (root == NULL){
          return;
      } if (level == 1){
          (root->data).printMember();
      } else if (level > 1) {
          printGivenLevel(root->left, level-1);
          printGivenLevel(root->right, level-1);
      }
    }

    int height(BSTNode<X>* node) {
        if (node == NULL){
            return 0;
        } else {
            int lheight = height(node->left);
            int rheight = height(node->right);

            if (lheight > rheight)
                return(lheight + 1);
            else return(rheight + 1);
        }
    }

    void setRoot(BSTNode<X> *node){
      root = node;
    }

    BSTNode<X>* getRoot(){
      return root;
    }

    BSTNode<X>* getSucessor(BSTNode<X> *d){
      BSTNode<X>* current = d->right;
      BSTNode<X>* sp = d;
      BSTNode<X>* successor = d;

      while(current != NULL){
        sp = successor;
        successor = current;
        current = current->left;
      }

      if(successor != d->right){
        sp->left = successor->right;
        successor->right = d->right;
      }

      return successor;
    }

    bool deleteNode(int k){

      if (root == NULL){
        return false;
      }

      BSTNode<X>* parent = root;
      BSTNode<X>* current = root;
      bool isLeft = true;

      while (current->key != k){
        parent = current;
        if (k < current->key){
          isLeft = true;
          current = current->right;
        } else {
          isLeft = false;
          current = current->right;
        }

        if (current == NULL){
          return false;
        }
      }

      //if we make it here, we've found the value lets proceed to delete

      //leaf treenode
      if (current->left == NULL && current->right ==NULL){
        if(current == root){
          root = NULL;
        } else if (isLeft){
          parent->left = NULL;
        } else {
          parent->right = NULL;
        }
      }

      //one child case (left child)
      else if (current->right == NULL){
        if (current == root){
          root = current->left;
        } else if (isLeft) {
          parent->left = current->left;
        } else {
          parent->right = current->left;
        }
      }

      //one child case (right child)
      else if(current->left == NULL){
        if(current == root){
          root = current->right;
        } else if (isLeft){
          parent->right = current->right;
        } else {
          parent->left = current->right;
        }
      }

      //two children
      else{
        BSTNode<X>* successor = getSucessor(current);

        if(current == root){
          root = successor;
        } else if (isLeft){
          parent->left = successor;
        } else {
          parent->right = successor;
        }

        successor->left = current->left;

        return true;
      }
    }

    BSTNode<X>* search(int key){
      BSTNode<X>* current = root;

      //This loops while searching for the data
      while (current->key != key){
        //checks to see if root is set to NULL
        if (current != NULL){

          //go to the left tree
          if (current->key > key){
            current = current->left;
          } //go down the right tree
          else {
            current = current->right;
          }
          //if the data is not found
          if(current == NULL){
            return NULL;
          }
        }
      }
      return current;
    }

    bool insert(BSTNode<X> *node){
      BSTNode<X>* temp = node;
      BSTNode<X>* current;
      BSTNode<X>* parent;

      //if tree is empty
      if(root == NULL){
        root = node;
      } else {
        current = root;
        parent = NULL;

        while (1){
          parent = current;

          //go to the left
          if (node->key < parent->key){
            current = current->left;
            //insert to the left
            if (current == NULL){
              parent->left = temp;
              return true;
            }
          } else {
            current = current->right;

            if(current == NULL){
              parent->right = temp;
              return true;;
            }
          }
        }
      }
    }

};

class Student{

  private:
    int id;
    string name;
    string level;
    string major;
    double gpa;
    int advisor;

  public:
      Student(){
        id = 0;
        name = "NULL";
        level = "NULL";
        major = "NULL";
        gpa = 0.0;
        advisor = 0;
      }

      Student(int newID, string newName, string newLevel, string newMajor, double newGPA, int newAdvisor){
        id = newID;
        name = newName;
        level = newLevel;
        major = newMajor;
        gpa = newGPA;
        advisor = newAdvisor;
      }

      int getKey(){
        return id;
      }

      string getName(){
        return name;
      }

      string getLevel(){
        return level;
      }

      string getMajor(){
        return major;
      }

      double getGPA(){
        return gpa;
      }

      int getAdvisor(){
        return advisor;
      }

      void changeAdvisor(int newAdvisor){
        advisor = newAdvisor;
      }

      void printStudent(){
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Level: " << level << endl;
        cout << "Major: " << major << endl;
        cout << "GPA: " << gpa << endl;
        cout << "Advisor ID: " << advisor << endl;
      }

      void printMember(){
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Level: " << level << endl;
        cout << "Major: " << major << endl;
        cout << "GPA: " << gpa << endl;
        cout << "Advisor ID: " << advisor << endl;
        cout << "\n";
      }

      friend bool operator== (const Student &c1, const Student &c2){
        return (c1.id == c2.id);
      }
      friend bool operator!= (const Student &c1, const Student &c2){
        return !(c1 == c2);
      }
      friend bool operator> (const Student &c1, const Student &c2)
      {
          return c1.id > c2.id;
      }
      friend bool operator>= (const Student &c1, const Student &c2)
      {
          return c1.id >= c2.id;
      }
      friend bool operator< (const Student &c1, const Student &c2)
      {
          return c1.id < c2.id;
      }
      friend bool operator<= (const Student &c1, const Student &c2)
      {
          return c1.id <= c2.id;
      }


};

class Faculty{
  private:
    int id;
    string name;
    string level;
    string department;
    DoublyLinkedList<int>* myAdvisees = new DoublyLinkedList<int>;

  public:
      Faculty(){
        id = 0;
        name = "NULL";
        level = "NULL";
        department = "NULL";
        myAdvisees = NULL;
      }

      Faculty(int newID, string newName, string newLevel, string newDepartment){
        id = newID;
        name = newName;
        level = newLevel;
        department = newDepartment;
      }

      int getKey(){
        return id;
      }

      string getName(){
        return name;
      }

      string getLevel(){
        return level;
      }

      string getDepartment(){
        return department;
      }

      int getAdviseeCount(){
        return myAdvisees->getSize();
      }

      int getAdviseeIDAtPos(int pos){
        myAdvisees->getAtPos(pos);
      }

      void printAdvisees(BST<Student>* myStudentBST){
        BSTNode<Student>* tempStudentNode = new BSTNode<Student>;
        if (myAdvisees->getSize() == 0){
          cout << "The faculty has no advisees!" << endl;
        } else {
          int numOfStudent = myAdvisees->getSize();
          for (int i = 0; i < numOfStudent; i++){
            tempStudentNode = myStudentBST->search(myAdvisees->getAtPos(i));
            (tempStudentNode->data).printMember();
          }
        }
      }

      DoublyLinkedList<int>* getAdviseeList(){
        return myAdvisees;
      }

      void copyList(DoublyLinkedList<int>* copyList){
        myAdvisees->setFront(copyList->getFront());
        myAdvisees->setBack(copyList->getBack());
        myAdvisees->setSize(copyList->getSize());
      }

      void addAdvisee(int temp){
        myAdvisees->insertFront(temp);
      }

      void removeAdvisee(int temp){
        int searchPos = myAdvisees->search(temp);
        myAdvisees->removeAtPos(searchPos);
      }

      void printFaculty(){
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Level: " << level << endl;
        cout << "Department: " << department << endl;
        cout << "Advisees: " << endl;
        myAdvisees->printList();
      }

      void printMember(){
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Level: " << level << endl;
        cout << "Department: " << department << endl;
        cout << "Advisees: " << endl;
        myAdvisees->printList();
        cout << "\n";
      }

      friend bool operator== (const Faculty &c1, const Faculty &c2){
        return (c1.id == c2.id);
      }
      friend bool operator!= (const Faculty &c1, const Faculty &c2){
        return !(c1 == c2);
      }
      friend bool operator> (const Faculty &c1, const Faculty &c2)
      {
          return c1.id > c2.id;
      }
      friend bool operator>= (const Faculty &c1, const Faculty &c2)
      {
          return c1.id >= c2.id;
      }
      friend bool operator< (const Faculty &c1, const Faculty &c2)
      {
          return c1.id < c2.id;
      }
      friend bool operator<= (const Faculty &c1, const Faculty &c2)
      {
          return c1.id <= c2.id;
      }
};

class BSTPair{
    private:
      BST<Student>* myStudentBST = new BST<Student>;
      BST<Faculty>* myFacultyBST = new BST<Faculty>;

    public:
      BSTPair(){
        myStudentBST = NULL;
        myFacultyBST = NULL;
      }

      void fillPair(BST<Student>* newStudentBST, BST<Faculty>* newFacultyBST){
        myStudentBST = newStudentBST;
        myFacultyBST = newFacultyBST;
      }

      BST<Student>* getStudentBST(){
        return myStudentBST;
      }

      BST<Faculty>* getFacultyBST(){
        return myFacultyBST;
      }
};

class RollBackStack{
  private:
    int count;

  public:
    RollBackStack(){
      count = 0;
    }

    void addTreePair(BSTPair* newTreePair){
      BST<Faculty>* tempFacultyBST = new BST<Faculty>;
      BST<Student>* tempStudentBST = new BST<Student>;
      BSTNode<Faculty>* tempFacultyNode = new BSTNode<Faculty>;
      BSTNode<Student>* tempStudentNode = new BSTNode<Student>;


      if (count < 5){
        if (count == 0){
          tempStudentBST = newTreePair->getStudentBST();
          tempFacultyBST = newTreePair->getFacultyBST();
          tempStudentNode = tempStudentBST->getRoot();
          tempFacultyNode = tempFacultyBST->getRoot();
          tempStudentBST->writeOutStudentFile("myStudentBST0.txt", tempStudentNode);
          tempFacultyBST->writeOutFacultyFile("myFacultyBST0.txt", tempFacultyNode);
        } else if (count == 1){
          tempStudentBST = newTreePair->getStudentBST();
          tempFacultyBST = newTreePair->getFacultyBST();
          tempStudentNode = tempStudentBST->getRoot();
          tempFacultyNode = tempFacultyBST->getRoot();
          tempStudentBST->writeOutStudentFile("myStudentBST1.txt", tempStudentNode);
          tempFacultyBST->writeOutFacultyFile("myFacultyBST1.txt", tempFacultyNode);
        } else if (count == 2){
          tempStudentBST = newTreePair->getStudentBST();
          tempFacultyBST = newTreePair->getFacultyBST();
          tempStudentNode = tempStudentBST->getRoot();
          tempFacultyNode = tempFacultyBST->getRoot();
          tempStudentBST->writeOutStudentFile("myStudentBST2.txt", tempStudentNode);
          tempFacultyBST->writeOutFacultyFile("myFacultyBST2.txt", tempFacultyNode);
        } else if (count == 3){
          tempStudentBST = newTreePair->getStudentBST();
          tempFacultyBST = newTreePair->getFacultyBST();
          tempStudentNode = tempStudentBST->getRoot();
          tempFacultyNode = tempFacultyBST->getRoot();
          tempStudentBST->writeOutStudentFile("myStudentBST3.txt", tempStudentNode);
          tempFacultyBST->writeOutFacultyFile("myFacultyBST3.txt", tempFacultyNode);
        } else if (count == 4){
          tempStudentBST = newTreePair->getStudentBST();
          tempFacultyBST = newTreePair->getFacultyBST();
          tempStudentNode = tempStudentBST->getRoot();
          tempFacultyNode = tempFacultyBST->getRoot();
          tempStudentBST->writeOutStudentFile("myStudentBST4.txt", tempStudentNode);
          tempFacultyBST->writeOutFacultyFile("myFacultyBST4.txt", tempFacultyNode);
        }
        count++;
      } else {
        remove("myStudentBST0.txt");
        rename("myStudentBST1.txt", "myStudentBST0.txt");
        rename("myStudentBST2.txt", "myStudentBST1.txt");
        rename("myStudentBST3.txt", "myStudentBST2.txt");
        rename("myStudentBST4.txt", "myStudentBST3.txt");

        remove("myFacultyBST0.txt");
        rename("myFacultyBST1.txt", "myFacultyBST0.txt");
        rename("myFacultyBST2.txt", "myFacultyBST1.txt");
        rename("myFacultyBST3.txt", "myFacultyBST2.txt");
        rename("myFacultyBST4.txt", "myFacultyBST3.txt");

        tempStudentBST = newTreePair->getStudentBST();
        tempFacultyBST = newTreePair->getFacultyBST();
        tempStudentNode = tempStudentBST->getRoot();
        tempFacultyNode = tempFacultyBST->getRoot();
        tempStudentBST->writeOutStudentFile("myStudentBST4.txt", tempStudentNode);
        tempFacultyBST->writeOutFacultyFile("myFacultyBST4.txt", tempFacultyNode);
      }
    }

    void cleanRollBack(){
      remove("myStudentBST0.txt");
      remove("myStudentBST1.txt");
      remove("myStudentBST2.txt");
      remove("myStudentBST3.txt");
      remove("myStudentBST4.txt");
      remove("myFacultyBST0.txt");
      remove("myFacultyBST1.txt");
      remove("myFacultyBST2.txt");
      remove("myFacultyBST3.txt");
      remove("myFacultyBST4.txt");
    }

    BSTPair* popTreePair(){
      BSTPair* newTreePair = new BSTPair;
      BST<Student>* tempStudentBST = new BST<Student>;
      BST<Faculty>* tempFacultyBST = new BST<Faculty>;
      count--;

      if (count < 1){
        count = 0;
      }

      if (count == 4){
        //read student text file and create a student BST
        tempStudentBST = tempStudentBST->readAStudentFile("myStudentBST4.txt");
        //read faculty text file and create a faculty BST
        tempFacultyBST = tempFacultyBST->readAFacultyFile("myFacultyBST4.txt");
      } else if (count == 3){
        tempStudentBST = tempStudentBST->readAStudentFile("myStudentBST3.txt");
        tempFacultyBST = tempFacultyBST->readAFacultyFile("myFacultyBST3.txt");
      } else if (count == 2){
        tempStudentBST = tempStudentBST->readAStudentFile("myStudentBST2.txt");
        tempFacultyBST = tempFacultyBST->readAFacultyFile("myFacultyBST2.txt");
      } else if (count == 1){
        tempStudentBST = tempStudentBST->readAStudentFile("myStudentBST1.txt");
        tempFacultyBST = tempFacultyBST->readAFacultyFile("myFacultyBST1.txt");
      } else if (count == 0){
        tempStudentBST = tempStudentBST->readAStudentFile("myStudentBST0.txt");
        tempFacultyBST = tempFacultyBST->readAFacultyFile("myFacultyBST0.txt");
      }
      newTreePair->fillPair(tempStudentBST, tempFacultyBST);
      return newTreePair;
    }

    void lowerCount(){
      count--;
      cout << "Count = " << count << endl;
    }

};

void cleanFile(string filename){
  ofstream myfile (filename);
  myfile.close();
}

int main(int argc, char *argv[] ){

  cout << "\n===============================================================\n";
  cout << "          Welcome to Michael's Magical School Database!";
  cout << "\n===============================================================\n";
  cout << "\n";

  RollBackStack* introStack = new RollBackStack();
  introStack->cleanRollBack();

  DoublyLinkedList<int>* tempStudents = new DoublyLinkedList<int>;
  int studentCount = 0;
  DoublyLinkedList<int>* tempFaculty = new DoublyLinkedList<int>;
  int facultyCount = 0;

  DoublyLinkedList<int>* lostStudents = new DoublyLinkedList<int>;

  //test for the existence of tables
  ifstream studentTreeTest("studentTable.txt");
  if (studentTreeTest.good() == false){
    ofstream myfile;
    myfile.open ("studentTable.txt");
    myfile << "";
    myfile.close();
  }

  ifstream facultyTreeTest("facultyTable.txt");
  if (facultyTreeTest.good() == false){
    ofstream myfile;
    myfile.open ("facultyTable.txt");
    myfile << "";
    myfile.close();
  }

  //Lets create the student tree
  BST<Student>* myStudentBST = new BST<Student>;
  ifstream studentTreeInfo("studentTable.txt");
  string studentLine;
  int lineCount = 1;

  int tempID = 0;
  string tempName = "NULL";
  string tempLevel = "NULL";
  string tempMajor = "NULL";
  double tempGPA = 0.0;
  int tempAdvisor = 0;

  string testString = "";

  while(getline(studentTreeInfo, studentLine)){
    if(studentLine == "X\r" || studentLine == "X\n" || studentLine == "X"){
      lineCount = 2;
      cout << "Start making a student" << endl;
    } else if (lineCount == 2){
      tempID = stoi(studentLine);
      tempStudents->insertFront(tempID);
      studentCount++;
      lineCount++;
    } else if (lineCount == 3){
      tempName = studentLine;
      lineCount++;
    } else if (lineCount == 4){
      tempLevel = studentLine;
      lineCount++;
    } else if (lineCount == 5){
      tempMajor = studentLine;
      lineCount++;
    } else if (lineCount == 6){
      tempGPA = stod(studentLine);
      lineCount++;
    } else if (lineCount == 7){
      tempAdvisor = stoi(studentLine);
      lineCount++;
    } else if (studentLine == "Y\r" || studentLine == "Y\n" || studentLine == "Y"){
      Student tempStudent = Student(tempID, tempName, tempLevel, tempMajor, tempGPA, tempAdvisor);
      BSTNode<Student>* myTempNode = new BSTNode<Student>;
      myTempNode->setData(tempStudent);
      myStudentBST->insert(myTempNode);
      cout << "We made a student" << endl;
      lineCount = 1;
    }
  }
  cout << "\n";
  studentTreeInfo.close();

  //Lets create the faculty tree
  BST<Faculty>* myFacultyBST = new BST<Faculty>;
  ifstream facultyTreeInfo("facultyTable.txt");

  //creates temp linked list to hold advisee ints
  DoublyLinkedList<int>* tempAdvisees = new DoublyLinkedList<int>;

  string tempDepartment = "NULL";
  string facultyLine;
  bool hasAdvisees = false;

  while(getline(facultyTreeInfo, facultyLine)){
    if(facultyLine == "X\r" || facultyLine == "X\n" || facultyLine == "X"){
      lineCount = 2;
      cout << "Start making a faculty" << endl;
      hasAdvisees = false;
    }
    else if (lineCount == 2){
      tempID = stoi(facultyLine);
      tempFaculty->insertFront(tempID);
      facultyCount++;
      lineCount++;
    }
    else if (lineCount == 3){
      tempName = facultyLine;
      lineCount++;
    }
    else if (lineCount == 4){
      tempLevel = facultyLine;
      lineCount++;
    }
    else if (lineCount == 5){
      tempDepartment = facultyLine;
      lineCount++;
    }
    else if (facultyLine == "Y\r" || facultyLine == "Y\n" || facultyLine == "Y"){
      //creates faculty object
      Faculty tempFaculty = Faculty(tempID, tempName, tempLevel, tempDepartment);
      //
      if (hasAdvisees == true){
        tempFaculty.copyList(tempAdvisees);
      }
      //clean the List
      tempAdvisees->cleanList();
      //creates BSTNode pointer to hold faculty
      BSTNode<Faculty>* myTempNode = new BSTNode<Faculty>;
      //Puts faculty object into pointer
      myTempNode->setData(tempFaculty);
      //Puts BSTNode pointer into the BST Tree
      myFacultyBST->insert(myTempNode);
      cout << "We made a faculty" << endl;
      //Resets Counter
      lineCount = 1;
    }
    else if (lineCount > 5){
      hasAdvisees = true;
      int tempAdviseeID = stoi(facultyLine);

      bool validAdvisee = false;

      bool studentInList = false;
      bool studentHasProperAdvisor = false;
      bool restartBool = false;
      int testValue = 5;

      while (validAdvisee == false){

        if (tempStudents->boolSearch(tempAdviseeID) == false || restartBool == true){
          string tempFacultyString = "";
          cout << "-------- ERROR --------" << endl;
          cout << "Faculty " << tempID << " has an invalid Advisee: " << tempAdviseeID << endl;
          cout << "New Advisee ID: ";
          getline(cin, tempFacultyString);
          tempAdviseeID = stoi(tempFacultyString);
          cout << "-----------------------" << endl;
          restartBool = false;
        }

        studentInList = true;

        BSTNode<Student>* checkStudentNode = new BSTNode<Student>;
        checkStudentNode = myStudentBST->search(tempAdviseeID);
        if ((checkStudentNode->data).getAdvisor() != tempID && restartBool == false){
          cout << "Error: This faculty member is not listed as an advisor to the student" << endl;
          studentInList = false;
          restartBool = true;
          testValue--;
        }

        studentHasProperAdvisor = true;

        if (studentInList == true && studentHasProperAdvisor == true){
          tempAdvisees->insertFront(tempAdviseeID);
          validAdvisee = true;
        }

      }
    }
  }
  facultyTreeInfo.close();
  BSTNode<Student>* checkStudentNode = new BSTNode<Student>;
  BSTNode<Faculty>* checkFacultyNode = new BSTNode<Faculty>;

  bool studentChecker = true;
  int validIncrement = 0;
  string checkString = "";

  bool advisorExists = false;
  bool adviseeFound = false;
  bool redoBool = false;

  int loopHolder = 0;


  for (int i = 0; i < studentCount; ++i){

    //go through each student and check for a valid advisor
    //get a student ID from the student ID linked list
    int studentToCheck = tempStudents->getAtPos(i);
    //get the student BSTNode Object from the BST
    checkStudentNode = myStudentBST->search(studentToCheck);
    //get the advisor value from the BSTNode Object
    int advisorCheck = (checkStudentNode->data).getAdvisor();

    //checks to see if the advisor even exists if they don't then this happens:
    if (myFacultyBST->search(advisorCheck) == NULL || redoBool == true){
      redoBool = false;
      cout << "-------- ERROR --------" << endl;
      cout << "Student " << studentToCheck << " has an invalid Advisor" << endl;
      cout << "New Advisor ID: ";
      getline(cin, checkString);
      advisorCheck = stoi(checkString);
      (checkStudentNode->data).changeAdvisor(advisorCheck);
      i--;
      cout << "-----------------------" << endl;
    } else {
      advisorExists = true;
    }

    //At this point we have confirmed that the student's advisor does exist, what we must check now is whether or not the
    //student themselves are in the faculty's list of advisees. If not we must allow the student to change their advisor by subtracting
    // 1 from i

    checkFacultyNode = myFacultyBST->search(advisorCheck);

    if (advisorExists == true){
      if (checkFacultyNode == NULL){
        redoBool = true;
        i--;
      } else {
        int numOfAdvisees = (checkFacultyNode->data).getAdviseeCount();
        for (int j = 0; j < numOfAdvisees; j++){
          if ((checkFacultyNode->data).getAdviseeIDAtPos(j) == studentToCheck){
            adviseeFound = true;
          }
        }
        if (adviseeFound == false){
          redoBool = true;
          i--;
        }
      }
    }

  }

  RollBackStack* genRollBack = new RollBackStack;
  BSTPair* newTreePair = new BSTPair;
  BST<Student>* myCopyStudentBST = new BST<Student>;
  BST<Faculty>* myCopyFacultyBST = new BST<Faculty>;
  myCopyStudentBST = myStudentBST;
  myCopyFacultyBST = myFacultyBST;

  newTreePair->fillPair(myCopyStudentBST, myCopyFacultyBST);
  genRollBack->addTreePair(newTreePair);

  cout << "\n===============================================================\n";
  cout << "\n";

  bool mainMenu = true;
  string dumbString = "";
  int dumbInt = 0;
  bool lostStudentsBool = false;

  bool rollBackBool = false;

  while (mainMenu == true){
    lostStudentsBool = false;

    //PRINT OUT ALL THE OPTIONS
    cout << "\n";
    cout << "******************* MAIN MENU ******************************************" << endl;
    cout << "(1)  Print all students and their information (sorted by ascending id #)" << endl;
    cout << "(2)  Print all faculty and their information (sorted by ascending id #)" << endl;
    cout << "(3)  Find and display student information given the students id" << endl;
    cout << "(4)  Find and display faculty information given the faculty id" << endl;
    cout << "(5)  Given a student’s id, print the name and info of their faculty advisor" << endl;
    cout << "(6)  Given a faculty id, print ALL the names and info of his/her advisees" << endl;
    cout << "(7)  Add a new student" << endl;
    cout << "(8)  Delete a student given the id" << endl;
    cout << "(9)  Add a new faculty member" << endl;
    cout << "(10) Delete a faculty member given the id" << endl;
    cout << "(11) Change a student’s advisor given the student id and the new faculty id" << endl;
    cout << "(12) Remove an advisee from a faculty member given the ids" << endl;
    cout << "(13) Rollback" << endl;
    cout << "(14) Tree Navigation Tool" << endl;
    cout << "(15) Exit" << endl;
    cout << "************************************************************************" << endl;
    cout << "\n";
    cout << "OPTION: ";

    getline(cin, dumbString);
    dumbInt = stoi(dumbString);
    cout << "\n";

    BSTNode<Student>* tempStudentNode = new BSTNode<Student>;
    BSTNode<Faculty>* tempFacultyNode = new BSTNode<Faculty>;

    if (dumbInt == 1){
        rollBackBool = true;
        tempStudentNode = myStudentBST->getRoot();
        myStudentBST->printInOrder(tempStudentNode);
    } else if (dumbInt == 2){
        rollBackBool = true;
        tempFacultyNode = myFacultyBST->getRoot();
        myFacultyBST->printInOrder(tempFacultyNode);
    } else if (dumbInt == 3){
        rollBackBool = true;
        cout << "Student ID: ";
        getline(cin, dumbString);
        int idSearch = stoi(dumbString);
        tempStudentNode = myStudentBST->search(idSearch);
        if (tempStudentNode == NULL){
          cout << "The student was not found!" << endl;
        } else {
          (tempStudentNode->data).printMember();
        }
        cout << "\n";
    } else if (dumbInt == 4){
        rollBackBool = true;
        cout << "Faculty ID: ";
        getline(cin, dumbString);
        int idSearch = stoi(dumbString);
        tempFacultyNode = myFacultyBST->search(idSearch);
        if (tempFacultyNode == NULL){
          cout << "The faculty member was not found!" << endl;
        } else {
          (tempFacultyNode->data).printMember();
        }
        cout << "\n";
    } else if (dumbInt == 5){
        rollBackBool = true;
        cout << "Student ID: ";
        getline(cin, dumbString);
        int tempStudentID = stoi(dumbString);
        cout << "\n";

        tempStudentNode = myStudentBST->search(tempStudentID);
        int facultyAdvisor = (tempStudentNode->data).getAdvisor();

        tempFacultyNode = myFacultyBST->search(facultyAdvisor);
        (tempFacultyNode->data).printMember();
    } else if (dumbInt == 6){
        rollBackBool = true;
        cout << "Faculty ID: ";
        getline(cin, dumbString);
        int tempFacultyID = stoi(dumbString);
        cout << "\n";

        tempFacultyNode = myFacultyBST->search(tempFacultyID);
        (tempFacultyNode->data).printAdvisees(myStudentBST);
    } else if (dumbInt == 7){
        cout << "ID: ";
        getline(cin, dumbString);
        int tempID = stoi(dumbString);
        cout << "Name: ";
        getline(cin, dumbString);
        string tempName = dumbString;
        cout << "Level: ";
        getline(cin, dumbString);
        string tempLevel = dumbString;
        cout << "Major: ";
        getline(cin, dumbString);
        string tempMajor = dumbString;
        cout << "GPA: ";
        getline(cin, dumbString);
        double tempGPA = stod(dumbString);
        cout << "Advisor ID: ";
        getline(cin, dumbString);
        int tempAdvisorID = stoi(dumbString);
        cout << "\n";
        Student tempStudent = Student(tempID, tempName, tempLevel, tempMajor, tempGPA, tempAdvisorID);
        BSTNode<Student>* newStudent = new BSTNode<Student>;
        newStudent->setData(tempStudent);
        myStudentBST->insert(newStudent);
        tempFacultyNode = myFacultyBST->search(tempAdvisorID);
        (tempFacultyNode->data).addAdvisee(tempID);
        cout << "Student Successfully Added!" << endl;
        cout << "\n";
    } else if (dumbInt == 8){
        cout << "ID: ";
        getline(cin, dumbString);
        int tempID = stoi(dumbString);

        tempStudentNode = myStudentBST->search(tempID);
        myStudentBST->deleteNode(tempID);

        int tempAdvisorID = (tempStudentNode->data).getAdvisor();
        tempFacultyNode = myFacultyBST->search(tempAdvisorID);
        (tempFacultyNode->data).removeAdvisee(tempID);

        cout << "Student deleted!" << endl;
        cout << "\n";
    } else if (dumbInt == 9){
        cout << "ID: ";
        getline(cin, dumbString);
        int tempID = stoi(dumbString);
        cout << "Name: ";
        getline(cin, dumbString);
        string tempName = dumbString;
        cout << "Level: ";
        getline(cin, dumbString);
        string tempLevel = dumbString;
        cout << "Department: ";
        getline(cin, dumbString);
        string tempDepartment = dumbString;
        Faculty tempFaculty = Faculty(tempID, tempName, tempLevel, tempDepartment);
        BSTNode<Faculty>* newFaculty = new BSTNode<Faculty>;
        bool adviseeLoop = true;
        while (adviseeLoop == true){
          cout << "Advisee ID (#/Exit):";
          getline(cin, dumbString);
          if (dumbString == "EXIT" || dumbString == "Exit"){
            adviseeLoop = false;
          } else {
            int tempStudentID = stoi(dumbString);
            tempFaculty.addAdvisee(tempStudentID);

            tempStudentNode = myStudentBST->search(tempStudentID);
            int oldFacultyID = (tempStudentNode->data).getAdvisor();
            (tempStudentNode->data).changeAdvisor(tempID);

            tempFacultyNode = myFacultyBST->search(oldFacultyID);
            (tempFacultyNode->data).removeAdvisee(tempStudentID);
          }
        }
        newFaculty->setData(tempFaculty);
        myFacultyBST->insert(newFaculty);

        cout << "\n";
    } else if (dumbInt == 10){
        cout << "ID: ";
        getline(cin, dumbString);
        int tempID = stoi(dumbString);
        tempFacultyNode = myFacultyBST->search(tempID);
        lostStudents = (tempFacultyNode->data).getAdviseeList();
        myFacultyBST->deleteNode(tempID);
        cout << "Faculty deleted!" << endl;
        cout << "\n";
        lostStudentsBool = true;
    } else if (dumbInt == 11){
        cout << "ID: ";
        getline(cin, dumbString);
        int tempID = stoi(dumbString);
        cout << "New Faculty ID: ";
        getline(cin, dumbString);
        int tempFacultyID = stoi(dumbString);
        tempStudentNode = myStudentBST->search(tempID);
        int oldFacultyID = (tempStudentNode->data).getAdvisor();
        (tempStudentNode->data).changeAdvisor(tempFacultyID);
        cout << "Student Advisor Changed!" << endl;
        tempFacultyNode = myFacultyBST->search(tempFacultyID);
        (tempFacultyNode->data).addAdvisee(tempID);
        cout << "New Advissee added to new advisor!" << endl;
        cout << "\n";
    } else if (dumbInt == 12){
        cout << "Faculty ID: ";
        getline(cin, dumbString);
        int tempFacultyID = stoi(dumbString);
        cout << "Student ID: ";
        getline(cin, dumbString);
        int tempStudentID = stoi(dumbString);
        cout << "New Student Advisor ID: ";
        getline(cin, dumbString);
        int tempAdvisorID = stoi(dumbString);

        tempFacultyNode = myFacultyBST->search(tempFacultyID);
        (tempFacultyNode->data).removeAdvisee(tempStudentID);
        cout << "Advisee removed from faculty!" << endl;

        tempStudentNode = myStudentBST->search(tempStudentID);
        (tempStudentNode->data).changeAdvisor(tempAdvisorID);
        cout << "Student Advisor Changed!" << endl;
        cout << "\n";
    } else if (dumbInt == 13){
        rollBackBool = true;

        BSTPair* newTreePair = new BSTPair;
        BST<Student>* newStudentBST = new BST<Student>;
        BST<Faculty>* newFacultyBST = new BST<Faculty>;

        newTreePair = genRollBack->popTreePair();
        newStudentBST = newTreePair->getStudentBST();
        newFacultyBST = newTreePair->getFacultyBST();

        myStudentBST = newStudentBST;
        myFacultyBST = newFacultyBST;
    } else if (dumbInt == 14){
        rollBackBool = true;
        cout << "\n";
        cout << "Would you like to view the student or faculty Tree?: ";

        bool loopTest = true;
        getline(cin, dumbString);
        cout << "\n";

        if (dumbString == "student" || dumbString == "Student"){
          BSTNode<Student>* myTestNode = new BSTNode<Student>;
          myTestNode = myStudentBST->getRoot();

          while (loopTest == true){
            cout << "Curent Node: " << endl;
            (myTestNode->data).printStudent();
            cout << "\n";

            cout << "(1) Left" << endl;
            cout << "(2) Right" << endl;
            cout << "(3) Exit" << endl;
            cout << "(4) Create New Student" << endl;
            cout << "(5) Parent" << endl;
            cout << "\n";

            cout << "Answer: ";
            getline(cin, dumbString);
            cout << "\n";

            if (dumbString == "3"){
              loopTest = false;
            } else if (dumbString == "1"){
              if (myTestNode->left == NULL){
                cout << "NULL VALUE REACHED" << endl;
                //loopTest = false;
                cout << "\n";
              } else {
                myTestNode = myTestNode->left;
              }
            } else if (dumbString == "2"){
              if (myTestNode->right == NULL){
                cout << "NULL VALUE REACHED" << endl;
                //loopTest = false;
                cout << "\n";
              } else {
                myTestNode = myTestNode->right;
              }
            } else if (dumbString == "4"){
                cout << "\n";
                cout << "===========================" << endl;
                cout << "ID: ";
                getline(cin, dumbString);
                int tempID = stoi(dumbString);
                cout << "Name: ";
                getline(cin, dumbString);
                string tempName = dumbString;
                cout << "Level: ";
                getline(cin, dumbString);
                string tempLevel = dumbString;
                cout << "Major: ";
                getline(cin, dumbString);
                string tempMajor = dumbString;
                cout << "GPA: ";
                getline(cin, dumbString);
                double tempGPA = stod(dumbString);
                cout << "Advisor ID: ";
                getline(cin, dumbString);
                int tempAdvisorID = stoi(dumbString);
                cout << "===========================" << endl;
                cout << "\n";
                Student tempStudent = Student(tempID, tempName, tempLevel, tempMajor, tempGPA, tempAdvisorID);
                BSTNode<Student>* newStudent = new BSTNode<Student>;
                newStudent->setData(tempStudent);
                myStudentBST->insert(newStudent);
            } else if (dumbString == "5"){
              if (myTestNode->parent == NULL){
                cout << "NULL VALUE REACHED" << endl;
                cout << "\n";
              } else {
                myTestNode = myTestNode->parent;
              }
            }

          }
        }

        if (dumbString == "faculty" || dumbString == "Faculty"){
          BSTNode<Faculty>* myTestNode = new BSTNode<Faculty>;
          myTestNode = myFacultyBST->getRoot();

          while (loopTest == true){
            cout << "Curent Node: " << endl;
            (myTestNode->data).printFaculty();
            cout << "\n";

            cout << "(1) Left" << endl;
            cout << "(2) Right" << endl;
            cout << "(3) Exit" << endl;
            cout << "(4) Create New Faculty" << endl;
            cout << "(5) Parent" << endl;
            cout << "\n";

            cout << "Answer: ";
            getline(cin, dumbString);
            cout << "\n";

            if (dumbString == "3"){
              loopTest = false;
            } else if (dumbString == "1"){
              if (myTestNode->left == NULL){
                cout << "NULL VALUE REACHED" << endl;
                //loopTest = false;
                cout << "\n";
              } else {
                myTestNode = myTestNode->left;
              }
            } else if (dumbString == "2"){
              if (myTestNode->right == NULL){
                cout << "NULL VALUE REACHED" << endl;
                //loopTest = false;
                cout << "\n";
              } else {
                myTestNode = myTestNode->right;
              }
            } else if (dumbString == "4"){
                cout << "\n";
                cout << "===========================" << endl;
                cout << "ID: ";
                getline(cin, dumbString);
                int tempID = stoi(dumbString);
                cout << "Name: ";
                getline(cin, dumbString);
                string tempName = dumbString;
                cout << "Level: ";
                getline(cin, dumbString);
                string tempLevel = dumbString;
                cout << "Department: ";
                getline(cin, dumbString);
                string tempDepartment = dumbString;
                cout << "===========================" << endl;
                cout << "\n";
                Faculty tempFaculty = Faculty(tempID, tempName, tempLevel, tempDepartment);
                BSTNode<Faculty>* newFaculty = new BSTNode<Faculty>;
                newFaculty->setData(tempFaculty);
                myFacultyBST->insert(newFaculty);
            } else if (dumbString == "5"){
              if (myTestNode->parent == NULL){
                cout << "NULL VALUE REACHED" << endl;
                cout << "\n";
              } else {
                myTestNode = myTestNode->parent;
              }
            }
          }
        }
    } else if (dumbInt == 15){
        rollBackBool = true;
        mainMenu = false;
        tempStudentNode = myStudentBST->getRoot();
        tempFacultyNode = myFacultyBST->getRoot();
        cleanFile("studentTable.txt");
        cleanFile("facultyTable.txt");
        myStudentBST->writeOutStudentFile("studentTable.txt", tempStudentNode);
        myFacultyBST->writeOutFacultyFile("facultyTable.txt", tempFacultyNode);
    }

    if (lostStudentsBool == true){
      //gets the amount of students without advisors
      int amountOfLostStudents = lostStudents->getSize();
      //this loops through each student
      for (int i = 0; i < amountOfLostStudents; ++i){
        bool checkAdvisorBool = true;
        int lostID = lostStudents->getAtPos(i);
        tempStudentNode = myStudentBST->search(lostID);
        while (checkAdvisorBool == true){
          cout << "Enter new Advisor ID for Student " << lostID << " : ";
          getline(cin, dumbString);
          int newAdvisor = stoi(dumbString);
          tempFacultyNode = myFacultyBST->search(newAdvisor);
          if (tempFacultyNode != NULL){
            (tempFacultyNode->data).addAdvisee(lostID);
            checkAdvisorBool = false;
          } else {
            cout << "That advisor does not exist" << endl;
          }
        }
      }
    }

    if (rollBackBool == false){
      BSTPair* newTreePair = new BSTPair;
      BST<Student>* myCopyStudentBST = new BST<Student>;
      BST<Faculty>* myCopyFacultyBST = new BST<Faculty>;
      myCopyStudentBST = myStudentBST;
      myCopyFacultyBST = myFacultyBST;

      newTreePair->fillPair(myCopyStudentBST, myCopyFacultyBST);
      genRollBack->addTreePair(newTreePair);
    } else {
      rollBackBool = false;
    }

  }
  genRollBack->cleanRollBack();
}
