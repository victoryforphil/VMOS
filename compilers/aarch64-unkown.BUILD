package(default_visibility = ['//visibility:public'])

filegroup(
  name = 'gcc',
  srcs = [
    'bin/aarch64-unknown-linux-gnu-gcc',
  ],
)

filegroup(
  name = 'ar',
  srcs = [
    'bin/aarch64-unknown-linux-gnu-ar',
  ],
)

filegroup(
  name = 'ld',
  srcs = [
    'bin/aarch64-unknown-linux-gnu-ld',
  ],
)

filegroup(
  name = 'nm',
  srcs = [
    'bin/aarch64-unknown-linux-gnu-nm',
  ],
)

filegroup(
  name = 'objcopy',
  srcs = [
    'bin/aarch64-unknown-linux-gnu-objcopy',
  ],
)

filegroup(
  name = 'objdump',
  srcs = [
    'bin/aarch64-unknown-linux-gnu-objdump',
  ],
)

filegroup(
  name = 'strip',
  srcs = [
    'bin/aarch64-unknown-linux-gnu-strip',
  ],
)

filegroup(
  name = 'as',
  srcs = [
    'bin/aarch64-unknown-linux-gnu-as',
  ],
)

filegroup(
  name = 'compiler_pieces',
  srcs = glob([
    'aarch64-unknown-linux-gnu/**',
    'lib64/**',
    'lib/gcc/aarch64-unknown-linux-gnu/**',
    'include/**',
  ]),
)

filegroup(
  name = 'compiler_components',
  srcs = [
    ':gcc',
    ':ar',
    ':ld',
    ':nm',
    ':objcopy',
    ':objdump',
    ':strip',
    ':as',
  ],
)