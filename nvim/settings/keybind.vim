nnoremap <F9> :wa<CR>:!g++ -D_GLIBCXX_DEBUG -DLOCAL -Wall -Wextra -Wunused-variable -pedantic -Wshadow -Wformat=2 -Wfloat-equal -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -Wconversion -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_GLIBCXX_ASSERTIONS -fno-sanitize-recover -Wl,--stack,268435456 % -o %:r && %:r<CR>
nnoremap <F1> :%d<CR>:-1read template.cpp<CR>

map <C-j> <C-W>j
map <C-k> <C-W>k
map <C-h> <C-W>h
map <C-l> <C-W>l

map 0 ^
nnoremap <silent> <Esc> :noh<CR>
