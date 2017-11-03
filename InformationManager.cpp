/*********information manager*********/
/*
*Powered by scudrt in 2017
*
*Data File Name: data.txt
*
*For each line in file:
*id name age grade level qq phone password isAMan
*
*About level: 
*low level users can't edit/add/delete higher level users
*/
#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstring>
#include <conio.h>
using namespace std;

#define MAXUSER 10000
#define GOD 9999

struct data
{
	int id,age,grade,level;
	string qq,phone,name,password;
	bool used,isAMan;
	void init(int);
	void show();
	void welcomeShow();
}user[MAXUSER+1],currentUser;

struct nodeForSort
{
	int id;
	string name;
	bool operator <=(const nodeForSort&)const;
	bool operator <(const nodeForSort&)const;
	void operator =(const data&);
}t[MAXUSER+1];

bool nodeForSort::operator<=(const nodeForSort& x)const
{
	return name <= x.name;
}

bool nodeForSort::operator<(const nodeForSort& x)const
{
	return name < x.name;
}

void nodeForSort::operator =(const data& x)
{
	id=x.id;
	name=x.name;
}

struct command
{
	int ida,idb;
	string others,name;
}currentInput;

enum state
{
	MainMenu,Exit,ShouldPause,
	LoginMenu,Login,Register,
	Add,Delete,Edit,Search,
	InputError,LoginError,RegisterError
}currentState;

string initPassword="123456";
/*login & register*/
void loginGuard();
void _getUser();
bool _loginCheck();
bool _registerCheck();
void _login();
void _register();
/*file*/
void load();
void loadFile();
void saveFile();
/*main menu input*/
void mainMenuGuard();
void solveCommand();
void _getCommand();
bool _commandLegal();
/*output*/
void cls();
void pause();
void showMessage();
/*storage & access*/
void search();
void addUser();
void deleteUser();
void modifyUser();
void statistics();
/*others*/
void mainMenu();
void exitGuard();
void popSort(int);
void simpleSort(int,int);

int main()
{
	mainMenu();
	return 0;
}

void mainMenu()
{
	loginGuard();
	while (currentState != Exit)
	{
		mainMenuGuard();
	}
	exitGuard();
}

void mainMenuGuard()
{
	while (currentState != Exit)
	{
		cls();
		currentState=MainMenu;
		showMessage();
		solveCommand();
		if (currentState == ShouldPause)
		{
			pause();
		}
	}
}

void solveCommand()
{
	char com;
	com=getch();
	if (com == '0')
	{
		currentState=Exit;
		return;
	}
	else if (com == '1') //search
	{
		search();
		currentState=ShouldPause;
	}
	else if (com == '2') //edit
	{
		modifyUser();
		currentState=ShouldPause;
	}
	else if (com == '3') //add
	{
		addUser();
		currentState=ShouldPause;
	}
	else if (com == '4') //delete
	{
		deleteUser();
		currentState=ShouldPause;
	}
	else if (com == '5') //statistics
	{
		statistics();
		currentState=ShouldPause;
	}
	cin.clear();
	cin.sync();
}

void addUser()
{
	currentState=Add;
	showMessage();
	int a,b;
	if (!(cin >> a >> b))
	{
		currentState=InputError;
		showMessage();
		return;
	}
	if (a>b)
	{
		int temp=a;
		a=b;
		b=temp;
	}
	if (a<1 || b<1 || a>MAXUSER || b>MAXUSER)
	{
		currentState=InputError;
		showMessage();
		return;
	}
	for (int i=a;i<=b;++i)
	{
		if (!user[i].used)
		{
			user[i].init(i);
			t[++t[0].id]=user[i];
			cout << "No." << i << " added\n";
		}
		else
		{
			cout << "No. " << i << " is already used.\n";
		}
	}
	simpleSort(1,t[0].id);
}

void modifyUser()
{
	currentState=Edit;
	showMessage();
	data temp;
	while (!(cin >> temp.id))
	{
		currentState=InputError;
		showMessage();
		cin.clear();
		cin.sync();
	}
	if (user[temp.id].used)
	{
		temp=user[temp.id];
		user[temp.id].show();
		if (temp.level > currentUser.level || (temp.id != currentUser.id && temp.level==currentUser.level)) //need higher level
		{
			cout << "No enough level to edit the user.\n";
			return;
		}
	}
	else
	{
		cout << "user No." << temp.id << " no exist or illegal input.";
		return;
	}
	char ch;
	int last;
	//predeal
	while (getchar() != '\n');
	//name
	cout << "name:" << temp.name << ' ';
	ch=getchar();
	if (ch != '\n')
	{
		temp.name=ch;
		while ((ch=getchar()) != '\n')
		{
			temp.name+=ch;
		}
	}
	//age
	last=temp.age;
	cout << "age:" << temp.age << ' ';
	ch=getchar();
	if (ch != '\n')
	{
		if (ch <= '9' && ch >= '0')
		{
			temp.age=ch-'0';
			while ((ch=getchar()) != '\n')
			{
				if (ch <= '9' && ch >= '0')
				{
					temp.age=temp.age*10+ch-'0';
				}
				else
				{
					temp.age=last;
					currentState=InputError;
					showMessage();
					break;
				}
			}
		}
		else
		{
			currentState=InputError;
			showMessage();
		}
	}
	//grade
	last=temp.grade;
	cout << "grade:" << temp.grade << ' ';
	ch=getchar();
	if (ch != '\n')
	{
		if (ch <= '9' && ch >= '0')
		{
			temp.grade=ch-'0';
			while ((ch=getchar()) != '\n')
			{
				if (ch <= '9' && ch >= '0')
				{
					temp.grade=temp.grade*10+ch-'0';
				}
				else
				{
					temp.grade=last;
					currentState=InputError;
					showMessage();
					break;
				}
			}
		}
		else
		{
			currentState=InputError;
			showMessage();
		}
	}
	//level
	if (temp.id != currentUser.id) //can't modify your own level
	{
		cout << "level:" << temp.level << ' ';
		ch=getchar();
		if (ch != '\n')
		{
			if (ch <= '9' && ch >= '0') //legal input
			{
				if (currentUser.level >= ch-'0') //suit level
				{
					temp.level=ch-'0';
				}
				else
				{
					cout << "can't give higher level.\n" << endl;
				}
			}
			else
			{
				currentState=InputError;
				showMessage();
			}
			while (getchar() != '\n');
		}
		//qq
		cout << "qq:" << temp.qq << ' ';
		ch=getchar();
		if (ch != '\n')
		{
			temp.qq=ch;
			while ((ch=getchar()) != '\n')
			{
				temp.qq+=ch;
			}
		}
	}
	//phone
	cout << "phone:" << temp.phone << ' ';
	ch=getchar();
	if (ch!='\n')
	{
		temp.phone=ch;
		while ((ch=getchar()) != '\n')
		{
			temp.phone+=ch;
		}
	}
	//isAMan
	cout << "man?: " << temp.isAMan << " (y/n) ";
	ch=getchar();
	if (ch != '\n')
	{
		if ((ch&95) == 'Y')
		{
			temp.isAMan=true;
		}
		else if ((ch&95) == 'N')
		{
			temp.isAMan=false;
		}
		else
		{
			currentState=InputError;
			showMessage();
		}
		while (getchar() != '\n');
	}
	//password
	if (temp.id == currentUser.id) //can only change your own password
	{
		cout << "password:" << temp.password << ' ';
		ch=getchar();
		if (ch != '\n')
		{
			temp.password=ch;
			while ((ch=getchar()) != '\n')
			{
				temp.password+=ch;
			}
		}
	}
	user[temp.id]=temp;
	if (currentUser.id == temp.id)
	{
		currentUser=temp;
	}
	for (int i=1;i<=t[0].id;++i)
	{
		if (t[i].id == temp.id)
		{
			t[i].name=temp.name;
			popSort(i);
			break;
		}
	}
}

void deleteUser()
{
	currentState=Delete;
	showMessage();
	int a,b;
	if (!(cin >> a >> b))
	{
		currentState=InputError;
		showMessage();
		return;
	}
	if (a < 1 || a > MAXUSER || b < 1 || b > MAXUSER) //illegal number
	{
		currentState=InputError;
		showMessage();
		return;
	}
	for (int i=a;i<=b;++i)
	{
		if (user[i].used)
		{
			if (user[i].level > currentUser.level)
			{
				cout << "Can't delete No." << i << " because of low level\n";
			}
			else if (i == currentUser.id)
			{
				cout << "Can't delete yourself:No." << i << "\n";
			}
			else
			{
				int l=1,r=t[0].id,mid;
				while (l<r)
				{
					mid=(l+r)/2;
					if (t[mid].name < user[i].name)
					{
						l=mid+1;
					}
					else
					{
						r=mid;
					}
				}
				t[l]=t[t[0].id];
				--t[0].id;
				user[i].used=false;
				cout << "No." << i << " deleted.\n";
			}
		}
	}
	simpleSort(1,t[0].id);
}

void search()
{
	currentState=Search;
	showMessage();
	if (!(cin >> currentInput.others))
	{
		currentState=InputError;
		showMessage();
		cin.clear();
		cin.sync();
		return;
	}
	string s=currentInput.others;
	int len=s.length();
	currentInput.ida=1; //to mark whether the input is number
	for (int i=0;i<len;++i)
	{
		if (s[i]>'9' || s[i]<'0')
		{
			currentInput.ida=0;
			break;
		}
	}
	//search id
	if (currentInput.ida && len<=4) //is legal id
	{
		currentInput.idb=0;
		for (int i=0;i<len;++i)
		{
			currentInput.idb=currentInput.idb*10+s[i]-'0';
		}
		if (user[currentInput.idb].used)
		{
			user[currentInput.idb].show();
		}
		else
		{
			cout << "No." << currentInput.idb << " no found.\n";
		}
	}
	//search name
	int l=1,r=t[0].id,mid;
	while (l<r)
	{
		mid=(l+r)/2;
		if (t[mid].name < s)
		{
			l=mid+1;
		}
		else
		{
			r=mid;
		}
	}
	if (t[l].name == s)
	{
		int i;
		for (i=l;i<=l+9;++i)
		{
			if ((t[i].name == s) && i<=t[0].id)
			{
				user[t[i].id].show();
				cout << endl;
			}
			else
			{
				break;
			}
		}
		if (i+1<=t[0].id)
		{
			if (user[t[i+1].id].name == s)
			{
				cout << "More users are ignored..\n";
			}
		}
	}
	else
	{
		cout << "User called " << s << " no found.\n";
	}
}

void statistics()
{
	cout << "number of users:" << t[0].id << endl;
}

void loginGuard()
{
	load();
	string password;
	char ch;
	int id;

	cls();
	currentState=LoginMenu;
	showMessage();
	while (1)
	{
		ch=getch();
		if (ch=='1')
		{
			_login();
		}
		else if (ch=='2')
		{
			_register();
		}
		else if (ch=='0')
		{
			currentState=Exit;
			return;
		}
		if (currentState == Login)
		{
			break;
		}
	}
	currentState=MainMenu;
	cls();
}

void _getUser()
{
	if (!(cin >> currentUser.id >> currentUser.password)) //illegal input
	{
		currentState=InputError;
		cin.clear();
		cin.sync();
	}
}

bool _loginCheck()
{
	if (currentUser.id >= 1 && currentUser.id <= MAXUSER)
	{
		if (user[currentUser.id].used) //user exist
		{
			if (user[currentUser.id].password == currentUser.password) //correct password
			{
				return true;
			}
		}
	}
	return false;
}

bool _registerCheck()
{
	if (currentUser.id >= 1 && currentUser.id<=MAXUSER)
	{
		if (user[currentUser.id].used == false)
		{
			return true;
		}
	}
	return false;
}

void _login()
{
	cls();
	currentState=Login;
	showMessage();
	while (currentState == Login)
	{
		_getUser();
		if (currentState == InputError)
		{
			showMessage();
			currentState=Login;
		}
		else
		{
			if (_loginCheck())
			{
				currentUser=user[currentUser.id];
				break;
			}
			else
			{
				currentState=LoginError;
				showMessage();
				currentState=Login;
			}
		}
	}
}

void _register()
{
	cls();
	currentState=Register;
	showMessage();
	while (currentState == Register)
	{
		_getUser();
		if (currentState == InputError)
		{
			showMessage();
			currentState=Register;
		}
		else
		{
			if (_registerCheck())
			{
				user[currentUser.id].init(currentUser.id);
				user[currentUser.id].password=currentUser.password;
				break;
			}
			else
			{
				currentState=RegisterError;
				showMessage();
				currentState=Register;
			}
		}
	}
	currentState=Login;
}

void exitGuard()
{
	currentState=Exit;
	showMessage();
	saveFile();
}

void showMessage()
{
	switch (currentState)
	{
		case MainMenu:
		currentUser.welcomeShow();
		cout << "Please press number to command:\n"
		<< "1.Search user.\n"
		<< "2.Edit user.\n"
		<< "3.Add user.\n"
		<< "4.Delete user.\n"
		<< "5.Statistics.\n"
		<< "0.Exit.\n";
		break;

		case LoginMenu:
		cout << "Please press number to go on:\n"
		<< "1.Login\n"
		<< "2.Register\n"
		<< "0.Exit\n";
		break;

		case Login:
		cout << "Enter [ID] [password] to login:\n";
		break;

		case Register:
		cout << "Enter [ID] [password] to register:\n";
		break;

		case Add:
		cout << "Enter [ID a] [ID b] to add users in [a,b]\n"
		<< "the initial password is " << initPassword << '\n';
		break;

		case Delete:
		cout << "Enter [ID a] [ID b] to delete users in [a,b].\n";
		break;

		case Edit:
		cout << "Enter [ID] and edit the user,enter to skip a key.\n";
		break;

		case Search:
		cout << "Input id or name to search.\n";
		break;

		case Exit:
		cout << "Saving the data,please wait a second.\n";
		break;

		case InputError:
		cout << "Illegal input.\n";
		break;

		case LoginError:
		cout << "Wrong password or id.\n";
		break;

		case RegisterError:
		cout << "User id is used.\n";
		break;
	}
}

void data::show()
{//to be continued;
	cout << "ID:" << id << " name:" << name << " level:" << level;
	if (isAMan)
		cout << " Male\n";
	else
		cout << " Female\n";
	cout << "age:" << age << ' ' << " grade:" << grade << endl;
	cout << "QQ:" << qq << ' ' << " phone:" << phone << endl;
}

void data::welcomeShow()
{
	cout << "Welcome,No." << id << ' ' << name << ' ' << "level: " << level << endl;
}

void data::init(int theID=0)
{
	id=theID;
	used=true;
	name="x";
	age=0;
	grade=0;
	level=0;
	qq="qq";
	phone="phone";
	isAMan=false;
	password=initPassword;
}

void load()
{
	loadFile();
	simpleSort(1,t[0].id);
}

void loadFile()
{
	ifstream in;
	in.open("data.txt");
	if (!in.is_open()) //no file means first login.
	{
		user[GOD].init(GOD);
		user[GOD].level=9;
		t[++t[0].id]=user[GOD];
		cout << "no data.txt\n";
	}
	else
	{
		int id;
		while (in >> id)
		{
			user[id].id=id;
			user[id].used=true;
			in >> user[id].name >> user[id].age >> user[id].grade;
			in >> user[id].level >> user[id].qq >> user[id].phone >> user[id].password;
			in >> user[id].isAMan;
			t[++t[0].id]=user[id];
		}
	}
	in.close();
}

void saveFile()
{
	ofstream out;
	out.open("data.txt");
	for (int i=1;i<=MAXUSER;++i)
	{
		if (user[i].used)
		{
			out << user[i].id << ' ' << user[i].name << ' ' << user[i].age << ' ';
			out << user[i].grade << ' ' << user[i].level << ' ' << user[i].qq << ' ';
			out << user[i].phone << ' ' << user[i].password << ' ' << user[i].isAMan << '\n';
		}
	}
	out.close();
}

void popSort(int now)
{
	nodeForSort temp=t[now];
	while (t[now+1]<t[now] && now<t[0].id)
	{
		t[now]=t[now+1];
		++now;
	}
	while (t[now]<t[now-1] && now>1)
	{
		t[now]=t[now-1];
		--now;
	}
	t[now]=temp;
}

void simpleSort(int left,int right)
{
	//A simple quick sort
	if (left >= right)
		return;
	int l=left,r=right;

	nodeForSort k=t[l];
	while (l<r)
	{
		while (l<r && k<=t[r])
			--r;
		t[l]=t[r];
		while (l<r && t[l]<=k)
			++l;
		t[r]=t[l];
	}
	t[l]=k;
	simpleSort(left,l-1);
	simpleSort(l+1,right);
}

void cls()
{
	system("cls");
}

void pause()
{
	system("pause");
}
