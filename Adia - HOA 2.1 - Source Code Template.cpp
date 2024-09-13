#include <iostream>
#include <string.h>
using namespace std;
  
class Student{
  private:
  string studentName; 
  int studentAge;
  
  public:
  //constructor
  Student(string newName ="John Doe", int newAge=18){ 
    studentName = move(newName);
    studentAge = newAge;
    cout << "Constructor Called." << endl;
  };

  //deconstructor
  ~Student(){
    cout << "Deconstructor Called." << endl;
  }
  
  //Copy Constructor
  Student(const Student &copyStudent){
    cout << "Copy Constructor Called" << endl; 
    studentName = copyStudent.studentName;
    studentAge = copyStudent.studentAge;
  }
  
  //Display Attributes void printDetails(){
  void printDetails(){
    cout << this->studentName << " " << this->studentAge << endl;
  }
};
    

int main() {
  
  const size_t j = 5;
  Student studentList[j] = {};
  string namesList[j] = {"Carly", "Freddy", "Sam", "Zack", "Cody"}; 
  int ageList[j] = {15, 16, 18, 19, 16};
  for(int i = 0; i < j; i++){ //loop A
    Student *ptr = new Student(namesList[i], ageList[i]); studentList[i] = *ptr;
  }
  for(int i = 0; i < j; i++){ //loop B 
    studentList[i].printDetails();
  }

return 0;
}

