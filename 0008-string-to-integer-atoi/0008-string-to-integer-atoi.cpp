class Solution {
public:
    int myAtoi(string str) {
//         long long int result=0;
//         int sign=1;
//         for(int i=0;i<s.length();i++)
//         {
//             cout<<s[i]<<endl;
//             int a=s[i]-'0';
//             cout<<a<<endl;
//             if(a>=0 && a<=9)
//             {
//                 if(a==0)
//                 {
//                     result=a;
//                 }
//                 else{
//                     result=result*10+a;
//                 }
//             } 
            
//             if(s[i]=='-')
//             {
//                 sign=-1;
//             }
//         }
        int sign = 1, pt = 0; 
        long long base = 0;
        while (str[pt] == ' ')
            pt++;
        if (str[pt] == '+' || str[pt] == '-')
            sign = 1 - 2 * (str[pt++] == '-');
        while (str[pt] >= '0' && str[pt] <= '9') {
            base = 10 * base + (str[pt++] - '0');
            if (base > INT_MAX)
                return sign == 1 ? INT_MAX : INT_MIN;
        }
        return (int) (base * sign);
        // return result*sign;
    }
};