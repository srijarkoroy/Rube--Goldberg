#include <iostream>
#include <cstring>
#include <queue>
#include <string>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;
//creating a node
struct Node
{
    char Name[30];
    int age;
    int DOB;
    struct Node *next;
    struct Node *prev;
    Node(char *name , int Age, int dob)
    {
        strcpy(Name, name);
        age = Age;
        DOB = dob;
        next = NULL;
        prev = NULL;
    }
};

struct Wrapper
{
    char Name[30];
    int age;
    int DOB;
};
// creating a queue
class Queue
{
private:
    struct Node *head;
    struct Node *last;

public:
    Queue()
    {
        head = NULL;
        last = NULL;
    }
    //inserting elements in queue
    void Insertion(char *name, int Age, int dob)
    {
        struct Node *temp = new Node(name, Age, dob);
        if (head == NULL)
        {
            head = temp;
            last = temp;
        }
        else
        {
            last->next = temp;
            last = temp;
        }
    }
    //printing elements of the queue
    void Print()
    {
        struct Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->Name << " | " << temp->age << " | " << temp->DOB << endl;
            temp = temp->next;
        }
    }
    //deleting element from the queue
    struct Wrapper Pop()
    {

        if (head != NULL)
        {
            if (head == last)
            {
                last = NULL;
            }
            struct Node *temp = head;
            head = temp->next;
            struct Wrapper p1;
            strcpy(p1.Name, temp->Name);
            p1.age = temp->age;
            p1.DOB = temp->DOB;
            delete temp;
            return p1;
        }
    }
};

int main()
{
    int n = 1;
    while (n)
    {
        // declaring an input stream type 'file'
        ifstream file;
        // opening our required text file
        file.open("input.txt");
        string text;

        Queue q1;
        Stack s1;
        Tree t1;
        List l1;
        int size;
        cout << "WELCOME TO RUBE GOLDBERG MACHINE!!" << endl;
        cout << endl;
        cout << "ENTER THE NUMBER OF ENTRIES YOU WANT TO FILL IN" << endl;
        cin >> size;
        cout << "OKAY ENTER YOUR DETAILS:" << endl;
        for (int i = 0; i < size; i++)
        {
            cout << i + 1 << ": ENTRY" << endl;
            char Name[30];
            char LastName[30];
            int age, DOB;
            cout << "ENTER FIRST NAME: " << endl;
            cin >> Name;
            cout << "ENTER LAST NAME: " << endl;
            cin >> LastName;
            cout << "ENTER AGE: " << endl;
            cin >> age;
            cout << "ENTER YEAR OF BIRTH: " << endl;
            cin >> DOB;
			
			
            q1.Insertion(Name, age, DOB);
        }
        while (getline(file, text))
        {
            char Name[30];
            char age[10], DOB[10];
            // cout << text << endl;
            string temp_text = text;
            //string my_str = "ABC,XYZ,Hello,World,25,C++";
            vector<string> result;
            stringstream s_stream(temp_text); //create string stream from the string
            while (s_stream.good())
            {
                string substr;
                getline(s_stream, substr, ','); //get first string delimited by comma
                result.push_back(substr);
            }
            strcpy(Name, result.at(0).c_str());
            strcpy(age,result.at(1).c_str());
            strcpy(DOB, result.at(2).c_str());

            q1.Insertion(Name,atoi(age), atoi(DOB));
        }
        ifstream fin;
        fin.open("input.txt");
        char str[80];
        int count=0;
        while(!fin.eof())
        {
            fin.getline(str,80);
            if(str[0]!='A')
                count++;
        }

        cout << "RUBE GOLDBERG MACHINE~$ Displaying Recorded Data:\n" << endl;
        q1.Print();
        cout << endl;
        cout << "RUBE GOLDBERG MACHINE~$ Reverse the Recorded Entries(1:YES | 0:NO)" << endl;
        cin >> n;
        if (n == 0)
        {
            break;
        }
        cout << ">> Reversing the Recorded Entries....\n" << endl;
        for (int i = 0; i < count; i++)
        {
            struct Wrapper temp = q1.Pop();
            s1.Insertion(temp.Name, temp.age,
                         temp.DOB);
        }
        for (int i = 0; i < count; i++)
        {
            struct Wrapper temp = s1.Pop();
            q1.Insertion(temp.Name, temp.age, temp.DOB);
        }
        q1.Print();
        cout << endl;
        cout << "RUBE GOLDBERG MACHINE~$ Get the PreOrder and PostOrder Traversal(1:YES | 0:NO)" << endl;
        cin >> n;
        if (n == 0)
        {
            break;
        }
        for (int i = 0; i < count; i++)
        {
            struct Wrapper temp = q1.Pop();
            t1.Insertion(temp.Name, temp.age, temp.DOB);
        }
        cout << ">> PreOrder Traversal:" << endl;
        t1.preOrder(0);
        cout << endl;
        cout << ">> PostOrder Traversal:" << endl;
        t1.postOrder(0);
        cout << endl;
        cout << "RUBE GOLDBERG MACHINE~$ Get the InOrder Traversal(1:YES | 0:NO)" << endl;
        cin >> n;
        if (n == 0)
        {
            break;
        }
        vector<struct Wrapper> ans;
        t1.Inorder(0, ans);
        for (int i = 0; i < ans.size(); i++)
        {
            l1.Insertion(ans[i].Name, ans[i].age, ans[i].DOB);
        }
        cout << ">> InOrder Traversal:" << endl;
        l1.Print();
        cout << "\nRUBE GOLDBERG MACHINE~$ Arrange the Entries Age-wise(1:YES | 0:NO)" << endl;
        cin >> n;
        if (n == 0)
        {
            break;
        }
        cout << ">> Sorting the List....." << endl;
        l1.Sort();
        cout << endl;
        l1.Print();
        cout << "\nRUBE GOLDBERG MACHINE~$ Add One more Entry to the List(1:YES | 0:NO)" << endl;
        cin >> n;
        if (n == 0)
        {
            break;
        }
        cout << ">> Enter the Details:" << endl;
        char Name[30];
        int age, DOB;
        cout << "\n ~ Name of the Person: ";
        cin >> Name;        
        cout << "\n ~ Enter the Age: ";
        cin >> age;
        cout << "\n ~ Enter the Year of Birth: ";
        cin >> DOB;
        l1.Insertion(Name, age, DOB);
        cout << "\nRUBE GOLDBERG MACHINE~$ Entries Synced with .txt file. Updated Records:" << endl;
        l1.Sort();
        cout << endl;
        l1.Print();
        std::ofstream outfile;

        outfile.open("input.txt", std::ios_base::app); // append instead of overwrite
        outfile << "\n"<<Name<<","<<age<<","<<DOB;
        cout << "\nRUBE GOLDBERG MACHINE~$ Terminate the Process(1:CONTINUE | 0:YES)" << endl;
        cin >> n;
        if (n == 0)
        {
            break;
        }
    }
    cout << "\nRUBE GOLDBERG MACHINE~$ Thank You !!!" << endl;
    return 0;
}
