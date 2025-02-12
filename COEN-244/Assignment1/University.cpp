#include "Student.h"
#include "CourseSection.h"
#include "Professor.h"
#include "Room.h"
#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <array>

// Create objects within the university
void new_student();
void new_course();
Professor new_professor();
Room new_room();

int main()
{
    array<int, 4> room_id = {0,0,0,0}; //counter for room numbers per floor
    int stu_id = 0; //integers to generate ID's
    int course_id = 0;
    int prof_id = 0;
    vector<Student*> students;
    vector<pair<CourseSection*, array<Student*, 100>>> registration; //Holds all the CourseSection* pointers as well as registered students
    vector<pair<CourseSection*, Room*>> courseAssignment;
    vector<pair<Professor*, array<CourseSection*, 3>>> professorAssignment;

    // User interface section
    cout << "Welcome to the University!" << endl;
    while(true)
    {
        cout << "Select an option:" << endl
        << "1. Add a student\n"
        << "2. Add a course section\n"
        << "3. Add a professor\n"
        << "4. Add a room\n" 
        << "5. Register a student to a course section\n"
        << "6. Assign a room to a course section\n"
        << "7. Assign a course section to a professor\n"
        << "8. Return the list of students taking a particular course\n"
        << "9. Return the list of course taught by a give prof\n"
        << "10. Return the room where the course section takes place\n"
        << "11. Search if a given students is taking a given course\n"
        << "12. Search if a given prof is teaching a given courses\n"
        << "13. Exit\n"
        << "Enter integer from 1 to 13: ";
        int in;
        cin >> in;

        switch(in)
        {
            case 1: //new Student object, call constructor
            {
                Student* stu = new Student(stu_id++);
                students.push_back(stu);
                break;
            }
            case 2: //new CourseSection object
            {
                CourseSection* cs = new CourseSection(course_id++);
                pair<CourseSection*, array<Student*, 100>> init(cs, {}); //add course sections to the registration array             
                for(int i = 0; i < init.second.size(); i++)
                    init.second[i] = nullptr; //initialize all ellements in the array to nullptr
                registration.push_back(init);
                cout << endl;
                break;
            }
            case 3: //new Professor object
            {
                Professor* prof = new Professor(prof_id++);
                pair<Professor*, array<CourseSection*, 3>> profsection;
                professorAssignment.push_back(profsection);
                break;
            }
            case 4: //new Room object
            {
                Room* rm = new Room(room_id);
                pair<CourseSection*, Room*> assign(nullptr, rm); //add course sections to the courseAssignment array
                courseAssignment.push_back(assign);                   
                break;
            }
            case 5: //Register a student to a course section
            {
                //catch exceptions
                if(registration.size() == 0)
                {
                    cout << "Please add courses before calling this function";
                    break;
                }else if(students.size() == 0){
                    cout << "Please add students before calling this function";
                    break;
                }

                cout << "\nChoose a course to register for (enter corresponding number):\n";
                //loop to enumerate courses
                for(int i = 0; i < registration.size(); i++)
                {                     
                    cout << i+1 << ". " << registration[i].first->gettitle();
                    if(registration[i].second[99] != nullptr)
                        cout << " (Course is full)";
                    cout << endl;
                }
                cout << "0. Cancel operation" << endl;
                int select = -1;
                while(true) //loop until valid input
                {
                    cout << "Choice: ";
                    cin >> select;

                    //check for errors
                    if(cin.fail()) //input isn't integer
                    {
                        cin.clear();
                        cin.ignore(10000, '\n'); 
                        cout << "Invalid input, please enter an integer\n";
                        continue;
                    }
                    else if(select < 0 || select > registration.size()) //input is not one of the options
                    {
                        cout << "Invalid input, out of range\n";                   
                        continue;
                    }
                    else if(select != 0 && registration[select-1].second[99] != nullptr) //course is full
                    {
                        cout << "Course section is full, choose another course\n";
                        continue;
                    }
                    break; //no error, input is valid
                }

                if(select == 0)
                {
                    cout << "Exiting gracefully\n";
                    break;
                }else{ //course chosen
                    cout << "Registering a student for " << registration[select - 1].first->gettitle() << endl; 
                }//select - 1 to adjust for the choice format of index+1
 
                //prompt for student id
                while(true){ //loop until exit code or valid input
                    string regstu;
                    cout << "Enter student ID ('Exit' to exit, 'List' to list all students): ";               
                    cin >> regstu;
                    Student* stu = nullptr; 
                    //he input corresponds to a student
                    for(Student* elem:students)
                    {
                        if(regstu == elem->getid())
                            {
                                stu = elem; //found matching student id                              
                                break;
                            }
                    //exit code or correct value of student
                    }
                    if(regstu == "Exit"){
                        cout << "Exiting Gracefully\n";
                        break;
                    }else if(regstu == "List"){
                        cout << "\nList of all students (Name, Surname: 'ID'): \n";
                        for(Student* elem:students)
                        {
                            cout << elem->getname() << ", " << elem->getsurname() << ": " << elem->getid() << endl;
                        }
                        cout << endl;
                        continue;
                    }else if(stu == nullptr) //didn't find corresponding student
                    {
                        cout << "Invalid student id\n";
                        continue;
                    }else { //entered a valid student id
                        //check if the student is already taken the class
                        if(stu->istaken(registration[select-1].first))
                        {
                            cout << "Student is already taking this course\n" << endl;
                            break; //return to menu
                        }
                        for(int i = 0; i < 100; i++)
                        {
                            if(registration[select-1].second[i] == nullptr)
                            {
                                registration[select-1].second[i] = stu; //register student to course     
                                cout << "Successfully registered " << registration[select-1].second[i]->getname() 
                                << " " << registration[select-1].second[i]->getsurname() 
                                << " to " << registration[select-1].first->gettitle() << endl << "\n";
                                stu->addcourse(registration[select-1].first); //add the course in the student's courses
                                break; //exit for loop     
                            }
                        }
                        break; //exit while loop
                        
                    }
                }
                break; //exit the switch case
            }
            case 6: //Assign rooms to courses
            {
                //catch exceptions
                if(courseAssignment.size() == 0)
                {                    
                    cout << "Please add rooms before calling this function\n";
                    break;
                }
                else if(registration.size() == 0)
                {
                    cout << "Please add courses before calling this function\n";
                }
                bool assigned = false;
                //search for a course
                cout << "Choose a course to assign a room for:\n";
                //loop to enumerate courses
                for(int i = 0; i < registration.size(); i++)
                {                     
                    cout << i+1 << ". " << registration[i].first->gettitle() << endl;
                }
                cout << "0. Cancel operation" << endl;
                int select = -1;
                while(true) //loop until valid input
                {
                    cout << "Choose an option (enter integer): ";
                    cin >> select;

                    //check for errors
                    if(cin.fail()) //input isn't integer
                    {
                        cin.clear();
                        cin.ignore(10000, '\n'); 
                        cout << "Invalid input, please enter an integer\n";
                        continue;
                    }
                    else if(select < 0 || select > registration.size()) //input is not one of the options
                    {
                        cout << "Invalid input, out of range\n";                   
                        continue;
                    }
                    break; //no error, input is valid
                }

                if(select == 0)
                {
                    cout << "Exiting gracefully\n";
                    break;
                }else{ //course chosen
                    for(int i = 0; i < courseAssignment.size(); i++)
                    {//see if the course already has a room
                        if(registration[select-1].first->getid() == courseAssignment[i].first->getid())
                        {
                            cout << registration[select-1].first->gettitle() << " already assigned to room " << courseAssignment[i].second->getid() << endl;
                            assigned = true;
                            break;
                        }
                    }
                    if(assigned == true) //don't assign a second room to the course
                        break;
                    cout << "Assigning a room to " << registration[select - 1].first->gettitle() << endl; 
                }//select - 1 to adjust for the choice format of index+1

                //select a room

                string assign;                
                //prompt for room number
                while(true)
                { //loop until exit code or valid input 
                    cout << "Enter Room number ('Exit' to exit, 'List' to see all rooms): ";               
                    cin >> assign;
                    int check = 0; 
                    //the input corresponds to a room
                    for(int i = 0; i < courseAssignment.size(); i++)
                    {
                        if(assign == courseAssignment[i].second->getid())
                            {
                                if(courseAssignment[i].first == nullptr)
                                {
                                    courseAssignment[i].first = registration[select - 1].first; //found valid room number, assign course
                                    goto out; //leave the switch case
                                }
                                else
                                    cout << "Room already assigned to a course\n";
                                    check = 1;
                                break;
                            }
                    //exit code or existing room number
                    }
                    if(assign == "Exit"){
                        cout << "Exiting Gracefully\n"; //allows to reach the break
                        goto out; //leave the loop
                    }else if(assign == "List"){
                        cout << "List of all room numbers:\n";
                        for(int i = 0; i < courseAssignment.size(); i++)
                        {
                            cout << "-> " << courseAssignment[i].second->getid();
                            if(courseAssignment[i].first != nullptr) //if room already has a course assigned to it
                                cout << " (assigned to: " << courseAssignment[i].first->gettitle() << ")";
                            cout << endl;
                        }
                    }else if(check == 0) //didn't find any room with matching number
                    {
                        cout << "Invalid room number\n";
                        continue;
                    }   
                }
                out:
                    break;
            }
            case 7: //Assign profs to course sections
            {
                //catch errors
                if(professorAssignment.size() == 0)
                {
                    cout << "Please register professors before calling this function" << endl;
                    break;
                }
                else if(registration.size() == 0)
                {
                    cout << "Please add courses before calling this function" << endl;
                    break;
                }

                while(true)
                {                    
                    cout << "\nEnter the professor id ('Exit' to exit, 'List' to see all professors): ";
                    string in;
                    cin >> in;
                    Professor* buffer = nullptr;
                    int i = 0;
                    for (int i; i < professorAssignment.size(); i++)
                    {
                        if(in == professorAssignment[i].first->getid())
                        {
                            //found the right professor
                            buffer = professorAssignment[i].first;
                            break;
                        }
                    }
                    if(in == "Exit")
                    {
                        cout << "Exited gracefully" << endl;
                        break; //return to menu
                    }
                    else if(in == "List") //list all registered professors
                    {
                        cout << endl;
                        for(int j = 0; j < professorAssignment.size(); j++)
                        {
                            cout << "Name: " << professorAssignment[j].first->getname() << " " << professorAssignment[j].first->getsurname() 
                            << ", ID: " << professorAssignment[j].first->getid() << endl;
                        }
                        continue;
                    }
                    else if(buffer == nullptr) //invalid prof id
                    {
                        cout << "Invalid ID\n";
                        continue;
                    }
                    else//found a professor
                    {
                        cout << "Assigning a course to " << buffer->getname() << " " 
                        << buffer->getsurname() << endl;

                        cout << "Courses currently assigned: \n";
                        int check = 0;
                        array<CourseSection*, 3> temp; //save courses already taken
                        for(int j = 0; j < 3;j++)
                        {
                            if(professorAssignment[i].second[j] != nullptr)
                            {
                                cout << "\n- " << professorAssignment[i].second[j]->gettitle();
                                temp[j] = professorAssignment[i].second[j];
                                check = 1;
                            }
                                                      
                        }
                        if (check == 0)
                            cout << "No courses currently assigned";

                        cout << "\nChoose the course to assign (enter corresponding number):\n";
                        //loop to enumerate courses
                        for(int j = 0; j < registration.size(); j++)
                        {                     
                            cout << j+1 << ". " << registration[j].first->gettitle();
                        }
                        cout << "0. Cancel operation" << endl;
                        int select = -1;
                        while(true) //loop until valid input
                        {
                            cout << "Choice: ";
                            cin >> select;

                            //check for errors
                            if(cin.fail()) //input isn't integer
                            {
                                cin.clear();
                                cin.ignore(10000, '\n'); 
                                cout << "Invalid input, please enter an integer\n";
                                continue;
                            }
                            else if(select < 0 || select > registration.size()) //input is not one of the options
                            {
                                cout << "Invalid input, out of range\n";                   
                                continue;
                            }
                            else if(select != 0) //check if course is already assigned
                            {
                                for(int j = 0; j < 3; j++)
                                {
                                    if(registration[select-1].first == temp[j])
                                    {
                                        cout << "Already teching this course\n";
                                        goto exit;
                                    }else if(temp[j] == nullptr) //add course to array
                                        professorAssignment[i].second[j] = registration[select-1].first;
                                    cout << "Now teaching " << registration[select-1].first->gettitle() << endl;
                                    goto exit;
                                }
                                

                            }
                            else if(select == 0)
                            {
                                cout << "Exiting gracefully\n";
                                break;
                            }else{ //course chosen
                                cout << "Registering a student for " << registration[select - 1].first->gettitle() << endl; 
                            }//select - 1 to adjust for the choice format of index+1

                            break; //no error, input is valid
                        }

                        
                    }
                }
                exit:
                break;
            }
            case 8: //Return the list of students taking a particular course
            {
                //catch exceptions
                if(students.size() == 0)
                {                    
                    cout << "Please add students before calling this function\n";
                    break;
                }
                else if(registration.size() == 0)
                {
                    cout << "Please add courses before calling this function\n";
                }
                cout << "\nList students enlisted in which course (enter corresponding number):\n";
                //loop to enumerate courses
                for(int j = 0; j < registration.size(); j++)
                {                     
                    cout << j+1 << ". " << registration[j].first->gettitle();
                }
                cout << "0. Cancel operation" << endl;
                int select = -1;
                while(true) //loop until valid input
                {
                    cout << "Choice: ";
                    cin >> select;

                    //check for errors
                    if(cin.fail()) //input isn't integer
                    {
                        cin.clear();
                        cin.ignore(10000, '\n'); 
                        cout << "Invalid input, please enter an integer\n";
                        continue;
                    }
                    else if(select < 0 || select > registration.size()) //input is not one of the options
                    {
                        cout << "Invalid input, out of range\n";                   
                        continue;
                    }
                    else if(select == 0)
                    {
                        cout << "Exiting gracefully\n";
                        break;
                    }else{ //list all students in the course
                        cout << "\nStudents:\n";
                         for(int j = 0; j < 100; j++)
                         {
                            if(registration[select-1].second[j] != nullptr)
                                cout << "Name: " << registration[select-1].second[j]->getname() << " "
                                << registration[select-1].second[j]->getsurname() << ", ID: "
                                << registration[select-1].second[j]->getid() << endl;
                            else
                                break; //exit loop when lest student has been printed out
                         }
                    }//select - 1 to adjust for the choice format of index+1

                    break; 
                }
                break;
            }
            case 9: //Return the list of course taught by a give prof
            {
                //catch exceptions
                if(professorAssignment.size() == 0)
                {                    
                    cout << "Please add professors before calling this function\n";
                    break;
                }

                cout << "\nEnter the professor id ('Exit' to exit, 'List' to see all professors): ";
                string in;
                while(true){
                    cout << "Choice: ";
                    cin >> in;
                    int check = 0;
                    for (int i = 0; i < professorAssignment.size(); i++)
                    {
                        if(in == professorAssignment[i].first->getid())
                        {
                            cout << "Courses taught by " << professorAssignment[i].first->getname() <<
                            " " << professorAssignment[i].first->getsurname() << ":\n";
                            //found the right professor
                            for(int j = 0; j < 3; j++)
                            {
                                if(professorAssignment[i].second[j] != nullptr)
                                    cout << professorAssignment[i].second[j]->gettitle() << endl;
                                else if(j < 0)
                                    break; //break if all courses have been listed
                                else if(j == 0)
                                {
                                    cout << "No courses currently being taught\n";
                                    break;
                                }
                            }
                            check = 1;
                            break;
                        }
                    }
                    if(in == "Exit")
                    {
                        cout << "Exited gracefully" << endl;
                        break; //return to menu
                    }
                    else if(in == "List") //list all registered professors
                    {
                        cout << endl;
                        for(int j = 0; j < professorAssignment.size(); j++)
                        {
                            cout << "Name: " << professorAssignment[j].first->getname() << " " << professorAssignment[j].first->getsurname() 
                            << ", ID: " << professorAssignment[j].first->getid() << endl;
                        }
                        continue;
                    }
                    else if(check == 0) //invalid prof id
                    {
                        cout << "Invalid ID\n";
                        continue;
                    }
                    break;
                }
                break;
            }
            case 10: //Return the room where the course section takes place
            {
                //catch exceptions
                if(courseAssignment.size() == 0)
                {                    
                    cout << "Please add rooms before calling this function\n";
                    break;
                }
                else if(registration.size() == 0)
                {
                    cout << "Please add courses before calling this function\n";
                }
                cout << "\nWhich course (enter corresponding number):\n";
                //loop to enumerate courses
                for(int j = 0; j < registration.size(); j++)
                {                     
                    cout << j+1 << ". " << registration[j].first->gettitle();
                }
                cout << "0. Cancel operation" << endl;
                int select = -1;
                while(true) //loop until valid input
                {
                    cout << "Choice: ";
                    cin >> select;

                    //check for errors
                    if(cin.fail()) //input isn't integer
                    {
                        cin.clear();
                        cin.ignore(10000, '\n'); 
                        cout << "Invalid input, please enter an integer\n";
                        continue;
                    }
                    else if(select < 0 || select > registration.size()) //input is not one of the options
                    {
                        cout << "Invalid input, out of range\n";                   
                        continue;
                    }
                    else if(select == 0)
                    {
                        cout << "Exiting gracefully\n";
                        break;
                    }else{ //give room where the course is taught
                        for(int i = 0; i < courseAssignment.size(); i++)
                        {
                            if(courseAssignment[i].first != nullptr && courseAssignment[i].first->getid() == registration[select-1].first->getid())
                            {
                                cout << courseAssignment[i].first->gettitle() << " is taught in room " << courseAssignment[i].second->getid() << endl;
                                goto skip10; //exit loop
                            } 
                        }
                        cout << courseAssignment[select-1].first->gettitle() << " has no assigned room\n";
                    }
                    skip10:
                    break;
                }//select - 1 to adjust for the choice format of index+1

                break; 
                
            }
            case 11: //Search if a given students is taking a given course
            {
                //catch exceptions
                if(registration.size() == 0)
                {
                    cout << "Please add courses before calling this function";
                    break;
                }else if(students.size() == 0){
                    cout << "Please add students before calling this function";
                    break;
                }

                cout << "\nChoose a course (enter corresponding number):\n";
                //loop to enumerate courses
                for(int i = 0; i < registration.size(); i++)
                {                     
                    cout << i+1 << ". " << registration[i].first->gettitle();
                    cout << endl;
                }
                cout << "0. Cancel operation" << endl;
                int select = -1;
                while(true) //loop until valid input
                {
                    cout << "Choice: ";
                    cin >> select;

                    //check for errors
                    if(cin.fail()) //input isn't integer
                    {
                        cin.clear();
                        cin.ignore(10000, '\n'); 
                        cout << "Invalid input, please enter an integer\n";
                        continue;
                    }
                    else if(select < 0 || select > registration.size()) //input is not one of the options
                    {
                        cout << "Invalid input, out of range\n";                   
                        continue;
                    }
                    break; //no error, input is valid
                }

                //valid input
                if(select == 0)
                {
                    cout << "Exiting gracefully\n";
                    break;
                }else{ //course chosen
                    cout << "Enter the student id: ";
                    string in11;
                    cin >> in11;
                    bool check = false;
                    for(Student* elem : students)
                    {
                        if(in11 == elem->getid())
                        {
                            check = true; //student exists
                            break;
                        }
                    }
                    if(check == false)
                    {
                        cout << "Invalid student id\n";
                        break;
                    }
                    for(Student* elem : registration[select-1].second)
                    {
                        if(elem == nullptr)
                        {
                            break; //error handling
                        }
                        else if(elem->getid() == in11)
                        {
                            cout << "Student is registered for " << registration[select-1].first->gettitle() << endl;
                            goto exit11;
                        }
                    }
                    cout << "Student is not registered for " << registration[select-1].first->gettitle() << endl;
                    break;
                }
                exit11: 
                break;
            }
            case 12: //Search if a given prof is teaching a given courses
            {
                //catch errors
                if(professorAssignment.size() == 0)
                {
                    cout << "Please register professors before calling this function" << endl;
                    break;
                }
                else if(registration.size() == 0)
                {
                    cout << "Please add courses before calling this function" << endl;
                    break;
                }
                
                cout << "\nEnter the professor id: ";
                string in;
                cin >> in;
                Professor* buffer = nullptr;
                int i = 0;
                for (int i; i < professorAssignment.size(); i++)
                {
                    if(in == professorAssignment[i].first->getid())
                    {
                        //found the right professor
                        buffer = professorAssignment[i].first;
                        cout << "Courses assigned: ";
                        bool check = false;
                        for(int j = 0; j < 3;j++)
                        {
                            if(professorAssignment[i].second[j] != nullptr)
                            {
                                cout << "\n- " << professorAssignment[i].second[j]->gettitle();
                                check = true;
                            }
                            else
                                break;
                                                      
                        }
                        if (check == false)
                        {
                            cout << "\nNo courses assigned\n";
                        }
                        break; //exit for loop
                    }
                }                
                if(buffer == nullptr) //invalid prof id
                {
                    cout << "Invalid ID\n";
                }
                break;
            }
            case 13: //Exit program
            {
                //destructor
                for(int i = 0; i < students.size(); i++)
                {
                    delete students[i];
                }

                for(int i = 0; i < registration.size(); i++)
                {
                    delete registration[i].first; //courses
                }

                for(int i = 0; i < courseAssignment.size(); i++)
                {
                    delete courseAssignment[i].second; //rooms
                }

                for(int i = 0; i < professorAssignment.size(); i++)
                {
                    delete professorAssignment[i].first;
                }
                cout << "Goodbye!";
                return 0; //exit program
            }
            default:
            {
                cout << "Invalid input\n";
                break;
            }
        }
    }

}

