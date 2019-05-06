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
    ],
)