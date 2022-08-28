#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <conio.h>
#include <iomanip>
#include <stdlib.h>

using namespace std;
///lower case alphabets.
char lower_alpha[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
int incorrectArrangement(string input)
{
    string line;
    int found = 0;
    ifstream words ("words.txt");
    if (words)
    {
        while(getline(words,line))
        {
            string Xinput = input, Ninput, permutations, Tinput, Tline, Nline, Xline = line;
            int len = Xinput.size(), flen = line.size();
            if (len == flen)
            {
                for (int i=1; i<Xinput.length(); i++)
                    Ninput.push_back(input[i]);
                for (int i = 1; i < flen; i++)
                    Nline.push_back(Xline[i]);
                Xinput.resize(1);
                Xline.resize(1);
                sort(Nline.begin(),Nline.end());
                sort(Ninput.begin(), Ninput.end());
                Tinput = Xinput + Ninput;
                Tline = Xline + Nline;
                if (Tinput == Tline)
                {
                    found = 1;
                    cout<<line<<" , ";
                    break;
                }
            }
        }
        words.close();
    }
    else
    {
        cout<<endl<<"Unexpected error occurred......."<<endl;
    }
    return found;
}

///function to show correct spelling if exchanged character is present in the given word
int exchangedCharacters (string input)
{
    string line, Xinput;
    int found = 0;
    ifstream words ("words.txt");
    if (words)
    {
        while (getline(words,line))
        {
            int len = input.size(), flen = line.size();
            if (len == flen)
            {
                for (int i = len-1; i >= 0 ; i--)
                {
                    Xinput = input;
                    Xinput[i] = lower_alpha[0];
                    for (int j=0; j<26; j++)
                    {
                        if (Xinput == line)
                        {
                            found = 1;
                            cout<<line<<" , ";
                            break;
                        }
                        Xinput[i] = lower_alpha[j];
                    }
                    if (found == 1 ) break;
                    else continue;
                }
            }
        }
        words.close();
    }
    else cout<<"\nUnexpected error occurred"<<endl;
    return found;
}
///function to show correct spelling if mixedExtraMissing character is present in the given word
int mixedExtraMissing (string input)
{
    string Xinput, line, Xline;
    int found = 0;
    ifstream words ("words.txt");
    if (words)
    {
        while (getline(words,line))
        {
            int len = input.size(), flen = line.size();
            if (len == flen)
            {
                for (int i = 1; i < len; i++)
                {
                    for (int j = 0; j < 26; j++)
                    {
                        Xinput = input; Xline = line;
                        Xinput.erase(Xinput.begin()+i);
                        Xinput.resize(len, 'a');
                        Xinput[len-1] = lower_alpha[j];
                        sort(Xinput.begin()+1,Xinput.end());
                        sort(Xline.begin()+1,Xline.end());
                        if (Xinput == Xline)
                        {
                            found = 1;
                            cout<<line<<" , ";
                            break;
                        }
                    }
                    if (found == 1) break;
                }
                if (found == 1) break;
            }
        }
        words.close();
    }
    return found;
}
///function to show correct spelling if Extra character is present in the given word
int extraCharacter (string input)
{
    string Xinput, line, Ninput, Tinput;
    int found = 0;
    ifstream words ("words.txt");
    if (words)
    {
        while (getline(words,line))
        {
             int len = input.size(), flen = line.size();
             if ((len-1) == flen)
             {
                 for (int i = 1; i < len; i++)
                 {
                     Xinput = input;
                     Xinput.erase(Xinput.begin()+i);
                     if (Xinput == line)
                     {
                         found = 1;
                         cout<<line<<" , ";
                         break;
                     }

                 }
             }
        }
        words.close();
    }
    else
    {
        cout<<"\nUnexpected error occurred\n";
    }
    return found;
}

///function to show correct spelling if missinChar error is present in the given word
int missingChar(string input)
{
    string Xinput, line, Tinput, Tline, Xline;
    int found = 0;
    ifstream words ("words.txt");
    if (words)
    {
        while (getline(words,line))
        {

            for (int i = 0; i < 26; i++)
            {

                int len = input.size(), flen = line.size();
                Xinput = input;
                Xline = line;
                Xinput.resize(len+1,'a');
                Xinput[len] = lower_alpha[i];
                len = Xinput.size();
                string Ninput, Nline;
                if (len == flen)
                {
                    for (int j = 1; j <=len; j++)
                        Ninput.push_back(Xinput[j]);
                    for (int j = 1; j <= flen; j++)
                        Nline.push_back(Xline[j]);
                    Xinput.resize(1);
                    Xline.resize(1);
                    sort(Nline.begin(),Nline.end());
                    sort(Ninput.begin(),Ninput.end());
                    Tinput = Xinput + Ninput;
                    Tline = Xline + Nline;
                    if (Tinput == Tline)
                    {
                        found = 1;

                        cout<<line<<" , ";
                        break;
                    }
                }
                if (found == 1) break;
            }
            if (found == 1) break;
        }
        words.close();
    }
    else
    {
        cout<<"\nUnexpected error occurred\n";
    }
    return found;
}

void spellcheck()
{
    string input,line,first,ans;
    int len,flen,correct=0,cnt=0;
    system("CLS");

    cout<<endl<<endl;
    cout<<setw(67)<<"SPELL CHECKER"<<endl;
    cout<<setw(69)<<"------------------"<<endl<<endl<<endl;
    cout<<setw(20)<<"Enter the word / sentence to be checked: ";
    getline(cin,input);

    istringstream iss(input);
    while(iss>> first)
    {

     for(int i=0;i<first.length();i++)
       first[i]=tolower(first[i]);
       len=first.length();

     ifstream words;
     words.open("words.txt");               //ifstream to read file
    if(words)
      {
          //cout<<"File found"<<endl;

          while (getline(words,line))
           {

              flen = line.length();

              if (len==flen)
                {
                  if (line==first)
                    {
                      correct=1;
                    }
                      else continue;
                }
              else continue;
           }

          words.close();
          if (correct==1)
          {
             cnt=cnt+1;


            correct=0;
          }

          else if(correct==0)
             {

                int missing = 0, extra = 0, mixed = 0, incorrect = 0, exchanged = 0,i=0;
                cout<<endl<<endl<<"--------------------------------------------"<<endl;
                cout<<endl<<"Incorrect Words : "<<first<<endl;
                cout<<endl<<"Suggested words : ";

                missing = missingChar(first);
                extra = extraCharacter(first);
                mixed = mixedExtraMissing(first);
                incorrect = incorrectArrangement(first);
                exchanged = exchangedCharacters(first);


                if (missing == 0 && extra == 0 && mixed == 0 && incorrect == 0 && exchanged == 0)
                {
                    cout<<endl<<"No such word exist"<<endl;
                }

             }
      }

    }
     fstream file;
    file.open ("example.txt", ios::app | ios::in );          //ios::app for append the data and ios::in for read the file.

    // Writing on file
    file << input << endl;
file.close();


    if(cnt==1 )
      cout<<"spelling is correct";

}

int open_file(int i)
{
  system("CLS");
  string data;
  ifstream words("example.txt");
  cout<<endl;


  {
    cout<<"***History***"<<endl;
    cout<<"  __________________ "<<endl;
    while(getline(words,data))

    {

      cout<<endl<<i<<". "<<data<<endl;
      i++;
    }
    cout<<endl<<"______________________ ";
    return (i);

  }
}

int main()
{
  string name;
  int choice;
  char ch;
  int i=1;

 system("CLS");

  do
  {
  cout<<endl<<endl;

  cout<<setw(56)<<"CHOICES"<<endl;
  cout<<setw(59)<<"-------------";
   cout<<endl;

  for(int i=0;i<4;i++)
    cout<<endl;

  cout<<setw(56)<<"1.Want to check spelling?"<<endl<<endl;

  cout<<setw(70)<<"2.Want to See previously checked words?"<<endl<<endl;

  cout<<setw(37)<<"3.EXIT"<<endl<<endl;

  cout<<setw(56)<<"Your Choice == ";
  cin>>choice;

  fflush(stdin);

  switch(choice)
  {
    case 1:
      spellcheck();
      break;
    case 2:
      open_file(i);
      break;
    case 3:
      exit(0);
    default:
      break;

  }
    cout<<endl<<endl<<"Want to Continue?('y' or 'n') : "<<endl<<endl;
    scanf("%c",&ch);
    system("CLS");
  } while(ch=='y');
    if(ch=='n')
    {
      cout<<"Thank you"<<endl<<endl;
    }

return 0;
}


