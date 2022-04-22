#pragma once
#include<iostream>
#include "TArrayTable.h"

using namespace std;

class TScanTable : public TArrayTable
{
public: TScanTable(int s = 100) :TArrayTable(s) {};
	  bool Find(TKey key)
	  {
		  for (int i = 0; i < DataCount; i++)
		  {
			  Eff++;
			  if (pRec[i].key == key)
			  {
				  CurrPos = i;
				  return true;
			  }
		  }
		  CurrPos = DataCount;
		  return false;
	  }

	  bool Insert(TRecord rec)
	  {
		  if (IsFull()) throw "Tab is Full";
		  if (Find(rec.key))
			  return false;
		  else
		  {
			  pRec[DataCount] = rec;
			  DataCount++;
			  Eff++;
			  return true;
		  }

	  }

	  bool Delete(TKey key)
	  {
		  if (IsEmpty()) throw "Tab Is Empty";
		  if (!Find(key)) return false;

		  pRec[CurrPos] = pRec[DataCount - 1];
		  DataCount--;
		  Eff++;
		  return true;
		  
	  }

};