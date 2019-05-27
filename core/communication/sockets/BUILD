cc_library(
    name = "vmos-sockets",
    srcs = ["tcp_server.cpp"],
    hdrs = ["tcp_server.hpp"],
    visibility = ["//visibility:public"],
    deps = [
        "//core/communication/sockets:asio"
    ],
)
cc_library(
    name = "asio",
    hdrs = glob([
        "**/**/*.*",
      
    ]),
    includes = ['.'],
    visibility = ["//visibility:public"],

)

