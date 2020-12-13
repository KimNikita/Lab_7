#include "ArrayList.h"
#include <fstream>
#include <../gtest/gtest.h>

TEST(TArrayList, can_create_arraylist)
{
  ASSERT_NO_THROW(TArrayList<int>());
}

TEST(TArrayList, can_correctly_ins_first)
{
  const int size = 4;
  vector<int> expE;
  TArrayList<int> A(size);
  for (int i = 0; i < size; i++)
  {
    A.InsFirst(i + 1);
    expE.push_back(size - i);
  }
  vector<int>res = A.ElemsModKEqualsZero(1);
  EXPECT_EQ(expE, res);
}

TEST(TArrayList, can_correctly_ins_last)
{
  const int size = 4;
  vector<int> expE;
  TArrayList<int> A(size);
  for (int i = 0; i < size; i++)
  {
    A.InsLast(i + 1);
    expE.push_back(i + 1);
  }
  vector<int>res = A.ElemsModKEqualsZero(1);
  EXPECT_EQ(expE, res);
}

TEST(TArrayList, can_correctly_ins)
{
  const int size = 4;
  vector<int> expE;
  TArrayList<int> A(size * 2);
  for (int i = 0; i < size; i++)
  {
    A.InsLast(i + 1);
  }
  TArrayListIterator<int> iterator = A.begin();
  for (int i = 1; i < size / 2 + size % 2; i++)
  {
    ++iterator;
  }
  for (int i = 0; i < size; i++)
  {
    A.Ins(iterator, i + 1);
    ++iterator;
  }
  for (int i = 0; i < size / 2 + size % 2; i++)
  {
    expE.push_back(i + 1);
  }
  for (int i = 0; i < size; i++)
  {
    expE.push_back(i + 1);
  }
  for (int i = size / 2 + size % 2; i < size; i++)
  {
    expE.push_back(i + 1);
  }
  vector<int>res = A.ElemsModKEqualsZero(1);
  EXPECT_EQ(expE, res);
}

TEST(TArrayList, can_correctly_del_first)
{
  const int size = 4;
  vector<int> expE;
  TArrayList<int> A(size);
  A.InsLast(1);
  for (int i = 1; i < size; i++)
  {
    A.InsLast(i + 1);
    expE.push_back(i + 1);
  }
  A.DelFirst();
  vector<int>res = A.ElemsModKEqualsZero(1);
  EXPECT_EQ(expE, res);
}

TEST(TArrayList, can_correctly_del_last)
{
  const int size = 4;
  vector<int> expE;
  TArrayList<int> A(size);
  for (int i = 0; i < size - 1; i++)
  {
    A.InsLast(i + 1);
    expE.push_back(i + 1);
  }
  A.InsLast(size);
  A.DelLast();
  vector<int>res = A.ElemsModKEqualsZero(1);
  EXPECT_EQ(expE, res);
}

TEST(TArrayList, can_correctly_del)
{
  const int size = 8;
  vector<int> expE;
  TArrayList<int> A(size);
  for (int i = 0; i < size; i++)
  {
    A.InsLast(i + 1);
  }
  TArrayListIterator<int> iterator = A.begin();
  for (int i = 0; i < size / 4 + size % 2; i++)
  {
    ++iterator;
  }
  for (int i = 0; i < size / 2; i++)
  {
    TArrayListIterator<int> tmp = iterator;
    ++iterator;
    A.Del(tmp);
  }
  for (int i = 0; i < size / 4 + size % 2; i++)
  {
    expE.push_back(i + 1);
  }
  for (int i = size / 2 + size / 4 + size % 2; i < size; i++)
  {
    expE.push_back(i + 1);
  }
  vector<int>res = A.ElemsModKEqualsZero(1);
  EXPECT_EQ(expE, res);
}

//доп задания

TEST(TArrayList, can_use_iterator)
{
  const int size = 4;
  TArrayList<int> A(size);
  string expS = "";
  for (int i = 0; i < size; i++)
  {
    expS += (i + 1) + '0';
    A.InsLast(i + 1);
  }
  TArrayListIterator<int> iterator = A.begin();
  string res = "";
  for (; iterator != A.end(); ++iterator)
  {
    res += *iterator + '0';
  }
  EXPECT_EQ(expS, res);
}

TEST(TArrayList, can_find_elems_mod_k_equals_0)
{
  const int size = 4;
  int k = 2;
  vector<int> expE;
  TArrayList<int> A(size);
  for (int i = 0; i < size; i++)
  {
    A.InsLast(i + 1);
    if ((i + 1) % k == 0)
      expE.push_back(i + 1);
  }
  vector<int> res;
  res = A.ElemsModKEqualsZero(k);
  EXPECT_EQ(expE, res);
}

TEST(TArrayList, can_write_list_to_file)
{
  const int size = 4;
  TArrayList<int> A(size);
  for (int i = 0; i < size; i++)
    A.InsLast(i + 1);
  A.WriteToFile("output.txt");
  string expL = "1234";
  string ArrayList = "";
  ifstream fin("output.txt");
  fin >> ArrayList;
  fin.close();
  EXPECT_EQ(expL, ArrayList);
}


