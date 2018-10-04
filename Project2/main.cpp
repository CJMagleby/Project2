#include <iostream>
#include <fstream>
using namespace std;


template<class T>
class LinearList
{
private:
    int length;
    int MaxSize;
    T *element;
public:
    LinearList(int MaxLinearSize=10);
    ~LinearList(){delete[]element;}
    int isEmpty()const{return length==0;}
    int Length()const{return length;}
    int Find(int k,T&x)const;
    int Search(const T&x)const;
    void Delete(int k,T&x);
    void Insert(int k,const T&x);
    void Output(string fileName)const;
};
template<class T>
LinearList<T>::LinearList(int MaxListSize)
{
    MaxSize=MaxListSize;
    element=new T[MaxSize];
    length=0;
}
template<class T>
int LinearList<T>::Find(int k,T&x)const
{
    if(k<1||k>length)
        return 0;
    x=element[k-1];
    return 1;
}
template<class T>
int LinearList<T>::Search(const T&x)const
{
    for(int i=0;i<length;i++)
        if(element[i]==x)
            return ++i;
    return 0;
}
template<class T>
void LinearList<T>::Delete(int k,T&x)
{
    if(Find(k,x))
    {
        for(int i=k;i<length;i++)
            element[i-1]=element[i];
        length--;
    }
    else
        cout<<"out of bounds\n";
}
template<class T>
void LinearList<T>::Insert(int k,const T&x)
{
    if(k<0||k>length)
        cout<<"out of bounds\n";
    if(length==MaxSize)
        cout<<"no memory\n";
    for(int i=length-1;i>=k;i--)
        element[i+1]=element[i];
    element[k]=x;
    length++;
}
template<class T>
void LinearList<T>::Output(string fileName)const
{
    ofstream myFile;
    myFile.open( fileName ); 
    
    if  (myFile.is_open())
        cout << "file is open!"<< endl;
    if(isEmpty())
        cout<<"list is empty\n";
    else
        for(int i=0;i<length;i++)
        {
            myFile<<element[i]<<"\t";
            cout<<element[i]<<"\t";
        }
    myFile.close();
}
struct node
{
    int data;
    node *next;
};
class LinkedList
{
protected:
    node *first;
    int length;
public:
    LinkedList()
    {
        first = NULL;
        length = 0;
    }
    ~LinkedList()
    {
        cout << "LIST DELETED" << endl;
    }
    void Insert(int data)
    {
        node* node = new struct node();
        node->data = data;
        node->next = this->first;
        this->first = node;
        this->length++;
    }
    void InsertAt(int data, int location)
    {
        node * current = this->first;
        for (int i = 0; i < location; i++) {
            current = current->next;
        }
        node * newNode = new node();
        newNode->data = data;
        node * temp = current->next;
        newNode->next = temp;
        
        current->next = newNode;
        this->length++;
    }
    void print(string fileName)
    {
        ofstream myFile;
        myFile.open(fileName);
        node* currentNode = this->first;
        int i = 1;
        while(currentNode)
        {
            myFile << currentNode->data << "\t";
            cout << currentNode->data << "\t";
            currentNode = currentNode->next;
            i++;
        }
        myFile.close();
    }
    void Delete(int index)
    {
        node *temp = this->first;
        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }
        node *temp2 = temp->next;
        temp->next = temp2->next;
        delete temp2;
        
    }

};
int main()
{
    
    LinearList <int> obj;
    
    int k = 11;
    for (int i = 0; i < 11; i++) {
        obj.Insert(i, k);
        k--;
    }
    int temp=7;
    obj.Delete(5,temp);
    
    obj.Insert(8, 100);
    
    string fileName = "Curtis.Magleby.aList.txt";
    obj.Output(fileName);
    cout << endl;
    
    LinkedList test;
    fileName = "Curtis.Magleby.lList.txt";
    for (int i = 1; i < 12; i++) {
        test.Insert(i);
    }
    test.InsertAt(100, 8);
    test.Delete(6);
    test.print(fileName);
    
    
    
    
    
    return 0;
}
