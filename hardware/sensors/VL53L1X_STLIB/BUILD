cc_library(
    name = "VL53L1X-STLib",
    srcs = glob(
        ["*.c", "*.cpp"],
    ),
    hdrs = glob([
        "*.h"
    ]),
    visibility = ["//visibility:public"],
    deps = [
        "//core:vmos-core",
        "//hardware/i2c:vmos-i2c",
    ],
)