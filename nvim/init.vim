sy on
filetype plugin on
filetype indent on
set cin ar aw ai is ts=4 sw=4 nu ru clipboard=unnamed,unnamedplus ignorecase backspace=eol,start,indent
autocmd VimEnter * if argc() > 0 && argv()[0] =~ '\.cpp$' | vsp | vertical resize +50 | wincmd l | sp | e .inp | wincmd j | e .out | wincmd h | endif
colorscheme evening
nnoremap <F9> :wa<CR>:!g++ -D_GLIBCXX_DEBUG -DLOCAL -Wall -Wextra -Wunused-variable -pedantic -Wshadow -Wformat=2 -Wfloat-equal -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -Wconversion -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_GLIBCXX_ASSERTIONS -fno-sanitize-recover -Wl,--stack,268435456 % -o %:r && %:r<CR>
nnoremap <F1> :%d<CR>:-1read template.cpp<CR>
map 0 ^
nnoremap <silent> <Esc> :noh<CR>
