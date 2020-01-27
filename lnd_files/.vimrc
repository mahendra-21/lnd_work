set tabstop=4
set nu
set expandtab
set shiftwidth=4
set autoindent
set smartindent
set cindent
set showmatch
set showmode
set eb
autocmd FileType make setlocal noexpandtab
autocmd BufNewFile *.c 0r ~/file_header.sh
autocmd BufNewFile *.h 0r ~/file_header.sh

iabbrev #i #include <stdio.h>
iabbrev #d #define
iabbrev main() int main(int argc, char **argv)
