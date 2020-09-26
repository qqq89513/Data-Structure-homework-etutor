"""
  This program read a string from stdin and parse it as an int array,
  then output the product.
  example input:1 2 32 7
  ouput:448
"""

while True:
  arr=input().split(' ')
  product=1
  for i in range(len(arr)):
    arr[i]=int(arr[i])
    product=product*arr[i]
  print(product)