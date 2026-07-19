" --- Plugin Management ---
call plug#begin()
Plug 'vim-airline/vim-airline'
Plug 'bfrg/vim-cpp-modern'
Plug 'jiangmiao/auto-pairs'
Plug 'dense-analysis/ale'
Plug 'morhetz/gruvbox'
Plug 'vim-autoformat/vim-autoformat'
call plug#end()

" --- Basic Settings ---
syntax on
filetype plugin indent on
set clipboard=unnamedplus

" --- UI Configuration ---
set number
set ruler
set cursorline
let g:gruvbox_contrast_dark = 'hard'
set background=dark
colorscheme gruvbox
set scrolloff=5
set updatetime=100

" --- Editor Behavior ---
set hidden
set mouse=a
set backspace=indent,eol,start
set autoindent
set smartindent
set tabstop=4
set softtabstop=4
set shiftwidth=4
set expandtab
set smarttab

" --- Search & Navigation ---
set ignorecase
set smartcase
set incsearch
set hlsearch

" --- File Handling ---
set nobackup
set noswapfile
set nowritebackup
set undofile
set undodir=~/.vim/undodir
autocmd VimEnter * if argc() > 0 && expand('%:e') =~ '^\(cpp\|c\)$' |
    \ execute 'vsp | vertical resize 150% | wincmd l | sp | e .inp | wincmd j | e .out | wincmd h' | endif
autocmd VimEnter * if argc() > 0 && expand('%:e') =~ '^\(py\)$' |
    \ execute 'vsp | vertical resize 150% | wincmd l | sp | e .inp | wincmd j | e .out | wincmd h' | endif

" --- Key Mappings ---
autocmd FileType cpp nnoremap <buffer> <F1> :%d<CR>:-1read template.cpp<CR>
autocmd FileType c nnoremap <buffer> <F1> :%d<CR>:-1read template.cpp<CR>
nnoremap <silent> <Esc> :nohlsearch<CR>:cclose<CR>
nmap 0 ^
inoremap jk <esc>
inoremap kj <esc>

" --- Compilation ---
autocmd FileType cpp nnoremap <buffer> <F9> :wa<CR>:!g++ -std=c++20 -D_GLIBCXX_DEBUG -ggdb3 -DLOCAL -Wall -Wextra -Wunused-variable -pedantic -Wshadow -Wformat=2 -Wfloat-equal -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -Wconversion -D_GLIBCXX_DEBUG_PEDANTIC -D_GLIBCXX_ASSERTIONS -fno-sanitize-recover -Wl,--stack,268435456 "%" -o "%:r.exe" && "./%:r.exe"<CR>
autocmd FileType c   nnoremap <buffer> <F9> :wa<CR>:!gcc -DLOCAL -Wall -Wextra % -o %:r && %:r<CR>
autocmd FileType python nnoremap <buffer> <F9> :wa<CR>:!python "%" < .inp > .out<CR>

" --- LSP & Formatting ---
let g:ale_linters = {
    \ 'c': ['clang'],
    \ 'cpp': ['clang'],
    \ 'python': ['flake8']
    \ }

let g:ale_fixers = {
    \ '*': ['remove_trailing_lines', 'trim_whitespace'],
    \ 'c': ['clang-format'],
    \ 'cpp': ['clang-format'],
    \ 'python': ['black', 'isort']
    \ }

let g:ale_c_clangformat_options = '-style=file'
let g:ale_cpp_clangformat_options = '-style=file'
let g:ale_fix_on_save = 1
let g:ale_set_quickfix = 1

" --- Python Paths & Config ---
let g:python3_host_prog = $HOME . 'C:\Users\PC\AppData\Roaming\Python\Python314\python.exe'

" Match Black's default line length so Flake8 doesn't complain prematurely
let g:ale_python_flake8_options = '--max-line-length=88'

" Point ALE to your Python 3.12 Scripts folder for the executables
let g:ale_python_flake8_executable = 'C:\Users\PC\AppData\Roaming\Python\Python314\Scripts\flake8.exe'
let g:ale_python_black_executable = 'C:\Users\PC\AppData\Roaming\Python\Python314\Scripts\black.exe'
let g:ale_python_isort_executable = 'C:\Users\PC\AppData\Roaming\Python\Python314\Scripts\isort.exe'
