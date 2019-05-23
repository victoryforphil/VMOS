package(default_visibility = ['//visibility:public'])
cc_toolchain_suite(
  name = 'toolchain',
  toolchains = {
  'aarch64|compiler':':gcc-linux-aarch64',
  'aarch64':':gcc-linux-aarch64',
  'armf|compiler':':gcc-linux-armf',
  'armf':':gcc-linux-armf',
  },
)

filegroup(
    name = "empty",
    srcs = [],
)


cc_toolchain(
  name = 'gcc-linux-aarch64',
  all_files = ':empty',
  compiler_files = ':empty',
  toolchain_identifier = 'aarch64-linux-gnu',
  cpu = 'aarch64',
  dwp_files = ':empty',
  dynamic_runtime_libs = [':empty'],
  linker_files = ':empty',
  objcopy_files = 'empty',
  static_runtime_libs = [':empty'],
  strip_files = 'empty',
  supports_param_files = 1,
)
cc_toolchain(
  name = 'gcc-linux-armf',
  all_files = ':empty',
  compiler_files = ':empty',
  toolchain_identifier = 'armf-linux-gnu',
  cpu = 'armf',
  dwp_files = ':empty',
  dynamic_runtime_libs = [':empty'],
  linker_files = ':empty',
  objcopy_files = 'empty',
  static_runtime_libs = [':empty'],
  strip_files = 'empty',
  supports_param_files = 1,
)