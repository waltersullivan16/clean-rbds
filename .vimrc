set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()
Plugin 'mattn/emmet-vim'
Plugin 'scrooloose/nerdtree'
Plugin 'scrooloose/syntastic'
Plugin 'pangloss/vim-javascript'
Plugin 'tpope/vim-unimpaired'
Plugin 'tpope/vim-repeat'
Plugin 'tpope/vim-abolish'
Bundle 'mxw/vim-jsx'
call vundle#end()
set hlsearch

filetype plugin indent on
set expandtab
set ts=2
set shiftwidth=2
execute pathogen#infect()
syntax on
set incsearch

au BufNewFile,BufRead *.es6 set filetype=javascript

set statusline+=%#warningmsg#
set statusline+=%{SyntasticStatuslineFlag()}
set statusline+=%*

let g:syntastic_always_populate_loc_list = 1
let g:syntastic_check_on_open = 1
let g:syntastic_python_checkers = ['pyflakes']
let g:syntastic_javascript_checkers = ['eslint']
let g:syntastic_jsx_checkers = ['eslint']
let g:syntastic_html_tidy_exec = 'tidy5'
let g:ctrlp_working_path_mode = 0


nnoremap gp `[v`]
let mapleader = "-"
nnoremap <leader>ev :vsplit $MYVIMRC<cr>


set runtimepath^=~/.vim/bundle/ctrlp.vim
let g:ctrlp_match_func = { 'match': 'pymatcher#PyMatch' }


set number
autocmd! bufwritepost .vimrc source % "autoreloader
set textwidth=79 colorcolumn=80 formatoptions=q "hard text wrapping and formatting
set clipboard=unnamedplus "use system clipboard as default register
set history=700
execute pathogen#infect()
autocmd BufWritePre * :%s/\s\+$//e
set tags=~/codility/tags

set path+=~/codility/frontend_v2/codility/templates
set path+=~/codility/frontend_v2/codility/static
set path+=~/codility/frontend_v2/codility/cui/static
set path+=~/codility/frontend_v2/codility/cui/templates

set autoread noswapfile
set wildmenu wildmode=longest,full
