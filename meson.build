project('Fundamentals', 'cpp', 'c',
        default_options: ['buildtype=debugoptimized',
                          'cpp_std=c++20'],
        license: 'Apache-2.0',
        license_files: 'License',
        version: '1')

Fundamentals_version = meson.project_version()

scdoc_dep = find_program('scdoc', required: get_option('compile-man-pages'))

config_h = configuration_data()
config_h.set('MFundamentalsVersion', Fundamentals_version)
config_h.set10('MFundamentalsWereCompiledWithManPages', scdoc_dep.found())
configure_file(
    output: 'BuildConfig.h',
    configuration: config_h)

top_include = include_directories('.')

subdir('Fundamentals')
subdir('FundamentalsDocumentation')

summary({'Compile man pages': scdoc_dep.found(),
         'Build type': get_option('buildtype')},
        section: 'Build configuration', bool_yn: true)
