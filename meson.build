project(
  'biosoup',
  ['cpp'],
  version : '0.11.0',
  default_options : [
    'buildtype=release',
    'warning_level=3',
    'cpp_std=c++11',
    'b_ndebug=if-release'],
  license : 'MIT',
  meson_version : '>=0.60.0'
)

###########
# Headers #
###########

subdir('include')

#########
# Tests #
#########

if (not meson.is_subproject()) and get_option('tests')
  biosoup_gtest_dep = dependency('gtest', version : '>= 1.10.0', main : true, fallback : ['gtest', 'gtest_main_dep'])

  subdir('test')
endif

###################
# Dependency info #
###################

if (not meson.is_subproject())
  import('pkgconfig').generate(
    name : 'biosoup',
    version : meson.project_version(),
    filebase : 'biosoup',
    description : 'C++ collection of header only bioinformatics data structures used for storage and logging.')
endif

biosoup_dep = declare_dependency(
  include_directories : biosoup_include_directories,
  version : meson.project_version()
)
