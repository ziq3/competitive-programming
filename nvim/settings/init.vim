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
set guifont=Mono:h15

syntax on

set autoread
set clipboard=unnamed,unnamedplus
set nu
set mouse=a
set ruler
set showcmd
set shellslash
set cursorline

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

autocmd VimEnter * if argc() > 0 && argv()[0] == "c.cpp" | vsp | vertical resize +40 | wincmd l | sp | e .inp | wincmd j | e .out | wincmd h | endif
