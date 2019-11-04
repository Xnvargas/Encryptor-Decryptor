#include <iostream>
#include <fstream>
#include<string>
#include<cctype>
#include<cstdlib>
#include<time.h>
#include<map>

using namespace std;

char cyph(char il,map<char,char>cyphmp)
{
   std::map<char,char>::iterator it=cyphmp.begin();
    it=cyphmp.find(il);
    if(it !=cyphmp.end())
    {
        char rez;
        rez=it->second;
        return rez;
    }
    return il;
}
bool checkr(char lo,map<char,char>cyphmp)
{
    std::map<char,char>::iterator it=cyphmp.begin();
    while(it!= cyphmp.end())
    {
        if(lo==it->second)
            return false;
    }
    return true;

}




std::string Rot13(std::string input)
{
    for (std::string::size_type len = input.length(),idx=0;idx!=len;++idx)
    {
        if (input[idx] >= 'a' && input[idx] <='m')
        {
            input[idx] = input[idx]+13;

        }
        else if(input[idx] >='n' && input[idx] <= 'z')
        {
            input[idx] = input[idx] -13;
        }
        else if(input[idx] >='A' && input[idx]<='M')
        {
            input[idx]= input[idx] + 13;
        }
        else if(input[idx] >= 'N' && input[idx]<= 'Z')
        {
            input[idx]= input[idx]-13;
        }
    }
    return input;
}







int main(int argc, char*argv[])
{
        if(argc<2)
            {
            cerr<<"MISSING COMMAND"<<endl;
            return -1;
            }
        if(argc>4)
        {
            cerr<<"TOO MANY ARGUMENTS"<<endl;
            return -1;
        }
        string first= argv[1];
        if (first=="-r")
                        {
                        if (argc==3){
                         ifstream infile;
                         while(infile.eof()==false)
                        {
                        if (infile.fail()== false)
                            {
                            infile.open(argv[2]);
                            if(infile.is_open()==false)
                            {
                            cerr<<argv[2]<<"FILE CANNOT BE OPENED"<<endl;
                            return -1;
                            }
                            else
                                {
                                    string olk;
                                    while(getline(infile,olk))
                                    {
                                    cout<<Rot13(olk)<<endl;
                                    }
                                    infile.close();
                                    return 0;
                                }

                            }
                            if(infile.fail())
                            break;

                            }
                            }
                            if (argc==4)
                            {

                            }

                            else
                        {

                            string stril;
                            while (getline(cin,stril))
                            {
                                stril.push_back('\n');
                                cout<<Rot13(stril);
                            }
                        return 0;
                        }
                    }

            else if (first=="-g")
                {
                    srand(time(NULL));
                    string alph[26];
                    for(int i=0;i<26;i++)
                    {
                        alph[i]=i+'a';
                    }
                    int alphsize=26;
                    for (int i=0;i<26;i++)
                    {
                        int val=rand()%alphsize;
                        cout<<alph[i]<<alph[val]<<endl;
                        alph[val]=alph[alphsize-1];
                        alphsize --;

                    }



                    return 0;
                }
                else if (first=="-e" || first=="-d")
                {
                    if (argc==3){
                         ifstream infile;
                         while(infile.eof()==false)
                        {
                            if (infile.fail()== false)
                            {
                            infile.open(argv[2]);
                            if (!infile.is_open())
                                {
                                    cerr << argv[2] << " DICTIONARY COULD NOT BE OPENED" << endl;
                                return -1;
                                }
                            else
                                {
                                    string olk,prealph;
                                    map<char,char> mpOne;
                                    while(getline(infile,olk))
                                    {
                                        prealph+=olk;
                                    }
                                    string alphabet,ciphertext;
                                    for(int i=0;i<prealph.length();i+=2)
                                    {
                                        alphabet+=prealph[i];
                                        ciphertext+=prealph[i+1];
                                    }
                                    for (int i = 0; i < 26; i++)
{
    if ((i + 97) != alphabet[i])
       {
               cerr << "MISSING LETTER " << char(i + 'a') << endl;
                 return -1;
        }
        for (int q = i + 1; q < 26; q++)
        {
               if (ciphertext[i] == ciphertext[q])
               {
                   cerr << "DUPLICATE CIPHERTEXT " << ciphertext[i] << endl;
                     return -1;
                  }
        }
}



                                    infile.close();

                                    return 0;
                                }

                            }
                            else
                                break;
                            }
                            }
                            if (argc==4)
                            {
                                ifstream infile;
                                infile.open(argv[3]);
                                if (!infile.is_open())
                                {
                                    cerr << argv[3] << " FILE COULD NOT BE OPENED" << endl;
                                return -1;
                                }

                            }
                            else
                            {
                                cout<<"NO DICTIONARY GIVEN"<<endl;
                                return 0;
                            }
                }

                else
                    {
                    cout<<argv[1]<<" NOT A VALID COMMAND"<<endl;
                    }


    return 0;
}

