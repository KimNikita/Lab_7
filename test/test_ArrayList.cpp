#include "ArrayList.h"
#include <fstream>
#include <../gtest/gtest.h>

TEST(TArrayList, can_create_list)
{
  ASSERT_NO_THROW(TArrayList<int>());
}
//
//TEST(TArrayList, can_correctly_ins_first)
//{
//  const int size = 4;
//  vector<int> expE;
//  TArrayList<int> L;
//  for (int i = 0; i < size; i++)
//  {
//    L.InsFirst(i + 1);
//    expE.push_back(size - i);
//  }
//  vector<int>res = L.ElemsModKEqualsZero(1);
//  EXPECT_EQ(expE, res);
//}
//
//TEST(TArrayList, can_correctly_ins_last)
//{
//  const int size = 4;
//  vector<int> expE;
//  TArrayList<int> L;
//  for (int i = 0; i < size; i++)
//  {
//    L.InsLast(i + 1);
//    expE.push_back(i + 1);
//  }
//  vector<int>res = L.ElemsModKEqualsZero(1);
//  EXPECT_EQ(expE, res);
//}
//
//TEST(TArrayList, can_correctly_ins)
//{
//  const int size = 4;
//  vector<int> expE;
//  TArrayList<int> L;
//  for (int i = 0; i < size; i++)
//  {
//    L.InsLast(i + 1);
//  }
//  ListIterator<int> iterator(L.GetFirst());
//  for (int i = 1; i < size / 2 + size % 2; i++)
//  {
//    ++iterator;
//  }
//  for (int i = 0; i < size; i++)
//  {
//    L.Ins(iterator.elem(), i + 1);
//    ++iterator;
//  }
//  for (int i = 0; i < size / 2 + size % 2; i++)
//  {
//    expE.push_back(i + 1);
//  }
//  for (int i = 0; i < size; i++)
//  {
//    expE.push_back(i + 1);
//  }
//  for (int i = size / 2 + size % 2; i < size; i++)
//  {
//    expE.push_back(i + 1);
//  }
//  vector<int>res = L.ElemsModKEqualsZero(1);
//  EXPECT_EQ(expE, res);
//}
//
//TEST(TArrayList, can_correctly_del_first)
//{
//  const int size = 4;
//  vector<int> expE;
//  TArrayList<int> L;
//  L.InsLast(1);
//  for (int i = 1; i < size; i++)
//  {
//    L.InsLast(i + 1);
//    expE.push_back(i + 1);
//  }
//  L.DelFirst();
//  vector<int>res = L.ElemsModKEqualsZero(1);
//  EXPECT_EQ(expE, res);
//}
//
//TEST(TArrayList, can_correctly_del_last)
//{
//  const int size = 4;
//  vector<int> expE;
//  TArrayList<int> L;
//  for (int i = 0; i < size - 1; i++)
//  {
//    L.InsLast(i + 1);
//    expE.push_back(i + 1);
//  }
//  L.InsLast(size);
//  L.DelLast();
//  vector<int>res = L.ElemsModKEqualsZero(1);
//  EXPECT_EQ(expE, res);
//}
//
//TEST(TArrayList, can_correctly_del)
//{
//  const int size = 8;
//  vector<int> expE;
//  TArrayList<int> L;
//  for (int i = 0; i < size; i++)
//  {
//    L.InsLast(i + 1);
//  }
//  ListIterator<int> iterator(L.GetFirst());
//  for (int i = 0; i < size / 4 + size % 2; i++)
//  {
//    ++iterator;
//  }
//  for (int i = 0; i < size / 2; i++)
//  {
//    TListElem<int>* tmp = iterator.elem();
//    ++iterator;
//    L.Del(tmp);
//  }
//  for (int i = 0; i < size / 4 + size % 2; i++)
//  {
//    expE.push_back(i + 1);
//  }
//  for (int i = size / 2 + size / 4 + size % 2; i < size; i++)
//  {
//    expE.push_back(i + 1);
//  }
//  vector<int>res = L.ElemsModKEqualsZero(1);
//  EXPECT_EQ(expE, res);
//}
//
////��� �������
//
//TEST(TArrayList, can_use_iterator)
//{
//  const int size = 4;
//  TArrayList<int> L;
//  string expS = "";
//  for (int i = 0; i < size; i++)
//  {
//    expS += (i + 1) + '0';
//    L.InsLast(i + 1);
//  }
//  ListIterator<int> iterator(L.GetFirst());
//  string res = "";
//  for (; !iterator.empty(); ++iterator)
//  {
//    res += *iterator + '0';
//  }
//  EXPECT_EQ(expS, res);
//}
//
//TEST(TArrayList, can_find_elems_mod_k_equals_0)
//{
//  const int size = 4;
//  int k = 2;
//  vector<int> expE;
//  TArrayList<int> L;
//  for (int i = 0; i < size; i++)
//  {
//    L.InsLast(i + 1);
//    if ((i + 1) % k == 0)
//      expE.push_back(i + 1);
//  }
//  vector<int> res;
//  res = L.ElemsModKEqualsZero(k);
//  EXPECT_EQ(expE, res);
//}
//
//TEST(TArrayList, can_write_list_to_file)
//{
//  const int size = 4;
//  TArrayList<int> L;
//  for (int i = 0; i < size; i++)
//    L.InsLast(i + 1);
//  L.WriteToFile("output.txt");
//  string expL = "1234";
//  string List = "";
//  ifstream fin("output.txt");
//  fin >> List;
//  fin.close();
//  EXPECT_EQ(expL, List);
//}


