

cc_library(
    name = "drive-subsystem",
    srcs = ["drive_subsystem.cpp"],
    hdrs = ["drive_subsystem.hpp"],
    visibility = ["//visibility:public"],
    deps = [
        "//core/threading:vmos-threading",
        "//core:vmos-core",
        "//hardware/control:vmos-control",
        ":drive_cc_proto",
    ],
)

cc_proto_library(
    name = "drive_cc_proto",
    deps = [":drive_proto"],
    visibility = ["//visibility:public"],
)
proto_library(
    name = "drive_proto",
    srcs = ["drive.proto"],
    deps = [
        "@com_google_protobuf//:any_proto",
        
],
)