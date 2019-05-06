cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    linkopts = ["-pthread"],
    deps = [
        "//core/threading:vmos-threading",
        "//core:vmos-core",
        "//hardware:vmos-hardware",
        "//hardware/i2c:vmos-i2c",
        "//testbed/systems:sensor-subsystem",
    ],
)