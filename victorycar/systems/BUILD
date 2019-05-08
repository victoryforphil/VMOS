
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
    ],
)

cc_library(
    name = "mock-subsystem",
    srcs = ["mock_subsystem.cpp"],
    hdrs = ["mock_subsystem.hpp"],
    visibility = ["//visibility:public"],
    deps = [
        "//core/threading:vmos-threading",
        "//core:vmos-core",
        ":mock_cc_proto",
    ],
)

cc_proto_library(
    name = "mock_cc_proto",
    deps = [":mock_proto"],
    visibility = ["//visibility:public"],
)
proto_library(
    name = "mock_proto",
    srcs = ["mock.proto"],
    deps = [
        "@com_google_protobuf//:any_proto",
        
],
)