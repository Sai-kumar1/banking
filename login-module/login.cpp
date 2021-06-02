// login page

// Cpp library
#include"../includes.h"
//end Cpp library

// User defined
#include"login.h"
#include"../global.h"
// end User defined

//definitions
#define USER_DATA_PATH "./database/"
#define USER_ID 1
#define NAME 2
#define PASWD 3
#define AC_TYPE 4
#define AMNT 5

using namespace std;

//global variable username so that we will allocate value from here
// and can be used in other modules
string username;

//function for login message after successful login of the user
void login_msg(string username){
    cout<<"Welcome "<<username<<"!"<<endl;
}


int login(){
    string password;
    cout<<"username:";cin>>username;//cout<<endl;
    cout<<"password:";cin>>password;cout<<endl;
    try{
        string file=USER_DATA_PATH+(string)username +"/info.txt";
        fstream user;
        user.open(file,ios::in);
        string data;
        for(int i=0;i<PASWD;i++){getline(user,data);}
       // cout<<data<<endl;
       //data.pop_back();//due to extra space at end
       // cout<<data.length()<<','<<password<<endl;
        if(password==data){
            login_msg(username);
        }
        else{
            cout<<"no such user or password combination :("<< '\n';
            return 1;
        }
        user.close();
    }
    catch(const std::exception& e)
    {
        cout<<"no such user or password combination :("<< '\n';
        return 1;
    }
    return 0;
    
}


