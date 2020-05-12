int myAtoi(string str) {
        int out=0;
        int sign=0;
        int integral=0;
        for(auto c: str)
        {
            if (c==' ')
            {
                if(integral==1 || sign)
                    break;
            }
            else if(c=='-' && sign==0)
                sign=-1;
            else if(c=='+' && sign==0)
                sign=1;
            else if(c>='0' && c<='9')
            {
                if(sign==0) sign=1;
                integral=1;
                if (out<214748364 ||(out==214748364 && c<='7'))
                    out*=10;                    
                else
                {
                    if(sign<0)
                        return INT_MIN;
                    else if (sign>0)
                        return INT_MAX;
                }
               
                out+=(c-'0');
            }
            else
            {
                if(integral==1)
                {
                    break;
                }
                else return 0;
            }
        }
        cout<<sign<<out;
        return (sign*out);
    }
