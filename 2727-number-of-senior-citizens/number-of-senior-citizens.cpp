class Solution {
public:
    int countSeniors(vector<string>& details){
        int count=0;
        // vector<int>age;
        int age=0;
    for(int j=0;j<details.size();j++){
        for(int i=11;i<13;i++){
            age = age * 10 + (details[j][i] - '0');
        }
        if(age>60)count++;
        age=0;

        }
  
      return count;  
    }
};