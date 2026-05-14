project(
  'Clipto',
  'cpp',
  version: '0.1.0-alpha',
  default_options: [
    'warning_level=3', 
    'cpp_std=c++23', 
  ],
  license: 'GPL-3.0',
  license_files: 'LICENSE',
  subproject_dir: 'vendor',
)

gtest_proj = subproject('gtest')
gtest_dep  = gtest_proj.get_variable('gtest_main_dep')
gmock_dep  = gtest_proj.get_variable('gmock_dep')

qt6_dep = dependency('qt6', modules: ['Core', 'Gui', 'Quick', 'Qml'])
qt6     = import('qt6')

qt_files = qt6.preprocess(
  qresources: 'src/ui/resources.qrc',
  dependencies: qt6_dep,
)

include = include_directories('include')

sources = [
  qt_files,
]

dependencies = [
  qt6_dep,
]

executable(
  'clipto',
  sources: [
    'src/main.cpp', 
    sources
  ],
  dependencies: dependencies,
  include_directories: include,
  install: false,
)

test_exe = executable(
  'clipto_test',
  sources: [
    'tests/main.cpp',
    sources,
  ],
  dependencies: [
    gtest_dep, 
    gmock_dep,
    dependencies
  ],
  include_directories: include,
)

test('main_test', test_exe, protocol: 'gtest')
