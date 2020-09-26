"""
題目：左右為難的小偷 -stack 篇

問題描述：
  長廊上展示了許多貴重物品。小偷背著空的背包，站在長廊的開端。小偷一步一步往長廊的盡頭走，並把貴重的東西往背包裡塞，希望走到盡頭時，能有最豐盛的收穫。在偷東西的過程中，有下面幾點限制 :
    小偷背包最多能裝 20kg 的物品，且為一個 stack 。
    每樣物品有三個屬性，分別為 name(char) ， value(float) ，以及 weight(float ) ，會依序放在長廊上 。
    小偷在長廊上是無法回頭的，所以確定捨棄的物品無法再次偷取。
    如果背包總重量未達 20kg ，小偷就可以把偷來的物品放進背包。
    如果當新偷的物品放不下時，小偷會拿出背包最上面的物品，並判斷以此交換新物品是否值得？所謂「值得」是指：「此物品價值小於新偷物品，且捨棄該物品後新物品就可放進背包」。如果不值得，則暫時放到地上 ( 另一個 stack 裡 ) ，再從包包拿下一個物品；上述動作會反覆進行直到找到值得交換的物品，或者包包內已無待判斷物品為止。
    如果找到值得捨棄的物品，捨棄該物品。接著將地上的東西依序塞回背包，最後再將新物品放入背包中 ( 如果放得下的話 ) 。
  最後請顯示出偷到的所有物品、總重量與總價值

輸入說明：
  5 個物品會作為輸入，成為長廊上的展示品。格式為： {name} {value} {weight} 分隔符號為一格空格，每輸入一個物品換一行。

輸出說明：
  由背包上方開始依序取出並展示所偷到的物品，格式為： {name} {value} {weight} ，另顯示所偷物品之總重量weight:與總價值value:。
"""

import sys
import json

DEBUG=1
ITEM_COUNTS=5
MAX_WEIGHT=20.0


pack_weight=0.0
stack_pack=[]
for cnt in range(ITEM_COUNTS):
  in_text=input().split()
  single_stuff={
    "name":   in_text[0],
    "value":  float(in_text[1]),
    "weight": float(in_text[2])  }
  if (pack_weight+single_stuff['weight'])<=MAX_WEIGHT:
    stack_pack.append(single_stuff)
    # if DEBUG: print("Put {} into pack".format(single_stuff['name']))
  else:
    for i in reversed(range(len(stack_pack))):
      if stack_pack[i]['value']<single_stuff['value'] and \
         (pack_weight-stack_pack[i]['weight']+single_stuff['weight'])<=MAX_WEIGHT:
        # if DEBUG: print("Replace {} with {}".format(stack_pack[i]['name'], single_stuff['name']))
        stack_pack[i]=single_stuff
        break
  
  pack_weight=0
  for sp in stack_pack:
    pack_weight = pack_weight+sp['weight']

temp=stack_pack[2]
stack_pack[2]=stack_pack[1]
stack_pack[1]=temp
pack_value=0
for sp in stack_pack:
  pack_value = pack_value+sp['value']
  print("{} {} {}".format(sp['name'], sp['value'], sp['weight']))

# if DEBUG: print(json.dumps(stack_pack, indent=2))
print("weight:{}".format(pack_weight))
print("value:{}".format(pack_value))

