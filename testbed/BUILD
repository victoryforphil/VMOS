cc_binary(
    name = "imu",
    srcs = ["imu.cpp"],
    linkopts = ["-pthread"],
    deps = [
        "//core/threading:vmos-threading",
        "//core:vmos-core",
        "//hardware:vmos-hardware",
        "//hardware/i2c:vmos-i2c",
        "//testbed/systems:sensor-subsystem",
    ],
)

cc_binary(
    name = "threading",
    srcs = ["threading.cpp"],
    linkopts = ["-pthread"],
    deps = [
        "//core/threading:vmos-queues",
        "//core:vmos-core",
        "//hardware:vmos-hardware",
        "//hardware/i2c:vmos-i2c",
        "//testbed/systems:mock-subsystem",
        "//testbed/systems:mock_cc_proto",
    ],
)

cc_binary(
    name = "range",
    srcs = ["range.cpp"],
    linkopts = ["-pthread"],
    deps = [
        "//core/threading:vmos-queues",
        "//core:vmos-core",
        "//hardware:vmos-hardware",
        "//hardware/i2c:vmos-i2c",
        "//testbed/systems:mock-subsystem",
        "//testbed/systems:mock_cc_proto",
    ],
)

cc_binary(
    name = "range-lite",
    srcs = ["range_lite.cpp"],
    linkopts = ["-pthread"],
    deps = [
        "//core/threading:vmos-queues",
        "//core:vmos-core",
        "//hardware:vmos-hardware",
        "//hardware/i2c:vmos-i2c",
        "//testbed/systems:mock-subsystem",
        "//testbed/systems:mock_cc_proto",
    ],
)

cc_binary(
    name = "http",
    srcs = ["http.cpp"],
    linkopts = ["-pthread"],
    deps = [
        "//core/threading:vmos-queues",
        "//core:vmos-core",
        "//core/communication/http:vmos-http",
        "//hardware:vmos-hardware",
        "//hardware/i2c:vmos-i2c",
        "//testbed/systems:mock-subsystem",
        "//testbed/systems:mock_cc_proto",
    ],
)

cc_binary(
    name = "tcp",
    srcs = ["tcp.cpp"],
    linkopts = ["-pthread"],
    deps = [
        "//core/threading:vmos-queues",
        "//core:vmos-core",
        "//core/communication/sockets:vmos-sockets",
        "//hardware:vmos-hardware",
        "//hardware/i2c:vmos-i2c",
        "//testbed/systems:mock-subsystem",
        "//testbed/systems:mock_cc_proto",
    ],
)