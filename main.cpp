
//stl
#include"./includes.h"
//

//user defined
#include"./login-module/login.h"
#include"./get_info/getinfo.h"
#include"./create-user/signup.h"
#include"./banking/transaction.h"

//
using namespace std;

void showOptions(){
    cout<<"1.Profile"<<endl;
    cout<<"2.show Transactions"<<endl;
    cout<<"3.start Transaction"<<endl;
}

void call_option(int option){
    switch (option)
    {
    case 1:
        showinfo();
        break;
    case 2:
        show_transac_info();
        break;
    case 3:
        transaction();
        break;
    default:
        break;
    }
}


int main(int argc,char* argv[]){
    int login_flag=0;
    int invalid = 1;
    string number="";
    while(invalid && number!="exit"){
        cout<<"1.login"<<endl;
        cout<<"2.sign-up"<<endl;
        cin>>number;
        if(stoi(number)==1){invalid=login();}
        else if(stoi(number) == 2){create_user( );}
    }

    if(!invalid){
        string line;
        int num;
        while(1){
            showOptions();
            cout<<"enter the option or type 'exit' to exit from program:\n>";
            cin>>line;
            if(line=="exit" || line=="EXIT"){ break; }
            num=stoi(line);
            call_option(num);
        }
    }
        
    return 0;
}