#include <memory>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Foobar
{
public:
    Foobar()
    {
        cout<<__FUNCTION__<<endl;
    }
    ~Foobar()
    {
        cout<<__FUNCTION__<<endl;
    }
};

//event system simulation
class EventDispatcher;
class EventConnection
{
public:
	EventConnection(int id, EventDispatcher *dispatcher)
		: _id(id)
		, _dispatcher(dispatcher){}

	int ID() const
	{
		return _id;
	}

	void disconnect();
private:
	int _id;
	EventDispatcher *_dispatcher;
};

class EventConnectionHolder
{
public:
	EventConnectionHolder()
	{}
	EventConnectionHolder(shared_ptr<EventConnection> connection)
		: _connectionWeakRef(connection)
	{}
	EventConnectionHolder(EventConnectionHolder &&rhs)
	{
		_connectionWeakRef.swap(rhs._connectionWeakRef);
	}
	EventConnectionHolder &operator = (EventConnectionHolder &&rhs)
	{
		_connectionWeakRef.reset();
		_connectionWeakRef.swap(rhs._connectionWeakRef);
		return *this;
	}
	~EventConnectionHolder()
	{
	}
	void disconnect()
	{
		if(!_connectionWeakRef.expired())
		{
			shared_ptr<EventConnection> connection = _connectionWeakRef.lock();
			if(connection)
				connection->disconnect();
		}
		else
			cout<<"EventConnection expired!"<<endl;
	}
private:
	EventConnectionHolder(const EventConnectionHolder &rhs);
	void operator = (const EventConnectionHolder &rhs);
private:
	weak_ptr<EventConnection> _connectionWeakRef;
};

class EventSlot
{
public:
	EventSlot(EventConnectionHolder &&holder)
		: _holder(std::move(holder)){}
	~EventSlot()
	{
		_holder.disconnect();
	}
private:
	EventConnectionHolder _holder;
};

class EventDispatcher
{
public:
	EventDispatcher()
		: _id(0){}
	~EventDispatcher()
	{
		cout<<__FUNCTION__<<endl;
	}

	EventConnectionHolder subscribeEvent()
	{
		shared_ptr<EventConnection> connection(new EventConnection(_id++,this));
		_connections.insert(make_pair(connection->ID(), connection));
		return connection;
	}

	void unsubscribeEvent(const EventConnection &connection)
	{
		auto itr = _connections.find(connection.ID());
		if(itr != _connections.end())
		{
			cout<<"Connection:"<<connection.ID()<<" unsubscribed!"<<endl;
			_connections.erase(itr);
		}
	}
private:
	int _id;
	map<int, shared_ptr<EventConnection>> _connections;
};

void EventConnection::disconnect()
{
	cout<<"Connection:"<<_id<<" disconnecting!"<<endl;
	_dispatcher->unsubscribeEvent(*this);
}

int main()
{
    /*shared_ptr<Foobar> ptrShared(new Foobar);
	weak_ptr<Foobar> ptrWeak(ptrShared);
	cout<<"weak_ptr valid:"<<(!ptrWeak.expired() ? "true" : "false")<<endl;
	shared_ptr<Foobar> ptrShared1 = ptrWeak.lock();
	ptrShared = nullptr;
	cout<<"weak_ptr valid:"<<(!ptrWeak.expired() ? "true" : "false")<<endl;*/
	EventDispatcher *dispatcher = new EventDispatcher;
	//vector<EventConnectionHolder> eventConnHolderPool;
	//eventConnHolderPool.push_back(dispatcher->subscribeEvent());
	EventConnectionHolder connectionHolder;
	connectionHolder = dispatcher->subscribeEvent();
	EventSlot slot(std::move(connectionHolder));
	//dispatcher->subscribeEvent();
	//EventSlot slot = dispatcher->subscribeEvent();
	//EventConnectionHolder connectionHolder(dispatcher->subscribeEvent());
	/*for(auto &holder : eventConnHolderPool)
	{
		holder.disconnect();
	}*/
	//connectionHolder.disconnect();
	delete dispatcher;
	return 0;
}
