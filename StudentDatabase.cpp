//.ccp file includes .h
//Implements functions

#include <iostream>
#include "StudentDatabase.h"
#include <cstdlib>
#include <fstream> //For reading textfile
#include <sstream> //for seperating a string
#include <string> //for seperating string
//#include <vector> //vector data structure use


//instantiate the vector array with contents of text file

//std::vector<STUDENT_NO::studentRecord> studentRecords;

void STUDENT_NO::create_vector(vector<studentRecord>& studentRecords){ //define create vector method fills vector for read/write
     
   
   
   //read from textfile and fill vector
   cout << "function createVector() called" << "\n\n";
   ifstream inFile;
   inFile.open("StudentDatabase.txt");

   if (!inFile){ //while next line
      cerr << "Unable to open file StudentDatabase.txt\n";
      
   }
  
   string number;
   string name;
   string surname;
   string classRecord;
   
   studentRecord s; //declare the struct that we are going to use
      
   while (inFile.peek() != EOF){ //line is student record
      
      //cout << line << endl; //prints the line
      inFile >> number >> name >> surname;
      getline(inFile,classRecord); //gets rest of line
      s.studentNumber = number;
      s.studentName = name;
      s.studentSurname = surname;
      s.classRecord = classRecord;
      //print_studentRecord(s); //print for confirmation purposes
      //cout << "adding to vector..\n\n";
      studentRecords.push_back(s); //adds student to vector
      
      
   }
   //cout << studentRecords.size();
   inFile.close();

}

//create new student
void STUDENT_NO::add_student(std::string name, string surname, string studentNumber, string classRecord, vector<studentRecord>& sr){

   cout << "\nfunction addStudent() called" << "\n";
   studentRecord student;  //add an instance of the studentRecord struct
   
   student.studentNumber = studentNumber;
   student.studentName = name;
   student.studentSurname = surname;
   student.classRecord = classRecord;
   
   sr.push_back(student);
   
   STUDENT_NO::print_studentRecord(student); //print for confirmation purposes
   //we want to add the student to the vector here...
}

//Prints the entered details for confirmation
string STUDENT_NO::print_studentRecord(studentRecord sr){

   //cout << "Contains student with student number:" << sr.studentNumber << "\n\n"; 
   return sr.studentNumber + " " + sr.studentName + " " + sr.studentSurname + " " + sr.classRecord;
   
}


//check if student exists
bool STUDENT_NO::existing_student(std::string studentNumber, vector<studentRecord> sr){

   cout << "\nChecking for existing student..." << "\n";
   
   for (int i = 0; i < sr.size();i++){
      if (sr[i].studentNumber == studentNumber){
         cout <<"Student already exists" << "\n";
         return true;
      }
   }
   cout << "Creating new student record for: " << studentNumber << "\n";
   return false;
}



void STUDENT_NO::read_database(vector<studentRecord>& sr){
//vector should be filled with textfile data now
//Print the contents of the vector
   //vector<studentRecord> studentRecords;
   cout << "\n";
   cout << "\nfunction readDatabase() called" << "\n";
   for (int i=0; i< sr.size();i++){
      
      cout << STUDENT_NO::print_studentRecord(sr[i]) + "\n";
      
   }
   cout << "\n";

}


//going to write to a textfile
void STUDENT_NO::save_database(){

   cout << "function saveDatabase() called" << "\n";

}



void STUDENT_NO::display_student_data(vector<studentRecord>& sr){

   cout << "function displayStudentData() called" << "\n\n";
   
   string studentNumber; //declare student number variable
   
   cout << "Please enter a student number\n";
   
   cin >> studentNumber;
   cout << "\n";
   
   bool flag = false;
   
   for (int i=0; i< sr.size();i++){
      
      if(sr[i].studentNumber == studentNumber){
         cout << "Record for student with student number: " << studentNumber << "\n";
         cout << "Name: " << sr[i].studentName << "\n";
         cout << "Surname: " << sr[i].studentSurname << "\n";
         cout << "Grades: " << sr[i].classRecord << "\n\n";
         flag = true;
      }
      
   }
   
   if (!flag){
      cout << "Student cannot be found\n\n";
   }
   
   
}



void STUDENT_NO::grade_student(vector<studentRecord>& sr){

   cout << "function gradeStudent() called" << "\n";

   string studentNumber; //declare student number variable
   
   cout << "Please enter a student number\n";
   
   cin >> studentNumber;
   cout << "\n";
   
   bool flag = false;
   
   for (int i=0; i< sr.size();i++){
      
      if(sr[i].studentNumber == studentNumber){
         cout << "Average for student with student number " << studentNumber << ":\n";
         cout << "Grades: " << sr[i].classRecord << "\n\n";
         
         string values;
         int total = 0;
         int noValues = 0;
         int value;
         
         values = sr[i].classRecord;
         
         istringstream iss(values);
         
         while (iss >> value){ //while we have a value to process..
            
            total = total + value;
            noValues +=1;
            //cout << total;
            
         } 
         
         float average = total/noValues;
         cout << "Average: " << average << "\n";
         flag = true;
      }
      
   }
   
   if (!flag){
      cout << "Student cannot be found\n\n";
   }
   

}
