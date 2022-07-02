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



qns 8. 
 // c++ program to illustrate the concept of constructors

#include <iostream>
using namespace std;

class integer
{
public:
  int x, y;

// Default Constructor declared
  integer()
  {
    x = 45;
    y = 10;
  }
};

int main()
{
  // Default constructor called automatically when the object is created
  integer a;
  cout << "x: " << a.x << endl << "y: " << a.y;
  return 0;
}




qns 9.
    // C++ program to illustrate parameterized constructors

#include <iostream>
using namespace std;

class integer
{
private:
  int a, b;
public:
  // Parameterized Constructor
  integer(int x, int y)
  {
    a = x;
    b = y;
  };

  int getX()
  {
    return a;
  };

  int getY()
  {
    return b;
  };
};
int main()
{
  integer v(10, 15); // Constructor called

  cout << "a = " << v.getX() << endl; // values assigned by constructor accessed
  cout<< "b = " << v.getY() << endl;

  return 0;
}




qns.10
    //write a program to illustrate copy contructor

#include <iostream>
using namespace std;

// declare a class
class Rectriangle {
  private:
    double length;
    double height;

  public:

    // initialize variables with parameterized constructor
    Rectriangle(double len, double hgt) {
      length = len;
      height = hgt;
    }

    // copy constructor with a Rectriangle object as parameter
    // copies data of the obj parameter
    Rectriangle(Rectriangle &obj) {
      length = obj.length;
      height = obj.height;
    }

    double calculateArea() {
      return length * height;
    }
};

int main() {
  // create an object of Rectriangle class
  Rectriangle Rectriangle1(10.5, 8.6);

  // copy contents of Rectriangle1 to Rectriangle2
  Rectriangle Rectriangle2 = Rectriangle1;

  // print areas of Rectriangle1 and Rectriangle2
  cout << "Area of Rectriangle 1: " << Rectriangle1.calculateArea() << endl;
  cout << "Area of Rectriangle 2: " << Rectriangle2.calculateArea();

  return 0;
}



qns.11
    // c++ program to illustrate multiple constructor
#include <iostream>
using namespace std;

class complex
{
  int a, b;
public:
   int x, y;
  complex() // default constructor
  {
    a= 10;
    b=45;
  };
  complex( int x, int y) // parameterized constructor
  {
    a=x;
    b=y;
  };
  complex( complex & v)	// copy constructor
  {
    a=v.a;
    b=v.b;
  };

    double calculateArea() {
      return a * b;
    }
};


int main()
{
   
    complex w;
    complex p(14,15);
    complex c = p;

    cout << "x: " << w.x << endl << "y: " << w.y << endl;;
    cout << "Area " << p.calculateArea() << endl;
    cout << "area " << c.calculateArea();

    return 0;
   
}


qns.12
    
//c++ program of copyconstructor
#include<iostream>
using namespace std;
class Samplecopyconstructor
{
    private:
    int x, y;   //data members
    
    public:
    Samplecopyconstructor(int x1, int y1)
    {
        x = x1;
        y = y1;
    }
    
    /* Copy constructor */
    Samplecopyconstructor (const Samplecopyconstructor &sam)
    {
        x = sam.x;
        y = sam.y;
    }
    
    void display()
    {
        cout<<x<<" "<<y<<endl;
    }
};
/* main function */
int main()
{
    Samplecopyconstructor obj1(10, 15);     // Normal constructor
    Samplecopyconstructor obj2 = obj1;      // Copy constructor
    cout<<"Normal constructor : ";
    obj1.display();
    cout<<"Copy constructor : ";
    obj2.display();
    return 0;
}


qns.13
    
// C++ program to illustrate Constructor overloading

#include <iostream>
using namespace std;

class shape
{
  int a, b;
public:
  // Constructor with no argument
  shape()
  {
    a= 2;
    b= 3;
  }
  // constructor with one argument
  shape(int x)
  {
    a=b=x;
  }
  // Constructor with two arguments
  shape(int x, int y)
  {
    a= x;
    b= y;
  }
  int area(void)
  {
    return(a*b);
  }
  void display()
  {
    cout<<"area="<< area() <<endl;
  }
};
int main()
{
  // Constructor Overloading with two different constructors of class name
  shape s;
  shape s2(6);
  shape s3( 3, 2);

  s.display();
  s2.display();
  s3.display();
  return 0;
}



qns.14
    /*.....A program to feature the concept of constructor overloading.......... */
#include <iostream>
using namespace std;
class ABC
{
     private:
        int x,y;
     public:
        ABC ()       //constructor 1 with no arguments
       {
            x = y = 0;
        }
        ABC(int a)    //constructor 2 with one argument
       {
             x = y = a;
        }
        ABC(int a,int b)    //constructor 3 with two argument
        {
              x = a; 
              y = b;
        }
        void display()
        {
              cout << "x = " << x << " and " << "y = " << y << endl;
        }
};
 
int main()
{
     ABC cc1; //constructor 1
     ABC cc2(10); //constructor 2
     ABC cc3(10,20); //constructor 3
     cc1.display();
     cc2.display();
     cc3.display();
     return 0;
 }


qns.15
    
//c++ program to illustrate try catch throws
#include <iostream>
using namespace  std;

double division(int x , int y)
{
    if(y == 0)
    {
    throw " division by zero condition";
    }

    return (x/y);
}


int main()
{
    int a,b;
    double z;

    cout << " enter the value of x" << endl;
    cin>>a;
    cout << "enter the value of y" << endl;
    cin>>b;

    try{
        z = division(a, b);
        cout << " z = " << z << endl;
    }catch( const char* msg){
        cerr << msg << endl;
    }
    return 0;
}



qns.16 
    // write a program to N number in ascending order using function template
#include <iostream>
using namespace std;

template <class T>

void asc( T t[], int n)
{
    int i, j;
    for(i = 0; i < n; i++)
    {
        for(j = i+1; j < i; j++)
        {
            if(t[j] < t[i])
            {
                T temp;
                temp = t[i];
                t[i] = t[j];
                t[j] = temp;
            }
        }
    }
}

int main()
{   
     int i, N, n[100];
    cout << "enter N " << endl;
    cin >> N;
    cout <<" enter numbers \n";
    for( i=0; i< N; i++)
    {
        cin >> n[i];
    }

    asc(n,N);
    cout << "afer sorting" << endl;
    for(i=0; i<N; i++)
    {
        cout<<n[i] <<",";
    }

    return 0;
}
