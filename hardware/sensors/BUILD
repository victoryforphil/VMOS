cc_library(
    name = "vmos-sensors",
    srcs = ["BNO055.cpp", "VL53L1X.cpp"],
    hdrs = ["BNO055.h", "VL53L1X.hpp"],
    visibility = ["//visibility:public"],
    deps = [
        "//core:vmos-core",
        "//hardware/i2c:vmos-i2c",
        "//hardware/sensors/VL53L1X_STLIB:VL53L1X-STLib"
    ],
)