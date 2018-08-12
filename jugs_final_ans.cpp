//Importing
#include <iostream>
#include<list>
#include<vector>
#include<iterator>
#include<stack>
#include <utility>
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
stack<int> fillCondition(int x,int y)
{
    stack<int> s;
    if(x<4)
    s.push(1);

    if(y<3)
    s.push(2);

    if(x>0)
    s.push(3);

    if(y>0)
    s.push(4);

    if((x+y)>=4 and y>0)
    s.push(5);

    if((x+y)>=3 and x>0)
    s.push(6);

    if((x+y)<=4 and y>0)
    s.push(7);

    if((x+y)<=3 and x>0)
    s.push(8);

    return s;
}



int main()
{
    //Entering the initial and final values of Jugs
    int ix,iy,fx,fy=0;
    cout<<"Enter the initial values of jugs::"<<endl;
    cin>>ix>>iy;
    cout<<"Enter the final values of jugs::"<<endl;
    cin>>fx>>fy;

    list <stack<int> > ps; // store comditions
    stack<pair<int,int> > org_temp;
    list <stack<int> > ps_temp;
    stack<pair<int,int> > org; // storing pairs
    vector<pair<int,int> > search;
    pair<int,int> p;
    stack<int> temp;
    pair<int,int> ptemp;

    //pushing the initial value in stack
    org.push(make_pair(ix,iy));
    temp = fillCondition(ix,iy);
    ps.push_back(temp);
    search.push_back(make_pair(ix,iy));

    int x = ix;
    int y = iy;
    int inner_top = 0;
    int found = 0;
    unsigned int i=0;

    while(!org.empty() && !ps.empty())
    {
        p = org.top();
        //checking whether final state is achieved or not
        if(p.first == fx && p.second == fy)
        {
            org_temp = org;
            stack<pair<int,int> > print;
            while(!org.empty())
            {
                p = org.top();
                print.push(p);
                //cout<<"("<<p.first<<","<<p.second<<")"<<",";
                org.pop();
            }
            while(!print.empty())
            {
                p = print.top();
                cout<<"("<<p.first<<","<<p.second<<")"<<"->";
                print.pop();
            }
            cout<<endl;
            org = org_temp;
            org.pop();
            ps.pop_back();
            search.pop_back();
            //break;
        }

        temp = ps.back();
        while(true)
        {
            ps.pop_back();
            if(temp.size()>0)
            {
                inner_top = temp.top();
                temp.pop();
                break;
            }
            else
            {
                for(i=0;i<search.size();++i)
                {
                    p = search.at(i);
                    if(p.first == org.top().first && p.second == org.top().second)
                    break;
                }
                search.erase(search.begin()+i);
                org.pop();
                temp = ps.back();
            }
        }
        ps.push_back(temp);

        p = org.top();
        ptemp = fillJugs(inner_top,p.first,p.second);

        found = 0;
        for(i=0;i<search.size();++i)
        {
            p = search.at(i);
            if(p.first == ptemp.first && p.second == ptemp.second)
            {
             found = 1;
             break;
            }
        }

        if(found == 0)
        {
            org.push(ptemp);
            search.push_back(ptemp);
            temp = fillCondition(ptemp.first,ptemp.second);
            ps.push_back(temp);
        }

        /*ps_temp = ps;
        org_temp = org;

        while(!ps.empty())
        {
            temp = ps.back();
            while(!temp.empty())
            {
                cout<<temp.top()<<",";
                temp.pop();
            }
            ps.pop_back();
            cout<<"||";
            cout<<org.top().first<<","<<org.top().second<<endl;
            org.pop();
        }
        cout<<endl;
        cout<<endl;
        org = org_temp;
        ps = ps_temp;*/

    }
    return 0;
}



