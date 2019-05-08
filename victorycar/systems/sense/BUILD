
cc_library(
    name = "sensor-subsystem",
    srcs = ["sensor_subsystem.cpp"],
    hdrs = ["sensor_subsystem.hpp"],
    visibility = ["//visibility:public"],
    deps = [
        "//core/threading:vmos-threading",
        "//core:vmos-core",
        "//hardware:vmos-hardware",
        "//hardware/i2c:vmos-i2c",
        ":imu_cc_proto",
    ],
)

cc_proto_library(
    name = "imu_cc_proto",
    deps = [":imu_proto"],
    visibility = ["//visibility:public"],
)
proto_library(
    name = "imu_proto",
    srcs = ["imu.proto"],
    deps = [
        "@com_google_protobuf//:any_proto",
        
],
)