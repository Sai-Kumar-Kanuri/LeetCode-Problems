class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        
        int a1=abs((ax1-ax2)*(ay1-ay2));
        int a2=abs((bx1-bx2)*(by1-by2));
        cout<<a1<<" "<<a2<<endl;
        
        int x=min(ax2,bx2)-max(ax1,bx1);
        int y=min(ay2,by2)-max(ay1,by1);
        
        int c=0;
        if(x>0 && y>0)
        {
            c=x*y;
        }
        cout<<c<<endl;
        
        return a1+a2-c;
        
    }
};