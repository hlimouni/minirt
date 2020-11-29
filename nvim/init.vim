"Plugings installing tool

call plug#begin()
Plug 'ayu-theme/ayu-vim' "ayu theme for vim
Plug 'vim-airline/vim-airline' "airline bottom nice bar
Plug 'pbondoer/vim-42header' "42 standard header
Plug 'kien/ctrlp.vim'
Plug 'preservim/nerdtree'
call plug#end()

"Basic settings

		"tab navigation
map <C-t><up> :tabr<CR>
map <C-t><down> :tabl<CR>
map <C-t><left> :tabp<CR>
map <C-t><right> :tabn<CR>


set number relativenumber " relative number set but keeping actual line number at cursor
map <F8> :NERDTreeToggle<CR>
set termguicolors     " enable true colors support
set tabstop=4
set shiftwidth=4

"ayu theme settings

let ayucolor="light"  " for light version of theme
let ayucolor="mirage" " for mirage version of theme
let ayucolor="dark"   " for dark version of theme
colorscheme ayu
