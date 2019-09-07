## Makefile文件的编写

```
# 由于我的目标文件是单独的, 所以我每次得 编辑 SRCS 和 TARG

# specify all source files here
SRCS	=	print_link_form_tail_to_head.c 	one_list.c one_list.h

# specify target here (name of executable)
# TARG	=	one_list		
TARG	=	print_link_form_tail_to_head 

# specify compiler, compile flags, and needed libs
CC	=	gcc
CFLAGS = -g -Wall
LIBS 	=	-lm 

# this translates	.c	file	in	src	list to .o's
OBJS	=	$(SRCS:	.c=.o)

#	all is not really	needed	, but is used to generate the target
all:	$(TARG)

# this generates the target executable
$(TARG):	$(OBJS)
	$(CC)	$(OBJS)		-o 	$(TARG)	

# this is a generic rule for .o files
%.o:	%.c 
	$(CC)	$(CFLAGS)	-c 	$<	$@
	
	
#clean
clean:	
	@echo "cleaning project"
	-rm *.o  $(TARG)
	@echo "cleaning complie"
.PHONY:	clean

```

