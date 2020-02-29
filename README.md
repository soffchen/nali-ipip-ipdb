# nali-ipip-ipdb
A fork of http://www.surfchen.org/nali using IPIP .ipdb data file (http://ipip.net)

基于 nali 修改支持 IPIP .ipdb 数据库 (http://ipip.net)

### Install

`./configure && make && make install`

### Usage

将 .ipdb 格式的数据文件保存到 /usr/local/share/ (可通过 .configure 设置)

`command|nali (example: mtr 8.8.8.8|nali)`

### for Macos

```
homebrew install json-c
gcc -o bin/ipipnali nali.c ipdb.c -I /usr/local/Cellar/json-c/0.13.1/include/json-c/ -L /usr/local/Cellar/json-c/0.13.1/lib -ljson-c
```
