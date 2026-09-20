class Solution {
public:
    int reverseDegree(string s) {
        int sum=0;
        for(int i=0;i<s.length();i++)
         sum+=(26-(s[i]-'a'))*(i+1);
         // s[i]=a  ->  26- (a - a) =26.. a=26
         // s[i]=z  ->  26 - (z-a) = 26 - 25 = 1
        
        return sum;
    }
};