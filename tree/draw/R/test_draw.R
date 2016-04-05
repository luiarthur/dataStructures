preorder <- c("0","1","NULL","NULL","2","1","NULL","NULL","3","NULL","NULL")

blanks <- function(n,char=" ") paste0(rep(char,n),collapse="")
'%+%' <- function(x,y) paste(x,y,sep="")

# Draw Node
print_node <- function(s) {cat("\n"); cat(paste0(s,collapse="\n"),"\n\n")}
draw_node <- function(root,left,right,sep=2,sep_r=sep,sep_l=sep) {
  root.len <- nchar(root[1])
  left.len <- nchar(left[1])
  right.len <- nchar(right[1])

  #num.lines <- max(left.len,right.len)
  #if ((length(left) < length(right)) {
  #  rep(blanks(left.len),)
  #} else {
  #}
  line1 <- blanks(left.len," ") %+% blanks(sep,"_") %+% root[1] %+% blanks(sep,"_") %+% blanks(right.len," ")

  line2 <- left[1] %+% blanks(sep*2 + root.len) %+% right[1]
  #for (i in 1:lines) {
  #  line2 <- left[1] %+% blanks(sep*2 + root.len) %+% right[1]
  #}

  c(line1,line2)
}

s <- draw_node("100","2000","3"); print_node(s)
S <- draw_node("0",s,s); print_node(S)

# Draw Tree
draw_tree <- function(root,sep=2,out="") {
  if (is.na(root)) {
    out
  } else {
    draw_tree %+% 
  }
}
