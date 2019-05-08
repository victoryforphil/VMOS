cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    linkopts = ["-pthread"],
    deps = [
        "//core/threading:vmos-queues",
        "//core:vmos-core",
        "//hardware:vmos-hardware",
        "//victorycar/systems/drive:drive-subsystem",
        "//victorycar/systems/sense:sensor-subsystem"
    ],
)