all: Bst

# Symbols helpful for understanding the productions
#   $@ is the production's target
#   $^ are the production's prerequisites

Bst:      bst.o  #trying to copy example
          cc -o $@ $^
Bst.o     Bst.c bst.h  #trying to copy example


clean:
          rm -f *. llDemo Bst

Demo:    Bst
        ./Bst
