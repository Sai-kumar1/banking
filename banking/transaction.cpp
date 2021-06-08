//stl
#include"../includes.h"
#include<ctime>
#include<sstream>

//user includes
#include"../global.h"
#include"./transaction.h"

//user definitions
#define USER_DATA_PATH ".//database//"
#define USER_ID 1
#define NAME 2
#define PASWD 3
#define AC_TYPE 4
#define AMNT 5


//function to get time
string gettime(){
	time_t tt;
	struct tm* ti;

	time(&tt);

	ti=localtime(&tt);
	return (string)asctime(ti);
}


//function which simulates transaction
int transaction(){
	//getting the inputs from logged in user
	string to,amount;
	cout<<"To ( enter the username ):";
	cin>>to;
	cout<<endl;
	//checking if user enter his own username in 'to' tag
	if(to==username){cout<<"cannot send money to your account:"<<endl;return 1;}
	cout<<"Amount:";
	cin>>amount;

	//trying to open the user data
	try{
		fstream from_user,to_user;
		//opening present user files to check amounts
		string from_file=USER_DATA_PATH+username+"//info.txt";
		from_user.open(from_file,fstream::in);
		string data;
		for(int i=0;i<AMNT;i++){ getline(from_user,data); }
		
		cout<<data<<endl;
		// trying to check if the 'to user' exist or not
		string file;
		try{
		file = DATA_PATH+to+"//info.txt";
		to_user.open(file,fstream::in);//opening file in write mode
		}
		catch(char*  e){
			cout<<"Msg : no such user\nTransaction aborted.\n";
			return 1;
		}

		// closing the opened files
		to_user.close();
		from_user.close();
		//for(int i=0;i<AMNT;i++){ getline(to_user,to_data); }
		
		// converting string to num using sstream library
		//bk_bl -> bankbalance fund->funds to transfer
		int bk_bl,fund;
		stringstream s1;s1<<data;s1>>bk_bl;
		stringstream s2;s2<<amount;s2>>fund;

		cout<<data<<","<<bk_bl<<","<<fund<<endl;

		// checking if the funds entered by the logged_in user is in his account or not
		if(bk_bl<fund){ cout<<"You have low funds in your account.\nTransaction aborted.\n";return 1;}

		

		// successful transaction leads to 
		// entering the transaction details in both users transaction details
		from_file = DATA_PATH+username+"//all_trans.txt";
		from_user.open(from_file,ios::app);//opening file in append mode to enter the transaction at the end 
		string trans=username+"    "+to+"        "+amount+"    "+gettime();
		from_user<<trans;//entering the transaction in logged_in user
		file=DATA_PATH+to+"//all_trans.txt";
		to_user.open(file, ios::app);// opening file in append mode to enter the transaction at the end 
		to_user<<trans;//entering the transction in the to_user account transaction logs

		cout<<trans<<endl;

		// closing the opened files
		to_user.close();
		from_user.close();

		// updating the amounts in sender( logged_in user ) and reciever 
		string  u_amt,t_amt,new_data;
		from_file=DATA_PATH+username+"//info.txt";
		file = USER_DATA_PATH+to+"//info.txt";
		from_user.open(from_file,fstream::in);
		to_user.open(file,ios::in);

		for(int i=0;i<AMNT;i++){ getline(from_user,data); }
		u_amt=data;cout<<u_amt<<endl;
		data="";
		int i=0;
		while(getline(to_user,data)){
			i++;
			if(i==AMNT){break;}
		 }
		t_amt=data;
		cout<<t_amt<<endl;
		//cout<<u_amt<<endl;

		fstream from1,to1;
		from1.open(from_file,fstream::out );
		to1.open(file,fstream::out);

		string temp="";
		i=0;
		size_t len = u_amt.length();
		while(getline(from_user,temp)){
			i++;
			if(i==AMNT){
				size_t pos = temp.find(u_amt);
				if(pos!=string::npos){
					temp.replace(pos,len,to_string(bk_bl-fund));
					//from1<<temp;
					}
				}
		}
		stringstream to_bk_bl;int to_bk_amt;
		to_bk_bl<<t_amt;
		to_bk_bl>>to_bk_amt;
		temp="";
		len = t_amt.length();
		i=0;
		while(getline(to_user,temp)){
			/*
			cout<<temp<<endl;
			if(temp.find(t_amt)==string::npos){
				temp.replace(temp.find(t_amt),t_amt.length(),to_string(to_bk_amt+fund));
				to1<<temp;
				}
			*/
			i++;
			if(i==AMNT){
				size_t pos = temp.find(u_amt);
				cout<<pos<<endl;
				cout<<temp<<endl;
				if(pos!=string::npos){
					temp.replace(pos,len,to_string(to_bk_amt+fund));
					//to1<<temp;
					}
				}
		}


		// closing the files that are opened
		from_user.close();from1.close();
		to_user.close();to1.close();
		return 0;

	}
	catch(char* e){
		cout<<"Unable to process your transaction\nTry again later";
		return 1;
	}
	return 0;
}