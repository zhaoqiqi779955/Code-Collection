template <class T>
class SqQueue
{
	T *base;
	int front;
	int rear;
	int size;
public:
	SqQueue(int size=0)
	{
		this->size=size;
		base=new  T[size];
		front=rear=0;
		if (!base)
		{
			exit(0);
		}
		
	}
	int queueLength()
	{
		return ((rear-front+size)%size);
	}
	bool insert(T e)
	{
		if((rear+1)%size==front)
		{
			return false;
		}
		base[rear]=e;
		rear=(rear+1)%size;
		return true;
	}
	T delQueue()
	{
		if(front==rear) return 0;
		int k=front;
		front=(front+1)%size;
		return base[k];
	}

};