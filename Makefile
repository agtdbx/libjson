all:
	meson build
	ninja -C build

buildtest:
	meson build -Dtest=true
	ninja -C build

run: buildtest
	./build/libjsonTest

fclean:
	rm -rf build release

re: fclean all

release:
	meson build_release --prefix=$$PWD/release
	ninja install -C build_release

.PHONY: all fclean re run
