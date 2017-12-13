/**
计算乘法
num1[i] * num2[j] -> ans[i+j], ans[i+j+1]
ans[i+j+1]先计算完，可以直接赋值
ans[i+j]需要存储进位，+=
*/
class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> ans(num1.size()+num2.size(), 0);
        
        for( int i = num1.size()-1; i >= 0; i-- ){
            for( int j = num2.size()-1; j >= 0; j-- ){
                int div = (num1[i]-'0') * (num2[j]-'0');
                int sum = ans[i+j+1] + div;
                ans[i+j+1] = sum%10;
                ans[i+j] += sum/10;
            }
        }
        string ansstr = "";
        int flag = 0;
        for( auto p: ans ){
            if( p != 0 || flag ){
                ansstr += (p+'0');
                flag = 1;
            }
        }
        return (ansstr.size()==0) ? "0" : ansstr;
    }
};
