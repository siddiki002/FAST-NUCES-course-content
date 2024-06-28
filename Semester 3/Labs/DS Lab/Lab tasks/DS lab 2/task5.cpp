#include <iostream>
#include <vector>
using namespace std;



int main()
{
    string name[]={"Ali","Hiba","Asma","Zain","Faisal"};
    string subjects[]={"Data Structure","Programming","DLD","Probability","Finance"};
    vector <vector<float>> arr;
    int size[5];
    for (int i = 0; i < 5; i++)
    {
        cout<<"Enter number of subjects "<<name[i]<<" has attempted"<<endl;
        int n;
        cin>>n;
        size[i] = n;
        vector<float> marks;
        for (int k = 0; k < n; k++)
        {
            cout<<"Enter gpa of "<<subjects[k]<<" "<<endl;
            float m;
            cin>>m;
            marks.push_back(m);
        }
        arr.push_back(marks);
    }
    
    for (int i = 0; i < 5; i++)
    {
        float sum=0;
        for (int j = 0; j < size[i]; j++)
        {
            sum+=(arr[i][j]*3);
        }
        float gpa=0;
        gpa = sum/(3*size[i]);
        cout<<"GPA of "<<name[i]<<" is: "<<gpa<<endl;
    }
}