project('libjson', 'cpp',
		version : '1.0',
		default_options : ['warning_level=3',
							'cpp_std=c++14'])

includes = include_directories('include')

lib = library('libjson',
			'srcs/Json.cpp',
			'srcs/JsonContent.cpp',
			include_directories: includes,
			install : true)

dep_libjson = declare_dependency(link_with: lib)

meson.override_dependency('libjson', dep_libjson)


executable('libjsonTest',
			'srcs/main.cpp',
			'srcs/Json.cpp',
			'srcs/JsonContent.cpp',
			include_directories: includes,
			install : true)
