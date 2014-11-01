CC = gcc
CFLAGS = -Wall -O2

TARGET = xldcdinfo
SOURCES = xldcdinfo.c XLDCDDABackend.c
OBJS = $(SOURCES:.c=.o)

all : $(TARGET)
$(TARGET) : $(OBJS) $(ASM_OBJS)
	$(CC) $^  -o $(TARGET) -framework IOKit -framework CoreFoundation

depend:
	$(CC) -MM $(CFLAGS) $(SOURCES) > dependencies

clean :
	rm -f $(OBJS) $(TARGET)

include dependencies
