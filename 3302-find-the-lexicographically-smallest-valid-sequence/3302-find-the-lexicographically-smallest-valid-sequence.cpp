class Solution {
public:
    vector<int> validSequence(string word1, string word2) {

        int n = word1.size();
        int m = word2.size();
      vector<int>left(m,-1);
      vector<int>right(m,-1);

        // matching from Left 

        int x=0;
        for(int j=0;j<m;j++){
            while(x<n && word1[x]!=word2[j])
               x++;

            if(x==n)
             break;

            left[j]=x;
            x++;    
        }
        
        // matching from right

        x=n-1;
        for(int j=m-1;j>=0;j--){
            while(x>=0 && word1[x]!=word2[j])
               x--;

            if(x<0)
             break;

            right[j]=x;
            x--;    
        }

        // try each position as mismatch

        for(int j=0; j<m;j++){

            if(j>0 && left[j-1]==-1)
             break;

            if(j<m-1 && right[j+1]==-1)
              continue;

            //last index used by prefix
            int prev = (j==0 ? -1 : left[j-1]); 

            int mismatch = prev +1;

            if(mismatch <n && word1[mismatch]==word2[j]){
                mismatch ++;
            
            }

            int limit = (j==m-1 ? n : right[j+1]);

            if(mismatch >= limit)
              continue;

            if(left[j]!=-1 && mismatch >= left[j])
              continue;

            vector<int>answer;

            for(int k=0;k<j;k++)
             answer.push_back(left[k]);

            answer.push_back(mismatch);

            int pos = mismatch +1;
            for(int k=j+1;k<m;k++){
                while(pos<n && word1[pos]!=word2[k])
                  pos++;

                answer.push_back(pos);
                pos++ ;
            }

            return answer;

            }
            if (left[m-1]!=-1)
              return left;

            return {};      
        }
        
    };
