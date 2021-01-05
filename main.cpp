#include<iostream>
#include<fstream>
#include<iomanip>
#include<stdlib.h>
#include<cstdio>
#include<ctime>
#include<cstring>
#include <conio.h>

using namespace std;
class student
{
    int id;
    int dd;
    int mm;
    int yyyy;
    char name[300];
    char address[500];
    char email[500];
    char gender;
    char dept[20];
    int pn;
    int gm;
    string uName;
    string sPass;
    string sec;
    string semester;

public:
    void getData();
    void showData();
    void view();
    void details();
    void details_mini();
    void setPass();
    void change_Pass();
    string getSection()
    {
        return sec;
    }
    string getSemester()
    {
        return semester;
    }
    int getID()
    {
        return id;
    }
    string userName()
    {
        return uName;
    }
    string passWord()
    {
        return sPass;
    }
} s;

void addData();
void project();
void login();
void Section();
void semester_view();
void displayData();
void getTrash();

void student:: setPass()
{
    cout<<"===========================Sign up for manage student==========================="<<endl;
    cout<<"Set username & password"<<endl;
    cout<<"Set username: ";
    cin>>uName;
    cout<<"Set Password: ";
    string x ="";
    char ch;
    ch = _getch();
    while(ch != 13)
    {
        x.push_back(ch);
        cout << '*';
        ch = _getch();
        sPass= x;
    }

}
void student:: change_Pass()
{
    cout<<"===========================You are ready to set new login info==========================="<<endl;
    cout<<"Set username & password"<<endl;
    cout<<"Set username: ";
    cin>>uName;
    cout<<"Set Password: ";
    string x ="";
    char ch;
    ch = _getch();
    while(ch != 13)
    {
        x.push_back(ch);
        cout << '*';
        ch = _getch();
        sPass= x;
    }

}
void newpass()
{
    ofstream fout;
    fout.open("password.bin",ios::binary|ios::out|ios::app);
    s.change_Pass();
    fout.write((char*)&s,sizeof(s));
    fout.close();
    system("cls");
}
void getPass()
{
    ofstream fout;
    fout.open("password.bin",ios::binary|ios::out|ios::app);
    s.setPass();
    fout.write((char*)&s,sizeof(s));
    fout.close();
    system("cls");

}
void view()
{
    int press;
    cout<<"1. Section wise view"<<endl;
    cout<<"2. semester wise view"<<endl;
    cout<<"3. view full database"<<endl;
    cout<<"Enter your choice: ";
    cin>>press;
    system("cls");
    switch(press)
    {
    case 1:
        Section();
        break;
    case 2:
        semester_view();
        break;
    case 3:
        displayData();
        break;

    }
}
void student::getData()
{
    cout<<"\t\t***********************Enter the student information below***********************"<<endl;
    cout<<endl<<"Enter student ID: ";
    cin>>id;
    cout<<endl<<"Enter student full name: ";
    cin.ignore();
    cin.getline(name,300);
    cout<<"Gender (M/F): ";
    cin>>gender;
    cout<<"Enter department: ";
    cin.ignore();
    cin.getline(dept,20);
    cout<<"Enter Section: ";
    cin>>sec;
    cin.ignore();
    cout<<"Enter Semester: ";
    cin>>semester;
    cout<<"Date of birth: (dd-mm-yyyy)";
    cin>>dd>>mm>>yyyy;
    cout<<"Enter email:";
    cin.ignore();
    cin.getline(email,500);
    cout<<"Enter student phone Number:";
    cin>>pn;
    cout<<"Enter student address:";
    cin.ignore();
    cin.getline(address,500);
    cout<<"Enter student guardian mobile number:";
    cin>>gm;
    cout<<"Registration successful."<<endl;
}
void student::details()
{
    string press;
    cout<<endl<<"Name"<<setw(21)<<":"<<name<<endl;
    cout<<endl<<"Department"<<setw(15)<<":"<<dept<<endl;
    cout<<endl<<"Section"<<setw(18)<<":"<<sec<<endl;
    cout<<endl<<"Semester"<<setw(17)<<":"<<semester<<endl;
    cout<<endl<<"Phone Number "<<setw(12)<<":0"<<pn<<endl;
    cout<<"Do you want to see full details?(Y/N):";
    cin>>press;
    system("cls");
    if(press=="Y" || press=="y")
    {
        showData();
    }
    else
    {
        system("cls");
    }
}
void student::details_mini()
{
    cout<<endl<<"               **                   "<<endl;
    cout<<endl<<endl<<"ID"<<setw(23)<<":"<<id<<endl;
    cout<<endl<<"Name"<<setw(21)<<":"<<name<<endl;
    cout<<endl<<"Department"<<setw(15)<<":"<<dept<<endl;
    cout<<endl<<"Section"<<setw(18)<<":"<<sec<<endl;
    cout<<endl<<"Semester"<<setw(17)<<":"<<semester<<endl;
    cout<<endl<<"Phone Number "<<setw(13)<<":0"<<pn<<endl<<endl;

}
void student::showData()
{
    cout<<endl<<endl;
    cout<<"                 **                   ";
    cout<<endl<<"ID"<<setw(23)<<":"<<id<<endl;
    cout<<endl<<"Name"<<setw(21)<<":"<<name<<endl;
    cout<<endl<<"Gender (M/F)"<<setw(13)<<":"<<gender<<endl;
    cout<<endl<<"Department"<<setw(15)<<":"<<dept<<endl;
    cout<<endl<<"Section"<<setw(18)<<":"<<sec<<endl;
    cout<<endl<<"Semester"<<setw(17)<<":"<<semester<<endl;
    cout<<endl<<"Date of birth"<<setw(12)<<":"<<dd<<"-"<<mm<<"-"<<yyyy<<endl;
    cout<<endl<<"Email: "<<setw(18)<<":"<<email<<endl;
    cout<<endl<<"Phone Number "<<setw(12)<<":"<<pn<<endl;
    cout<<endl<<"Address "<<setw(17)<<":"<<address<<endl;
    cout<<endl<<"Guardian mobile number "<<setw(2)<<":"<<gm<<endl;
    cout<<endl;
}
void addData()
{
    ofstream fout;
    fout.open("student.bin",ios::binary|ios::out|ios::app);
    s.getData();
    fout.write((char*)&s,sizeof(s));
    fout.close();
}
void displayData()
{
    cout<<setw(50)<<"\t\t\t******************Student details******************"<<endl;
    ifstream fin;
    fin.open("student.bin",ios::in|ios::binary);
    while(fin.read((char*)&s,sizeof(s)))
    {
        s.showData();
    }
    fin.close();
}
void searchData()
{
    int n,flag=0;
    ifstream fin;
    fin.open("student.bin",ios::in|ios::binary);
    cout<<"Enter Student ID for search: ";
    cin>>n;
    system("cls");
    while(fin.read((char*)&s,sizeof(s)))
    {
        if(n==s.getID())
        {
            cout<<"The details of '"<<n<<"' shown"<<endl;
            s.details();
            flag++;
        }
    }
    fin.close();
    if(flag==0)
    {
        cout<<"ID '"<<n<<"' not found....\n\n";
    }
}
void semester_view()
{
    string n;
    int flag=0;
    ifstream fin;
    fin.open("student.bin",ios::in|ios::binary|ios::app);
    cout<<"Enter semester you want to search: ";
    cin>>n;
    system("cls");

    cout<<"The details of '"<<n<<"' Semester"<<endl;

    while(fin.read((char*)&s,sizeof(s)))
    {
        if(n.compare(s.getSemester())==0)
        {
            while(!fin.eof())
            {
                s.details_mini();
                flag++;
                break;
            }

        }
    }
    fin.close();

    if(flag==0)
    {
        cout<<"The semester you enter dose not exist."<<endl;
    }
}


void Section()
{
    string n;
    int flag=0;
    ifstream fin;
    fin.open("student.bin",ios::in|ios::binary);
    cout<<"Enter Section you want to search: ";
    cin>>n;
    system("cls");
    cout<<"\n*******************The details of '"<<n<<"' Section*******************"<<endl;
    while(fin.read((char*)&s,sizeof(s)))
    {
        if(n.compare(s.getSection())==0)
        {
            while(!fin.eof())
            {
                s.details_mini();
                flag++;
                break;
            }
        }
    }
    fin.close();
    if (flag==0)
    {
        cout<<"The Section you enter dose not exist."<<endl;
    }
}

void deleteData()
{
    int n,flag=0;
    string press;
    ifstream fin;
    ofstream fout,tout;
    fin.open("student.bin",ios::in|ios::binary);
    fout.open("temporary.bin",ios::out|ios::app|ios::binary);
    tout.open("Trash.bin",ios::out|ios::app|ios::binary);
    cout<<"Enter ID you want to delete: ";
    cin>>n;
    system("cls");
    while(fin.read((char*)&s,sizeof(s)))
    {
        if(n==s.getID())
        {
            cout<<"The Following ID No. "<<n<<" has been deleted:\n";
            s.showData();
            tout.write((char*)&s,sizeof(s));
            flag++;

        }
        else
        {
            fout.write((char*)&s,sizeof(s));
        }
    }
    fout.close();
    tout.close();
    fin.close();
    if(flag==0)
        cout<<"ID Not found"<<endl;
    remove("student.bin");
    rename("temporary.bin","student.bin");
    cout<<"Do you want to see deleted details?(Y/N):";
    cin>>press;
    system("cls");
    if(press=="Y"|| press=="y")
    {
        getTrash();
    }
    else
    {
        system("cls");
    }

}

void getTrash()
{
    ifstream fin;
    fin.open("Trash.bin",ios::in|ios::binary);
    while(fin.read((char*)&s,sizeof(s)))
    {
        s.showData();
    }
    fin.close();
}
void modifyData()
{
    int n, flag, pos;
    fstream fio;
    fio.open("student.bin",ios::in|ios::out|ios::binary);
    cout<<"Enter Id for Modify : ";
    cin>>n;
    system("cls");
    while(fio.read((char*)&s,sizeof(s)))
    {
        pos=fio.tellg();
        if(n==s.getID())
        {
            cout<<"The Following Id "<<n<<" will be modified with new data:\n";
            s.showData();
            cout<<"\n\nNow Enter the New Details....\n";
            s.getData();
            fio.seekg(pos-sizeof(s));
            fio.write((char*)&s,sizeof(s));
            flag++;
        }
    }
    fio.close();
    if(flag==0)
        cout<<"Id "<<n<<" not found....\n\n";
}
void changepass()
{
    int n, flag=0, pos;
    string a;
    string b;
    fstream fio;
    fio.open("password.bin",ios::in|ios::out|ios::binary);
    cout<<"Enter your old username: ";
    cin>>a;
    cout<<"Enter your old password: ";
    cin>>b;
    system("cls");
    while(fio.read((char*)&s,sizeof(s)))
    {
        pos=fio.tellg();
        if(b==s.passWord())
        {
            cout<<"\n\nNow Enter the New Details....\n";
            newpass();
            fio.seekg(pos-sizeof(s));
            fio.write((char*)&s,sizeof(s));
            flag++;
            break;
        }
    }
    fio.close();

    if(flag==0)
        cout<<"Incorrect username or password. try again....";
}


void project()
{
    int choice;
    do
    {

        system("cls");
        cout<<"\t\t\t...............STUDENT MANAGEMENT SYSTEM..............\n";
        cout<<"\t\t\t======================================================\n";
        cout<<"1. Registration for new student"<<endl;
        cout<<"2. View Student Data"<<endl;
        cout<<"3. Search Student"<<endl;
        cout<<"4. Delete Student Data"<<endl;
        cout<<"5. Modify Student Data"<<endl;
        cout<<"6. Change login password"<<endl;
        cout<<"0. logout"<<endl;
        cout<<"Enter your choice  : ";
        cin>>choice;
        system("cls");
        switch(choice)
        {
        case 1:
            addData();

            break;
        case 2:
            view();
            break;
        case 3:
            searchData();
            break;
        case 4:
            deleteData();
            break;
        case 5:
            modifyData();
            break;
        case 6:
            changepass();
            break;
        }
        system("pause");
    }
    while(choice);
}

void date()
{
    time_t T= time(NULL);
    struct  tm tm = *localtime(&T);
    printf("\n\n\n");
    printf("\t\t\t\t\t   Date:%02d/%02d/%04d\n",tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);

}
void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

void loding()
{
    system("color 0A");
    cout<<"\n\n\n\t\t\t\tPlease wait while loading\n\n";
    char a=177, b=219;
    cout<<"\t\t\t\t";
    for (int i=0; i<=25; i++)
        cout<<a;
    cout<<"\r";
    cout<<"\t\t\t\t";
    for (int i=0; i<=25; i++)
    {
        cout<<b;

        for (int j=0; j<=1e8; j++);
    }

    system("cls");
}
void login()
{
    string user;
    string pass;
    int  flag=0;
    ifstream my_file("password.bin");
    if (my_file)
    {
        ifstream my_file;
        my_file.open("password.bin",ios::in|ios::binary);
        cout<<"\t\t\t...............STUDENT MANAGEMENT SYSTEM..............\n";
        cout<<"\t\t\t======================================================\n";
        cout<<"\t\t\t||Please Login first||"<<endl;
        cout<<"\t\t\tUsername: ";
        cin>>user;
        cout<<"\t\t\tpassword: ";
        string x ="";
        char ch;
        ch = _getch();
        while(ch != 13)
        {
            x.push_back(ch);
            cout << '*';
            ch = _getch();
            pass= x;
        }
        system("cls");

        while(my_file.read((char*)&s,sizeof(s)))
        {
            if((user==s.userName())&&(pass==s.passWord()))
            {
                cout<<"\n\n\n\n\t\tLogin Successful.........."<<endl;
                loding();
                system("cls");
                project();
                flag++;
            }
        }
        my_file.close();

        if(flag==0)
        {
            cout<<"\t\t\tworng password! try again"<<endl;
            system("pause");
            system("cls");
            login();
        }
    }

    else
    {
        getPass();
    }
}
int main()
{
    system("color 0A");
    date();
    login();
}


