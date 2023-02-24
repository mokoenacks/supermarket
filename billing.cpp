#include<iostream>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

string numerr="Please enter a number only";
class market{
	private:
		int pcode;
		float price;
		float disc;
		string pname;
		
		public:
			void menu();
			void admin();
			void customer();
			void add();
			void edit();
			void del();
			void list();
			void receipt();
};

void market :: menu(){
	m:
	string option;
	string email;
	string password;
	
	cout<<"___________________________________"<<endl;
	cout<<endl;
	cout<<"          Market Main Menu         "<<endl;
	cout<<endl;
	cout<<"___________________________________"<<endl;
	cout<<endl;
	cout<<"         1. Admin                  "<<endl;
	cout<<endl;
	cout<<"         2. Customer                  "<<endl;
	cout<<endl;
	cout<<"         3. Exit                  "<<endl;
	cout<<endl;	
	//catch strings should be integers only
	
		cout<<"\n 	Please select your option:";
		cin>>option;
		if(option!="1" ||option != "2" || option !="3"){
			cout<<"Please select the given numbers "<<endl;
			goto m;
		}
		int opt=stoi(option);
	
		switch(opt){
			case 1:
				cout<<"		Please Login	"<<endl;
				cout<<"		Enter Email		: ";
				cin>>email;
				cout<<"		Enter password	: ";
				cin>>password;
				if(email=="admin@mail.com" && password=="admin01#")
				{
					admin();
				}
				else{
					cout<<"Invalid email or password"<<endl;
				}
				
				break;
			
			case 2:
				customer();
				break;
			
			case 3:
				exit(0);
				break;
				
			default:
				cout<<"Please select from the given options!"<<endl;
				
		}
		
	
	

	goto m;	
}

	


void market::admin(){
	
	m:
	string option;
	cout<<"\n\n\n\t\t\tAdministrator menu";
	cout<<"\n\t\t\t__1. Add product \t";
	cout<<endl;
	cout<<"\n\t\t\t__2. Modify product \t";
	cout<<endl;
	cout<<"\n\t\t\t__3. Delete product \t";
	cout<<endl;
	cout<<"\n\t\t\t__4. back to main menu \t";
	cout<<endl;
	cout<<endl;
	cout<<"\n\t\t\t Please enter your choice: ";
	cin>>option;
		if(option!="1" ||option != "2" || option !="3"){
			cout<<"Please select the given numbers "<<endl;
			goto m;
		}
		int	opt=stoi(option);
	switch(opt){
		case 1:
			add();
			break;
		case 2:
			edit();
			break;
		case 3:
			del();
			break;
		case 4:
			menu();
			break;
		default:
			cout<<"Invalid choice!"<<endl;
			
		
	}
	goto m;
}

void market::customer(){
	
	m:
	int option;
	cout<<"\n\n\n\t\t\tCustomer menu";
	cout<<"\n\t\t\t__1. Buy product \t";
	cout<<endl;
	cout<<"\n\t\t\t__2. Back to menu \t";
	cout<<endl;
	cout<<"\n\t\t\t__2. Enter your option: ";
	cin>>option;
		if(option!="1" ||option != "2" || option !="3"){
			cout<<"Please select the given numbers "<<endl;
			goto m;
		}
	switch(stoi(option)){
		case 1:
			receipt();
			break;
		case 2:
			menu();
			break;
		default :
			cout<<"Invalid choice !"<<endl;
			
	}
	goto m;
	
}

void market::add(){
	
	m:
	fstream data;
	int c;
	int token=0;
	float p;
	float d;
	string n;
	
	cout<<"\n\n\t Add new product";
	cout<<"\n\n\t Product code:  ";
	cin>>pcode;
	cout<<"\n\n\t Product name : ";
	cin>>pname;
	cout<<"\n\n\t Product price : ";
	cin>>price;
	cout<<"\n\n\t Product discount :";
	cin>>disc;
	
	data.open("datafile.txt",ios::in);
	
	if(!data){
		
		data.open("datafile.txt", ios::app|ios::out);
		data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<disc<<"\n";
		data.close();
		
	}
	else
	{
		data>>c>>n>>p>>d;
		while(!data.eof())
		{
			if(c ==pcode)
			{
				token++;
				
			}
			data>>c>>n>>p>>d;
		}
		data.close();
		
	}
	
	if(token==1){
		goto m;
	}
	else{
		data.open("datafile.txt", ios::app|ios::out);
		data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<disc<<"\n";
		data.close();
	}
	
	cout<<"\n\n\t Record inserted !";
	
	
}

void market::edit(){
	
	fstream data,data1;
	int pkey;
	int token=0;
	int c;
	float p;
	float d;
	string n;
	
	cout<<"\n\n\t Modify product";
	cout<<"\n\n\t Product code:  ";
	cin>>pkey;
	
	data.open("datafile.txt",ios::in);
	if(!data)
	{
		cout<<"\n File doesn't exist";
	}
	else{
		data1.open("datafile1.txt",ios::app|ios::out);
		
		data<<pcode<<pname<<price<<disc;
		while(!data.eof())
		{
			if(pkey==pcode)
			{
				cout<<"\n\t Enter new product code: ";
				cin>>c;
				cout<<"\n\t Enter product name: ";
				cin>>p;
				cout<<"\n\t Enter price :";
				cin>>n;
				cout<<"\n\t Enter Discount: ";
				cin>>d;
				data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
				cout<<"\n\t Record edit complete";
				token++;
			}
			else
			{
				data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<disc<<"\n";
			}
			
			data>>pcode>>pname>>price>>disc;
		}	
		
		data.close();
		data1.close();
	
		remove("datafile.txt");
		rename("datafile1.txt","datafile.txt");
		
		if(token==0)
		{
			cout<<"\n\n Record not found !";
		}
	}
	
	
}

void market::del()
{
	fstream data,data1;
	int pkey;
	int token=0;
	
	cout<<"\n\t Delete product";
	cout<<"\n\t Enter product code: ";
	cin>>pkey;
	
	data.open("datafile.txt",ios::in);
	if(!data)
	{
		cout<<"File doesn't exist";
	}
	else
	{
		data1.open("datafile1.txt" , ios::app | ios::out);
		data>>pcode>>pname>>price>>disc;
		while(!data.eof())
		{
			if(pcode==pkey)
			{
				cout<<"\n\t Product succesfully deleted";
				token++;
			}
			else
			{
				data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<disc<<"\n";
			}
			data>>pcode>>pname>>price>>disc;
		}
			data.close();
		data1.close();
	
		remove("datafile.txt");
		rename("datafile1.txt","datafile.txt");
		
		if(token==0)
		{
			cout<<"\n\n Record not found !";
		}
	}
	
}

void market::list()
{
	fstream data;
	data.open("datafile.txt",ios::in);
	cout<<"\n\n____________________________\n";
	cout<<"ProNo\t\tName\t\tPrice\n";
	cout<<"\n\n____________________________\n";
	data>>pcode>>pname>>price>>disc;
	while(!data.eof())
	{
		cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
		data>>pcode>>pname>>price>>disc;
	}
	data.close();
	
}

void market::receipt()
{
	m:
	fstream data;
	
	int goods[100];
	int quantity[100];
	char option;
	int c=0;
	float amount =0;
	float disc=0;
	float total=0;
	
	cout<<"\n\n\t RECEIPT ";
	data.open("datafile.txt",ios::in);
	if (!data)
	{
		cout<<"\n\n Empty Datafile ";
	}
	else
	{
		data.close();
		
		list();
		cout<<"\n___________________________\n";
		cout<<endl;
		cout<<"\n        Place you order    \n";
		cout<<endl;
		cout<<"\n___________________________\n";
		
		do
		{
			cout<<"\n\n Enter Product code :";
			cin>>goods[c];
			cout<<"\n\nEnter Quantity: ";
			quantity[c];
			for (int i=0;i<c;i++)
			{
				if(goods[c]==goods[i])
				{
					cout<<"\n\n This is a duplicated product code.Please try again";
					goto m;
				}
				
			}
			c++;
			cout<<"\n\n Do you want to buy another product ? Press Y or N :";
			cin>>option;
			
		} while(option=='y' || option =='Y');
		
		cout<<"\n\n\t ___________________________RECEIPT_____________________\n";
		cout<<"\nProduct No\t Product Name\t Product Quantity\t Price\t Amount\t Discounted amount\n";
		
		for(int i=0;i<c;i++)
		{
			data.open("datafile.txt",ios::in);
			data>>pcode>>pname>>price>>disc;
			while(!data.eof())
			{
				if(pcode==goods[i])
				{
					amount==price*quantity[i];
					disc=amount-(amount*disc*disc/100);
					total=total+disc;
					cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<quantity[i]<<"\t\t"<<price<<"\t\t"<<amount<<"\t\t"<<disc;
				}
				
				data>>pcode>>pname>>price>>disc;
			}
		}
		
		data.close();
	}
	
	cout<<"\n\n________________________________________________________\n";
	cout<<"Total Amount : "<<total;
	cout<<"\n________________________________________________________\n";
	
}




int main()
{
	market a;
	a.menu();
}
