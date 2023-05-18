###########
# Headers #
###########

biosoup_include_directories = include_directories(['.'])

if meson.is_subproject()
  subdir_done()
endif

install_headers(
  files([
    'biosoup/nucleic_acid.hpp',
    'biosoup/overlap.hpp',
    'biosoup/progress_bar.hpp',
    'biosoup/sequence.hpp',
    'biosoup/timer.hpp',
  ]),
  subdir : 'biosoup')
