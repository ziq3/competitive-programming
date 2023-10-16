let g:clipboard = {
     \ 'name': 'WslClipboard',
     \ 'copy': {
     \    '+': 'clip.exe',
     \    '*': 'clip.exe',
     \  },
     \ 'paste': {
     \    '+': 'powershell.exe -c [Console]::Out.Write($(Get-Clipboard -Raw).tostring().replace("`r", ""))',
     \    '*': 'powershell.exe -c [Console]::Out.Write($(Get-Clipboard -Raw).tostring().replace("`r", ""))',
     \  },
     \ 'cache_enabled': 0
   \ }

nnoremap <silent> <Esc> :noh<CR>
set termguicolors
syntax on

set nobackup
set nowb
set noswapfile

set autoread
set clipboard=unnamed,unnamedplus
set nu
set mouse=a
set ruler
set showcmd
set shellslash

set autoindent
set smartindent

set tabstop=4
set softtabstop=4
set shiftwidth=4


set hlsearch
set smartcase
set ignorecase
set incsearch

set backspace=indent,eol,start
set nofixendofline

autocmd VimEnter * if argc() > 0 && argv()[0] == "main.cpp" | vsp | vertical resize +50 | wincmd l | sp | e .inp | wincmd j | e .out | wincmd h | endif
