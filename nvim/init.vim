call plug#begin()
Plug 'vim-airline/vim-airline'
Plug 'bfrg/vim-cpp-modern'
Plug 'jiangmiao/auto-pairs'
Plug 'dense-analysis/ale'
Plug 'morhetz/gruvbox'
Plug 'vim-autoformat/vim-autoformat'
call plug#end()


sy on
filetype plugin on
filetype indent on
set noswapfile
set nobackup
set cin ar aw ai is ts=4 sw=4 nu ru clipboard=unnamed,unnamedplus ignorecase backspace=eol,start,indent
autocmd VimEnter * if argc() > 0 && argv()[0] =~ '\.cpp$' | vsp | vertical resize +50 | wincmd l | sp | e .inp | wincmd j | e .out | wincmd h | endif
autocmd VimEnter * if argc() > 0 && argv()[0] =~ '\.c$' | vsp | vertical resize +50 | wincmd l | sp | e .inp | wincmd j | e .out | wincmd h | endif
colorscheme gruvbox



nnoremap <F9> :wa<CR>:!g++ -std=c++20 -D_GLIBCXX_DEBUG -DLOCAL -Wall -Wextra -Wunused-variable -pedantic -Wshadow -Wformat=2 -Wfloat-equal -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -Wconversion -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_GLIBCXX_ASSERTIONS -fno-sanitize-recover -Wl,--stack,268435456 % -o %:r && %:r<CR>'
nnoremap <F1> :%d<CR>:-1read template.cpp<CR>
map 0 ^
nnoremap <silent> <Esc> :noh<CR>




let g:ale_cpp_cc_options = '-std=c++20 -Wall -Wextra'
let g:ale_cpp_cc_executable = 'g++'
let g:python3_host_prog="C:\\Users\\PC\\AppData\\Local\\Programs\\Python\\Python312\\python.exe"
au BufWrite * :Autoformat
let g:formatdef_clangformat = '"clang-format -style=file"'
let g:formatters_cpp = ['clangformat']
