includes = include_directories('.')

libCommonCode = static_library('CommonCode', 'Common.cc',
                               include_directories: [top_include, includes])

libCommonCode_dep = declare_dependency(
    include_directories : includes,
    link_with: libCommonCode)
