cc_library(
    name = "vmos-sensors",
    srcs = ["BNO055.cpp", "VL53L1X.cpp", "VL53L1X_Lite.cpp"],
    hdrs = ["BNO055.h", "VL53L1X.hpp",  "VL53L1X_Lite.hpp"],
    visibility = ["//visibility:public"],
    deps = [
        "//core:vmos-core",
        "//hardware/i2c:vmos-i2c",
        "//hardware/sensors/VL53L1X_STLIB:VL53L1X-STLib",
        "//hardware/sensors/VL53L1X_STLIB:VL53L1X-STLib-Lite"
    ],
)