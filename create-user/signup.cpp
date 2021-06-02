//stl includes
#include"../includes.h"
#include<filesystem> // for making new directory
#include<sys/stat.h>
#include<sys/types.h>

//user includes
#include"signup.h"

using namespace std;


class userinfo{
    public:
    string username;
    string password;
    string ac_type;
    string amount="0";
    /*
    userinfo(string user,string pswd,string ac_ty){
        username=username;
        password=pswd;
        ac_type=ac_ty;
    }
    */
};

int create_user(){
    cout<<"------------"<<endl;
    cout<<"signup"<<endl;
    cout<<"------------"<<endl;
    userinfo user;
    string password,cnf_pwd;
    cout<<"username:";cin>>user.username;cout<<endl;
    int pwd=0;
    while(!pwd){
        cout<<"password:";cin>>password;cout<<endl;
        cout<<"confirm password:";cin>>cnf_pwd;cout<<endl;
        if(password==cnf_pwd){user.password=cnf_pwd;pwd=1;}
        else{cout<<"password and confirm password are not same\n Re-enter your password";}
        }
        cout<<"account type:";cin>>user.ac_type;cout<<endl;
    //userinfo user = new userinfo()
    try{
        string  direc = DATA_PATH+user.username;
        char* directory = strcpy(new char[direc.length() + 1], direc.c_str());
        
        if(mkdir(directory,0777)==-1){
            fstream files;
            files.open(direc+"/info.txt",ios::app);
            files<<to_string(user.username.length()*7%200)<<endl;
            files<<user.username<<endl;
            files<<user.password<<endl;
            files<<user.ac_type<<endl;
            files<<user.amount<<endl;

            files.close();
            files.open(direc+"/all_trans.txt",ios::out);
            files.close();
            return 0;
        }
        else{
            cout<<"error in creating your account\nTry again later"<<endl;
            return 1;
        }
    }
    catch(char* s){
        cout<<"unexpected error try later";
        return 1;
    }
    return 1;
}