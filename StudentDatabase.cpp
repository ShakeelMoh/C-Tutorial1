//.ccp file includes .h
//Implements functions

#include <iostream>
#include "StudentDatabase.h"
#include <cstdlib>
#include <fstream> //For reading/writing textfile
#include <sstream> //for seperating a string
#include <string> //for seperating string
#include <iomanip> //for using setw
//#include <vector> //vector data structure use


//instantiate the vector array with contents of text file

//std::vector<STUDENT_NO::studentRecord> studentRecords;

void STUDENT_NO::create_vector(vector<studentRecord>& studentRecords){ //define create vector method fills vector for read/write
     
   
   
   //read from textfile and fill vector
   //cout << "function createVector() called" << "\n\n";
   ifstream inFile;
   inFile.open("StudentDatabase.txt");

   if (!inFile){ //while next line
      cerr << "Unable to open file StudentDatabase.txt\n";
      
   }
  
   string number;
   string name;
   string surname;
   string classRecord;
   
   string temp; //stores temp first two lines we need to skip
   string temp2;
   studentRecord s; //declare the struct that we are going to use
   
   int count = 0; //counter to check line number
   
   //getline(inFile,  temp); //skip line
   //cout << "skipping line: " << temp;
   //getline(inFile,  temp2); //skip line #2
   
   while (inFile.peek() != EOF){ //line is student record
      
      count++;
      if (count > 2){
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
      } else {
         getline(inFile,  temp); //skip line
      }
      
      
      
      
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
   
   //STUDENT_NO::print_studentRecord(student); //print for confirmation purposes
   //we want to add the student to the vector here...
}

//Prints the entered details for confirmation
void STUDENT_NO::print_studentRecord(studentRecord sr){

   //cout << "Contains student with student number:" << sr.studentNumber << "\n\n"; 
   //return sr.studentNumber + "\t\t" + sr.studentName + "\t\t" + sr.studentSurname + "\t\t" + sr.classRecord;
   cout << std::left << std::setw(25) << sr.studentNumber << std::setw(25) << sr.studentName << std::setw(25) << sr.studentSurname << std::setw(25) << sr.classRecord << "\n";
   
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
      STUDENT_NO::print_studentRecord(sr[i]);
      
   }
   cout << "\n";

}


//going to write to a textfile
void STUDENT_NO::save_database(vector<studentRecord>& sr){

   cout << "function saveDatabase() called" << "\n";
   
   ofstream outFile;
   outFile.open("StudentDatabase.txt");

   if (!outFile){ 
      cerr << "Unable to open file StudentDatabase.txt\n";
      
   }
   
   outFile << std::left << std::setw(25) << "STUDENT NUMBER" << std::setw(25) << "NAME" << std::setw(25) << "SURNAME" << std::setw(25) << "GRADES";
   outFile << std::left << "-----------------------------------------------------------------------------------------\n";
   
   for(int i = 0; i < sr.size(); i++){
      outFile << std::setw(25) << sr[i].studentNumber << std::setw(25) << sr[i].studentName << std::setw(25) << sr[i].studentSurname << std::setw(25) << sr[i].classRecord << "\n";
   }
   
   outFile.close();

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

   cout << "function gradeStudent() called\n";

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
         cout << "Average: " << average << "\n\n";
         flag = true;
      }
      
   }
   
   if (!flag){
      cout << "Student cannot be found\n\n";
   }
   

}
