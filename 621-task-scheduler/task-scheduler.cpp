class Solution {
public:
    int leastInterval(vector<char>& t, int n) {
        map<char,int> m;
        priority_queue<int> pq;
        for(int i=0;i<t.size();i++){
            m[t[i]]++;
        }

        for(auto i:m){
            pq.push(i.second);
        }

        int ans=0;
        vector<int> pt;
        while(pq.size()>0){
            for(int i=0;i<=n;i++){
                if(pq.size()){
                    int tt=pq.top();
                    pq.pop();
                    tt--;
                    if(tt>0) pt.push_back(tt);
                }else{
                    if(pt.size() == 0){
                        break;
                    }
                }
                ans++;
            }

            for(int i=0;i<pt.size();i++){
                pq.push(pt[i]);
            }

            pt.clear();
        }

        return ans;
    }
};