project('libjson', 'cpp',
		version : '1.0',
		default_options : ['warning_level=3',
							'cpp_std=c++14'])

includes = include_directories('include')

lib = library('json',
			'srcs/Json.cpp',
			'srcs/JsonContent.cpp',
			include_directories: includes,
			install : true)

dep_libjson = declare_dependency(link_with: lib, include_directories: includes)

meson.override_dependency('libjson', dep_libjson)

if get_option('test')
executable('libjsonTest',
			'srcs/main.cpp',
			'srcs/Json.cpp',
			'srcs/JsonContent.cpp',
			include_directories: includes,
			install : true)
endif
