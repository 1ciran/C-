/*Question no.1- program to illustratenthe wroking of oject and class in c++ programming
*/
#include <iostream>
using namespace std;

class Room {
    public:

    double length;
    double breath;
    double height;

    double calculateArea(){
        return length * breath;

    }

    double calculateVolume(){
        return length * breath * height;

    }
};
int main(){
    Room room1;
    room1.breath = 19.2;
    room1.height = 19.2;
    room1.length = 42.5;


    cout << " area of room " << room1.calculateArea() << endl;;
    cout << " volume of room " << room1.calculateVolume() << endl;

    return 0;
}

/* Question no.1- program to demonstrate the working of public and private in c++ class
*/

#include <iostream>
using namespace std;

class Room {
    private:
    double length;
    double breadth;
    double height;

    public:

        void initData( double len, double brth, double hgt)
        {
            length = len;
            breadth = brth;
            height = hgt;

        }

        double calculateArea(){
            return length * breadth;
        }

        double calculateVolume(){
            return length * breadth * height;
        }
};

int main(){
    Room room2;
   room2.initData(42.5, 30.8, 19.2);

    cout << " area of room " << room2.calculateArea() << endl;
    cout << " volume of room" << room2.calculateVolume() << endl;

    return 0;
}

/* Question no.3- write a program to create a class named employee_ info with data member 
emp_id and Emp_name. create another class name finance_info from Employee_info
with data member Bas_sal and Ot_sal. Create an independent class extra_allowances
with data member Tray_All, House_All and Dail_All. Now, derive another class
name Total_info from Finance_info and Extra_allowances with data member Tot_sal.
make necessary function for the above and show the gross salary. */


#include <iostream>
using namespace std;

class Employee_info {
    public:
        int emp_id;
        string name;

};

class Finance_info : public Employee_info{
    public:
    double Bas_sal;
    double ot_sal;
};

class Extra_allowances{
    public:
     double tray_all;
     double house_all;
     double  dail_all;
};


class Total_info : public Finance_info, public Extra_allowances{
      double tot_sal;
    public:
    
      
    int gross_salary()
    {
        tot_sal = Bas_sal + ot_sal + tray_all + house_all + dail_all;
        return tot_sal;
    }
    
};

int main(){
    Total_info t;
    t.emp_id = 11;
    t.name = "kiran";
    t.Bas_sal = 400;
    t.ot_sal = 500;
    t.tray_all = 500;
    t.dail_all = 600;
    t.house_all = 500;
    
    cout << " employee id : " << t.emp_id << endl;
    cout << "employee name : " << t.name << endl; 
    cout << " gross salary is " << t.gross_salary() << endl;
    

    return 0;
}

/* Question no.4 write a program using class to add two object of class name Time , passing object as 
argument. the time class contain hours, minute and seconds as its private members.
construct appropriate member functions input should be interactive */


#include <iostream>
using namespace std;

class Time{
    private:
        int hour, minute, seconds;
    
    public:
    Time getinput( int a , int b, int c)
        {   Time t;
            t.hour = a;
            t.minute = b;
            t.seconds = c;
            return t;
        }
        // in this function we pass object as argument
        void output(Time t){
            cout << t.hour << " hours " <<endl;
            cout << t.minute << " mins "<< endl;
            cout << t.seconds << " sec " << endl;
        }
};



int main(){
    int x, y, z;
    cout << " enter  hour " <<  endl;
    cin >> x;
    cout << "enter  minute " << endl;
    cin >> y;
    cout << " enter seconds " << endl;
    cin >> z;
    Time time;
    time = time.getinput( x , y , z);
    time.output(time);

    return 0;

}

/* Question no.5 - write a program to create a class Emp with data member (Id, Name, Address)
drive a class Salary with data member (basicsal, post) and again derive
class Record with data member(month , absent, total) and display employ
complete information where total is calculate by deducing total
"absent" days from basicsal */

#include <iostream>
using namespace std;

class Emp
{
public:
  int id;
  string Name, Address;
};

class Salary : public Emp
{
public:
  int basicsal;
  string post;
};

class Record : public Salary
{
  int month;
  int absent_day;
  int total, a, b;
  double absent;

public:
  void getdata()
  {
    cout << " enter id " << endl;
    cin >> id;
    cout << " enter name " << endl;
    cin >> Name;
    cout << " enter address " << endl;
    cin >> Address;
    cout << " enter post " << endl;
    cin >> post;
    cout << " enter basic salary " << endl;
    cin >> basicsal;
    cout << " enter number of month of work" << endl;
    cin >> month;
    cout << " enter absent day" << endl;
    cin >> absent_day;
  }

  int deducing_total()
  {
    a = month * 30;
    b = basicsal / a;
    absent = b * absent_day;
    total = basicsal - absent;
    return total;
  }

  void display()
  {

    cout << " Employee information " << endl;
    cout << "id = " << id << endl;
    cout << "name = " << Name << endl;
    cout << "address = " << Address << endl;
    cout << "post = " << post << endl;
    cout << "month = " << month << endl;
    cout << "basic_sal = " << basicsal << endl;
    cout << "absent day = " << absent_day << endl;
    cout << "total = " << deducing_total() << endl;
  }
};

int main()
{
  Record rec;
  rec.getdata();
  rec.display();

  return 0;
}

/*Qestion no.6 - write an OOP to create a class name student with data member result 
and name . create another class from student name Mark with data member 
int_score. create an independent class Sports  with data member
ext_score. Now derive another class Result From mark and sport 
with data member total score. make necessary function for above 
and show the result. */

#include <iostream>
using namespace std;

class Sport;

class student {

    string name, result;
    public:
    void getdata()
    {
        cout << " enter result " << endl;
        cin >> result;
        cout << "enter name " << endl;
        cin >> name;
     }
};

class Mark : public student
{    
     public:
     int int_score;
};


class Sport
{
    public:
    int ext_score;

};


class Result : public Mark , public Sport
{   
    int total_score;
    public:
    void output()
    {
        total_score = int_score + ext_score;
        cout << " total score  is " << total_score << endl;
    }
    
};

int main()
{
    Result rlt;
    rlt.getdata();
    cout << " enter the value of internal value " << endl;
    cin >> rlt.int_score;
    cout << "enter the value of external value " << endl;
    cin >> rlt.ext_score;

    rlt.output();

    return 0;

}

/*qustion no. 7 - write a program to demonstrate writing an 
object to a data file and reading it back */ 

#include <iostream>
#include <fstream>

using namespace std;

// class Employee
// {
//   public:  
//     string Name;
//     int Employee_id;
//     int salary;

// };

// int main()
// {
//     Employee Emp_1;
//     Emp_1.Name = "kiran";
//     Emp_1.Employee_id = 2021;
//     Emp_1.salary = 10000;

//     Employee Emp_2;
//     Emp_2.Name = "bulan";
//     Emp_2.Employee_id = 2022;
//     Emp_2.salary = 110000;

//     ofstream file1;
//     file1.open("Employ.txt", ios::app);
//     file1.write((char *)&Emp_1, sizeof(Emp_1));
//     file1.write((char *)&Emp_2, sizeof(Emp_2));
//     file1.close();


//     ifstream file2;
//     file2.open("Employ.txt", ios::in);
//     file2.seekg(0);
//     file2.read((char *)&Emp_1, sizeof(Emp_1));
//     cout << "\nname: " << Emp_1.Name;
//     cout << "\nemployee id: " << Emp_1.Employee_id;
//     cout << "\nsalary: " << Emp_1.salary;

//     file2.read((char *)&Emp_2, sizeof(Emp_2));
//     cout << "\nname: " << Emp_2.Name;
//     cout <<"\nemployee id: " << Emp_2.Employee_id;
//     cout << "\nsalary: " << Emp_2.salary;
//     file2.close();

//     return 0;

// }



// you can write either above or down program


class Student_info
{
    int rollno;
    string name, line;

    public:
    void write_data()
    {
        ofstream write_out;
        write_out.open("student_record.dat", ios::out);
        cout << " roll number " << endl;
         cin >> rollno;
        write_out << " student roll number " << rollno << endl;

        cout << " name " << endl;
         cin >> name;
         write_out << " student name " << name << endl;

         write_out.close();
        
    }

    void read_data()
    {
     
     ifstream record_in;
     record_in.open("student_record.dat", ios::in);
     while(record_in)
     {
       getline(record_in,line);
       cout << line << endl;

     }
     record_in.close();
    }

};

int main()
{
  
     Student_info sd_1;
     sd_1.write_data();
     sd_1.read_data();

     return 0;
}

// class Employee
// {
//   public:  
//     string Name;
//     int Employee_id;
//     int salary;

// };

// int main()
// {
//     Employee Emp_1;
//     Emp_1.Name = "kiran";
//     Emp_1.Employee_id = 2021;
//     Emp_1.salary = 10000;

//     Employee Emp_2;
//     Emp_2.Name = "bulan";
//     Emp_2.Employee_id = 2022;
//     Emp_2.salary = 110000;

//     ofstream file1;
//     file1.open("Employ.txt", ios::app);
//     file1.write((char *)&Emp_1, sizeof(Emp_1));
//     file1.write((char *)&Emp_2, sizeof(Emp_2));
//     file1.close();


//     ifstream file2;
//     file2.open("Employ.txt", ios::in);
//     file2.seekg(0);
//     file2.read((char *)&Emp_1, sizeof(Emp_1));
//     cout << "\nname: " << Emp_1.Name;
//     cout << "\nemployee id: " << Emp_1.Employee_id;
//     cout << "\nsalary: " << Emp_1.salary;

//     file2.read((char *)&Emp_2, sizeof(Emp_2));
//     cout << "\nname: " << Emp_2.Name;
//     cout <<"\nemployee id: " << Emp_2.Employee_id;
//     cout << "\nsalary: " << Emp_2.salary;
//     file2.close();

//     return 0;

// }



class Student_info
{
    int rollno;
    string name, line;

    public:
    void write_data()
    {
        ofstream write_out;
        write_out.open("student_record.dat", ios::out);
        cout << " roll number " << endl;
         cin >> rollno;
        write_out << " student roll number " << rollno << endl;

        cout << " name " << endl;
         cin >> name;
         write_out << " student name " << name << endl;

         write_out.close();
        
    }

    void read_data()
    {
     
     ifstream record_in;
     record_in.open("student_record.dat", ios::in);
     while(record_in)
     {
       getline(record_in,line);
       cout << line << endl;

     }
     record_in.close();
    }

};

int main()
{
  
     Student_info sd_1;
     sd_1.write_data();
     sd_1.read_data();
     
     return 0;
}