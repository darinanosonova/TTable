#pragma once
#include <string>
#include <iostream>

using namespace std;

typedef int TKey;
typedef std::string TValue;

struct TRecord
{
	TKey key;
	TValue val;

	bool operator == (TKey k)
	{
		if (k == key) return true;
		else return false;
	}

	bool operator != (TKey k)
	{
		if (k != key) return true;
		else return false;
	}

	bool operator > (TKey k)
	{
		if (k > key) return true;
		else return false;
	}

	bool operator < (TKey k)
	{
		if (k < key) return true;
		else return false;
	}
};

class TTable
{
protected:
	int DataCount;
	int Eff;
public:
	TTable()
	{
		DataCount = 0;
		Eff = 0;
	};
	~TTable() {};
	int GetDataCount()
	{
		return DataCount;
	}
	int GetEff()
	{
		return Eff;
	}
	int ClearEff()
	{
		return Eff = 0;
	}
	bool IsEmpty()
	{
		if (DataCount == 0) return true;
		else false;
	}
	virtual bool IsFull() = 0;
	virtual bool Find(TKey k) = 0;
	virtual bool Insert(TRecord rec) = 0;
	virtual bool Delete(TKey k) = 0;
	virtual void Reset() = 0;
	virtual void GoNext() = 0;
	virtual bool IsEnd() const = 0;
	virtual TKey GetKey() const = 0;
	virtual TValue GetValue() const = 0;

	friend ostream& operator << (ostream& os, TTable &t)
	{
		for (t.Reset(); !t.IsEnd(); t.GoNext())
		{
			os << t.GetKey();
			return os;
		}
	};

};
