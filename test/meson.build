###########
# Sources #
###########

biosoup_test_sources = files([
  'nucleic_acid_test.cpp',
  'overlap_test.cpp',
  'progress_bar_test.cpp',
  'sequence_test.cpp',
  'timer_test.cpp',
])

biosoup_test = executable(
  'biosoup_test',
  biosoup_test_sources,
  dependencies : biosoup_gtest_dep,
  include_directories : biosoup_include_directories,
  install : false)

#########
# Tests #
#########

test('biosoup gtest unit tests', biosoup_test)
