#Made by iam2soup on github.
#if anyone wants to commit a cmake and/or a makefile please do.
#dont name your source dir with an @ symbol. EX: prog/example/s@urce/
#and dont name your headers with an @. symbol. EX: lorem@ipsum.h / <lorem@ipsum.h>
# os = linux
#CHANGABLE
opsy="linux"
builder="clang"
outputf="RAGcloth.bin"
sourcef="${opsy}-RAGcloth.c"
reqlib="@ncurses"
srcloc="src"
#PROCESSING dont change unless you know what your doing.
reqlibproc="${reqlib//@/-l}"
endvar="$builder $reqlibproc -o $outputf $sourcef"
#RUNNING COMMAND(S)
cd $srcloc
eval "$endvar"
