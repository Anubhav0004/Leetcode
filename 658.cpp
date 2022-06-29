class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) 
    {
        //binary search optimistaion
        int n = arr.size();
        int left = 0, right = n - k, startIdx = 0;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (mid+k == n || x - arr[mid] <= arr[mid+k] - x) {
                startIdx = mid; // Found a valid answer -> Update
                right = mid - 1; // Try to find the left most answer in the left side
            } else {
                left = mid + 1; // Find in the right side
            }
        }
        return vector<int>(arr.begin() + startIdx, arr.begin() + startIdx + k);
        
         //two pointers
        int left = 0, right = arr.size()-1;
        
        while (right - left + 1 > k) {
            
            if (arr[right] - x < x - arr[left]) left++;
            else right--;
        }
        
        return vector<int>(arr.begin() + left, arr.begin() + right + 1);
        
        // max heap bnani aa;
        priority_queue<pair<int,int>> hp;
        vector<int> op;
        for(int i=0;i<arr.size();i++)
        {
            int val=abs(arr[i]-x);
            hp.push({val,arr[i]});
            if(hp.size()>k)
            {
                hp.pop();
            }  
        }
        while(hp.size()!=0)
        {
            op.push_back(hp.top().second);
            hp.pop();
        }
        sort(op.begin(),op.end());
        return op;
    }
};
