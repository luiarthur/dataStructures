#!/usr/bin/env Rscript

source("R/draw_tree.R",chdir=TRUE)
default_file <- "mytree.o"
args <- commandArgs(trailingOnly=TRUE)
if (length(args==1)) default_file <- args[1]

draw_tree(readLines(default_file))
