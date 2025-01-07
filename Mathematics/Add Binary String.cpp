#Time and Space Complexity is O(N+M)

class Solution
{
public:
    string addBinary(string num1, string num2)
    {
        if(num1=="0")
        {
            return num2;
        }
        if(num2=="0")
        {
            return num1;
        }
        
        if(num2.size()>num1.size())
        {
            return addBinary(num2,num1);  /* Assuming num1 always greater or equal */
        }
        
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        
        int i=0;
        int j=0;
        int carry=0;
        int data=0;
        string ans="";
        
        while(i<num1.length()&&j<num2.length())
        {
            data=(num1[i]-'0'+num2[j]-'0'+carry);
            carry=data/2;
            data=data%2;
            ans.push_back(data+'0');
            i++;
            j++;
        }
        while(i<num1.size())
        {
            data=(num1[i]-'0'+carry);
            carry=data/2;
            data=data%2;
            ans.push_back(data+'0');
            i++;
        }
        if(carry)
        {
            ans.push_back(carry+'0');
        }
        reverse(ans.begin(),ans.end());
        return ans;    
    }
};
