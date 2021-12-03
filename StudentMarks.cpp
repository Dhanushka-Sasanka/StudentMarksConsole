
#include <iostream>
#include <time.h>
#include <iomanip>
#include <cstdlib>
using namespace std;

#define STUDENT_COUNT 10
#define SUBJECT_COUNT 6
int student[STUDENT_COUNT];
int subject[SUBJECT_COUNT];
int mark[STUDENT_COUNT][SUBJECT_COUNT];

string intro =
    R"(
===========================================================================
****** Console Log Program. Please Enter Relevant Number to Proceed *******
===========================================================================
)";

    void menu(){
        cout << "==================================================" << endl;
        cout << "|                 OPERATIONS                      |" << endl;
        cout << "==================================================" << endl;
        cout << "1.  FILL DATA" << endl;
        cout << "2.  PRINT All DATA" << endl;
        cout << "3.  PRINT TOTAL" << endl;
        cout << "4.  RAND ONE IN CLASS" << endl;
        cout << "5.  AVERAGE MARKS FOR A SUBJECT" << endl;
        cout << "6.  EDIT MARKS FOR SPECIFIED SUBJECT OF A STUDENT" << endl;
        cout << "7.  RESET DATA" << endl;
        cout << "8.  CLEAR ALL MARK SHEET" << endl;
        cout << "PRESS 0 to SYSTEM EXIT."<< endl<< endl;
    }

    void fillData(){

        for (int i = 0; i < STUDENT_COUNT; i++){
            student[i] = 1000+i;
        }

        for (int i = 0; i < SUBJECT_COUNT; i++){
            subject[i] = 500+(i*2);
        }

        for (int i = 0; i < STUDENT_COUNT; i++){
                for (int j = 0; j < SUBJECT_COUNT; j++){
                        int midMarks = rand()%41;
                        int finalMarks = rand()%61;
                        int magicMarks = rand()%6;
                        int totalMarks = midMarks+finalMarks+magicMarks;

                        if(totalMarks>=100){
                            totalMarks=midMarks+finalMarks;
                            }
                        mark[i][j] = totalMarks;
                }
        }
        cout << "\nData Filled Successfully..!" << endl<< endl<< endl;
    }

    void printAllData(){
        cout << endl<< endl;

        int total=0;

        if (student[0]==0){

            cout << "Invalid User Input..!! Please Fill Data First "<<endl <<endl;
        }else{
        for(int a=0; a<SUBJECT_COUNT;a++){
            cout<<right<<setw(10)<<subject[a];
        }
        cout<<endl<<endl;
        for(int i=0; i<STUDENT_COUNT;i++){

            cout<<student[i]<<"    ";
            for(int j=0; j<SUBJECT_COUNT;j++){

                 cout<<left<<setw(10)<<mark[i][j];
            }
            cout<<endl;
        }
    }
    cout<<endl <<endl;
    }

    void totalMarkAllStudent(){

        if (mark[0][0]==0){
            cout << endl<< endl;
            cout << "Invalid User Input..!! Please Fill Data First "<<endl <<endl;
        }else{
        int marks=0;
        for (int i = 0; i < STUDENT_COUNT; i++){
            for (int j = 0; j < SUBJECT_COUNT; j++){
                marks+= mark[i][j];
            }
        }
        cout << endl<< endl;
        cout<<"Total Marks of All Students : " <<marks<< endl;
        cout << endl<< endl;
    }
    }


    int findStudentIdIndex(int studentId){
        int studentIndex =-1;
        for (int i = 0; i < STUDENT_COUNT; i++){
             if(studentId==student[i]){
                studentIndex =i;
                break;
             }
        }
        return studentIndex;
    }



    void totalMarkGivenStudent(int studentId){
        int studentIndex = findStudentIdIndex(studentId);
        int marks=0;

        if (student[0]==0){
            cout << endl<< endl;
            cout << "Invalid User Input..!! Please Fill Data First "<<endl <<endl;
        }else if(studentIndex==-1){
            cout << endl<< endl;
            cout<<"Invalid Student Id..!!"<< endl;
            cout << endl<< endl;
        }else{
            for (int i = 0; i < SUBJECT_COUNT; i++){
                marks+= mark[studentIndex][i];
            }
            cout << endl<< endl;
            cout<<"Total Marks of Student Id, "<<studentId<<" : " <<marks<< endl;
            cout << endl<< endl;
        }
    }

    void rank1(){
        int marks=0,maxMark=0;
        int rank_1_Index=0;

         if (mark[0][0]==0){
            cout << "Invalid User Input..!! Please Fill Data First "<<endl <<endl;
        }else{
        for (int i = 0; i < STUDENT_COUNT; i++){
            marks=0;
            for (int j = 0; j < SUBJECT_COUNT; j++){
                marks+= mark[i][j];
            }
            if(maxMark<marks){
                maxMark = marks;
                rank_1_Index=i;
            }
        }
        cout << endl<< endl;
        cout<<"Student Id of Rank 01 in class : " <<student[rank_1_Index]<< endl;
        cout << endl<< endl;
        }
    }

    int findSubjectIdIndex(int subjectId){
        int subjectIndex =-1;
        for (int i = 0; i < SUBJECT_COUNT; i++){
             if(subjectId==subject[i]){
                subjectIndex =i;
                break;
             }
        }

        return subjectIndex;
    }

    void averageMarkGivenSubject(int subjectId){
        int subjectIndex = findSubjectIdIndex(subjectId);
        double marks=0;

        if (subject[0]==0){
            cout << endl<< endl;
            cout << "Invalid User Input..!! Please Fill Data First "<<endl <<endl;
        }else if(subjectIndex==-1){

            cout << endl<< endl;
            cout<<"Invalid Subject Id..!!"<< endl;
            cout << endl<< endl;
        }else{
            for (int i = 0; i < STUDENT_COUNT; i++){
                marks+= mark[i][subjectIndex];
            }
            marks=marks/STUDENT_COUNT;
            cout << endl<< endl;
            cout<<"Average Marks of Subject ID, "<<subjectId<<" : " <<marks<< endl;
            cout << endl<< endl;
        }
    }

    void EditIndividualMarks(int studentId ,int subjectId){
        int studentIndex = findStudentIdIndex(studentId);
        int subjectIndex = findSubjectIdIndex(subjectId);

         if (student[0]==0||subject[0]==0){
                cout << endl<< endl;
            cout << "Invalid User Input..!! Please Fill Data First "<<endl <<endl;
        }else if(studentIndex==-1 && subjectIndex==-1){
            cout << endl<< endl;
            cout<<"Invalid Student ID and Subject ID..!!"<< endl;
            cout << endl<< endl;
        }
        else if(studentIndex==-1){
            cout << endl<< endl;
            cout<<"Invalid Student ID..!!"<< endl;
            cout << endl<< endl;
        }else if( subjectIndex==-1){
            cout << endl<< endl;
            cout<<"Invalid Subject ID..!!"<< endl;
            cout << endl<< endl;
        }

        else{
            int marks=0;
            cout << "Enter New marks : ";
            cin >> marks;
            if(marks>=100){
                cout << "Invalid Input..!! Marks should be less than 100"<<endl<<endl;
            }else{
            mark[studentIndex][subjectIndex]=marks;
            cout << "Marks Edited Successfully..!!"<<endl<<endl;
            }
        }
    }

    void resetGivenSubjectMarks(int subjectId){
        int subjectIndex = findSubjectIdIndex(subjectId);
        int marks=0;

        if (subject[0]==0){
            cout << endl<< endl;
            cout << "Invalid User Input..!! Data Not Found to Reset "<<endl <<endl;
        }else if(subjectIndex==-1){
            cout << endl<< endl;
            cout<<"Invalid Subject Id..!!"<< endl;
            cout << endl<< endl;
        }else{
            for (int i = 0; i < STUDENT_COUNT; i++){
               mark[i][subjectIndex]=0;
            }
            cout << endl<< endl;
            cout<<"Marks of Subject ID, "<<subjectId << " is Reseted Successfully..!!"<< endl;
            cout << endl<< endl;
        }
    }


    void resetGivenStudentMarks(int studentId){
        int studentIndex = findStudentIdIndex(studentId);
        int marks=0;

        if (student[0]==0){
            cout << endl<< endl;
            cout << "Invalid User Input..!! Data Not Found to Reset "<<endl <<endl;
        }else if(studentIndex==-1){
            cout << endl<< endl;
            cout<<"Invalid Student Id..!!"<< endl;
            cout << endl<< endl;
        }else{
            for (int i = 0; i < SUBJECT_COUNT; i++){
                mark[studentIndex][i]=0;
            }
            cout << endl<< endl;
            cout<<"Marks of Student ID, "<<studentId <<" is Reseted Successfully..!!"<< endl;
            cout << endl<< endl;
        }
    }

    void resetAllMarks(){
        for (int i = 0; i < STUDENT_COUNT; i++){
            for (int j = 0; j < SUBJECT_COUNT; j++){
                mark[i][j]=0;
            }
        }
        cout << endl<< endl;
        cout<<"All Marks Reseted Successfully..!!"<< endl<<endl;
    }


int main()
{
    srand(time(0));
    bool loop =true;
	int userInput;
    int studentId=-1,subjectId=-1;
     cout<<intro<<endl;
	do{
        menu();
        cout << "Select : ";
        cin>>userInput;
        switch(userInput){
        case 0:
            loop =false;
            break;
        case 1:
            fillData();
            break;
        case 2:
            printAllData();
            break;
        case 3:
           cout <<right<<setw(9)<<" "<< "1.  Total marks of all students" << endl;
           cout <<right<<setw(9)<<" "<< "2.  Total marks of a given student" << endl<<endl;
           cout << "Select : ";
           cin>>userInput;
           if(userInput==1){
            totalMarkAllStudent() ;
           }else if(userInput==2){
           cout << "Enter Student Id : ";
            cin >> studentId;
            totalMarkGivenStudent(studentId) ;
           }else{
           cout << endl<< endl;
            cout << "Invalid Input..!!" << endl<< endl;
           }
            break;
        case 4:
            rank1() ;
            break;
        case 5:
              cout << "Enter Subject ID : ";
            cin >> subjectId;
            averageMarkGivenSubject(subjectId);
            break;
        case 6:
            cout << "Enter Student Id : ";
            cin >> studentId;
            cout << "Enter Subject Id : ";
            cin >> subjectId;
            EditIndividualMarks(studentId,subjectId);
            break;
        case 7:
           cout<<right<<setw(9)<<" "<< "1.  Reset Marks for a Subject" << endl;
           cout<<right<<setw(9)<<" "<< "2.  Reset Marks for a Student" << endl;
           cout<<right<<setw(9)<<" "<< "3.  Reset All Data" << endl;
           cout << endl;
           cout<< "Select : ";
           cin>>userInput;
           if(userInput==1){
            cout<<"Enter Subject Id : ";
            cin >> subjectId;
            resetGivenSubjectMarks(subjectId) ;
           }else if(userInput==2){
           cout << "Enter Student Id : ";
            cin >> studentId;
            resetGivenStudentMarks(studentId);
           }else if(userInput==3){
               resetAllMarks() ;
           }else{
           cout << endl<< endl;
           cout << "Invalid Input..!!" << endl<< endl;
           }
            break;
        case 8:
            system("cls") ;
            break;

        default:
            cout << endl<< endl;
            cout << "Invalid Input..!!" << endl<< endl;
        }
	}while(loop);

    return 0;
}
