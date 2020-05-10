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

    BSTNode<X>* search(BSTNode<X>* test, int key){
      if (root == NULL || root->key == key){
        return root;
      }

      if (root->key < key){
        return search(root->right, key);
      }

      return search (root->left, key);
    }
    };




    ///////////////////////////   OLD DRIVER CODE ////////////////////////////////////

    BST<Student>* myBST = new BST<Student>;
    BSTNode<Student>* myFirstNode = new BSTNode<Student>;
    BSTNode<Student>* mySecondNode = new BSTNode<Student>;
    BSTNode<Student>* myThirdNode = new BSTNode<Student>;
    BSTNode<Student>* myFourthNode = new BSTNode<Student>;

    Student kyle = Student(10, "Kyle", "Freshman", "Biology", 4.0, 2);
    Student jacob = Student(4, "Jacob", "Senior", "CS", 3.8, 7);
    Student howard = Student(20, "Howard", "Senior", "Film", 2.5, 7);
    Student daniel = Student(15, "Daniel", "Junior", "English", 3.5, 6);
    myFirstNode->setData(kyle);
    mySecondNode->setData(jacob);
    myThirdNode->setData(howard);
    myFourthNode->setData(daniel);

    myBST->insert(myFirstNode);
    myBST->insert(mySecondNode);
    myBST->insert(myThirdNode);
    myBST->insert(myFourthNode);
    myBST->deleteNode(10);


    bool loopTest = true;
    string dumbString = "";

    BSTNode<Student>* myTestNode = new BSTNode<Student>;
    myTestNode = myBST->getRoot();

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
        myBST->insert(newStudent);
      } else if (dumbString == "5"){
        if (myTestNode->parent == NULL){
          cout << "NULL VALUE REACHED" << endl;
          cout << "\n";
        } else {
          myTestNode = myTestNode->parent;
        }
      }

    }

    Faculty tempFaculty = Faculty(tempID, tempName, tempLevel, tempDepartment);



    //Lets create the faculty tree
    BST<Faculty>* myFacultyBST = new BST<Faculty>;
    ifstream facultyTreeInfo("facultyTable.txt");

    //creates temp linked list to hold advisee ints
    //DoublyLinkedList<int> tempAdvisees;;

    string tempDepartment = "NULL";
    string facultyLine;
    //bool hasAdvisees = false;
    int studentAdvisees [100];
    int adviseeCount = -1;

    while(getline(facultyTreeInfo, facultyLine)){
      if(facultyLine == "X\r"){
        lineCount = 2;
        cout << "1) Start making a faculty" << endl;
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
      else if (facultyLine == "Y\r"){
        //creates faculty object
        Faculty tempFaculty = Faculty(tempID, tempName, tempLevel, tempDepartment);

        //iterate through array and put values into faculty then resets array
        for (int i = 0; i < adviseeCount + 1; i++){
          tempFaculty.addAdvisee(studentAdvisees[i]);
          studentAdvisees[i] = 0;
        }

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
        adviseeCount++;
        int tempAdviseeID = stoi(facultyLine);
        cout << "Student Advisee Found: " << tempAdviseeID << endl;
        studentAdvisees[adviseeCount] = tempAdviseeID;
      }
    }


    //////////////////////////////////////////////////////TEMP DRIVER CODE//////////////////////////////////////////////////////////////
    cout << "\n";
    cout << "Would you like to view the student or faculty Tree?: ";

    bool loopTest = true;
    string dumbString = "";
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
