/*
	A process p(i) broadcasts a locally time stamped REQUEST message (tsi, i) to all the processes.
	Recieving process p(j) inserts the REQUEST message(tsi, i) int its proper position in queue_j.
	Then sends a REPLY to process p(i).
	REPLY messages are RECIEVED from all the processes.
	If the REQUEST of p(i) is in the front of queue_i, then p(i) enters the CRITICAL SECTION.
	After finishing the execution of CS, 
		a process p(i) removes the request from its own queue.
		BROADCASTS a RELEASE message to all processes so that they can remove the REQUEST of p(i) from their QUEUE.
*/		

#include<iostream>
using namespace std;
void insert(int);
void show();
class p1{
	public:
			struct queue1{
		int ts;
		int p;
		queue1 *next;
	}*front=NULL,*rear;
		p1()
		{
			insert(3,1);
			show();
		}
		void insert(int n, int ps)
	{
	struct queue1 *temp;
	temp=new queue1;
	if(temp==NULL)
	{
		cout<<"Overflow Condition"<<endl;
		return;
	}
	temp->ts=n;
	temp->p=ps;
	temp->next=NULL;
	if(front==NULL)
	{
		front=temp;
		rear=temp;
	}
	else
	{
		rear->next=temp;
		rear=temp;
	}
	//cout<<n<<" is inserted"<<endl;
	}
	void show()
		{
			if(front==NULL)
			{
				cout<<"Underflow"<<endl;
				return;
			}
			struct queue1 *temp;
			temp=front;
			cout<<"Queue1";
			while(temp!=NULL)
			{
				cout<<"("<<temp->ts<<", "<<temp->p<<")";
				temp=temp->next;
			}
			cout<<endl;
		}
	int message_sent()
	{
		if(front==NULL)
			{
				cout<<"Underflow"<<endl;
				return 0;
			}
		struct queue1 *temp;
		temp=front;
		return temp->ts;
	}
};
class p2{
	public:
		struct queue2{
	int ts;
	int p;
	queue2 *next;
}*front=NULL,*rear;
		p2()
		{
			insert(1,2);
			show();
		}
		void insert(int n, int ps)
		{
			struct queue2 *temp;
			temp=new queue2;
			if(temp==NULL)
			{
				cout<<"Overflow Condition"<<endl;
				return;
			}
			temp->ts=n;
			temp->p=ps;
			temp->next=NULL;
			if(front==NULL)
			{
				front=temp;
				rear=temp;
			}
			else
			{
				rear->next=temp;
				rear=temp;
			}
			//cout<<n<<" is inserted"<<endl;
		}
		void show()
		{
			if(front==NULL)
			{
				cout<<"Underflow"<<endl;
				return;
			}
			struct queue2 *temp;
			temp=front;
			cout<<"Queue2";
			while(temp!=NULL)
			{
				cout<<"("<<temp->ts<<", "<<temp->p<<")";
				temp=temp->next;
			}
			cout<<endl;
		}
	int message_sent()
	{
		if(front==NULL)
			{
				cout<<"Underflow"<<endl;
				return 0;
			}
		struct queue2 *temp;
		temp=front;
		return temp->ts;
	}
};
class p3{
	public:
		struct queue3{
			int ts;
			int p;
			queue3 *next;
		}*front=NULL,*rear;
		p3()
		{
			insert(2,3);
			show();
		}
		void insert(int n, int ps)
	{
	struct queue3 *temp;
	temp=new queue3;
	if(temp==NULL)
	{
		cout<<"Overflow Condition"<<endl;
		return;
	}
	temp->ts=n;
	temp->p=ps;
	temp->next=NULL;
	if(front==NULL)
	{
		front=temp;
		rear=temp;
	}
	else
	{
		rear->next=temp;
		rear=temp;
	}
	//cout<<n<<" is inserted"<<endl;
	}
	void show()
		{
			if(front==NULL)
			{
				cout<<"Underflow"<<endl;
				return;
			}
			struct queue3 *temp;
			temp=front;
			cout<<"Queue3";
			while(temp!=NULL)
			{
				cout<<"("<<temp->ts<<", "<<temp->p<<")";
				temp=temp->next;
			}
			cout<<endl;
		}
	int message_sent()
	{
		if(front==NULL)
			{
				cout<<"Underflow"<<endl;
				return 0;
			}
		struct queue3 *temp;
		temp=front;
		return temp->ts;
	}
};
int main()
{
	p1 a;
	p2 b;
	p3 c;
	//ist step sending requests
	int y;
	cout<<"Enter the process to start (1,2,3) : ";
	cin>>y;
	if(y==1)//first processor
	{
		int msg = a.message_sent();
		b.insert(msg,y);
		cout<<"Queue2 is updated : ";
		b.show();
		c.insert(msg,y);
		cout<<"Queue3 is updated : ";
		c.show();
	}
	else if(y==2)//second processor
	{
		int msg = b.message_sent();
		a.insert(msg,y);
		cout<<"Queue1 is updated : ";
		a.show();
		c.insert(msg,y);
		cout<<"Queue3 is updated : ";
		c.show();
	}
	else if(y==3)//third processor
	{
		int msg = c.message_sent();
		a.insert(msg,y);
		cout<<"Queue1 is updated : ";
		a.show();
		b.insert(msg,y);
		cout<<"Queue2 is updated : ";
		b.show();
	}
	else
		cout<<"Invalid processor"<<endl;
	return 0;
}
