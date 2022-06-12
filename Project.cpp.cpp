#include<iostream>
using namespace std;
class SignUp;
class CommentStack
{
	public:
		CommentStack *Next;
		CommentStack *Previous;
		string Comment;
		string UserName;
	CommentStack(string Comm , string Un)
	{
		Comment=Comm;	
		UserName=Un;
		Next=Previous=NULL;
	}
	void Display()
	{
		cout<<"\t\t\t\t+ BY "<<"("<<UserName<<")"<<" ="<<Comment<<endl;
	}
};
class CommentStackLinking
{
	public:
		CommentStack *Top;
		
	CommentStackLinking()
	{
		Top=NULL;
	}
	bool IsEmpty()
	{
		if(Top==NULL)
			return 1;
		else
			return 0;
	}
	void AddComment(string val , string un)
	{
		CommentStack *New=new CommentStack(val , un); 
		if(IsEmpty())
		{
			Top=New;
		}
		else
		{
			Top->Next=New;
			New->Previous=Top;
			Top=New;
		}
	}
	string Pop()
	{
		if(IsEmpty())
		{
			cout<<"STACK IS EMPTY !! "<<endl;
			return "";
		}
		else
		{
			CommentStack *Temp=Top;
			if(Temp->Previous==NULL) //IF HEAD IS GOING TO POP 
			{
				delete Temp;
				Top=NULL;
				return Temp->Comment;
			}
			else
			{
				string X=Top->Comment;
				Top=Top->Previous;
				Top->Next=NULL;
				delete Temp;
				return X;
			}
		}
	}
	string TopOfStack()
	{
		if(IsEmpty())
		{
			cout<<"STACK IS EMPTY !! "<<endl;
			return "";
		}
		else
		{
			string X=Top->Comment;
			return X;
		}
	}
	void DisplayComment()
	{
		if(Top==NULL)
		{
			cout<<"\t\t\t\tNO COMMENT ADDED YET !! "<<endl;
		}
		else
		{
			CommentStack *Temp=Top;
			while(Temp!=NULL)
			{
				cout<<"\t\t\t\t+ BY "<<"("<<Temp->UserName<<")"<<" = "<<Temp->Comment<<endl;
				Temp=Temp->Previous;
			}
		}
	}
};
class ConversationStack
{
	public:
		ConversationStack *Next;
		ConversationStack *Previous;
		string Name;
	ConversationStack(string Un)
	{	
		Name=Un;
		Next=Previous=NULL;
	}
};
class ConversationStackLinking
{
	public:
		ConversationStack *Top;
		
	ConversationStackLinking()
	{
		Top=NULL;
	}
	bool IsEmpty()
	{
		if(Top==NULL)
			return 1;
		else
			return 0;
	}
	void AddName(string un)
	{
		ConversationStack *New=new ConversationStack(un); 
		if(IsEmpty())
		{
			Top=New;
		}
		else
		{
			Top->Next=New;
			New->Previous=Top;
			Top=New;
		}
	}
	string Pop()
	{
		if(IsEmpty())
		{
			cout<<"STACK IS EMPTY !! "<<endl;
			return "";
		}
		else
		{
			ConversationStack *Temp=Top;
			if(Temp->Previous==NULL) //IF HEAD IS GOING TO POP 
			{
				delete Temp;
				Top=NULL;
				return Temp->Name;
			}
			else
			{
				string X=Top->Name;
				Top=Top->Previous;
				Top->Next=NULL;
				delete Temp;
				return X;
			}
		}
	}
	string TopOfStack()
	{
		if(IsEmpty())
		{
			cout<<"STACK IS EMPTY !! "<<endl;
			return "";
		}
		else
		{
			string X=Top->Name;
			return X;
		}
	}
	bool Search(string Name)
	{
		if(Top==NULL)
		{
			return 0;
		}
		else
		{
			ConversationStack *Temp=Top;
			while(Temp!=NULL)
			{
				if(Temp->Name==Name)
				{
					return 1;
				}
				Temp=Temp->Previous;
			}
		}
		return 0;
	}
	void ConversationDisplay()
	{
		if(Top==NULL)
		{
			cout<<endl;
			cout<<"\t\t\t============================"<<endl;
			cout<<"\t\t\t\tYOU HAVEN'T CHAT WITH ANYBODY !! "<<endl;
			cout<<"\t\t\t============================"<<endl;
			cout<<endl;
		}
		else
		{
			ConversationStack *Temp=Top;
			while(Temp!=NULL)
			{
				cout<<"\t\t\t+) "<<Temp->Name<<endl;
				Temp=Temp->Previous;
			}
		}
	}
};
class MessegeNode
{
	public:
		string Send;
		string Receive;
		MessegeNode *Next;
		MessegeNode *Previous;
	MessegeNode(string Sn , string Rc)
	{
		Send=Sn;
		Receive=Rc;
		Next=Previous=NULL;
	}		
};
class MessegeList
{
	public:
		MessegeNode *Head;
		MessegeNode *Tail;
	MessegeList()
	{
		Head=Tail=NULL;
	}
	void AddMessege(string Sn="" , string Rc="")
	{
		MessegeNode *New=new MessegeNode(Sn , Rc);
		if(Head==NULL)
		{
			Head=Tail=New;
		}
		else
		{
			Tail->Next=New;
			New->Previous=Tail;
			Tail=Tail->Next;
		}
	}
	void DisplayMessege()
	{
		MessegeNode *Temp=Head;
		if(Temp==NULL)
		{
			cout<<"\t\t\t============================"<<endl;
			cout<<"\t\t\tYOU NEVER CHAT WITH THIS USER "<<endl;
			cout<<"\t\t\t============================"<<endl;
			cout<<endl;
		}
		else
		{
			while(Temp!=NULL)
			{
				if(!Temp->Send.empty())
				{
					cout<<"\t\t\t+) "<<Temp->Send<<endl;
				}
				if(!Temp->Receive.empty())
				{
					cout<<"\t\t\t\t\t+) "<<Temp->Receive<<endl;
				}
				Temp=Temp->Next;
			}
		}
	}
};
class MessegeUserNode
{
	public:
		MessegeList *ML;
		SignUp *Sender;
		SignUp *Receiver;
		MessegeUserNode *Next;
		MessegeUserNode *Prev;
	MessegeUserNode(SignUp *Sen , SignUp *Rec)
	{
		Sender=Sen;
		Receiver=Rec;
		ML=new MessegeList;
		Next=Prev=NULL;
	}
};
class MessegeUserList
{
	public:
		MessegeUserNode *Head;
		MessegeUserNode *Tail;
	MessegeUserList()
	{
		Head=Tail=NULL;
	}
	bool InsertUser(SignUp *Se , SignUp *Re)
	{
		MessegeUserNode *New=new MessegeUserNode(Se , Re);
		if(Head==NULL)
		{
			Head=Tail=New;
			return 1;
		}
		else
		{
			if(Search(New->Sender , New->Receiver)==NULL)
			{
				Tail->Next=New;
				New->Prev=Tail;
				Tail=Tail->Next;
				return 1;
			}
			else
			{
				return 0;
			}
		}
	}
	MessegeUserNode *Search(SignUp *S , SignUp *R)
	{
		MessegeUserNode *Temp=Head;
		while(Temp!=NULL)
		{
			if(Temp->Sender==S && Temp->Receiver==R)
			{
				return Temp;
			}
			Temp=Temp->Next;
		}
		return NULL;
	}
};
class FriendsNode
{
	public:
		string Name;
		FriendsNode *Next;
		FriendsNode *Previous;
	FriendsNode(string Na)
	{
		Name=Na;
		Next=Previous=NULL;
	}		
};
class FriendsList
{
	public:
		FriendsNode *Head;
		FriendsNode *Tail;
	FriendsList()
	{
		Head=Tail=NULL;
	}
	void AddFriend(string Na)
	{
		FriendsNode *New=new FriendsNode(Na);
		if(Head==NULL)
		{
			Head=Tail=New;
		}
		else
		{
			Tail->Next=New;
			New->Previous=Tail;
			Tail=Tail->Next;
		}
	}
	bool SearchFriend(string Name)
	{
		FriendsNode *Temp=Head;
		if(Temp==NULL)
		{
			return 0;
		}
		else
		{
			while(Temp!=NULL)
			{
				if(Temp->Name==Name)
				{
					return 1;
				}
				Temp=Temp->Next;
			}
		}
		return 0;
	}
	void DeleteFriend(string Name)
	{
		FriendsNode *Temp=Head;
		FriendsNode *Del;
		if(Temp==NULL)
		{
			return;
		}
		else
		{
			while(Temp!=NULL)
			{
				if(Head->Name==Name)
				{
					Del=Head;
					Head=Head->Next;
					Del->Next=NULL;
				}
				else if(Tail->Name==Name)
				{
					Del=Tail;
					Tail=Tail->Previous;
					Tail->Next=NULL;
				}
				else
				{
					while(Temp!=NULL)
					{
						if(Temp->Name==Name)
						{
							Del=Temp;
							Temp->Previous->Next=Temp->Next;
							Temp->Next->Previous=Temp->Previous;
							break;
						}
						Temp=Temp->Next;
					}
				}
				delete Del;
				return;
			}
		}
	}
	void DisplayFriend()
	{
		FriendsNode *Temp=Head;
		if(Head==NULL)
		{
			return;
		}
		else
		{
			while(Temp!=NULL)
			{
				cout<<"\t\t\t+) "<<Temp->Name<<endl;
				Temp=Temp->Next;
			}
		}
	}
};
class Time
{
	public:
		int Hour;
		int Minutes;
		int Seconds;
	Time()
	{
		Hour=0;
		Minutes=0;
		Seconds=0;
	}
	void InputTime()
	{
		cout<<"\t\t\tENTER THE HOUR    : ";
		cin>>Hour;
		cout<<"\t\t\tENTER THE MINUTES : ";
		cin>>Minutes;
		cout<<"\t\t\tENTER THE SECONDS : ";
		cin>>Seconds;
	}
	int GetHour()
	{
		return Hour;
	}
	int GetMinutes()
	{
		return Minutes;
	}
	int GetSeconds()
	{
		return Seconds;
	}
};
class Date
{
	public:
		int Day;
		int Month;
		int Year;
	Date()
	{
		Day=0;
		Month=0;
		Year=0;
	}
	void InputDate()
	{
		cout<<"\t\t\tENTER THE DAY   : ";
		cin>>Day;
		cout<<"\t\t\tENTER THE MONTH : ";
		cin>>Month;
		cout<<"\t\t\tENTER THE YEAR  : ";
		cin>>Year;
	}
	int GetDay()
	{
		return Day;
	}
	int GetMonth()
	{
		return Month;
	}
	int GetYear()
	{
		return Year;
	}
};
class LikeNode
{
	public:
		SignUp *Liker;
		LikeNode *Next;
	LikeNode(SignUp *User)
	{
		Liker=User;
		Next=NULL;
	}
};
class LikeNodeLinking
{
	public:
		LikeNode *Head;
	LikeNodeLinking()
	{
		Head=NULL;
	}
	bool InsertLike(SignUp *Us)
	{
		LikeNode *New=new LikeNode(Us);
		if(Head==NULL)
		{
			Head=New;
			return 0;
		}
		else
		{
			bool Ans=Search(Us);
			if(Ans==1)
			{
				Delete(Us);
				return 1;
			}
			else
			{
				LikeNode *Temp=Head;
				while(Temp->Next!=NULL)
				{
					Temp=Temp->Next;
				}
				Temp->Next=New;
			}
			return 0;
		}
	}
	void Delete(SignUp *Us)
	{	
			LikeNode *Previous=Head;
			LikeNode *Front=Head;
			LikeNode *Del;
			if(Front==NULL)
			{
				return;
			}
			else
			{
				if(Front->Liker==Us)
				{
					Del=Front;
					Front=Front->Next;
					Head=Front;
				}
				else
				{
					while(Front->Next!=NULL)
					{
						Previous=Front;
						Front=Front->Next;
						if(Front->Liker==Us)
						{
							Del=Front;
							Previous->Next=Front->Next;
						}
					}
				}
				delete Del;
			}
	}
	bool Search(SignUp *Te)
	{
		LikeNode *Temp=Head;
		while(Temp!=NULL)
		{
			if(Temp->Liker==Te)
			{
				return 1;
			}
			Temp=Temp->Next;
		}
		return 0;
	}
	int Count()
	{
		LikeNode *Temp=Head;
		int Sum=0;
		if(Temp==NULL)
		{
			return Sum;
		}
		else
		{
			while(Temp!=NULL)
			{
				Sum++;
				Temp=Temp->Next;
			}
		}
		return Sum;
	}
};
class Post
{
	public:
		string Content;
		string Name;
		int PostNo;
		Date *D1;
		Time *T1;
		LikeNodeLinking *LNL;
	Post()
	{
		Content="";
		PostNo=0;
		Name="";
		D1=new Date;
		T1=new Time;
		LNL=new LikeNodeLinking;
	}
	void CreatePost()
	{
		cout<<"\t\t\tENTER THE ID OF NEW POST : ";
		cin>>PostNo;
		cout<<endl;
		cin.ignore();
		cout<<"\t\t\tENTER THE DETAILED CONTENT OF POST ... !! "<<endl;
		cout<<endl;
		cout<<"\t\t\t";
		getline(cin , Content);
		cout<<endl;
		cout<<"\t\t\t============================"<<endl;
		cout<<"\t\t\tIT'S TIME TO ENTER THE DATE !! "<<endl;
		cout<<"\t\t\t============================"<<endl;
		cout<<endl;
		D1->InputDate();
		cout<<endl;
		cout<<"\t\t\t============================"<<endl;
		cout<<"\t\t\tIT'S TIME TO ENTER THE TIME !! "<<endl;
		cout<<"\t\t\t============================"<<endl;
		cout<<endl;
		T1->InputTime();
	}
	void DisplayPost()
	{
		cout<<"\t\t\t============================"<<endl;
		cout<<"\t\t\tPOST NUMBER   : "<<PostNo<<endl;
		cout<<"\t\t\tCREATOR NAME  : "<<Name<<endl;
		cout<<"\t\t\tCREATION DATE : "<<D1->GetDay()<<"/"<<D1->GetMonth()<<"/"<<D1->GetYear()<<endl;
		cout<<"\t\t\tCREATION TIME : "<<T1->GetHour()<<":"<<T1->GetMinutes()<<":"<<T1->GetSeconds()<<endl;
		cout<<"\t\t\t============================"<<endl;
		cout<<"\t\t\tPOST CONTENT : "<<endl;
		cout<<"\t\t\t";
		cout<<Content;
		cout<<endl;
		char Ch=3;
		cout<<"\t\t\t============================"<<endl;
		cout<<"\t\t\t             "<<LNL->Count()<<" "<<Ch <<endl;
		cout<<"\t\t\t****************************"<<endl;
	}
	void IndividualDisplayPost()
	{
		cout<<"\t\t\t============================"<<endl;
		cout<<"\t\t\tPOST NUMBER   : "<<PostNo<<endl;
		cout<<"\t\t\tCREATOR NAME  : "<<Name<<endl;
		cout<<"\t\t\tCREATION DATE : "<<D1->GetDay()<<"/"<<D1->GetMonth()<<"/"<<D1->GetYear()<<endl;
		cout<<"\t\t\tCREATION TIME : "<<T1->GetHour()<<":"<<T1->GetMinutes()<<":"<<T1->GetSeconds()<<endl;
		cout<<"\t\t\t============================"<<endl;
		cout<<"\t\t\tPOST CONTENT : "<<endl;
		cout<<"\t\t\t";
		cout<<Content;
		cout<<endl;
		char Ch=3;
		cout<<"\t\t\t============================"<<endl;
		cout<<"\t\t\t             "<<LNL->Count()<<" "<<Ch <<endl;
		cout<<"\t\t\t****************************"<<endl;
	}
};
class PostNode
{
	public:
		PostNode *Next;
		PostNode *Previous;
		Post *PST;
		CommentStackLinking *CST;
	PostNode(Post *PT)
	{
		PST=PT;
		CST=new CommentStackLinking;
		Next=Previous=NULL;
	}	
};
class PostNodeLinking
{
	public:
		PostNode *Head;
		PostNode *Tail;
	PostNodeLinking()
	{
		Head=Tail=NULL;
	}
	int AuthenticatePost(int PNO)
	{
		PostNode *Temp=Head;
		if(Head==NULL)
		{
			return 0;
		}
		else
		{
			while(Temp!=NULL)
			{
				if(Temp->PST->PostNo==PNO)
				{
					system("cls");
					cout<<endl;
					cout<<"\t\t\t============================"<<endl;
					cout<<"\t\t\tPOST WITH GIVEN ID ALREADY EXIST !! "<<endl;
					cout<<"\t\t\t============================"<<endl;
					cout<<endl;
					cout<<"\t\t\t";
					system("pause");
					return 1;
				}
				Temp=Temp->Next;
			}
		}
		return 0;
	}
	void AddPost(string Name)
	{
		Post *PS=new Post;
		PS->CreatePost();
		PS->Name=Name;
		int Ans=AuthenticatePost(PS->PostNo);
		if(Ans==1)
		{
			delete PS;
			return ;
		}
		PostNode *New=new PostNode(PS);
		if(Head==NULL)
		{
			Head=Tail=New;
		}
		else if(CompareDate(New->PST->D1) >= CompareDate(Head->PST->D1))
		{
			New->Next=Head;
			Head->Previous=New;
			Head=New;
		}
		else
		{
			PostNode *Temp=Head;
			while(Temp->Next!=NULL && (CompareDate(Temp->PST->D1)>=CompareDate(New->PST->D1)))
			{
				Temp=Temp->Next;
			}
			if(Temp->Next==NULL && (CompareDate(Temp->PST->D1)>=CompareDate(New->PST->D1)))
			{
				Temp->Next=New;
				New->Previous=Temp;
				Tail=New;
			}
			else
			{
				New->Next=Temp;
				Temp->Previous->Next=New;
				New->Previous=Temp->Previous;
				Temp->Previous=New;
			}
		}
		cout<<endl;
		cout<<"\t\t\t============================"<<endl;
		cout<<"\t\t\tPOST HAS BEEN CREATED SUCCESSFULLY !! "<<endl;
		cout<<"\t\t\t============================"<<endl;
		cout<<endl;
		cout<<"\t\t\t";
		system("pause");
	}
	void AddPostByObject(PostNode *Obj)
	{
		PostNode *New=new PostNode(Obj->PST);
		if(Head==NULL)
		{
			Head=Tail=New;
		}
		else if(CompareDate(New->PST->D1) >= CompareDate(Head->PST->D1))
		{
			New->Next=Head;
			Head->Previous=New;
			Head=New;
		}
		else
		{
			PostNode *Temp=Head;
			while(Temp->Next!=NULL && (CompareDate(Temp->PST->D1)>=CompareDate(New->PST->D1)))
			{
				Temp=Temp->Next;
			}
			if(Temp->Next==NULL && (CompareDate(Temp->PST->D1)>=CompareDate(New->PST->D1)))
			{
				Temp->Next=New;
				New->Previous=Temp;
			}
			else
			{
				New->Next=Temp;
				Temp->Previous->Next=New;
				New->Previous=Temp->Previous;
				Temp->Previous=New;
			}
		}
	}
	int CompareDate(Date *D1)
	{
		int Num1=D1->GetDay()+(D1->GetMonth()*12)+(D1->GetYear()*365);
		return Num1;
	}
	void ViewPost()
	{
		PostNode *Temp=Head;
		if(Temp==NULL)
		{
			cout<<"\t\t\t============================"<<endl;
			cout<<"\t\t\tPOST PAGE IS EMPTY !! "<<endl;
			cout<<"\t\t\t============================"<<endl;
		}
		else
		{
			while(Temp!=NULL)
			{
				Temp->PST->DisplayPost();
				Temp=Temp->Next;
			}
		}
	}
	void IndividualViewPost(PostNode *Tmp)
	{
		Tmp->PST->IndividualDisplayPost();
		cout<<"\t\t\tCOMMENTS : "<<endl;
		Tmp->CST->DisplayComment();
	}
	void DeletePost()
	{
		PostNode *Temp=Head;
		PostNode *Del=NULL;
		if(Temp==NULL)
		{
			cout<<"\t\t\t============================"<<endl;
			cout<<"\t\t\tPOST PAGE IS EMPTY !! "<<endl;
			cout<<"\t\t\t============================"<<endl;
			cout<<endl;
			cout<<"\t\t\t";
			system("pause");
		}
		else
		{
			cout<<"\t\t\tENTER POST NUMBER TO DELETE : ";
			int PNO;
			cin>>PNO;
			int Coun=0;
			if(Head->PST->PostNo==PNO)
			{
				Del=Head;
				Head=Head->Next;
				Del->Next=NULL;
				
				cout<<endl;
				cout<<"\t\t\t============================"<<endl;
				cout<<"\t\t\tPOST HAS BEEN DELETED SUCCESSFULLY !! "<<endl;
				cout<<"\t\t\t============================"<<endl;
				cout<<endl;
				cout<<"\t\t\t";
				system("pause");
				
				Coun++;
			}
			else
			{
				while(Temp!=NULL)
				{
					if(Temp->PST->PostNo==PNO)
					{
						if(Temp->Next==NULL)
						{
							Del=Temp;
							Tail=Tail->Previous;
							Tail->Next=NULL;
							
							cout<<endl;
							cout<<"\t\t\t============================"<<endl;
							cout<<"\t\t\tPOST HAS BEEN DELETED SUCCESSFULLY !! "<<endl;
							cout<<"\t\t\t============================"<<endl;
							cout<<endl;
							cout<<"\t\t\t";
							system("pause");
							
							Coun++;
							break;
						}
						else
						{
							Temp->Previous->Next=Temp->Next;
							Temp->Next->Previous=Temp->Previous;
							
							cout<<endl;
							cout<<"\t\t\t============================"<<endl;
							cout<<"\t\t\tPOST HAS BEEN DELETED SUCCESSFULLY !! "<<endl;
							cout<<"\t\t\t============================"<<endl;
							cout<<endl;
							cout<<"\t\t\t";
							system("pause");
							
							Coun++;
							break;
						}
					}
					Temp=Temp->Next;
				}
			}
			if(Coun==0)
			{
				cout<<endl;
				cout<<"\t\t\t============================"<<endl;
				cout<<"\t\t\tPOST NOT FOUND !! "<<endl;
				cout<<"\t\t\t============================"<<endl;
				cout<<endl;
				cout<<"\t\t\t";
				system("pause");
				return;
			}
			delete Del;
		}
	}
	void UpdatePost()
	{
		PostNode *Temp=Head;
		if(Temp==NULL)
		{
			cout<<"\t\t\t============================"<<endl;
			cout<<"\t\t\tPOST PAGE IS EMPTY !! "<<endl;
			cout<<"\t\t\t============================"<<endl;
			cout<<endl;
			cout<<"\t\t\t";
			system("pause");
		}
		else
		{
			cout<<"\t\t\tENTER THE POST NUMBER TO UPDATE :";
			int PNO;
			cin>>PNO;
			cout<<endl;
			int Cou=0;
			while(Temp!=NULL)
			{
				if(Temp->PST->PostNo==PNO)
				{
					cin.ignore();
					cout<<"\t\t\tENTER THE DETAILED CONTENT OF POST ... !! "<<endl;
					cout<<endl;
					cout<<"\t\t\t";
					getline(cin , Temp->PST->Content);
					
					cout<<endl;
					cout<<"\t\t\t============================"<<endl;
					cout<<"\t\t\tPOST HAS BEEN UPDATED SUCCESSFULLY !! "<<endl;
					cout<<"\t\t\t============================"<<endl;
					cout<<endl;
					cout<<"\t\t\t";
					system("pause");
				
					Cou++;
					break;
				}
				Temp=Temp->Next;
			}
			if(Cou==0)
			{
				cout<<"\t\t\t============================"<<endl;
				cout<<"\t\t\tNO POST FOUND "<<endl;
				cout<<"\t\t\t============================"<<endl;
				cout<<endl;
				cout<<"\t\t\t";
				system("pause");
			}
		}
	}
};
class UserData
{
	public:
		string UserName;
		string PassWord;
	UserData()
	{
		UserName="";
		PassWord="";
	}
	void InputData()
	{
		cout<<"\t\t\tENTER UNIQUE USER-NAME : ";
		getline(cin , UserName);
		cout<<"\t\t\tENTER UNIQUE PASS-WORD : ";
		getline(cin , PassWord);
	}
	void DisplayData()
	{
		cout<<"\t\t\tUSER-NAME : "<<UserName<<endl;
		cout<<"\t\t\tPASS-WORD : "<<PassWord<<endl;
	}
};
class SignUp
{
	public:
		UserData UD;
		PostNodeLinking *PNL;
		FriendsList *Friends;
		FriendsList *Requests;
		ConversationStackLinking *Conversation;
		MessegeUserList *MUL;
		SignUp *Left;
		SignUp *Right;
	SignUp(UserData U)
	{
		UD=U;
		PNL=new PostNodeLinking;
		Friends =new FriendsList;
		Requests=new FriendsList;
		Conversation=new ConversationStackLinking;
		MUL=new MessegeUserList;
		Left=Right=NULL;
	}
};
class SignUp_Linking
{
	public:
		SignUp *Root;
	SignUp_Linking()
	{
		Root=NULL;
	}
	void Insertion()
	{
		Top:

		UserData U1;
		U1.InputData();
		if(U1.UserName=="" && U1.PassWord=="")
		{
			cout<<endl;
			cout<<"\t\t\tNO INPUT DETECTED !! "<<endl;
			return;
		}
		SignUp *New=new SignUp(U1);
		
		if(Root==NULL)
		{
			Root=New;
		}
		else
		{
			SignUp *Temp=Root;
			while(true)
			{
				if(New->UD.UserName==Temp->UD.UserName)
				{
					cout<<endl;
					cout<<"\t\t\tUSER-NAME MUST BE UNIQUE !! "<<endl;
					cout<<endl;
					cout<<"\t\t\t============================"<<endl;
					cout<<"\t\t\tPRESS 1) TO GO BACK "<<endl;
					cout<<"\t\t\tPRESS 2) TO RETRY   "<<endl;
					int Ask;
					cout<<"\t\t\tCHOCIE > ";
					cin>>Ask;
					cin.ignore();
					if(Ask==2)
					{
						system("cls");
						cout<<"\t\t\t============================"<<endl;
						cout<<"\t\t\t           SIGN-UP          "<<endl;
						cout<<"\t\t\t============================"<<endl;
						cout<<endl;
						goto Top;
					}
					else
					{
						return;
					}
				}
				if(New->UD.UserName>Temp->UD.UserName)
				{
					if(Temp->Right==NULL)
					{
						Temp->Right=New;
						break;
					}
					else
					{
						Temp=Temp->Right;
					}
				}
				else
				{
					if(Temp->Left==NULL)
					{
						Temp->Left=New;
						break;
					}
					else
					{
						Temp=Temp->Left;
					}
				}
			}
		}
		cout<<endl;
		cout<<"\t\t\t============================"<<endl;
		cout<<"\t\t\tYOU SUCCESSFULLY SIGNED UP "<<endl;
		cout<<"\t\t\t============================"<<endl;
	}
};
class Node{
public:
	char Character;
	bool IsEndOfWord;
	Node *Children[91];

	Node(char Ch)
	{
		Character = Ch;
		IsEndOfWord = false;
		for (int i = 0; i <91; i++)
		{
			Children[i] = NULL;
		}
	}
};

class Tries
{
public:
	Node* Root;
	
	Tries()
	{
		Root = NodeCreation('\0');
	}

	Node* NodeCreation(char c)
	{
		Node *NewNode = new Node(c);
		return NewNode;
	}

	void Insert(string word)
	{
		Node* Temp = Root;
		char ch = '\0';
		int pos = 0;
		for (int i = 0; i < word.length(); i++)
		{
			
			ch = word[i];
			pos = 'z'-ch;
			if (Temp->Children[pos] == NULL)
			{
				Temp->Children[pos] = NodeCreation(ch);
			}
			Temp = Temp->Children[pos];
		}
		Temp->IsEndOfWord = true;
	}

	void Display(Node* Temp, string Word)
	{
		if (Temp == NULL)
			return;
		
			if (Temp!=Root)
				Word = Word + Temp->Character;
			if (Temp->IsEndOfWord)
				cout <<"\t\t\t+) "<<Word<<endl;
			for (int i = 0; i<91; i++)
			{
				Display(Temp->Children[i], Word);
			}
	}
	Node* search(Node* Temp, string key, int Index)
	{
		
		if (Temp == NULL)
		{
			return Temp;
		}

		char ch = key[Index];

		if (Temp->IsEndOfWord && Index==key.size())
		{
			return Temp;
		}
		if (ch == '\0')
		{
			return Temp;
		}
		int i = 'z'-ch;
		 
		return	search(Temp->Children[i], key, ++Index);
					
	}
};
class LogIn
{
	public:
		SignUp *SuRoot;
		SignUp *FoundRoot;
		SignUp *RequestedUser;
		Tries TR;
		int NodeCounter=0;
		LogIn()
		{
			SuRoot=NULL;
			FoundRoot=NULL;
			RequestedUser=NULL;
		}
		int Authenticate_User(SignUp *Temp)
		{
			SuRoot=Temp;
			if(SuRoot==NULL)
			{
				cout<<"\t\t\tYOU NEED TO SIGN-UP FIRST !! "<<endl;
				return -1;
			}
			else
			{
				cout<<"\t\t\tENTER USER-NAME : ";
				string Uname;
				getline(cin , Uname);
				cout<<"\t\t\tENTER PASS-WORD : ";
				string Upass;
				getline(cin , Upass);
				bool Found=Search_User(Uname , Upass , SuRoot);
				if(Found==1)
				{
					cout<<endl;
					cout<<"\t\t\t============================"<<endl;
					cout<<"\t\t\tWELCOME !! LOG-IN SUCCESS !!"<<endl;
					cout<<"\t\t\t============================"<<endl;
					return 1;
				}
				else
				{
					return 0;
				}
			}	
		}
		bool Search_User(string Name , string Pass , SignUp *Temp)
		{
			while(Temp!=NULL)
			{
				if(Temp->UD.UserName==Name && Temp->UD.PassWord==Pass)
				{
					FoundRoot=Temp;
					return 1;
				}
				if(Name>Temp->UD.UserName)
				{
					Temp=Temp->Right;
				}
				else
				{
					Temp=Temp->Left;
				}
			}
			return 0;
		}
		bool Search_User_By_Name(string Name)
		{
			SignUp *Temp=SuRoot;
			while(Temp!=NULL)
			{
				if(Temp->UD.UserName==Name)
				{
					RequestedUser=Temp;
					return 1;
				}
				if(Name>Temp->UD.UserName)
				{
					Temp=Temp->Right;
				}
				else
				{
					Temp=Temp->Left;
				}
			}
			return 0;
		}
		SignUp *Search_User_Return(string Name)
		{
			SignUp *Temp=SuRoot;
			int Count=0;
			while(Temp!=NULL)
			{
				if(Temp->UD.UserName==Name)
				{
					Count++;
					return Temp;
				}
				if(Name>Temp->UD.UserName)
				{
					Temp=Temp->Right;
				}
				else
				{
					Temp=Temp->Left;
				}
			}
			return 0;
		}
		void CountNodes(SignUp *Temp)
		{
			if(Temp==NULL)
			{
				return;
			}
			else
			{
				CountNodes(Temp->Left);
				CountNodes(Temp->Right);
				NodeCounter++;
			}
		}
		void TriesInsert(SignUp *Temp)
		{
			if(Temp==NULL)
			{
				return;
			}
			else
			{
				TR.Insert(Temp->UD.UserName);
				TriesInsert(Temp->Left);
				TriesInsert(Temp->Right);
			}
		}
		void Personal_Tab()
		{
			Menu:
			system("cls");
			cout<<"\t\t\t============================"<<endl;
			cout<<"\t\t\t      PERSONAL TAB MENU     "<<"\t("<<FoundRoot->UD.UserName<<")"<<endl;
			cout<<"\t\t\t============================"<<endl;
			cout<<endl;
			cout<<"\t\t\tPRESS 1) TO CREATE NEW POST "<<endl;
			cout<<"\t\t\tPRESS 2) TO VIEW POST "<<endl;
			cout<<"\t\t\tPRESS 3) TO UPDATE POST "<<endl;
			cout<<"\t\t\tPRESS 4) TO DELETE POST "<<endl;
			cout<<"\t\t\tPRESS 5) TO GO BACK "<<endl;
			int Select;
			cout<<endl;
			cout<<"\t\t\tENTER YOUR CHOCIE : ";
			cin>>Select;
			if(Select==1)
			{
				system("cls");
				cout<<"\t\t\t============================"<<endl;
				cout<<"\t\t\t  WELCOME IN POST CREATION  "<<"\t("<<FoundRoot->UD.UserName<<")"<<endl;
				cout<<"\t\t\t============================"<<endl;
				cout<<endl;
				FoundRoot->PNL->AddPost(FoundRoot->UD.UserName);
				
			}
			if(Select==2)
			{
				system("cls");
				cout<<"\t\t\t============================"<<endl;
				cout<<"\t\t\t    WELCOME IN POST VIEW    "<<"\t("<<FoundRoot->UD.UserName<<")"<<endl;
				cout<<"\t\t\t============================"<<endl;
				cout<<endl;
				FoundRoot->PNL->ViewPost();
				cout<<endl;
				cout<<"\t\t\t";
				system("pause");
			}
			if(Select==3)
			{
				system("cls");
				cout<<"\t\t\t============================"<<endl;
				cout<<"\t\t\t    WELCOME IN POST UPDATE  "<<"\t("<<FoundRoot->UD.UserName<<")"<<endl;
				cout<<"\t\t\t============================"<<endl;
				cout<<endl;
				FoundRoot->PNL->UpdatePost();
			}
			if(Select==4)
			{
				system("cls");
				cout<<"\t\t\t============================"<<endl;
				cout<<"\t\t\t  WELCOME IN POST DELETION  "<<"\t("<<FoundRoot->UD.UserName<<")"<<endl;
				cout<<"\t\t\t============================"<<endl;
				cout<<endl;
				FoundRoot->PNL->DeletePost();
			}
			if(Select==5)
			{
				return;
			}
			else
			{
				goto Menu;
			}
		}
		void Friends_Tab()
		{
			Menu:
			system("cls");
			cout<<"\t\t\t============================"<<endl;
			cout<<"\t\t\t       FRIENDS TAB MENU     "<<"\t("<<FoundRoot->UD.UserName<<")"<<endl;
			cout<<"\t\t\t============================"<<endl;
			cout<<endl;
			cout<<"\t\t\tPRESS 1) TO SEE MY FRIENDS "<<endl;
			cout<<"\t\t\tPRESS 2) TO ADD NEW FRIEND "<<endl;
			cout<<"\t\t\tPRESS 3) TO SEE FRIEND REQUEST "<<endl;
			cout<<"\t\t\tPRESS 4) TO GO BACK "<<endl;
			int Select;
			cout<<endl;
			cout<<"\t\t\tENTER YOUR CHOCIE : ";
			cin>>Select;
			if(Select==1)
			{
				system("cls");
				cout<<"\t\t\t============================"<<endl;
				cout<<"\t\t\t    WELCOME IN MY FRIENDS   "<<"\t("<<FoundRoot->UD.UserName<<")"<<endl;
				cout<<"\t\t\t============================"<<endl;
				cout<<endl;
				if(FoundRoot->Friends->Head==NULL)
				{
					cout<<"\t\t\t============================"<<endl;
					cout<<"\t\t\t   YOU HAVE NO FIRENDS YET  "<<endl;
					cout<<"\t\t\t============================"<<endl;
					cout<<endl;
					cout<<"\t\t\t";
					system("pause");
				}
				else
				{
					cout<<endl;
					cout<<"\t\t\tYOUR FRIENDS ARE : "<<endl;
					cout<<endl;
					FoundRoot->Friends->DisplayFriend();
					cout<<endl;
					cout<<"\t\t\t";
					system("pause");
				}
			}
			if(Select==2)
			{
				system("cls");
				cout<<"\t\t\t============================"<<endl;
				cout<<"\t\t\t   WELCOME IN ADD FRIENDS   "<<"\t("<<FoundRoot->UD.UserName<<")"<<endl;
				cout<<"\t\t\t============================"<<endl;
				cout<<endl;
				
				cin.ignore();
				TriesInsert(SuRoot);
				cout<<"\t\t\tENTER KEYWORD TO SEARCH : ";
				string Key;
				getline(cin , Key);
				if(Key=="")
				{
					cout<<endl;
					cout<<"\t\t\t============================"<<endl;
					cout<<"\t\t\t      NO INPUT DETECTED     "<<endl;
					cout<<"\t\t\t============================"<<endl;
					cout<<endl;
					cout<<"\t\t\t";
					system("pause");
					goto Menu;
				}
				cout<<endl;
				Node* Temp=TR.search(TR.Root,Key,0);
				Key.erase(Key.size()-1);
				if (Temp)
				{
					cout<<"\t\t\tAVAILABLE USERS ARE !! "<<endl;
					cout<<endl;
					TR.Display(Temp, Key);
				}
				else
				{
					cout<<"\t\t\t============================"<<endl;
					cout << "\t\t\tUSER NOT FOUND !! "<<endl;
					cout<<"\t\t\t============================"<<endl;
					cout<<endl;
					cout<<"\t\t\t";
					system("pause");
					goto Menu;
				}
				string Pick;
				cout<<endl;
				cout<<"\t\t\tENTER THE NAME TO SEND REQUEST : ";
				getline(cin , Pick);
				cout<<endl;
				bool Chk=FoundRoot->Friends->SearchFriend(Pick);
				if(Chk==1)
				{
					cout<<endl;
					cout<<"\t\t\t============================"<<endl;
					cout<<"\t\t\tYOU BOTH ARE FRIEND ALREADY !!"<<endl;
					cout<<"\t\t\t============================"<<endl;
					cout<<endl;
					cout<<"\t\t\t";
					system("pause");
					goto Menu;
				}
				if(FoundRoot->UD.UserName==Pick)
				{
					cout<<endl;
					cout<<"\t\t\t============================"<<endl;
					cout<<"\t\t\tREQUEST TO YOURSELF IS PROHIBBETED !!"<<endl;
					cout<<"\t\t\t============================"<<endl;
					cout<<endl;
					cout<<"\t\t\t";
					system("pause");
					goto Menu;
				}
				bool Find=Search_User_By_Name(Pick);
				if(Find==1)
				{
					RequestedUser->Requests->AddFriend(FoundRoot->UD.UserName);
					cout<<"\t\t\t============================"<<endl;
					cout<<"\t\t\tFRIEND REQUEST SENT !! "<<endl;
					cout<<"\t\t\t============================"<<endl;
					cout<<endl;
				}
				else
				{
					cout<<"\t\t\t============================"<<endl;
					cout<<"\t\t\tUSER NOT FOUND !! "<<endl;
					cout<<"\t\t\t============================"<<endl;
					cout<<endl;
				}
				cout<<"\t\t\t";
				system("pause");
				
			}
			if(Select==3)
			{
				system("cls");
				cout<<"\t\t\t============================"<<endl;
				cout<<"\t\t\t  WELCOME IN FRIEND REQUEST "<<"\t("<<FoundRoot->UD.UserName<<")"<<endl;
				cout<<"\t\t\t============================"<<endl;
				cout<<endl;
				if(FoundRoot->Requests->Head==NULL)
				{
					cout<<"\t\t\t============================"<<endl;
					cout<<"\t\t\t  YOU HAVE NO REQUESTS YET  "<<endl;
					cout<<"\t\t\t============================"<<endl;
					cout<<endl;
					cout<<"\t\t\t";
					system("pause");
				}
				else
				{
					cout<<endl;
					cout<<"\t\t\tAVAILABLE REQUESTS ARE : "<<endl;
					cout<<endl;
					FoundRoot->Requests->DisplayFriend();
					string Pick;
					cout<<endl;
					cin.ignore();
					cout<<"\t\t\tENTER THE NAME TO ADD FRIEND : ";
					getline(cin , Pick);
					cout<<endl;
					bool Find=Search_User_By_Name(Pick);
					if(Find==1)
					{
						FoundRoot->Friends->AddFriend(Pick);
						RequestedUser->Friends->AddFriend(FoundRoot->UD.UserName);
						cout<<"\t\t\t============================"<<endl;
						cout<<"\t\t\tYOU BOTH BECAME FRIEND'S !! "<<endl;
						cout<<"\t\t\t============================"<<endl;
						cout<<endl;
						FoundRoot->Requests->DeleteFriend(RequestedUser->UD.UserName);
					}
					else
					{
						cout<<"\t\t\t============================"<<endl;
						cout<<"\t\t\tUSER NOT FOUND !! "<<endl;
						cout<<"\t\t\t============================"<<endl;
						cout<<endl;
					}
					cout<<endl;
					cout<<"\t\t\t";
					system("pause");
				}
			}
			if(Select==4)
			{
				return;
			}
			else
			{
				goto Menu;
			}
		}
		void Home_Tab()
		{
			Menu:
			system("cls");
			cout<<"\t\t\t============================"<<endl;
			cout<<"\t\t\t        HOME TAB MENU       "<<"\t("<<FoundRoot->UD.UserName<<")"<<endl;
			cout<<"\t\t\t============================"<<endl;
			cout<<endl;
			cout<<"\t\t\tPRESS 1) TO VIEW POST (ALSO OF FRIENDS)"<<endl;
			cout<<"\t\t\tPRESS 2) TO UPDATE OWN POST "<<endl;
			cout<<"\t\t\tPRESS 3) TO DELETE OWN POST "<<endl;
			cout<<"\t\t\tPRESS 4) TO GO BACK "<<endl;
			int Select;
			cout<<endl;
			cout<<"\t\t\tENTER YOUR CHOCIE : ";
			cin>>Select;
			if(Select==1)
			{
				system("cls");
				cout<<"\t\t\t============================"<<endl;
				cout<<"\t\t\t    WELCOME IN VIEW POSTS   "<<"\t("<<FoundRoot->UD.UserName<<")"<<endl;
				cout<<"\t\t\t============================"<<endl;
				cout<<endl;
				PostNodeLinking *PL=new PostNodeLinking;
				if(FoundRoot->Friends->Head==NULL)
				{
					AddOwnData(PL , FoundRoot->PNL->Head);
				}
				else
				{
					AddOwnData(PL , FoundRoot->PNL->Head);
					FriendsNode *FN=FoundRoot->Friends->Head;
					while(FN!=NULL)
					{
						SignUp *User=Search_User_Return(FN->Name);
						PostNode *PN=User->PNL->Head;
						while(PN!=NULL)
						{
							PL->AddPostByObject(PN);
							PN=PN->Next;
						}
						FN=FN->Next;
					}
				}
				PL->ViewPost();
				cout<<"\t\t\t  YOU ARE ALL CAUGHT UP !!  "<<endl;
				cout<<"\t\t\t============================"<<endl;
				cout<<endl;
				cout<<"\t\t\t=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+= "<<endl;
				cout<<"\t\t\tPRESS 1 ) TO VIEW POST INDIVIDUALLY "<<endl;
				cout<<"\t\t\tPRESS 2 ) TO ADD A PUBLIC COMMENT "<<endl;
				cout<<"\t\t\tPRESS 3 ) TO LIKE THE POST "<<endl;
				cout<<"\t\t\tPRESS 4 ) TO GO BACK  "<<endl;
				cout<<"\t\t\t=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+= "<<endl;
				cout<<endl;
				cout<<"\t\t\tENTER THE CHOICE : ";
				int Choice;
				cin>>Choice;
				if(Choice==1)
				{
					system("cls");
					cout<<"\t\t\t============================"<<endl;
					cout<<"\t\t\t WELCOME IN INDIVIDUAL VIEW "<<"\t("<<FoundRoot->UD.UserName<<")"<<endl;
					cout<<"\t\t\t============================"<<endl;
					string Name;
					int PostNo;
					cin.ignore();
					cout<<endl;
					cout<<"\t\t\tENTER THE NAME OF USER  : ";
					getline(cin , Name);
					cout<<"\t\t\tENTER THE POST NUMBER # : ";
					cin>>PostNo;
					cin.ignore();
					cout<<endl;
					SignUp *Found=Search_User_Return(Name);
					if(Found)
					{
						PostNode *PostTemp=Found->PNL->Head;
						if(PostTemp==NULL)
						{
							cout<<endl;
							cout<<"\t\t\t============================"<<endl;
							cout<<"\t\t\tNO POST ADDED BY USER !! "<<endl;
							cout<<"\t\t\t============================"<<endl;
							cout<<endl;
							cout<<"\t\t\t";
							system("pause");
							goto Menu;
						}
						else
						{
							int Co=0;
							while(PostTemp!=NULL)
							{
								if(PostTemp->PST->PostNo==PostNo)
								{
									Co++;
									Found->PNL->IndividualViewPost(PostTemp);
									break;
								}
								PostTemp=PostTemp->Next;
							}
							if(Co==0)
							{
								cout<<"\t\t\t============================"<<endl;
								cout<<"\t\t\tNO POST FOUND WITH THIS ID !! "<<endl;
								cout<<"\t\t\t============================"<<endl;
							}
						}
					}
					else
					{
						cout<<"\t\t\t============================"<<endl;
						cout<<"\t\t\tUSER NOT FOUND !! "<<endl;
						cout<<"\t\t\t============================"<<endl;
					}
				}
				if(Choice==2)
				{
					system("cls");
					cout<<"\t\t\t============================"<<endl;
					cout<<"\t\t\t WELCOME IN COMMENT SECTION "<<"\t("<<FoundRoot->UD.UserName<<")"<<endl;
					cout<<"\t\t\t============================"<<endl;
					cout<<endl;
					string Name;
					int PostNo;
					cin.ignore();
					cout<<endl;
					cout<<"\t\t\tENTER THE NAME OF USER  : ";
					getline(cin , Name);
					cout<<"\t\t\tENTER THE POST NUMBER # : ";
					cin>>PostNo;
					cin.ignore();
					cout<<endl;
					SignUp *Found=Search_User_Return(Name);
					if(Found)
					{
						PostNode *PostTemp=Found->PNL->Head;
						if(PostTemp==NULL)
						{
							cout<<endl;
							cout<<"\t\t\t============================"<<endl;
							cout<<"\t\t\tNO POST ADDED BY USER !! "<<endl;
							cout<<"\t\t\t============================"<<endl;
							cout<<endl;
							cout<<"\t\t\t";
							system("pause");
							goto Menu;
						}
						else
						{
							int Co=0;
							while(PostTemp!=NULL)
							{
								if(PostTemp->PST->PostNo==PostNo)
								{
									Match:
									Co++;
									cout<<"\t\t\t";
									system("pause");
									system("cls");
									cout<<"\t\t\t============================"<<endl;
									cout<<"\t\t\t WELCOME IN COMMENT SECTION "<<endl;
									cout<<"\t\t\t============================"<<endl;
									cout<<endl;
									PostTemp->PST->DisplayPost();
									string Text;
									cout<<"\t\t\tWRITE YOUR COMMENT : ";
									getline(cin , Text);
									PostTemp->CST->AddComment(Text , FoundRoot->UD.UserName);
									cout<<endl;
									
									system("cls");
									cout<<"\t\t\t============================"<<endl;
									cout<<"\t\t\t WELCOME IN COMMENT SECTION "<<endl;
									cout<<"\t\t\t============================"<<endl;
									cout<<endl;
									Found->PNL->IndividualViewPost(PostTemp);
									
									cout<<"\t\t\t============================"<<endl;
									cout<<"\t\t\tCOMMENT ADDED SUCCESSFYLLY !! "<<endl;
									cout<<"\t\t\t============================"<<endl;
									cout<<endl;
									cout<<"\t\t\t";
									system("pause");
								}
								PostTemp=PostTemp->Next;
							}
							if(Co==0)
							{
								cout<<"\t\t\t============================"<<endl;
								cout<<"\t\t\tNO POST FOUND WITH THIS ID !! "<<endl;
								cout<<"\t\t\t============================"<<endl;
								cout<<endl;
								cout<<"\t\t\t";
								system("pause");
							}
						}
					}
					else
					{
						cout<<"\t\t\t============================"<<endl;
						cout<<"\t\t\tUSER NOT FOUND !! "<<endl;
						cout<<"\t\t\t============================"<<endl;
						cout<<endl;
						cout<<"\t\t\t";
						system("pause");
					}
				}
				if(Choice==3)
				{
					system("cls");
					cout<<"\t\t\t============================"<<endl;
					cout<<"\t\t\t  WELCOME IN LIKE SECTION   "<<"\t("<<FoundRoot->UD.UserName<<")"<<endl;
					cout<<"\t\t\t============================"<<endl;
					cout<<endl;
					string Name;
					int PostNo;
					cin.ignore();
					cout<<endl;
					cout<<"\t\t\tENTER THE NAME OF USER  : ";
					getline(cin , Name);
					cout<<"\t\t\tENTER THE POST NUMBER # : ";
					cin>>PostNo;
					cin.ignore();
					cout<<endl;
					SignUp *Found=Search_User_Return(Name);
					if(Found)
					{
						PostNode *PostTemp=Found->PNL->Head;
						if(PostTemp==NULL)
						{
							cout<<endl;
							cout<<"\t\t\t============================"<<endl;
							cout<<"\t\t\tNO POST ADDED BY USER !! "<<endl;
							cout<<"\t\t\t============================"<<endl;
							cout<<endl;
							cout<<"\t\t\t";
							system("pause");
							goto Menu;
						}
						else
						{
							int Co=0;
							while(PostTemp!=NULL)
							{
								if(PostTemp->PST->PostNo==PostNo)
								{
									Get:
									Co++;
									cout<<"\t\t\t";
									system("pause");
									system("cls");
									cout<<"\t\t\t============================"<<endl;
									cout<<"\t\t\t WELCOME IN COMMENT SECTION "<<endl;
									cout<<"\t\t\t============================"<<endl;
									cout<<endl;
									PostTemp->PST->DisplayPost();
									cout<<"\t\t\tPRESS 1 ) TO LIKE THE POST "<<endl;
									int Num=0;
									cout<<"\t\t\tENTER THE CHOICE : ";
									cin>>Num;
									if(Num==1)
									{
										bool Chk=PostTemp->PST->LNL->InsertLike(FoundRoot);
										if(Chk==1)
										{
											cout<<endl;
											cout<<"\t\t\t============================"<<endl;
											cout<<"\t\t\tLIKE REMOVED SUCCESSFULLY !! "<<endl;
											cout<<"\t\t\t============================"<<endl;
											cout<<endl;
											cout<<"\t\t\t";
											system("pause");
										}
										else
										{
											cout<<endl;
											cout<<"\t\t\t============================"<<endl;
											cout<<"\t\t\tLIKED THE POST SUCCESSFYLLY !! "<<endl;
											cout<<"\t\t\t============================"<<endl;
											cout<<endl;
											cout<<"\t\t\t";
											system("pause");
										}
									}
									else
									{
										cout<<endl;
										cout<<"\t\t\t============================"<<endl;
										cout<<"\t\t\t  UNABLE TO ADD THE LIKE !! "<<endl;
										cout<<"\t\t\t============================"<<endl;
										cout<<endl;
										cout<<"\t\t\t";
										system("pause");
									}
								}
								PostTemp=PostTemp->Next;
							}
							if(Co==0)
							{
								cout<<"\t\t\t============================"<<endl;
								cout<<"\t\t\tNO POST FOUND WITH THIS ID !! "<<endl;
								cout<<"\t\t\t============================"<<endl;
								cout<<endl;
								cout<<"\t\t\t";
								system("pause");
							}
						}
					}
					else
					{
						cout<<"\t\t\t============================"<<endl;
						cout<<"\t\t\tUSER NOT FOUND !! "<<endl;
						cout<<"\t\t\t============================"<<endl;
						cout<<endl;
						cout<<"\t\t\t";
						system("pause");
					}
				}
				else
				{
					cout<<endl;
					cout<<"\t\t\t";
					system("pause");
					goto Menu;
				}	
			}
			if(Select==2)
			{
				system("cls");
				cout<<"\t\t\t============================"<<endl;
				cout<<"\t\t\t    WELCOME IN POST UPDATE  "<<"\t("<<FoundRoot->UD.UserName<<")"<<endl;
				cout<<"\t\t\t============================"<<endl;
				cout<<endl;
				FoundRoot->PNL->UpdatePost();
			}
			if(Select==3)
			{
				system("cls");
				cout<<"\t\t\t============================"<<endl;
				cout<<"\t\t\t  WELCOME IN POST DELETION  "<<"\t("<<FoundRoot->UD.UserName<<")"<<endl;
				cout<<"\t\t\t============================"<<endl;
				cout<<endl;
				FoundRoot->PNL->DeletePost();
			}
			if(Select==4)
			{
				return;
			}
			else
			{
				goto Menu;
			}
		}
		void AddOwnData(PostNodeLinking *LL , PostNode *Temp)
		{		
			if(Temp==NULL)
			{
				return;
			}
			else
			{
				while(Temp!=NULL)
				{
					LL->AddPostByObject(Temp);
					Temp=Temp->Next;
				}
			}
		}
		void Messege_Tab()
		{
			Menu:
			system("cls");
			cout<<"\t\t\t============================"<<endl;
			cout<<"\t\t\t      MESSEGE TAB MENU      "<<"\t("<<FoundRoot->UD.UserName<<")"<<endl;
			cout<<"\t\t\t============================"<<endl;
			cout<<endl;
			cout<<"\t\t\tPRESS 1) TO VIEW CONSERVATION   "<<endl;
			cout<<"\t\t\tPRESS 2) TO SELECT USER TO CHAT "<<endl;
			cout<<"\t\t\tPRESS 3) TO GO BACK "<<endl;
			int Select;
			cout<<endl;
			cout<<"\t\t\tENTER YOUR CHOCIE : ";
			cin>>Select;
			if(Select==1)
			{
				system("cls");
				cout<<"\t\t\t============================"<<endl;
				cout<<"\t\t\t   WELCOME IN CONVERSATION  "<<"\t("<<FoundRoot->UD.UserName<<")"<<endl;
				cout<<"\t\t\t============================"<<endl;
				if(FoundRoot->Conversation->IsEmpty()==1)
				{
					cout<<endl;
					cout<<"\t\t\t============================"<<endl;
					cout<<"\t\t\t   YOUR CHAT BOX IS EMPTY   "<<endl;
					cout<<"\t\t\t============================"<<endl;
					cout<<endl;
					cout<<"\t\t\t";
					system("pause");
				}
				else
				{
					cout<<endl;
					FoundRoot->Conversation->ConversationDisplay();
					cout<<endl;
					cout<<"\t\t\t============================"<<endl;
					cout<<"\t\t\t";
					system("pause");
					goto Menu;
				}
			}
			if(Select==2)
			{
				system("cls");
				cout<<endl;
				cout<<"\t\t\t============================"<<endl;
				cout<<"\t\t\t       WELCOME TO CHAT      "<<"\t("<<FoundRoot->UD.UserName<<")"<<endl;
				cout<<"\t\t\t============================"<<endl;
				cout<<endl;
				cin.ignore();
				TriesInsert(SuRoot);
				cout<<"\t\t\tENTER USER NAME TO SEARCH : ";
				string Key;
				getline(cin , Key);
				if(Key=="")
				{
					cout<<endl;
					cout<<"\t\t\t============================"<<endl;
					cout<<"\t\t\t      NO INPUT DETECTED     "<<endl;
					cout<<"\t\t\t============================"<<endl;
					cout<<endl;
					cout<<"\t\t\t";
					system("pause");
					goto Menu;
				}
				cout<<endl;
				Node* Temp=TR.search(TR.Root,Key,0);
				Key.erase(Key.size()-1);
				if (Temp)
				{
					cout<<"\t\t\tAVAILABLE USERS ARE !! "<<endl;
					cout<<endl;
					TR.Display(Temp, Key);
				}
				else
				{
					cout<<"\t\t\t============================"<<endl;
					cout << "\t\t\tUSER NOT FOUND !! "<<endl;
					cout<<"\t\t\t============================"<<endl;
					cout<<endl;
					cout<<"\t\t\t";
					system("pause");
					goto Menu;
				}
				string Pick;
				cout<<endl;
				cout<<"\t\t\tENTER THE NAME TO START CHAT : ";
				getline(cin , Pick);
				cout<<endl;
				if(FoundRoot->UD.UserName==Pick)
				{
					cout<<"\t\t\t============================"<<endl;
					cout<<"\t\t\tCHAT TO YOURSELF IS PROHIBBETED !!"<<endl;
					cout<<"\t\t\t============================"<<endl;
					cout<<endl;
					cout<<"\t\t\t";
					system("pause");
					goto Menu;
				}
				SignUp *Find=Search_User_Return(Pick);
				if(Find)
				{
					Front:
					system("cls");
					cout<<"\t\t\t============================"<<endl;
					cout<<"\t\t\tSENDER: "<<FoundRoot->UD.UserName<<"    RECEIVER: "<<Pick<<endl;
					cout<<"\t\t\t============================"<<endl;
					cout<<endl;
					
					cout<<"\t\t\t============================"<<endl;
					cout<<"\t\t\tPRESS 1) TO WRITE MESSEGE "<<endl;
					cout<<"\t\t\tPRESS 2) TO GO BACK "<<endl;
					cout<<endl;
					cout<<"\t\t\tENTER YOUR CHOICE : ";
					int Ans;
					cin>>Ans;
					if(Ans==1)
					{
						system("cls");
						cout<<"\t\t\t============================"<<endl;
						cout<<"\t\t\tSENDER: "<<FoundRoot->UD.UserName<<"    RECEIVER: "<<Pick<<endl;
						cout<<"\t\t\t============================"<<endl;
						MessegeUserNode *MUN0=FoundRoot->MUL->Search(FoundRoot , Find);
						if(MUN0==NULL)
						{
							cout<<endl;
							cout<<"\t\t\t============================"<<endl;
							cout<<"\t\t\tYOU NEVER CHAT WITH THIS USER "<<endl;
							cout<<"\t\t\t============================"<<endl;
						}
						else
						{
							cout<<endl;
							MUN0->ML->DisplayMessege();
						}
						cout<<endl;	
						cout<<"\t\t\t============================"<<endl;
						cin.ignore();
						cout<<"\t\t\tWRITE YOUR MESSEGE : ";
						string Messege;
						getline(cin , Messege);
						
						if(FoundRoot->MUL->InsertUser(FoundRoot , Find)==1)
						{
							Find->MUL->InsertUser(Find , FoundRoot);
							MessegeUserNode *MUN1=FoundRoot->MUL->Search(FoundRoot , Find);
							MessegeUserNode *MUN2=Find->MUL->Search(Find , FoundRoot);
							
							MUN1->ML->AddMessege(Messege , "");
							MUN2->ML->AddMessege("" , Messege);
						}
						else
						{
							MessegeUserNode *MUN1=FoundRoot->MUL->Search(FoundRoot , Find);
							MessegeUserNode *MUN2=Find->MUL->Search(Find , FoundRoot);
							
							MUN1->ML->AddMessege(Messege , "");
							MUN2->ML->AddMessege("" , Messege);
						}
						if(FoundRoot->Conversation->Search(Find->UD.UserName)==0)
						{
							FoundRoot->Conversation->AddName(Find->UD.UserName);
						}
						system("cls");
						cout<<"\t\t\t============================"<<endl;
						cout<<"\t\t\tSENDER: "<<FoundRoot->UD.UserName<<"    RECEIVER: "<<Pick<<endl;
						cout<<"\t\t\t============================"<<endl;
						cout<<endl;
						MessegeUserNode *MUN3=FoundRoot->MUL->Search(FoundRoot , Find);
						MUN3->ML->DisplayMessege();
						cout<<endl;
						cout<<"\t\t\t============================"<<endl;
						cout<<endl;
						cout<<"\t\t\t";
						cout<<system("pause");
						goto Front;
					}
					else
					{
						goto Menu;
					}
				}
				else
				{
					cout<<"\t\t\t============================"<<endl;
					cout<<"\t\t\tUSER NOT FOUND !! "<<endl;
					cout<<"\t\t\t============================"<<endl;
					cout<<endl;
				}
				cout<<"\t\t\t";
				system("pause");
			}
			if(Select==3)
			{
				return;
			}
			else
			{
				goto Menu;
			}
		}
};
int main()
{
	SignUp_Linking SL;
	LogIn LI;
	Top:
	system("cls");
	cout<<"\t\t\t============================"<<endl;
	cout<<"\t\t\t       SOCIAL MEDIA APP     "<<endl;
	cout<<"\t\t\t============================"<<endl;
	cout<<endl;
	int Ask;
	cout<<"\t\t\tPRESS 1) FOR SIGN-UP (NEW-USER)"<<endl;
	cout<<"\t\t\tPRESS 2) FOR LOG-IN  (OLD USER)"<<endl;
	cout<<endl;
	cout<<"\t\t\tENTER YOUR CHOCIE : ";
	cin>>Ask;
	cin.ignore();
	if(Ask==1)
	{
		system("cls");
		cout<<"\t\t\t============================"<<endl;
		cout<<"\t\t\t           SIGN-UP          "<<endl;
		cout<<"\t\t\t============================"<<endl;
		cout<<endl;
		SL.Insertion();
		cout<<endl;
		cout<<"\t\t\t";
		system("pause");
		goto Top;
	}
	if(Ask==2)
	{
		system("cls");
		cout<<"\t\t\t============================"<<endl;
		cout<<"\t\t\t           LOG-IN           "<<endl;
		cout<<"\t\t\t============================"<<endl;
		cout<<endl;
		int Check=LI.Authenticate_User(SL.Root);
		if(Check!=0)
		{
			cout<<endl;
			cout<<"\t\t\t";
			system("pause");
		}
		if(Check==1)
		{
			LogInTop:
			system("cls");
			cout<<"\t\t\t============================"<<endl;
			cout<<"\t\t\t          LOG-IN MENU       "<<endl;
			cout<<"\t\t\t============================"<<endl;
			cout<<endl;
			cout<<"\t\t\tPRESS 1) FOR PERSONAL TAB "<<endl;
			cout<<"\t\t\tPRESS 2) FOR HOME TAB "<<endl;
			cout<<"\t\t\tPRESS 3) FOR FRIENDS TAB "<<endl;
			cout<<"\t\t\tPRESS 4) FOR MESSAGES TAB "<<endl;
			cout<<"\t\t\tPRESS 5) FOR LOG-OUT "<<endl;
			cout<<endl;
			cout<<"\t\t\tENTER YOUR CHOCIE : ";
			int Key;
			cin>>Key;
			if(Key==1)
			{
				LI.Personal_Tab();
				cout<<endl;
				cout<<"\t\t\t";
				system("pause");
				goto LogInTop;
			}
			if(Key==2)
			{
				LI.Home_Tab();
				cout<<endl;
				cout<<"\t\t\t";
				system("pause");
				goto LogInTop;
			}
			if(Key==3)
			{
				LI.Friends_Tab();
				cout<<endl;
				cout<<"\t\t\t";
				system("pause");
				goto LogInTop;
			}
			if(Key==4)
			{
				LI.Messege_Tab();
				cout<<endl;
				cout<<"\t\t\t";
				system("pause");
				goto LogInTop;
			}
			if(Key==5)
			{
				cout<<endl;
				cout<<"\t\t\t";
				system("pause");
				goto Top;
			}
			else
			{
				goto LogInTop;
			}
		}
		if(Check==0)
		{
			cout<<endl;
			cout<<"\t\t\t============================"<<endl;
			cout<<"\t\t\tACCOUNT DO NOT EXIST !! RETRY"<<endl;
			cout<<"\t\t\t============================"<<endl;
			cout<<endl;
			cout<<"\t\t\t";
			system("pause");
			goto Top;
		}
		if(Check==-1)
		{
			goto Top;
		}
	}
	else
	{
		goto Top;
	}
}