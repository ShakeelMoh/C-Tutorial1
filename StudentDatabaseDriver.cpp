#include <iostream>   //a system header file - needed to do simple I/O
#include "StudentDatabase.h"	         // our header file - contains decl of fib()
#include <cstdlib> //for clearing console


using namespace std;  

int main (void)
{
      
      
      //we need to create the vector for use later
      vector<MHMSHA056::studentRecord> sr;
      MHMSHA056::create_vector(sr);//must recreate vector because of changes that couldve occured
      //MHMSHA056::create_vector(sr);
      
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
               
               if (MHMSHA056::existing_student(number, sr)){
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
        
            
            
            MHMSHA056::add_student(name, surname, number, record, sr);
            selection.clear();
         } else if (selection == "2"){
            MHMSHA056::read_database(sr);
         }else if (selection == "3"){
            MHMSHA056::save_database(sr);
         }else if (selection == "4"){
            MHMSHA056::display_student_data(sr);
         }else if (selection == "5"){
            MHMSHA056::grade_student(sr);
         }
   	
      
        if (selection == "q"){
               break;
            }
         }
        return 0; // always return a value to calling system
}
