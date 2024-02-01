//write a c++ program which first reads words from a dictionary file, and inserts them into a hash table.

#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    string word,meaning;
    Node* next;

    public:
    Node()
    {
        //cout<<"Node initialized"<<endl;
        next=NULL;
    }

    Node(string w,string m)
    {
        this->word=w;
        this->meaning=m;
        next=NULL;
    }
};

class Hashing1
{
    public:
    Node*  table[10];
    int location;

    public:
    Hashing1()
    {
        for(int i=0;i<10;i++)
        {
        table[i]=NULL;
        }
    }

    void hash_function(string data,string mean,int size)
    {
        string d=data;
        string m=mean;
        int hash=0;
        int l=data.length();

        for(int i=0;i<data.length();i++)
        {
            char c=data[i];
            hash+=c*(pow(10,l-1-i));
        }
        location=hash%size;

        insertword(location,d,m);
    }
    void insertword(int location,string d,string m)
    {
        // Node* temp=head;
        // while(temp!=location) 
        Node *p=new Node(d,m); 
        Node* temp=table[location];
        p->next=temp;
        table[location]=p;
    }

    void searchword(string val,int size){
            int hash=0;
            int l=val.length();

        for(int i=0;i<val.length();i++)
        {
            char c=val[i];
            hash+=c*(pow(10,l-1-i));
        }
        location=hash%size;

        Node * tt=table[location];
        while(tt!=NULL)
            {
                if(tt->word==val)
                {
                cout<<"Hash function of "<<tt->word<<" is "<<location<<endl;
                cout<<"The meaning of the word "<<tt->word<<" is:"<< tt->meaning<<endl;
                return;
                }
                tt=tt->next;
            }
            cout<<"Word not found"<<endl;
    }

    void displaytable()
    {
        for(int i=0;i<10;i++)
        {
            Node* t=table[i];
            while(t!=NULL)
            {
            cout<<"Hash function of "<<t->word<<" is "<<i<<endl;
            cout<<"word: "<<t->word<<endl;
            cout<<"meaning: "<<t->meaning<<endl;
            cout<<endl;
            t=t->next;
            }
        }
    }
};

int main()
{
    char ch;
    int size;
    string data1,mean;
    Hashing1 obj;

    cout<<"Enter table size:"<<endl;
    cin>>size;
    
    for(int i=0;i<size;i++)
    {
        cout<<"Enter word to be inserted:"<<endl;
        cin>>data1;
        cout<<"Enter meaning of the word:"<<endl;
        cin>>mean;
        obj.hash_function(data1,mean,size);
    }
    cout<<endl;
    cout<<"Displaying words and meaning: "<<endl;
    obj.displaytable();
    cout<<endl;
    string val;
    cout<<"Enter the word to be searched:"<<endl;
    cin>>val;
    obj.searchword(val,size);
    //obj.displaytable();
}







 // do
    // {
    //     cout<<"Enter word to be inserted:"<<endl;
    //     cin>>data1;
    //     Hashing obj(data1);
    //     cout<<"Press Y to continue adding words:"<<endl;
    //     cin>>ch;
    // }while(ch=='Y')
    