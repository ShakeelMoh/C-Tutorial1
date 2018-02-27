//.h file

#ifndef DATABASE_H
#define DATABASE_H

#include<vector>

using namespace std;

namespace STUDENT_NO{ //this should be my student number
   //Define method headers here
   
   //StudentRecord struct must be instantiated (like a student object)

   struct studentRecord{
      string studentNumber;
      string studentName;
      string studentSurname;
      string classRecord;
   };
   
  
   
   //create vector array
   extern vector<studentRecord>& studentRecords;
   
   void create_vector(vector<studentRecord>&);
   
   void add_student(string name, string surname, string studentNumber, string classRecord, vector<studentRecord>&); //adds to vector array
   
   string print_studentRecord(studentRecord sr);
   
   bool existing_student(string studentNumber, vector<studentRecord>); //checks if student already exists in vector
   
   void read_database(vector<studentRecord>&);   //reads vector array
   
   void save_database();   //pushes vector array to text file
   
   void display_student_data(vector<studentRecord>&);  //searches vector array for student details
   
   void grade_student(vector<studentRecord>&);   //searches vector array and calculates student average mark

}

//void clear(void);
#endif