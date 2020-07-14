#include<iostream>
#include<string>

using namespace std;

int Char2Num (char ch, int i, int c)
{
    int val;
    switch(ch)
    {
        case '0': val = 0 * i + c; 
        break;
        case '1': val = 1 * i + c;
        break;
        case '2': val = 2 * i + c;
        break;
        case '3': val = 3 * i + c;
        break;
        case '4': val = 4 * i + c;
        break;
        case '5': val = 5 * i + c;
        break;
        case '6': val = 6 * i + c;
        break;
        case '7': val = 7 * i + c;
        break;
        case '8': val = 8 * i + c;
        break;
        case '9': val = 9 * i + c;
        break;
    }
    return val;
}

char digit2char (int c)
{
    char ch;
    switch(c)
    {
        case 0: ch = '0'; 
        break;
        case 1: ch = '1'; 
        break;
        case 2: ch = '2'; 
        break;
        case 3: ch = '3'; 
        break;
        case 4: ch = '4'; 
        break;
        case 5: ch = '5'; 
        break;
        case 6: ch = '6'; 
        break;
        case 7: ch = '7'; 
        break;
        case 8: ch = '8'; 
        break;
        case 9: ch = '9'; 
        break;
    }
    return ch;
}

string largeFactorial(int A) 
{
    string s="1";
    int c = 0;
    for(int i=1;i<=A;i++)
    {
        if(i==1)
            s = "1";
        else
        {
            for(int j=s.length()-1;j>=0;j--)
            {
                char ch = s[j];
                int val = Char2Num(ch,i,c);
                c = (val / 10);
                val = val % 10;
                s[j] = digit2char(val);
            }
            if(c!=0)
            {
                while(c)
                {
                    s = " " + s;
                    s[0] = digit2char(c%10);
                    c = c / 10;
                }
            }
        }
    }
    return s;
}

int main()
{
    int n;
    cin>>n;
    cout<<largeFactorial(n)<<endl;
}