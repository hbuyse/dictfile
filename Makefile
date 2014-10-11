EXEC = wordcount

CC = gcc
LD = gcc

CFLAGS = -g3 -Wall -fmessage-length=0
LDFLAGS =

SRC           = $(shell find . -name '*.c')
OBJ           = $(foreach var,$(notdir $(SRC:.c=.o)),$(var))
HDR          += $(foreach var,$(dir $(shell find . -name *.h)),-I$(var))

# Put verbosity on
ifeq ($(V),1)
	VERBOSE	= @
else
	VERBOSE =
endif


$(EXEC): $(OBJ)
	$(VERBOSE) $(LD) $(OBJ) -o $(EXEC) $(LDFLAGS)


%.o: %.c
	$(VERBOSE) $(CC) -c -o $@ $< $(CFLAGS) $(HDR)


distclean:
	$(VERBOSE) find . -type f -name '*.o' -delete
	$(VERBOSE) rm -f $(EXEC)


# Launch the program
launch: $(EXEC)
	$(VERBOSE) ./$(EXEC)


l: launch


# Debug the program
debug: all
	$(VERBOSE) gdb $(EXEC)


# Launch DoxyWizard
doxy: $(SRC)
	$(VERBOSE) doxygen Doxyfile


# Delete documentation generated by Doxygen
rmdoxy:
	$(VERBOSE) rm -R doxygen/latex
	$(VERBOSE) rm -R doxygen/html


# Indent the files
indent:
	$(VERBOSE) indent \
	--blank-lines-after-declarations \
	--blank-lines-after-procedures \
	--blank-lines-before-block-comments \
	--no-blank-lines-after-commas \
	--braces-on-if-line \
	--braces-on-func-def-line \
	--braces-on-struct-decl-line \
	--case-indentation0 \
	--case-brace-indentation4 \
	--cuddle-do-while \
	--declaration-indentation8 \
	--dont-break-function-decl-args \
	--dont-break-function-decl-args-end \
	--dont-break-procedure-type \
	--dont-format-comments \
	--dont-format-first-column-comments \
	--dont-cuddle-else \
	--remove-preprocessor-space \
	--space-after-cast \
	--space-after-for \
	--space-after-if \
	--space-after-parentheses \
	--no-space-after-function-call-names \
	--no-space-after-parentheses \
	--space-after-while \
	--indent-level4 \
	--no-tabs \
	$(SRC) $(HDR)
	$(VERBOSE) rm `find . -name *~`
