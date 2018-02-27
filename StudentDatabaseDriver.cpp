#include <iostream>   //a system header file - needed to do simple I/O
#include "StudentDatabase.h"	         // our header file - contains decl of fib()
#include <cstdlib> //for clearing console


using namespace std;  

int main (void)
{
      
      
      //we need to create the vector for use later
      vector<STUDENT_NO::studentRecord> sr;
      
      STUDENT_NO::create_vector(sr);
      
      string selection;
      for (;;){
      
         cout << "1: Add student\n";
         cout << "2: Read database\n";
         cout << "3: Save Database\n";
         cout << "4: Display given student data\n";
         cout << "5: Grade Student\n";
         cout << "q: Quit\n";
   
         cout << "\nEnter a number (or q to quit) and press return...\n";
         cin >> selection;
         
       
         if (selection == "1"){
            string name;
            string surname;
            string number;
            string record;
            
            bool flag = true;
            
            while (flag){
               cout << "\nEnter student number" << endl;
               cin >> number;
               
               if (STUDENT_NO::existing_student(number, sr)){
               } else {
                  flag = false;
               }
            }
            
            
            cout << "\nEnter student name" << endl;
            cin >> name;
            cout << "\nEnter student surname" << endl;
            cin >> surname;
            cout << "\nEnter student class record" << endl;
            cin.ignore(256, '\n');
            getline(cin, record);
        
            
            
            STUDENT_NO::add_student(name, surname, number, record, sr);
            selection.clear();
         } else if (selection == "2"){
            STUDENT_NO::read_database(sr);
         }else if (selection == "3"){
            STUDENT_NO::save_database();
         }else if (selection == "4"){
            STUDENT_NO::display_student_data(sr);
         }else if (selection == "5"){
            STUDENT_NO::grade_student(sr);
         }
   	
      
        if (selection == "q"){
               break;
            }
         }
        return 0; // always return a value to calling system
}
