#include<iostream>
#include<fstream>
#include<string.h>
#include<iomanip>
using namespace std;

struct login{
    char admin_name[50];
    char admin_username[50];
    char admin_email[50];
    char admin_password[20];
    char admin_fixed_password[20];

    int user_id;
    char user_name[50];
    char user_username[50];
    char user_email[50];
    char user_password[20];
};

class account{
	int id;
	char name[50];
	char username[20];
	char password[10];

	char location[50];
	int travel_cost;
	int service_cost;
	char date[50];
	double time;
public:
	void create_admin_account();
	void create_user_account();
	void show_account() const;

	void create_trip();
	void show_trip() const;
    void create_booked();
	void report() const;
	void report2() const;
	int ret_id() const;
};

void admin_info();
void user_info();
void write_trip();
void display_trip();
void user_display_trip();
void admin_display_trip();
void delete_trip(int n);
void cacel_booked_trip(int n);
void write_admin_account();
void write_user_account();
void booked_trip();
void admin_registration();
void admin_login();
void user_registration();
void user_login();
void display_booked_trip();
void admin_home();
void user_home();

void red(){
    cout<<"\033[1;31m";
}
void yellow(){
    cout<<"\033[1;33m";
}
void green(){
    cout<<"\033[0;32m";
}
void blue(){
    cout<<"\033[0;34m";
}
void purple(){
    cout<<"\033[0;35m";
}
void cyan(){
    cout<<"\033[0;36m";
}
void white(){
    cout<<"\033[0;37m";
}
void reset(){
  cout<<"\033[0m";
}
void pasue(){
    for(int y=0; y<=8888888; ++y){
    }
}

void intro(){
    green();
    char name1[] = "\n\n\t\t\t      WELCOME TO HOLIDAY TRIP     \n";
    char name2[] = "\t\t\t======================================\n";
    char name3[] = "\t\t\tFind your best holiday destination here...\n\n\n";
    char name4[] = "\t\t\t\tPRESS ENTER TO CONTINUE...\n\n\n";
    for(int x=0; name1[x]!=NULL; x++){
        printf("%c",name1[x]);
        pasue();
    }
    for(int x=0; name2[x]!=NULL; x++){
        printf("%c",name2[x]);
        pasue();
    }
    for(int x=0; name3[x]!=NULL; x++){
        printf("%c",name3[x]);
        pasue();
    }
    for(int x=0; name4[x]!=NULL; x++){
        printf("%c",name4[x]);
        pasue();
    }
    getchar();
    reset();
}
void home(){
    system("clear");
    cout<<"\n\t\t================================================="<<endl;
    cout<<"\t\t|                                               |"<<endl;
    cout<<"\t\t|               Your Identity?                  |"<<endl;
    cout<<"\t\t|           ----------------------              |"<<endl;
    cout<<"\t\t|                                               |"<<endl;
    cout<<"\t\t|               1. Admin                        |"<<endl;
    cout<<"\t\t|               2. User                         |"<<endl;
    cout<<"\t\t|                                               |"<<endl;
    cout<<"\t\t=================================================\n\n"<<endl;
    cout<<"\t\tENTER YOUR ANSWER : ";

    int iden,num;

    cin>>iden;
    system("clear");
    switch(iden){
    case 1:
        admin_info();
        cin>>iden;
        switch(iden){
        case 0:
            home();
            break;
        case 1:
            admin_registration();
            break;
        case 2:
            admin_login();
            break;
        }
        break;
    case 2:
        user_info();
        cin>>iden;
        switch(iden){
        case 0:
            home();
            break;
        case 1:
            user_registration();
            break;
        case 2:
            user_login();
            break;
        case 3:
            display_trip();
            break;
        }
        break;
    }

}                                             /*===================================================*/
int main(){
    system("clear");
    intro();
    home();
    system("clear");

    return 0;
}

void admin_info(){
    cout<<"\t\t                                            "<<endl;
    cout<<"\t\t                 WELCOME ADMIN              "<<endl;
    cout<<"\t\t              -------------------           "<<endl;
    cout<<"\t\t               1. Registration              "<<endl;
    cout<<"\t\t               2. Login                     "<<endl;
    cout<<"\t\t               0. Back To Home              "<<endl;
    cout<<"\t\t        =============================\n\n"<<endl;
    cout<<"\n\t\t\tENTER YOUR ANSWARE : ";
}
void user_info(){
    cout<<"\t\t                                           "<<endl;
    cout<<"\t\t                 WELCOME USER              "<<endl;
    cout<<"\t\t               ----------------            "<<endl;
    cout<<"\t\t               1. Registration             "<<endl;
    cout<<"\t\t               2. Login                    "<<endl;
    cout<<"\t\t               3. Find Trips               "<<endl;
    cout<<"\t\t               0. Back To Home             "<<endl;
    cout<<"\t\t        =============================\n\n"<<endl;
    cout<<"\n\t\t\tENTER YOUR ANSWARE : ";
}

                                             //             Create Admin account
                                             /* ===================================================*/
void admin_registration(){

    FILE *file;
    struct login l;
    file=fopen("admin.txt","w");

    getchar();
    cout<<"\n\t\t\tEnter Your Name : ";
    cin.ignore();
	cin.getline(l.admin_name,50);
    //cout<<"\t\t\tEnter user id : "; cin>>l.user_id;
    cout<<"\t\t\tEnter Username : "; cin>>l.admin_username;
    cout<<"\t\t\tEnter Email : "; cin>>l.admin_email;
    cout<<"\t\t\tEnter Password : "; cin>>l.admin_password;

    fwrite(&l,sizeof(l),1,file);
    fclose(file);
    cout<<"\n\t\t\tYour information is successfully stored"<<endl;
    cout<<"\t\t\twe will send you admin login passowrd\n"<<endl;

    getchar();

    admin_login();
}
void admin_login(){
    char admin_username[50];
    char admin_password[20];
    //char admin_fixedPassword[5]="123";

    FILE *file;

    file=fopen("admin.txt","r");
    struct login l;

    cout<<"\n\t\t\tEnter username : "; cin>>admin_username;
    cout<<"\t\t\tEnter password : "; cin>>admin_password;

    while(fread(&l,sizeof(l),1,file)){
        if(strcmp(admin_username,l.admin_username)==0 && strcmp(admin_password,l.admin_password)==0){
            cout<<"\n\t\t\tSuccessfully login\n\n"<<endl;

            cout<<"\t\t\t1. Add New Trip"<<endl;
            cout<<"\t\t\t2. View Trip"<<endl;
            cout<<"\t\t\t3. Delete Trip"<<endl;
            cout<<"\t\t\t0. Back to Main Manu"<<endl;
            cout<<"\n\t\t\tENTER YOUR ANSWARE : ";
            int Find;
            cin>>Find;
            switch(Find){
                case 0:
                    home();
                    break;
                case 1:
                    write_trip();
                    break;
                case 2:
                    admin_display_trip();
                    break;
                case 3:
                    int num;
                    cout<<"\n\n\tDelete Id No => "; cin>>num;
                    delete_trip(num);
                    break;
                default:
                    cout<<"\n\t\t\tInvalid"<<endl;
            }

        } else{
            cout<<"\n\t\t\tPlease Enter correct username and password\n"<<endl;

            admin_login();
        }
    }
    fclose(file);
}

void admin_home(){
    cout<<"\n\t\t\t1. Add New Trip"<<endl;
    cout<<"\t\t\t2. View Trip"<<endl;
    cout<<"\t\t\t3. Delete Trip"<<endl;
    cout<<"\t\t\t0. Back to Main Manu"<<endl;
    cout<<"\n\t\t\tENTER YOUR ANSWARE : ";
    int Find;
    cin>>Find;
    switch(Find){
        case 0:
            home();
            break;
        case 1:
            write_trip();
            break;
        case 2:
            admin_display_trip();
            break;
        case 3:
            int num;
            cout<<"\n\n\t "; cin>>num;
            delete_trip(num);
            break;
        default:
            cout<<"\n\t\t\tInvalid"<<endl;
    }
    getchar();
}
void user_home(){
    cout<<"\n\t\t\t1. View Trip"<<endl;
    cout<<"\t\t\t2. Display Your Trip"<<endl;
    cout<<"\t\t\t3. Cancel Trip"<<endl;
    cout<<"\t\t\t0. Back to Main Manu"<<endl;
    cout<<"\n\t\t\tENTER YOUR ANSWARE : ";

    int Find;
    scanf("%d",&Find);
    switch(Find){
        case 0:
            home();
            break;
        case 1:
            user_display_trip();
            break;
        case 2:
            display_booked_trip();
            break;
        case 3:
            int num;
            cout<<"\n\n\tCancel Id No => "; cin>>num;
            cacel_booked_trip(num);
            break;
        default:
            cout<<"\n\t\t\tInvalid"<<endl;
    }
    getchar();
}

void user_registration(){
    FILE *file=fopen("user.txt","w");
    struct login l;

    getchar();
    cout<<"\n\t\t\tEnter your full name : ";
    cin.ignore();
	cin.getline(l.user_name,50);
    cout<<"\t\t\tEnter username : "; cin>>l.user_username;
    cout<<"\t\t\tEnter email : "; cin>>l.user_email;
    cout<<"\t\t\tEnter password : "; cin>>l.user_password;

    fwrite(&l,sizeof(l),1,file);
    fclose(file);

    cout<<"\n\t\t\tYour information is successfully stored\n"<<endl;
    getchar();

    user_login();
}
void user_login(){
    char user_username[50];
    char user_password[20];

    FILE *file=fopen("user.txt","r");
    struct login l;

    cout<<"\n\t\t\tEnter username or email : "; cin>>user_username;
    cout<<"\t\t\tEnter password : "; cin>>user_password;

    while(fread(&l,sizeof(l),1,file)){
        if((strcmp(user_username,l.user_username)==0 || strcmp(user_username,l.user_email)==0) && strcmp(user_password,l.user_password)==0){
            cout<<"\t\t\tSuccessfully Login\n"<<endl;

            cout<<"\t\t\t1. View Trip"<<endl;
            cout<<"\t\t\t2. Display Your Trip"<<endl;
            cout<<"\t\t\t3. Cancel Trip"<<endl;
            cout<<"\t\t\t0. Back to Main Manu"<<endl;
            cout<<"\n\t\t\tENTER YOUR ANSWARE : ";

            int Find;
            scanf("%d",&Find);
            switch(Find){
                case 0:
                    home();
                    break;
                case 1:
                    user_display_trip();
                    break;
                case 2:
                    display_booked_trip();
                    break;
                case 3:
                    int num;
                    cout<<"\n\n\tCancel Id No => "; cin>>num;
                    cacel_booked_trip(num);
                    break;
                default:
                    cout<<"\n\t\t\tInvalid"<<endl;
            }

        } else{
            cout<<"\n\tPlease enter correct username and password\n"<<endl;

            user_login();
        }
    }
    fclose(file);
}
                                        //                 CREATE AND DELETE TRIP
                                        /*===================================================*/
void account::create_trip(){
	cout<<"\nTrip ID no\t\t: ";
	cin>>id;
	cout<<"Enter Location\t\t: ";
	cin.ignore();
	cin.getline(location,50);
	cout<<"Enter Travel Cost\t: ";
	cin>>travel_cost;
	cout<<"Enter Service charge\t: ";
	cin>>service_cost;
	cout<<"Enter Date\t\t: ";
	cin.ignore();
	cin.getline(date,50);
	cout<<"Enter Time\t\t: ";
	cin>>time;
}
void write_trip(){
	account ac;
	ofstream outFile;
	outFile.open("tripCreate.dat",ios::binary|ios::app);
	ac.create_trip();
	outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));
	outFile.close();

	admin_home();
}
void account::show_trip() const{
	cout<<"\nID No. : "<<id;
	cout<<"\nLocation : ";
	cout<<location;
	cout<<"\nTravel cost : "<<travel_cost;
	cout<<"\nExtra cost : "<<service_cost;
	cout<<"\nDate : "<<date;
	cout<<"\nTime : "<<time;
}

void display_trip(){
	account ac;
	ifstream inFile;
	inFile.open("tripCreate.dat",ios::binary);
	if(!inFile){
		cout<<"File is not exist..."<<endl;
		return;
	}
	cout<<"\n\n\t\t\tAVAILABLE TRIP LIST\n\n";
	cout<<"============================================================================\n";
	cout<<"ID no.    Location     Travel_Cost    Extra_cost   Date           Time      \n";
	cout<<"============================================================================\n";
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account))){
		ac.report();
	}
	inFile.close();

    int x;
    user_info();
    cin>>x;
    switch(x){
    case 0:
        home();
        break;
    case 1:
        user_registration();
        break;
    case 2:
        user_login();
        break;
    case 3:
        display_trip();
        break;
    }
}
void admin_display_trip(){
    account ac;
	ifstream inFile;
	inFile.open("tripCreate.dat",ios::binary);
	if(!inFile){
		cout<<"File is not exist...";
		return;
	}
	cout<<"\n\n\t\t\tAVAILABLE TRIP LIST\n\n";
	cout<<"============================================================================\n";
	cout<<"ID no.    Location     Travel_Cost    Extra_cost   Date           Time      \n";
	cout<<"============================================================================\n";
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account))){
		ac.report();
	}
	inFile.close();

	admin_home();
}
void user_display_trip(){
    account ac;
	ifstream inFile;
	inFile.open("tripCreate.dat",ios::binary);
	if(!inFile){
		cout<<"File is not exist...";
		return;
	}
	cout<<"\n\n\t\t\tAVAILABLE TRIP LIST\n\n";
	cout<<"============================================================================\n";
	cout<<"ID no.    Location     Travel_Cost    Extra_cost   Date           Time      \n";
	cout<<"============================================================================\n";
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account))){
		ac.report();
	}
	inFile.close();

    cout<<"\n\n\t1. Booked Trip"<<endl;
    cout<<"\t0. Back to Home ===> ";
    int x;
    cin>>x;
    switch(x){
    case 0:
        user_home();
        break;
    case 1:
        booked_trip();
        break;
    }

	user_home();
}

void account::create_booked(){
	cout<<"\n\tEnter Trip Id No => ";
	cin>>id;
}
void booked_trip(){
	account ac;
	ofstream outFile;
	outFile.open("booked.dat",ios::binary|ios::app);
	ac.create_booked();
	outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));
	outFile.close();
	cout<<"\tTrip Booked Successfully"<<endl;

	user_home();
}
void display_booked_trip(){
    account ac;
	ifstream inFile;
	inFile.open("booked.dat",ios::binary);
	if(!inFile){
		cout<<"\n\t\t\tFile is not exist...";
		return;
	}
	cout<<"\n\n\t\tTrip booked List\n\n";
	cout<<"\t\tYour Trip Booking List bellow. "<<endl;
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account))){
		ac.report2();
	}
	inFile.close();

	user_home();
}

void cacel_booked_trip(int n){
	account ac;
	ifstream inFile;
	ofstream outFile;
	inFile.open("booked.dat",ios::binary);
	if(!inFile){
		cout<<"File is not exist";
		return;
	}
	outFile.open("Temp.dat",ios::binary);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account))){
		if(ac.ret_id()!=n){
			outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));
		}
	}
	inFile.close();
	outFile.close();
	remove("booked.dat");
	rename("Temp.dat","booked.dat");
	cout<<"\n\tTrip Celcelled .."<<endl;

	user_home();
}

void delete_trip(int n){
	account ac;
	ifstream inFile;
	ofstream outFile;
	inFile.open("tripCreate.dat",ios::binary);
	if(!inFile){
		cout<<"File is not exist";
		return;
	}
	outFile.open("Temp.dat",ios::binary);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account))){
		if(ac.ret_id()!=n){
			outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));
		}
	}
	inFile.close();
	outFile.close();
	remove("tripCreate.dat");
	rename("Temp.dat","tripCreate.dat");
	cout<<"\n\tTrip Deleted .."<<endl;

	admin_home();
}

int account::ret_id() const{
	return id;
}
void account::report() const{
	cout<<id<<setw(6)<<" "<<location<<setw(6)<<" "<<travel_cost<<setw(10)<<" "<<service_cost<<setw(6)<<" "<<date<<setw(6)<<" "<<time<<endl;
}
void account::report2() const{
	cout<<"\t\t"<<id<<endl;
}
