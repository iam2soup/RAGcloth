#Made by iam2soup on github.
#if anyone wants to commit a cmake and/or a makefile please do.
#dont name your source dir with an @ symbol. EX: prog/example/s@urce/
#and dont name your headers with an @. symbol. EX: lorem@ipsum.h / <lorem@ipsum.h>
# os = linux
#CHANGABLE
#cd src
opsy="linux"
builder="clang"
outputf="RAGcloth.bin"
sourcef="${opsy}-RAGcloth.c"
reqlib="@ncurses"
#srcloc="@ src"
srcloc="src"
#PROCESSING
#srclocproc="${srcloc//@/cd}"
#i am stupid. SCRlocproc????????
reqlibproc="${reqlib//@/-l}"
endvar="$builder $reqlibproc -o $outputf $sourcef"
#echo $endvar
#echo "$srclocproc"
#eval "$srclocproc"
#cd src
cd $srcloc
eval "$endvar"
#this isnt working let me fix rq.
#fixed i think
#fixed it i had the unrenamed .c file that had the uppercase linux.
#remind me to remove these after i upload to the repo.
