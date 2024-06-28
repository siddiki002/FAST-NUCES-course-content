#include <iostream>
#include <string>
using namespace std;

class Animal
{
private:
    string name,type,color;
    int age;
public:
        Animal(){};
        Animal (const Animal &obj)
        {
            name = obj.name;
            age = obj.age;
            color = obj.color;
            type = obj.type;
        }
        Animal(string n, string t, string c, int a)
        {
            name = n;type = t;color = c;age = a;
        }
        string get_name(){return name;}
        void set_data(string n, string t, string c, int a)
        {
            name = n;type = t;color = c;age = a;
        }
        void show()
        {
            cout<<"Name is: "<<name<<endl<<"Color is: "<<color<<endl<<"Type is: "<<type<<endl<<"Age is: "<<age<<endl<<endl;
        }

};
void sorting(Animal* arr, int n)
{
    
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if(arr[i].get_name()>arr[j].get_name())
            {
                Animal temp;
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }   
        }
        
    }
    
    
}
int main()
{
    Animal *ptr = new Animal[5];        //Part 1
    //Part 2
    for (int i = 0; i < 5; i++)
    {
        string name,type,color;
        int age;
        cout<<"Enter name, color and type"<<endl;
        cin>>name>>color>>type;
        cout<<"Enter age"<<endl;
        cin>>age;
        ptr[i].set_data(name,type,color,age);
    }
    sorting(ptr,5);
    cout<<"After sorting"<<endl;
    for (int i = 0; i < 5; i++)
    {
        ptr[i].show();
    }
    
}