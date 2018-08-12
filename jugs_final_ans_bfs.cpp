#include <iostream>
#include<vector>
#include<iterator>
#include<stack>
#include <utility>
#include<queue>
using namespace std;

//Filling Jugs based on condition c and returning new pair of values
pair<int,int> fillJugs(int c,int x,int y)
{
    pair<int,int> p;
    if(c==1)
    {
    p.first = 4;
    p.second = y;
    }
    else if(c==2)
    {
        p.first = x;
        p.second = 3;
    }
    else if(c==3)
    {
        p.first = 0;
        p.second = y;
    }
    else if(c==4)
    {
        p.first = x;
        p.second = 0;
    }
    else if(c==5)
    {
        p.first = 4;
        p.second = y-(4-x);
    }
    else if(c==6)
    {
        p.first = x-(3-y);
        p.second = 3;
    }
    else if(c==7)
    {
        p.first = x+y;
        p.second = 0;
    }
    else
    {
        p.first = 0;
        p.second = x+y;
    }
    return p;
}

//Finding all possible valid conditions
vector<int> fillCondition(int x,int y)
{
    vector<int> s;
    if(x<4)
    s.push_back(1);

    if(y<3)
    s.push_back(2);

    if(x>0)
    s.push_back(3);

    if(y>0)
    s.push_back(4);

    if((x+y)>=4 and y>0)
    s.push_back(5);

    if((x+y)>=3 and x>0)
    s.push_back(6);

    if((x+y)<=4 and y>0)
    s.push_back(7);

    if((x+y)<=3 and x>0)
    s.push_back(8);

    return s;
}

int check(vector<pair<int,int> > s,pair<int,int> p)
{
    int i=0;
    pair<int,int> ptemp;
    for(i=0;i<s.size();++i)
    {
        ptemp = s.at(i);
        if(ptemp.first == p.first && ptemp.second == p.second)
            return 1;
    }
    return 0;
}

struct Node
{
    int x;
    int y;
    vector<Node *> child;
    Node * parent;
};


int main()
{
    //Entering the initial and final values of Jugs
    int ix,iy,fx,fy=0;
    cout<<"Enter the initial values of jugs::"<<endl;
    cin>>ix>>iy;
    cout<<"Enter the final values of jugs::"<<endl;
    cin>>fx>>fy;

    vector<pair<int,int> > search;
    queue<Node * > org; // storing pairs
    vector<int> temp;
    pair<int,int> ptemp;

    //creating parent node
    Node *root = new Node;
    root->x = ix;
    root->y = iy;
    root->parent = NULL;
    //search.push_back(make_pair(ix,iy));
    Node *prev =root;
    org.push(root);


    while(!org.empty())
    {
        /*if(prev->x == fx && prev->y == fy)
        {
            Node *q = prev;
            while(q!=NULL)
            {
                cout<<"("<<q->x<<","<<q->y<<")"<<"->";
                q=q->parent;
            }
            cout<<endl;
            org.pop();
            prev = org.front();
            for(unsigned int i=0;i<search.size();++i)
            {
                ptemp = search.at(i);
                if(ptemp.first == fx && ptemp.second == fy)
                {
                    search.erase(search.begin()+i);
                    break;
                }
            }
        }*/
        temp = fillCondition( prev->x, prev->y);

        for(unsigned int i=0;i<temp.size();++i)
        {
            ptemp = fillJugs(temp.at(i),prev->x,prev->y);
            if(ptemp.first == fx && ptemp.second == fy)
            {
                cout<<"("<<fx<<","<<fy<<")"<<"->";
                Node *q = prev;
                while(q!=NULL)
                {
                    cout<<"("<<q->x<<","<<q->y<<")"<<"->";
                    q=q->parent;
                }
                cout<<endl;
            }
            else if(check(search,ptemp) == 0)
            {
                Node *p = new Node;
                p->x = ptemp.first;
                p->y = ptemp.second;
                p->parent = prev;
                prev->child.push_back(p);
                org.push(p);
            }
            else
            {
            }

        }
        search.push_back(make_pair(prev->x, prev->y));
        org.pop();
        prev = org.front();
    }

    return 0;
}

