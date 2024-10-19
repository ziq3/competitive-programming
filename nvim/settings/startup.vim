syntax on
set termguicolors
colorscheme gruvbox

set nobackup
set nowb
set noswapfile

filetype plugin on
filetype indent on

set autoread
set clipboard=unnamed,unnamedplus
set nu
set mouse=a
set ruler
set showcmd

set expandtab
set smarttab
set tabstop=4
set softtabstop=4
set shiftwidth=4

set ai "Auto indent
set si "Smart indent
set wrap "Wrap lines

set hlsearch
set smartcase
set ignorecase
set incsearch

set backspace=eol,start,indent
set whichwrap+=<,>,h,l
set nofixendofline

autocmd VimEnter * if argc() > 0 && argv()[0] == "main.cpp" | vsp | vertical resize +50 | wincmd l | sp | e .inp | wincmd j | e .out | wincmd h | endif
