win_flex.exe -o lexer.yy.cpp -c++ lexer.l
win_bison.exe -d -v -o parser.tab.cpp parser.y
