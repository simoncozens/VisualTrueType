OBJS = \
CvtManager.o File.o List.o MathUtils.o Memory.o Platform.o TextBuffer.o \
TMTParser.o TTAssembler.o TTEngine.o TTFont.o TTGenerator.o Variation.o \
VariationInstance.o VariationModels.o vttcompile.o

.cpp.o :
	callcatcher $(CXX) --std=c++14 -c -o $@ $^

.PHONY : clean

default: vttcompile

vttcompile: $(OBJS)
	echo callcatcher $(CXX) --std=c++14 -o $@ $^
	callcatcher $(CXX) --std=c++14 -o $@ $^

clean :
	$(RM) $(OBJS) vttcompile vttcompile.exe
