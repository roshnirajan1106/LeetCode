class Solution {
public:
    bool overlap(int small1,int small2, int large1,int large2)
    {
        cout<<small1<<" "<<small2<< " "<<large1<<" "<<large2<<endl;
        if(small1 == small2)
            return true;
        if(large1  >= small2)
            return true;
        
        return false;
        
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() == 0 || intervals.size() == 1)
            return intervals;
        
        vector<vector<int>>res; 
        int i =0 ; 
        int j = 1;
        sort(intervals.begin(),intervals.end());
        
        int n = intervals.size();
        while( i < n)
        {
            if(j== n || overlap(intervals[i][0] , intervals[j][0],intervals[i][1],intervals[j][1]) == false  )
            {
                res.push_back(intervals[i]);
               // cout<<"hey"<<endl;
            }else{
               // cout<<"hello"<<endl;
                intervals[j][0]  = intervals[i][0];
                intervals[j][1] = max(intervals[j][1],intervals[i][1]);
            }
            
            i++;
            j++;
        }
        return res;
    }
};