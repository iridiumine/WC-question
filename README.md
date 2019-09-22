# WC-question
## 1.wc.exe 
wc.exe是一个常见的工具，它能统计文本文件的字符数、单词数和行数。这个项目要求写一个命令行程序，模仿已有wc.exe 的功能，并加以扩充，给出某程序设计语言源文件的字符数、单词数和行数。
## 2.项目说明
### 用户输入的模式：[parameter] [file_name]
### 基础功能列表:
-c file.c     //返回文件 file.c 的字符数<br>
-w file.c     //返回文件 file.c 的词的数目<br>
-l file.c     //返回文件 file.c 的行数<br>
### 扩展功能列表
-s file.c     //递归处理目录下符合条件的文件<br>
-a file.c     //返回更复杂的数据（代码行数/空行数/注释行数）<br>
-f file.c     //说明这个文件是哪一种语言的 例如： C/Java/C++/JavaScript/Python/HTML,如果看不出属于任何语言，就输出TXT<br>
**空行：**本行全部是空格或格式控制字符，如果包括代码，则只有不超过一个可显示的字符，例如“{”<br>
**代码行：**本行包括多于一个字符的代码<br>
**注释行：**本行不是代码行，并且本行包括注释。一个有趣的例子是有些程序员会在单字符后面加注释:<br>
} //注释<br>
在这种情况下，这一行属于注释行。

