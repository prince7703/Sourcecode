 vector<int> dailyTemperatures(vector<int>& t) {
        
        stack<pair<int,int>>stk;
        int n=t.size();
        vector<int>ans(n,0);

        for(int i=n-1;i>=0;i--)
        {
            if(stk.empty())
            {
                stk.push({t[i],i});
                ans[i]=0;

            }
            else if(stk.top().first<=t[i])
            {
                while( !stk.empty() && stk.top().first<=t[i] )
                {
                    stk.pop();
                }

                if(stk.empty())
                {
                    
                    ans[i]=0;
                }
                else
                {
                    ans[i]=stk.top().second-i; 
                }
                stk.push({t[i],i});

            }
            else{
                   ans[i]=stk.top().second-i; 
                   stk.push({t[i],i});
            }

        }
        return ans;
    }
