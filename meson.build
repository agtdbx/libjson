project('libjson', 'cpp',
		version : '1.0',
		default_options : ['warning_level=3',
							'cpp_std=c++14'])

includes = include_directories('include')

library('libjsonTest',
			'srcs/Json.cpp',
			'srcs/JsonContent.cpp',
			include_directories: includes,
			install : true)

executable('libjsonTest',
			'srcs/main.cpp',
			'srcs/Json.cpp',
			'srcs/JsonContent.cpp',
			include_directories: includes,
			install : true)
