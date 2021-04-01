// Question:
Given two integers a and b, return the sum of the two integers without using the operators + and -.

 

Example 1:

Input: a = 1, b = 2
Output: 3
Example 2:

Input: a = 2, b = 3
Output: 5
 

Constraints:

-1000 <= a, b <= 1000

// Code:
class Solution {
public:
    int getSum(int a, int b) {
        
        int tmp;
        int carry = 0;
        int res=0;
        int r1 = a;
        int r2 = b;
        a =abs(a);
        b = abs(b);
        
        if(a == r1 && b==r2 || (a==-1*r1) && (b == -1*r2)) {
                for(int i=0;i<10;i++) {       

                    if((a>>i&1) == 1 &&  (b>>i&1)==1 && carry == 0) {
                        carry = 1; 
                    } else if((a>>i&1) == 1 &&  (b>>i&1)==1 && carry == 1) {
                        res |= (1<<i);
                        carry = 1;
                    } else if(((a>>i&1) == 0) &&  ((b>>i&1)==0) && carry == 0) {
                        carry = 0;              
                    } else if(((a>>i&1) == 0) &&  ((b>>i&1)==0) && carry == 1) {
                        carry = 0; 
                        res |= (1<<i);
                    } else if(((a>>i&1) == 0) &&  ((b>>i&1)==1) && carry == 1) {
                        carry = 1;        

                    } else if(((a>>i&1) == 1) &&  ((b>>i&1)==0) && carry == 1) {
                       carry = 1; 
                    } else {
                        res |= (1<<i);
                        carry = 0;
                    }
                }
            if((a==-1*r1) && (b == -1*r2)) {
                return -1*res;
            }
            return res;
        } else {
            if(a>b) {
                b = -1*b;
            } else {
                a = -1*a;
            }
            for(int i=0;i<10;i++) {       

                    if((a>>i&1) == 1 &&  (b>>i&1)==1 && carry == 0) {
                        carry = 1; 
                    } else if((a>>i&1) == 1 &&  (b>>i&1)==1 && carry == 1) {
                        res |= (1<<i);
                        carry = 1;
                    } else if(((a>>i&1) == 0) &&  ((b>>i&1)==0) && carry == 0) {
                        carry = 0;              
                    } else if(((a>>i&1) == 0) &&  ((b>>i&1)==0) && carry == 1) {
                        carry = 0; 
                        res |= (1<<i);
                    } else if(((a>>i&1) == 0) &&  ((b>>i&1)==1) && carry == 1) {
                        carry = 1;        

                    } else if(((a>>i&1) == 1) &&  ((b>>i&1)==0) && carry == 1) {
                       carry = 1; 
                    } else {
                        res |= (1<<i);
                        carry = 0;
                    }
                }
            if(a!=r1 || b!= r2) {
                return -1*res;
            }
            return res;
        }
        
        return res;
     }
    
};