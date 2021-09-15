#include <iostream>
#include <fstream>
using namespace std;

int main ()
{
	int ans, key;
	string st,ft;
	cout<<"Press 1 to Encrypt a file.\n Press 2 to Decrypt a file."<<endl;
	cin>>ans;
	cout<<"Enter File Name -"<<endl;
	cin>>st;
        cout<<"Enter File Type : "<<endl;
	cin>>ft;                            //assumed that user has entered '.' in front
	cout<<"Enter Key -"<<endl;
	cin>>key;

	if (ans == 1)
	{
		char c;
		ifstream fin;                         
		ofstream fout;
		fin.open(st.c_str(), ios::binary);    //string.c_ctr()  to convert a standard string into c string
		st = "Encrypted" + ft;                
		fout.open(st.c_str(), ios::binary);   //creating and opening new file named Encrypted+"ft" (ex- Encrypted.jpg) for writing
		while (!fin.eof())
		{
			fin>>noskipws>>c;   //reads the whitespaces with the help of noskipws
			int temp = (c + key);       //encryption technique
			fout<<(char)temp;        
		}
                
		fin.close();
		fout.close();
	}
	else if (ans == 2)
	{
		
		char c;
		ifstream fin;
		ofstream fout;                       // same as above except file name and technique
		fin.open(st.c_str(), ios::binary);
		st = "Decrypted" + ft;
		fout.open(st.c_str(), ios::binary);
		while (!fin.eof())
		{
			fin>>noskipws>>c;
			int temp = (c - key);            //decryption technique
			fout<<(char)temp;
		}
		fin.close();
		fout.close();
	}
        else
        cout<<"Invalid Choice";

}
