class Solution {
public:
bool checkpel(string s){
        string output="";
        int n=s.length();
        for(auto ch:s){
            if(isalnum(ch))output+=tolower(ch);
        }
        cout<<output;
        int m=output.length();
        bool check=true;
        int i=0;
        int j=m-1;
        while(i<j){
            if(output[i]!=output[j]){
                check=false;
                break;
            }else{
                i++;
                j--;
            }
        }
      return check;  
}
    string firstPalindrome(vector<string>& words) {
        string ans="";
        for(auto str:words){
            if(checkpel(str)){
                ans=ans+str;
                break;
            }
        }
    return ans;  
    }
};