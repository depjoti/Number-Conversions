#include<iostream>
#include<math.h>
using namespace std;

class Inputs{

protected:
    double deci_1,deci_2;
    int *bin_1,*bin_2,digits,dcobn;

    public:

    void set_deci_1(double dec1)
    {
        deci_1=dec1;
    }
    void set_deci_2(double dec2)
    {
        deci_2=dec2;
    }
    void set_bin_1(int *bin1)
    {
        bin_1=bin1;
    }
    void set_bin_2(int *bin2)
    {
        bin_2=bin2;
    }
    void set_digits(int dig)
    {
        digits=dig;
    }
    void set_dec_of_bin(int dob)
    {
        dcobn=dob;
    }
};

class compliments:public Inputs{

public:
    int value;
    void r_dec( )
    {
        if(deci_1>0)
        value=(pow(10,digits)-deci_1);
        else
        value=(pow(10,1)-deci_1);

        cout<<"R's Compliment For"<<deci_1<<" = "<<value<<endl;
        digits=0;
    }
    void r_bin()
    {
        value=(pow(2,digits)-deci_2);
        cout<<value;
    }
};

class Subtractors:public Inputs
{
    public:
    int value;
    void subtract_with_r_dec( )
    {
        value=(pow(10,digits+1)-deci_2);
        value=deci_1+value;
        cout<<value<<endl;
    }
    void subtract_with_r_bin()
    {
        //cout<<deci_1<<"\n"<<deci_2;
        value=(pow(2,digits)-deci_2);
        cout<<value<<endl;
        value=value+deci_1;
    }
};


class BCD_CODES: public Inputs{

    public:
    void get_bcd_8421()
    {
        cout<<"BCD\t8\t4\t2\t1"<<endl;
        if(deci_1>=8)
        {
            cout<<"\t"<<(int)deci_1/8<<"\t";
            deci_1=(int)deci_1-8;
        }
        else
        cout<<"\t0";
        if(deci_1>=4)
        {
            cout<<(int)deci_1/4<<"\t";
            deci_1=(int)deci_1-4;
        }
        else
        cout<<"\t0\t";
        if(deci_1>=2)
        {
            cout<<(int)deci_1/2<<"\t";
            deci_1=(int)deci_1-2;
        }
        else
          cout<<"0\t";
        if(deci_1>0)
        cout<<(int)deci_1/1<<endl;
        else
           cout<<"0\t"<<endl;
    }
    void get_ex_3()
    {
        cout<<"Code For Ex-3"<<endl;
        while(digits>0)
        {
            cout<<bin_1[digits-1];
            digits--;
        }
        cout<<endl;
    }
    void get_84_2_1();
    void get_2421();
    void get_5043210();
};

class Gray_code:public Inputs{

public:
    int flag;
    void Bin_to_gray()
    {
        while(flag<digits)
        {
            cout<<bin_1[flag];
            flag++;
        }
        cout<<endl;
        flag=0;
        while(flag<digits)
        {
            cout<<bin_2[flag];
            flag++;
        }
        cout<<endl;
    }

    void Gray_to_Binary()
    {
        while(flag<digits)
        {
            cout<<bin_2[flag];
            flag++;
        }
        cout<<endl;
        flag=0;
        while(flag<digits)
        {
            cout<<bin_1[flag];
            flag++;
        }
    }
};

class decoder:public Inputs{
    public:
    void Three_line_decoder();
    void Four_line_decoder();
};

int bin1[10],bin2[10],bin_ext[10];
int dec1=0,dec2=0,digits=0,inpt,i=0;

int get_digits(int dec)
{
    digits=0;
    while(dec>0)
    {
        dec=dec/10;
        digits++;
    }
    return digits;
}
void binary_to_decimal( )
{
    int j=0,k=i-1;
    while(j<i)
    {
        dec2=dec2+bin1[j]*pow(2,k);
        j++;
        k--;
    }
}

void binary2_to_decimal( )
{
    int j=0,k=i-1;
    while(j<i)
    {
        dec2=dec2+bin2[j]*pow(2,k);
        j++;
        k--;
    }
}
int get_binary_digits(int dec)
{
    digits=0;
    while(dec>0)
    {
        bin_ext[digits]=dec%2;
        dec=dec/2;
        digits++;
    }
    return digits;
}
void get_gray_code()
{
    i=0;
    dec1=0;
    bin2[i]=bin1[i];
    while(i<inpt)
    {
        dec1=bin1[i]+bin1[i+1];
        if(dec1==1)
            bin2[i+1]=1;
        else
            bin2[i+1]=0;
        i++;
    }
}
void get_binary_from_gray()
{
    i=0;
    dec1=0;
    bin_ext[i]=bin2[i];
    while(i<inpt)
    {
        dec1=bin_ext[i]+bin2[i+1];
        if(dec1==1)
            bin_ext[i+1]=1;
        else
            bin_ext[i+1]=0;
        i++;
    }
}





int main()
{
    int opt;
    cout<<"1.Compliments\n2.Subtraction BY Compliments\n3.BCD_CODES\n4.Gray_Code_Conversions\n5.Decoders"<<endl;
    cin>>opt;
    switch(opt)//main switch starts
    {
    case 1:
        {//compliment case 1 starts
            compliments n1;
            cout<<"1.R's Compliment Of Decimal\n2.R's Compliment Of Binaries"<<endl;
            cin>>opt;
            switch(opt)//switch from compliments
            {
            case 1:
                {//compliments case for decimal starts
                    cin>>dec1;
                    n1.set_deci_1(dec1);
                    get_digits(dec1);
                    n1.set_digits(digits);
                    n1.r_dec();
                }//ends
                break;
            case 2:
                {//for binary starts
                    cin>>inpt;
                    while(i<inpt)
                        {
                            cin>>bin1[i];
                            i++;
                        }
                    n1.set_bin_1(bin1);
                    n1.set_digits(inpt);
                    binary_to_decimal();
                    n1.set_deci_2(dec2);
                    n1.r_bin();
                }//binary ends
                break;
            }//switch from compliments ends
        }//main switch case 1 of compliments ends
        break;
            case 2:
                {//subtraction case starts
                    Subtractors s1;
                    cout<<"1.Subtraction Of R's Compliment Of Decimal\n2.Subtraction Of R's Compliment Of Binaries"<<endl;
                    cin>>opt;
                    switch(opt)//subtraction switch starts
                    {
                        case 1:
                                {//case 1 is for decimal starts
                                    cin>>dec1;
                                    cin>>dec2;
                                    s1.set_deci_1(dec1);
                                    s1.set_deci_2(dec2);
                                    get_digits(dec2);
                                    inpt=digits;
                                    s1.set_digits(digits);
                                    s1.subtract_with_r_dec();
                                    get_digits(s1.value);
                                    if(digits>inpt)
                                    {
                                        i=0;
                                        while(i<digits-1)
                                        {
                                            bin1[i]=s1.value%10;
                                            s1.value=s1.value/10;
                                            i++;
                                        }
                                        i--;
                                        cout<<"Subtracted Value = ";
                                        while(i>=0)
                                        {
                                            cout<<bin1[i];
                                            i--;
                                        }
                                    }
                                    else
                                    {
                                        cout<<(pow(10,digits)-s1.value);
                                    }
                                }//case 1 for decimal ends
                    break;
                    case 2:
                                    {//case 2 for binary subtraction starts
                                        cout<<"1st binary digit"<<endl;
                                        cin>>inpt;
                                        dec1=inpt;
                                        while(i<inpt)
                                        {
                                            cin>>bin1[i];
                                            i++;
                                        }
                                        binary_to_decimal();
                                        s1.set_deci_1(dec2);
                                        i=0;
                                        dec2=0;
                                        cout<<"Second Binary Digit"<<endl;
                                        cin>>inpt;
                                        while(i<inpt)
                                        {
                                            cin>>bin2[i];
                                            i++;
                                        }
                                        binary2_to_decimal();
                                        s1.set_deci_2(dec2);
                                        s1.set_bin_1(bin1);
                                        s1.set_bin_2(bin2);
                                        s1.set_digits(inpt);
                                        s1.subtract_with_r_bin();
                                        digits=get_binary_digits(s1.value);
                                        if(digits>dec1)
                                        {
                                            i=0;
                                            while(i<dec1)
                                            {
                                                bin1[i]=s1.value%2;
                                                s1.value=s1.value/2;
                                                i++;
                                            }
                                            i--;
                                            while(i>=0)
                                            {
                                                cout<<bin1[i];
                                                i--;
                                            }
                                        }
                                        else
                                        {
                                            digits=get_binary_digits(s1.value);
                                            cout<<(pow(2,digits)-s1.value);
                                        }
                                    }//case 2 for binary subtraction ends
                                    break;
                    }//subtraction switch ends
                }//main subtraction case ends
        break;
        case 3:
          {//main case for bcd starts
                BCD_CODES b1;
                i=0;
                     cout<<"Enter 4 Bits"<<endl;
                      while(i<4)
                    {
                        cin>>bin1[i];
                        i++;
                    }
                    b1.set_bin_1(bin1);
                    binary_to_decimal();
                    digits=get_binary_digits(dec2+3);
                    b1.set_digits(digits);
                    b1.set_bin_1(bin_ext);
                    b1.get_ex_3();
                    cout<<"\nEnter A Decimal Less than 16"<<endl;
                    cin>>dec1;
                    b1.set_deci_1(dec1);
                    b1.get_bcd_8421();
          } //main class for bcd ends
        break;
        case 4:
            {//main class for gray code starts
                    Gray_code g1;
                    cin>>inpt;
                    while(i<inpt)
                    {
                        cin>>bin1[i];
                        i++;
                    }
                    g1.set_digits(inpt);
                    g1.set_bin_1(bin1);
                    get_gray_code();
                    g1.set_bin_2(bin2);
                    g1.flag=0;
                    g1.Bin_to_gray();
                    get_binary_from_gray();
                    g1.set_bin_1(bin_ext);
                    g1.flag=0;
                    g1.Gray_to_Binary();
            }//main class for gray code ends
            break;
        default :
            cout<<"Invalid Inputs!!!!!!"<<endl;
    }//main switch ends
    return 0;
}
