OBJS	= source/main.o
SOURCE	= source/main.cpp
HEADER	= header/menus.h header/errors.h
OUT	= HTGA.exe
LFLAGS	 = 

all: HTGA.exe

HTGA.exe: $(OBJS)
	$(CC) -o $@ $^ $(LFLAGS)

%.o: %.c $(HEADER)
	$(CC) -c -o $@ $< $(LFLAGS)

clean:
	rm -f $(OBJS) $(OUT)