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

//creating a stack
class Stack
{
private:
    struct Node *head;

public:
    Stack()
    {
        head = NULL;
    }
    //inserting elements in the stack
    void Insertion(char *name, int Age, int dob)
    {
        struct Node *temp = new Node(name, Age, dob);
        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            temp->next = head;
            head = temp;
        }
    }
    //popping elements from the stack
    struct Wrapper Pop()
    {
        if (head != NULL)
        {
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
    //printing elements of the stack
    void Print()
    {
        struct Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->Name << " | " << temp->age << " | " << temp->DOB << endl;
            temp = temp->next;
        }
        return;
    }
};

//creating a tree
class Tree
{
private:
    vector<struct Wrapper> v1;

public:
    //inserting elements in the tree
    void Insertion(char *name, int Age, int dob)
    {
        struct Wrapper p;
        strcpy(p.Name, name);
        p.age = Age;
        p.DOB = dob;
        v1.push_back(p);
    }
    int getLeft(int i)
    {
        return ((2 * i) + 1);
    }
    int getRight(int i)
    {
        return ((2 * i) + 2);
    }
    //inorder traversal in the tree
    void Inorder(int a, vector<struct Wrapper> &ans)
    {
        if (a >= v1.size())
        {
            return;
        }
        Inorder(getLeft(a), ans);
        ans.push_back(v1[a]);
        Inorder(getRight(a), ans);
    }
    //pre order traversal in the tree
    void preOrder(int a)
    {
        if (a >= v1.size())
        {
            return;
        }
        cout << v1[a].Name << " | " << v1[a].age << " | " << v1[a].DOB << endl;
        preOrder(getLeft(a));
        preOrder(getRight(a));
    }
    //post order traversal in the tree
    void postOrder(int a)
    {
        if (a >= v1.size())
        {
            return;
        }
        postOrder(getLeft(a));
        postOrder(getRight(a));
        cout << v1[a].Name << " | " << v1[a].age << " | " << v1[a].DOB << endl;
    }
};
//creating a linked list
class List
{
private:
    struct Node *head;

public:
    List()
    {
        head = NULL;
    }
    //inserting elements in the linked list
    void Insertion(char *name, int Age, int dob)
    {
        struct Node *temp = new Node(name, Age, dob);
        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            struct Node *temp2 = head;
            while (temp2->next != NULL)
            {
                temp2 = temp2->next;
            }
            temp2->next = temp;
            temp->prev = temp2;
        }
    }
    //swapping two nodes of the linked list
    void swap(Node *c, Node *d)
    {
        char tempL[30];
        char tempR[30];
        int tempAge;
        int tempDOB;
        strcpy(tempR, c->Name);
        tempAge = c->age;
        tempDOB = c->DOB;
        strcpy(c->Name, d->Name);
        c->age = d->age;
        c->DOB = d->DOB;
        strcpy(d->Name, tempR);
        d->age = tempAge;
        d->DOB = tempDOB;
    }
    //printing all the elements of th linked list
    void Print()
    {
        struct Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->Name << " | " << temp->age << " | " << temp->DOB << endl;
            temp = temp->next;
        }
    }
    //getting the last node of the linked list
    Node *lastNode()
    {
        struct Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        return temp;
    }
    //partitioning the list for quick sort
    Node *Partition(struct Node *first, struct Node *last)
    {
        int pValue = last->age;
        Node *i = first->prev;
        for (Node *j = first; j != last; j = j->next)
        {
            if (j->age <= pValue)
            {
                i = (i == NULL) ? first : i->next;
                swap(i, j);
            }
        }
        i = (i == NULL) ? first : i->next;
        swap(i, last);
        return i;
    }
    //sorting the linked list using quick sort
    void quickSort(struct Node *first, struct Node *tail)
    {
        if (tail != NULL && first != tail && first != tail->next)
        {
            Node *pindex = Partition(first, tail);
            quickSort(first, pindex->prev);
            quickSort(pindex->next, tail);
        }
    }
    void Sort()
    {
        struct Node *tail = lastNode();
        struct Node *first = head;
        quickSort(first, tail);
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
