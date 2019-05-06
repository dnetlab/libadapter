
TARGET  := libadapter.so
SOURCES := network.c switch.c nvram.c utils.c
OBJS    := $(SOURCES:.c=.o)

CFLAGS  += -I. -Os -pipe
LDFLAGS += -lconfig

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -s -shared -o $@ $(OBJS) $(LDFLAGS)

.c.o:
	$(CC) -c -o $@ -fpic $(CFLAGS) $< 

clean:
	rm -f $(OBJS) $(TARGET) 

.PHONY: clean all
