class compare {
    public:
        bool operator()(pair<int, int> a, pair<int, int> b)
        {
            if(a.second == b.second)
                return a.first < b.first;
            return a.second > b.second;    
        }
};

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        
        int n = nums.size();
        unordered_map<int, int> mp;

        for(auto x : nums)
            mp[x]++;

        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;   

        for(auto it : mp)
            pq.push({it.first, it.second});

        int i = 0;
        while(!pq.empty())
        {
            int value = pq.top().first;
            int freq = pq.top().second;
            pq.pop();

            while(freq--)
                nums[i++] = value;

        }     

        return nums;
    }
};