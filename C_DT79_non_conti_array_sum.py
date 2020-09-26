"""
問題描述 ：
  輸入一個整數List L，求L的一個非連續子序列，其兩數和最大，非連續子序列定義：子序列中任意相鄰的兩個數，在原序列中都不相鄰。

輸入說明 ：
  第一個數字為輸入數列元素個數，接著輸入數列元素。

輸出說明 ：
  輸出非連續子序列之最大和

輸入:
  4
  2
  -3
  3
  59

輸出:
  61
"""

import sys

item_count=int(input())
arr=[]
max_sum=-99999999999999999 # representing negative infinity
for i in range(item_count):
  num=int(input())
  arr.append(num)

for i in range(item_count):
  if i+2<item_count:
    for j in range(i+2, item_count): # range(start, stop)
      max_sum=max(arr[i]+arr[j], max_sum)

print("{}".format(max_sum))

