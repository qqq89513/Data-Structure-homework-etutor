# Exercise Discriptions
The following discriptions are mostly in chinese because I copy them directly from the E-Tutor platform and I'm lazy to translate them.

### C_AR01 一維陣列反轉 I
- 題目描述: 一維陣列反轉
- 輸入: 輸入一個一維陣列，以空格隔開各元素
- 輸出: 輸出反轉後的陣列
- 範例
  輸入 | 輸出
  ------------- | -------------
  4 6 3 69 234  | 234 69 3 6 4
  56 89 23 3 1  | 1 3 23 89 56




### C_AR04 邊緣偵測
- 題目描述  
  一個二元圖形通常用一個二維陣列表示，其中的值為0或1，即為淺色（以1表）圖形在深色（以0表）的背景中。在分析圖形時往往需要找出其邊緣，稱之為邊緣偵測。所謂”邊緣”即為一個1的pixel其上下左右至少有一個為0。寫一個程式讀入二元圖形，輸出該圖之邊緣。
- 輸入  
  第一行為一個正整數N，代表共有幾組測試資料。之後接下來有N組數據，每組第一行為兩個正整數n及m，表示二元圖形的大小，之後n行每行有m個數字（1 ≤ n,m ≤ 80 ，每個數字中間有一個空格），分別是0或1，即為該組測試資料之二元圖形。
- 輸出  
  將不是邊緣的點以底線‘_’表示，邊緣的點則以0表示，每個測試資料結果之間空一行。
- 範例
  輸入 | 輸出
  ------------- | -------------
  2<br>5 7<br>0 0 0 0 0 0 0<br>0 0 1 1 1 0 0<br>0 1 1 1 1 1 0<br>0 0 1 1 1 0 0<br>0 0 0 0 0 0 0<br>8 11<br>0 0 0 0 0 0 0 0 0 0 0<br>0 0 1 1 0 0 0 1 1 0 0<br>0 1 1 1 1 0 1 1 1 1 0<br>0 0 1 1 1 1 1 1 1 0 0<br>0 0 0 1 1 1 1 1 0 0 0<br>0 0 0 0 1 1 1 0 0 0 0<br>0 0 0 0 0 1 0 0 0 0 0<br>0 0 0 0 0 0 0 0 0 0 0| _ _ _ _ _ _ _<br>_ _ 0 0 0 _ _<br>_ 0 _ _ _ 0 _<br>_ _ 0 0 0 _ _<br>_ _ _ _ _ _ _<br><br>_ _ _ _ _ _ _ _ _ _ _<br>_ _ 0 0 _ _ _ 0 0 _ _<br>_ 0 _ _ 0 _ 0 _ _ 0 _<br>_ _ 0 _ _ 0 _ _ 0 _ _<br>_ _ _ 0 _ _ _ 0 _ _ _<br>_ _ _ _ 0 _ 0 _ _ _ _<br>_ _ _ _ _ 0 _ _ _ _ _<br>_ _ _ _ _ _ _ _ _ _ _
    | 






### C_AR07 有違反數獨的規則嗎
- 問題描述  
    輸入一個9*9的數字矩陣，其中每個元素均為0～9，其中0代表該格尚未填入數字。請撰寫一支程式判斷該矩陣是否符合數獨之規則。數獨的規則如下：
    1. 矩陣中的每一列（9個元素）只能出現1~9至多各一次。
    2. 矩陣中的每一行（9個元素）只能出現1~9至多各一次。
    3. 9個3*3的小矩陣（9個元素），亦分別只能出現1~9至多各一次。
- 輸入  
  9*9的數字矩陣，其中每個元素均為0～9, 0代表該格尚未填入數字.
- 輸出說明  
    若該輸入符合數獨規則，則輸出 true
    否則需輸出違反規則的列或行或區塊之編號，分別有三種：
    1. 若為列違反規則，則輸出該列中違反規則之最小數字，格式為： row[?], #?，其中第1個’?’代表列編號；第2個’?’代表第一個違反的數字
    2. 若為行違反規則，則輸出該行中違反規則之最小數字，格式為： column[?], #?，其中第1個’?’代表行編號；第2個’?’代表第一個違反的數字
    3. 若為區塊違反規則，則輸出該區塊中違反規則之最小數字，格式為： block[?], #?，其中第1個’?’代表區塊編號；第2個’?’代表第一個違反的數字
    注意，所有的行、列、區塊編號均為1～9；區塊的編號採row-major。以下是blcok的編號:  
      1 2 3  
      4 5 6  
      7 8 9  
    PS:因為原本題目有些地方會有爭議,所以在這裡補充，原本的題目在"中文題庫")  
    若輸出不是true時, 則依序輸出各個row, column, block有錯誤的數字(即是在範圍內有重複)  
    即使此數字在row和column都會重複出現, 也要分別印出來(例如下面範例2的row2 #9, column1 #9)  
- 範例
  輸入1 | 輸出1
  ---------- | -----------
  023456789   |true
  456789123   |
  789123456   |
  231564897   |
  564897231   |
  897231564   |
  312605978   |
  645978312   |
  908312645   |

  輸入2 | 輸出2
  ---------- | -----------
  023450789   |row2 #5
  956789523   |row2 #9
  659723456   |row3 #5
  231564807   |row3 #6
  504897231   |column1 #6
  897231564   |column1 #9
  302605978   |column2 #5
  605978412   |column4 #7
  908312605   |column7 #4
  &nbsp;      |column7 #5
  &nbsp;      |block1 #5
  &nbsp;      |block1 #6
  &nbsp;      |block1 #9
  &nbsp;      |block2 #7
  &nbsp;      |block3 #5

  輸入3 | 輸出3
  ---------- | -----------
  020456789   |row2 #9
  496789123   |block1 #9
  789123456   |
  231564897   |
  564897231   |
  807231564   |
  312605978   |
  645978312   |
  908312645   |
  
  輸入4 | 輸出4
  ---------- | -----------
  023452789   |row1 #2
  156789123   |row2 #1
  119123456   |row3 #1
  231564827   |row4 #2
  534897231   |row5 #3
  897231564   |row8 #4
  302605978   |colume1 #1
  645978412   |colume2 #3
  908312645   |colume6 #2
  &nbsp;      |colume7 #4
  &nbsp;      |colume8 #2
  &nbsp;      |block1 #1
  &nbsp;      |block2 #2
  &nbsp;      |block4 #3
  &nbsp;      |block6 #2
  &nbsp;      |block9 #4

### C_AR20 檢查數值是否有重複
- 問題描述  
Given a numerical array input, verified if any items are repetitive.  
  input 1: First line is a number between 1~128, representing the item counts of the second line  
  input 2: Second line is a numerical array input, spilted with space. Values of items are between 1 to the number input in the first line.
  ouput:0 if any items are repetitive, 1 otherwise.
- 範例
  輸入 | 輸出
  ------------- | -------------
  8<br>1 4 6 2 3 5 8 7 | 1

### C_AR77 二維陣列反轉
- 問題描述：
    二維陣列反轉，陣列內容如下：
  提示：
    1. 請先輸入陣列大小
    2. 第一個輸入的數為列，第二個輸入的數為行
    3. 如 3X3 得陣列，反轉後如下 :
        1 2 3          9 8 7
        4 5 6  反轉後  6 5 4
        7 8 9          3 2 1
- 輸入：  
    3  
    3
- 輸出：  
    9 8 7  
    6 5 4  
    3 2 1  

### AR128 巴斯卡三角形
- 問題描述  
  巴斯卡三角形（ Pascal's Triangle ）的頂端是 1 ，視為 row 0 。  
  第 1 列 (row 1) 為兩個 1 ，這兩個 1 是由他們上頭左右兩數之和（不在三角形內的數視為 0 ）。  
  依此類推產生第 2 列 (row 2): 0+1= 1 ; 1+1= 2 ; 1+0= 1 。第 3 列 (row 3): 0+1= 1 ; 1+2= 3 ; 2+1= 3 ; 1+0= 1 。  
  循此法可以產生一巴斯卡三角形。  
  每列由左而右各數，分別命名為第 0 元素，第 1 元素， … ，如此第 n 列第 r 元素是 (n!)/( r!*(n-r)! )。  
  請寫一個程式將巴斯卡三角形中之指定列的指定元素印出來。每筆測試資料結果輸出於一行 ， 最後必須有換行字元 。
- 輸入說明  
  輸入檔中第一行為一個正整 數 N ( 0 N N 組測試資料。  
  之後接下來有 N 行，每行有兩個整數，第一個整數 n，代表巴斯卡三角形中之第 n 列 ( 0 ≤ n ≤ 65 ) 第二個整數 m 代表該列由左而右第 m 個元素 ( 從 0 起算 ) 。
- 範例  
  輸入 | 輸出
  ---- | ----
  3<br>0 0<br>3 1<br>10 4 | 1<br>3<br>210


### C_AR146 最大值與最小值
- 問題描述 ：
    寫一個程式來找出輸入的十個數字的最大值和最小值，數值不限定為整數，且值可存放於 float 型態數值內。
- 輸入說明 ：
    輸入十個數字，以空白間隔。
- 輸出說明 ：
    輸出數列中的最大值與最小值，輸出時需附上小數點後兩位數字。
- 範例
  輸入 | 輸出
  ------------- | -------------
   -2 -15.2 0 89.5 100 25.3 7 30 76 4| maximum:100.00<br>minimum:-15.20


### C_BT03 正方形
- 問題描述: 輸入線段的個數，以及每個線段的長度，判斷這些線段是否能夠組成一個三角形。
- 輸入說明: 輸入的第一個數為線段個數，接下來依序為每個線段的長度。火柴長度皆大於零。
- 輸出說明: 要是可以組成三角形，則輸出 true ，否則輸出 false 。
- 範例
  輸入 | 輸出
  ------------- | -------------
  4 1 1 1 1              |yes
  5 10 20 30 40 50       |no
  8 9 6 10 23 7 8 4 1    |no
  8 1 7 2 6 4 4 3 5      |yes
  4 1 2 3 4              |no

### C_CH30 是否為三角形
- 問題描述
  輸入線段的個數，以及每個線段的長度，判斷這些線段是否能夠組成一個三角形。
- 輸入說明
  輸入的第一個數為線段個數，接下來依序為每個線段的長度。火柴長度皆大於零。
- 輸出說明
  要是可以組成三角形，則輸出 true ，否則輸出 false 。
- 範例
  輸入 | 輸出
  ------------- | -------------
  6 5 3 6 2 7 9          |true
  8 5 3 6 2 7 9 10 18    |true
  6 18 1 2 100 5 9       |false
  4 2 31 5 9             |false
  2 10 5                 |false




### C_DP01 參加活動
- 問題描述  
  某甲預定於星期日 7:00~17:00 參加一些活動。為了不浪費時間，某甲希望當天參加的活動總收穫最多。  
  假設每一活動有起迄時間及一正整數表示預期收穫量，每項活動全程參加之後，可得該項活動之預期收穫量。  
  請寫一程式幫某甲選擇當天應參加的活動，以達成最高收穫量。  
  請注意某甲在任何時間只能參加一活動，且一活動全程參加完畢後，才能再參加下一個活動。  
- 輸入說明  
  第一列有一個正整數，代表活動之個數 n ，請注意 n ≤ 10 。  
  其後有 n 列，每一列代表一項活動，每一列之資料依序為活動名稱、活動起始參加時間、結束時間、及預期收穫量。各項資料之間，以一個空白分隔。
  活動名稱為英文字母(不超過 10 個字母)；時間為 24 小時制，以 4 個阿拉伯數字表示，且各時間均為整點時間(只有七時、八時、九時、十時 … )，
  例如 0800 表示上午八時， 1400 表示下午二時；預期收穫量為一個正整數。
- 輸出說明  
  印出一列，依序列出可參加活動的活動名稱及其總收穫量。各項資料之間以一個空白分隔。
- 範例
  輸入 | 輸出
  ------------- | -------------
  6<br>A1 0700 0800 1<br>A2 0800 1000 6<br>A3 0800 0900 5<br>A4 0900 1200 6<br>A5 1000 1600 12<br>A6 1300 1700 8 | A1 A3 A4 A6 20

### C_DT01 The Tree
- 問題描述
  寫一個程式，用"樹"計算一個算式。考慮這個算式4 + x * 7。我們會用下面的遞迴定義來表示此算式樹。
  首先，一個正整數或是變數是一個算式樹。再來，如果運算子是'+', '-', '*', 或 '/'的其中之一，
  並且左樹和右樹都是算式樹，則(運算子 左樹 右樹 )也是一個算式樹。按照此定義，我們可以用( + 4 ( * x 7 ) )來表示先前的算式。
  現在給定一個算式樹，以及其中所含的變數的值，請計算整個算式的值。
  Pre order: (root, left-node, right-node), (運算子 左樹 右樹 )
- 輸入說明
  輸入的第一行是一個算式樹，不超過1000個字元。注意樹中相鄰的兩個元素會以空白隔開。變數的名稱會是合法的C變數名稱([_A-Za-z0-9]並且非數字開頭)，且不超過32字元。接下來的n行( n ≤ 50，代表樹中變數的數目)以此格式： 變數 = 值 表示各個變數的值，同樣以空白隔開。
- 輸出說明 ：
  輸出為這個算式樹的值。
  輸出輸入範例:
    第一個範例，4+(x*7), x=5
      ( + 4 ( * x 7 ) )         |39
      x = 5                     |
    第二個範例，4+3+(7*6)
      ( + 4 ( + 3 ( * 7 6) ) )   |49
- 範例
  算式 | 輸入 | 輸出
  ----- | ------------- | -------------
  4+(x*7), x=5 | ( + 4 ( * x 7 ) )<br>x = 5 |39
  4+3+(7*6)    | ( + 4 ( + 3 ( * 7 6) ) )   |49


### C_DT05 尋找任意整數數列中之最大遞增子數列
- 問題描述
  最大遞增子數列為一個數列中所有遞增子數列的集合中元素最多的遞增子數列，例如:  
    數列A： 1,2,2,3,1,8,7,5,4  
    數列A之最大遞增子數列：1,2,3,8  
  請寫出一個程式輸入一個以空白分隔的數列，輸出最大的遞增子數列。
- 輸入說明
  請任意輸入一串整數數列，可以有正、負號，任兩組數字之間要逗點。例如: -1,-9,2,7,0,11,-98
- 輸出說明
  輸出最大遞增子數列，任兩組數字之間要逗點。例如:
  -1,2,7,11
- 範例
  輸入 | 輸出
  ------------- | -------------
  1,2,2,3,1,8,7,5,4 | 1,2,3,8
  -9,6,5,4,3,1 | -9,6

### C_DT09 左右為難的小偷-stack篇
- 問題描述  
  長廊上展示了許多貴重物品。小偷背著空的背包，站在長廊的開端。小偷一步一步往長廊的盡頭走，並把貴重的東西往背包裡塞，希望走到盡頭時，能有最豐盛的收穫。在偷東西的過程中，有下面幾點限制:
  1. 小偷背包最多能裝 20kg 的物品，且為一個 stack 。
  2. 每樣物品有三個屬性，分別為 name(char) ， value(float) ，以及 weight(float)，會依序放在長廊上。
  3. 小偷在長廊上是無法回頭的，所以確定捨棄的物品無法再次偷取。
  4. 如果背包總重量未達 20kg ，小偷就可以把偷來的物品放進背包。
  5. 如果當新偷的物品放不下時，小偷會拿出背包最上面的物品，並判斷以此交換新物品是否值得？所謂「值得」是指：「此物品價值小於新偷物品，且捨棄該物品後新物品就可放進背包」。如果不值得，則暫時放到地上 ( 另一個 stack 裡 ) ，再從包包拿下一個物品；上述動作會反覆進行直到找到值得交換的物品，或者包包內已無待判斷物品為止。
  6. 如果找到值得捨棄的物品，捨棄該物品。接著將地上的東西依序塞回背包，最後再將新物品放入背包中 ( 如果放得下的話 ) 。  
  
  最後請顯示出偷到的所有物品、總重量與總價值
- 輸入說明  
  5 個物品會作為輸入，成為長廊上的展示品。格式為： {name} {value} {weight} 分隔符號為一格空格，每輸入一個物品換一行。
- 輸出說明  
  由背包上方開始依序取出並展示所偷到的物品，格式為： {name} {value} {weight} ，另顯示所偷物品之總重量weight:與總價值value:。
- 範例
  輸入1 | 輸出1
  ------------- | -------------
  b 50 2.5<br>c 100 16<br>d 52 1<br>e 55 1.5<br>f 60 2 | f 60.0 2.0<br>e 55.0 1.5<br>c 100.0 16.0<br>weight:19.5<br>value:215.0<br>

  輸入2 | 輸出2
  ------------- | -------------
  b 40 10.5<br>c 30 8.5<br>d 65 5<br>e 85 4.5<br>f 100 10<br> | f 100.0 10.0<br>e 85.0 4.5<br>d 65.0 5.0<br>weight:19.5<br>value:250.0<br>



### C_DT79 非連續子序列之最大和
- 問題描述  
  輸入一個整數List L，求L的一個非連續子序列，其兩數和最大，非連續子序列定義：子序列中任意相鄰的兩個數，在原序列中都不相鄰。
- 輸入說明  
  第一個數字為輸入數列元素個數，接著輸入數列元素。
- 輸出說明  
  輸出非連續子序列之最大和
- 範例
  輸入 | 輸出
  ------------- | -------------
  4<br>2<br>-3<br>3<br>59<br> | 61

### C_GM14 對角線所穿過的正方形數目
- 問題描述  
    給定兩個正整數 a 及 b ， a 、 b 形成一個矩形，其中 a 為矩形的長而 b 為矩形的寬。令此矩形由單位為 1 的正方形所組成，
    所以這個矩形中包含了 a × b 個正方形。  
    請寫一個程式，計算這個矩形的對角線所穿過的小正方形數。
    舉例而言，6*8的矩形的對角線穿過了 12 個小正方形。在這個例子中，你要輸出 12。
- 輸入說明  
  我們的輸入只有一行。一行中包含兩個數字，這兩個數字用逗號隔開。第一個數字是 a ，第二個數字則是 b
- 輸出說明  
    將矩形對角線所穿過的小正方形數給輸出。
- 範例
  輸入 | 輸出
  ------------- | -------------
  5,8 | 12
  47,36 | 82
  101,200 | 300

### C_OT61 數數之積
- 問題描述  
  給定若干整數，輸出其乘積。
- 輸入說明  
  題目有不定筆數的測資，最多有 9 筆。每一列有一筆測試資料。每筆測試資料含 n 個空白格開的整數 m 。
- 輸出說明  
  請針對每筆測資輸出其各整數之乘績。
- 測資規範  
  - 1 ≤ n ≤ 12
  - 0 ≤ m ≤ 40
- 範例
  輸入 | 輸出
  ------------- | -------------
   2 3 4<br>1 2 2 4 0 7| 24<br>0
   1 2 3 4 5<br> 6 8 12 3 4 7 | 120<br>48384

### C_RU02 河內塔遊戲
- 問題描述  
  河內塔遊戲中有三根支架 A 、 B 、 C ，每根支架最多可放 n 個大小不同、中心挖孔的圓盤，大圓盤不得放在小圓盤上面。  
  起先 n 個圓盤均置於支架 A 上(如圖一所示，以 n=3 為例)。
  今欲將這 n 個圓盤從支架 A 搬到支架 C ，每次只能搬一個盤子，支架 B 當作暫存處，請問共須搬動多少次的盤子才能完成？  
  請寫一個非遞迴( non-recursive )程式來處理這個問題。為簡單起見，這 n 個圓盤以數字 1 到 n 來表示，大數字代表大盤子，圓盤置於支架之情形用橫式表示，請參考 Sample Output 。
- 輸入說明  
  輸入圓盤之個數 n ( 3 ≦ n ≦ 8 )
- 輸出說明  
  程式開始時顯示圓盤之個數n及支架A、B、C上圓盤放置情形(參考 Sample Output ，以 n=3 為例)，當搬動之次數為 5 之倍數( 5, 10, 15, … )時，需顯示 A 、 B 、 C 支架上圓盤放置之情形，並印出已經搬動盤子的次數。螢幕印滿後暫停，按任何鍵再繼續執行，直到完成後，顯示此 n 個盤子已搬至支架 C 上，並印出搬動之總次數。
- 範例  
  輸入:
    3
  輸出:
    Number of Discs: 3
    ***********************************
    Initial State:
    A: 3 2 1
    B:
    C:
    ***********************************
    After Moved 5 Times:
    A: 1
    B: 2
    C: 3
    ***********************************
    :
    :
    :
    ***********************************
    Total Moved 7 Times:
    A:
    B:
    C: 3 2 1


### C_SO52 泡沫排序法
- 問題描述  
  老師排序班上成績之高低係一經常性需處理之問題，請試著將一大筆成績資料，運用排序演算法，依高至低方式依序排列之。
- 輸入說明  
  第一列會有一個數字 n 代表 成績之筆數， 接下來會有 n 筆介於 2~50 之不同成績測試資料，每筆一列， 2<n<26 。
- 輸出說明  
  對於每筆輸入 成績 測試資料依序輸出編號及排序結果。
- 範例  
  輸入 | 輸出
  ------------- | -------------
  5<br>31<br>90<br>28<br>35<br>61<br> | 1 90<br>2 61<br>3 35<br>4 31<br>5 28<br>
    | 


### C_ST11 星號菱形輸出
- 問題描述  
  試寫一個程式，可以繪製出如下的圖形：（若輸入偶數，將自動少一行 ) 。  
  PS:若輸入偶數，將自動少一行 ,是因為星號數是1,3,5,7,...,5,3,1的規律,是以奇數行為成長,所以輸入8的話,輸出會和7一樣(沒有8行的菱形)
- 輸入說明  
  輸入一個正整數。
- 範例
  輸入 | 輸出
  ------------- | -------------
  7 | <pre>   \*<br><br>  \*\*\*<br><br> \*\*\*\*\*<br><br>\*\*\*\*\*\*\*<br><br> \*\*\*\*\*<br><br>  \*\*\*<br><br>   \*<br></pre>

### C_ST21 文字及字母出現次數
- 問題描述  
  在電腦科學上 ，計算一串文字上各個字母出現的頻率是常被用到的技術，這對壓縮來講是很重要的資訊，而計算字數也可以幫助人們作校正的工具。一行文字被空白、逗點或是句點所分隔而形成很多字，例如 ”I have a pencil.” 這行字就有 I ， have ， a ， pencil 這四個字，即此行字數為 4 。所以現在要請你幫忙設計一個程式來計算一行文字的字 數及各個字母出現的次數。
- 輸入說明  
  輸入一行正常的英文文字，也就是不要有開頭是空白或是有連續兩個 空白的情形發生，並且內容只能包含英文字母、空白、逗點、句點。 注意 : 輸入的字串長度最多是 100 。
- 輸出說明  
  第一行輸出一個正整數 n ，表示此行文字的字數。 第二行開始依序輸出在此行文字中有出現的字母及出現的次數。注意 : 大小寫要分開計算。  
  格式：出現的字母(空格)：(空格)出現的次數
- 範例  
  輸入 | 輸出
  ------------- | -------------
  I had a dog | 4<br>a : 2<br>d : 2<br>g : 1<br>h : 1<br>I : 1<br>o : 1<br>
