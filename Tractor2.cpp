//  Copyright © 2017 Dougy Ouyang. All rights reserved.

#include <iostream>
#include <queue>
#include <cmath>

using namespace std;
int mat[502][502];
double n;
bool visited[502][502];


int floodfill(int x, int y, int tcost)
{
    queue<pair<int, int> > po;
    queue<int> c;
    pair<int, int> in;
    int point=1;
    
    in.first=x, in.second=y;
    visited[x][y]=true, po.push(in), c.push(mat[x][y]);
    while(!po.empty()){
        int curx=po.front().first, cury=po.front().second, cost=c.front();
        po.pop(), c.pop();
        if(mat[curx+1][cury]!=-1 && !visited[curx+1][cury] && abs(mat[curx+1][cury]-cost)<=tcost)
            in.first=curx+1, in.second=cury, po.push(in), visited[curx+1][cury]=true, c.push(mat[curx+1][cury]), point++;
        if(mat[curx-1][cury]!=-1 && !visited[curx-1][cury] && abs(mat[curx-1][cury]-cost)<=tcost)
            in.first=curx-1, in.second=cury, po.push(in), visited[curx-1][cury]=true, c.push(mat[curx-1][cury]), point++;
        if(mat[curx][cury+1]!=-1 && !visited[curx][cury+1] && abs(mat[curx][cury+1]-cost)<=tcost)
            in.first=curx, in.second=cury+1, po.push(in), visited[curx][cury+1]=true, c.push(mat[curx][cury+1]), point++;
        if(mat[curx][cury-1]!=-1 && !visited[curx][cury-1] && abs(mat[curx][cury-1]-cost)<=tcost)
            in.first=curx, in.second=cury-1, po.push(in), visited[curx][cury-1]=true, c.push(mat[curx][cury-1]), point++;
    }
    if(point>=ceil((n*n)/2))
        return 1;
    return 0;
}

int main()
{
    int low=0, hi=1000000;
    int i, j;
    for(i=0;i<=501;i++)
        for(j=0;j<=501;j++)
            mat[i][j]=-1;
    
    cin >> n;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            cin >> mat[i][j];
    
    while(low!=hi){
        bool cost=false;
        for(i=0;i<=501;i++)
            for(j=0;j<=501;j++)
                visited[i][j]=false;
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                if(!visited[i][j])
                    if(floodfill(i, j, (low+hi)/2)){
                        cost=true;
                        break;
                    }
        if(cost){
            if(low==hi)
                break;
            hi=(low+hi)/2;
        }
        else
            low=(low+hi)/2+1;
    }
    
    cout << low << endl;
    
    return 0;
}
