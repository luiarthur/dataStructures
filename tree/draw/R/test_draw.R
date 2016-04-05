preorder <- c("0","1","NULL","NULL","2","1","NULL","NULL","3","NULL","NULL")

blanks <- function(n,char=" ") paste0(rep(char,n),collapse="")
paste_block <- function(x,y) {
  N <- 0
  if (length(x) < length(y)) {
    N <- length(y)
    x <- c(x, rep(blanks(nchar(x[1])), N-length(x)))
  } else {
    N <- length(x)
    y <- c(y, rep(blanks(nchar(y[1])), N-length(y)))
  }

  sapply(1:N, function(i) paste(x[i],y[i],sep=""))
}
'%+%' <- function(x,y) paste_block(x,y)

xx <- c("111","222","333")
yy <- c("1111","2222","3333","4444")

zz <- paste_block(xx,yy)
cat(zz[1],"\n"); cat(zz[2],"\n"); cat(zz[3],"\n"); cat(zz[4],"\n")


zz2 <- xx %+% yy
cat(zz2[1],"\n"); cat(zz2[2],"\n"); cat(zz2[3],"\n"); cat(zz2[4],"\n")

# Draw Node
rgx <- function(pattern,x) regexpr(pattern,x)[1]
print_node <- function(s) {cat("\n"); cat(paste0(s,collapse="\n"),"\n\n")}
draw_node <- function(root,left,right,sep=2,sep_r=sep,sep_l=sep) {
  root.len <- nchar(root[1])
  left.len <- nchar(left[1])
  right.len <- nchar(right[1])

  left_dist_from_root <- left.len - rgx('\\d',left[1])
  right_dist_from_root <- rgx('\\d',right[1])
  line1 <- blanks(left.len-left_dist_from_root," ") %+% blanks(sep+left_dist_from_root,"_") %+% root %+% 
           blanks(sep+right_dist_from_root,"_") %+% blanks(right.len-right_dist_from_root," ")
  line2 <- left %+% blanks(sep*2 + root.len) %+% right

  c(line1,line2)
}

s <- draw_node("100","2000","3"); print_node(s)
S <- draw_node("0",s,s); print_node(S)
SS <- draw_node("0",S,s); print_node(SS)
SSS <- draw_node("3",S,SS,sep=3); print_node(SSS)

# Draw Tree
x <- preorder
x <- c("0","0","1","NULL","NULL","2","1","NULL","NULL","3","NULL","NULL","2","1","NULL","NULL","3","NULL","NULL")

draw_tree <- function(x) {
  y <- gsub("NULL,NULL", "|", paste(x,collapse=","))
  y <- unlist( strsplit(y,",") )

  draw_tree.rec <- function(z) {
    if (tail(z,1) == "|") z <- z[-length(z)]
    pos <- min( which(z == "|") )
    root <- z[1]
    left <- z[2:(pos-1)]
    right <- z[(pos+1):length(z)]
    
    # Figure out the case for left > 1
    if (length(left) > 1 && length(right) > 1) {
      draw_node(root,draw_tree.rec(left),draw_tree.rec(right))
    } else if (length(left) == 1 && length(right) > 1) {
      draw_node(root,left,draw_tree.rec(right))
    } else if (length(right) == 1 && length(left) > 1) {
      draw_node(root,draw_tree.rec(left),right)
    } else {
      draw_node(root,left,right)
    }
  }
  
  s <- draw_tree.rec(y); print_node(s)
}
draw_tree(x)
