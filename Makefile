all:
	meson build && ninja -C build

run: all
	./build/libjsonTest

clean:
	rm -rf build

re: clean all

.PHONY: all clean re run
