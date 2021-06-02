//stl inlcudes
#include"../includes.h"

//user inlcudes
#include"../global.h"
#include"./getinfo.h"

//definitions
#define USER_ID 1
#define NAME 2
#define PASWD 3
#define AC_TYPE 4
#define AMNT 5

//since evrey user us saved as a file we use file_streams to work with data
void show_transac_info(){
    fstream user;
    string file = (string)DATA_PATH+username+"/all_trans.txt";
    user.open(file,ios::in);
    string transaction;
    cout<<"-------------------"<<endl;
    cout<<"Transactions:"<<endl;
    cout<<"-------------------"<<endl;
    cout<<"------------------------------------------------------------"<<endl;
    cout<<"T.Num\t"<<"From\t"<<"To\t"<<"Date And Time\t"<<"\tAmnt"<<endl;
   int tnum=0;

   cout<<"------------------------------------------------------------"<<endl;
   while(user){
        getline(user,transaction);
        tnum++;
        cout<<tnum<<'\t'<<transaction<<endl;
    }
   cout<<"------------------------------------------------------------"<<endl;
    user.close();
}

void showinfo(){
    string file = (string)DATA_PATH+(string)username+"/info.txt"; //path to the user_info of a particular user
    fstream user;
    user.open(file,ios::in);
    string data;
    int line_num=0;
    string head[]={"Id","Full Name","pwd","A/C type","Balance"};
    cout<<"------------"<<endl;
    cout<<"Profile"<<endl;
    cout<<"------------"<<endl;
    cout<<"--------------------------------------------"<<endl;
    while(getline(user,data)){
        line_num++;
        if(line_num==PASWD){continue;}
        cout<<head[line_num-1]<<" : "<<data<<endl;
    }
    cout<<"--------------------------------------------"<<endl;
   
    user.close();
}