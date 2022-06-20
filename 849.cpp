class Solution {
public:
    int maxDistToClosest(vector<int>& seats) 
    {
        int longest = 0, beginning = 0, i = 0;
        // count zeros in beginning
        while (seats[i]==0)
        {
            beginning++;
            i++;
        }
        // find longest sequence of zeros in middle
        int count = beginning;
        for (; i<seats.size(); i++)
        {
            if (seats[i] == 0)
                count++;
            else
            {
                longest = max({count, longest});
                count = 0;
            }
        }
        // at the end, count = length of zeros in the end
        // in the middle we have to divide the length in two to find maximum distance
        longest = longest%2==0?longest/2:longest/2+1;
        // return the largest distance
        return max({longest, count, beginning});
        // int x=0,max=0;
        // int count=0;
        // for(int i=0;i<v.size();i++)
        // {
        //     if(v[i]==0)
        //     {
        //         while(v[i]==0 && i<v.size())
        //         {
        //             count++;
        //             i++;
        //         }
        //     }
        //     if(max<count)
        //         max=count;
        //     count=0;
        //     if(i==v.size())
        //         break;
        // }
        // if(max==1)
        //     return 1;
        // return max/2+1;
    }
};
