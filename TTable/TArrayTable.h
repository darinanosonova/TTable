#pragma once
#include"TTable.h"

class TArrayTable: TTable
{
protected:
	TRecord* pRec;
	int TabSize;
	int CurrPos;
public:
	TArrayTable(int size = 20)
	{
		TabSize = size;
		CurrPos = -1;
		pRec = new TRecord[TabSize];

	};
	virtual ~TArrayTable()
	{
		delete[] pRec;
	};
	virtual bool IsFull()
	{
		if (DataCount == TabSize) return true;
		else return false;
	}
	int GetDataCount()
	{
		return DataCount;
	};
	int GetTabSize()
	{
		return TabSize;
	}
	virtual TKey GetKey()
	{
		return pRec[CurrPos].key;
	};
	virtual TValue GetValue()
	{
		return pRec[CurrPos].val;
	};
	void Reset()
	{
		CurrPos = 0;
	}
	bool IsEnd()
	{
		if (CurrPos == TabSize) return true;
		else return false;
	};
	void GoNext()
	{
		if (CurrPos < TabSize) CurrPos++;
	};
	
};